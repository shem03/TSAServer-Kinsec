// =================================================================================
//  File    : TSADbService.cpp
//  Author  : �����
//  Created : 2006-12-30
//  CopyRight (C) �����
// =================================================================================

// =================================================================================
//  Include Header Files
#include <time.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if defined(_LINUX)
#  include <unistd.h>
#  include <signal.h>
#  include <dirent.h>
#  include <sys/ipc.h>
#  include <sys/msg.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#endif
#include "TSADbServiceApp.h"

// =================================================================================
//  Macro Definition
#define PID_FILE       "Pid/TSADbService.pid"
#define MSG_PATH       "TSADbService.msg"
#define MSG_NUM        10370
CTSADbServiceApp g_app;
#if defined(_WIN32)
#elif defined(_LINUX)
int g_msgId = 0;
#endif

// =================================================================================
//  Structure Definition
struct S_Cmd_Message
{
	long lMsgType;
	char szCmd[8192];
};

// =================================================================================
//  Global Function Definition
#if defined(_LINUX)
// = Before exit.
void OnBeforeExit( int signal )
{

	remove( PID_FILE );
	if( g_msgId > 0 && msgctl( g_msgId, IPC_RMID, NULL ) == -1 )
	{
		switch( errno )
		{
		case EIDRM :
			printf( "[Error] ɾ����Ϣ���г�����ǰ��Ϣ�����Ѿ���ɾ����\n" ); break;
		case EINVAL :
			printf( "[Error] ɾ����Ϣ���г�����Ч����Ϣ���У�\n" ); break;
		case EPERM :
			printf( "[Error] ɾ����Ϣ���г�����Ȩ��ִ�иò�����\n" ); break;
		default :
			printf( "[Error] ɾ����Ϣ���г���ϵͳ�ڲ�����\n" ); break;
		}
		g_msgId = 0;
	}

	printf( "[Info] ʱ������ݿ����ֹͣ�ɹ���\n" );
	exit( 0 );
}
#endif

void Stop();
void Service()
{
	// Create child process.
#if defined(_LINUX)
	pid_t pid;
	pid = fork();
	if( pid != 0 )
		exit( 0 );

	DIR * dir = opendir( "Pid" );
	dir ? closedir( dir ) : mkdir( "Pid", S_IRWXU | S_IRWXG | S_IRWXO );
	FILE * fp = fopen( PID_FILE, "wb" );
	if( fp )
	{
		pid = getpid();
		fwrite( &pid, 1, sizeof( pid ), fp );
		fclose( fp );
	}
	else
	{
		printf( "[Error] ����ʱ������ݿ�����������PID�ļ�ʧ�ܣ�\n" );
		exit( 0 );
	}

	// setup signal callback.
	signal( SIGTERM, OnBeforeExit );

	// Create message queue.
	key_t key = ftok( MSG_PATH, 'a' );
	g_msgId = msgget( key, IPC_CREAT | 0666 );
	if( g_msgId == -1 )
	{
		switch( errno )
		{
		case EEXIST :
			printf( "[Error] ������Ϣ���г�������Ϣ�����Ѿ����ڣ�\n" ); break;
		case ENOMEM :
			printf( "[Error] ������Ϣ���г��������ڴ治�㣡\n" ); break;
		case ENOSPC :
			printf( "[Error] ������Ϣ���г��������ɽ�������Ϣ���������Ŀ��\n" ); break;
		default :
			printf( "[Error] ������Ϣ���г���ϵͳ�ڲ�����\n" ); break;
		}
		Stop();
		exit( 0 );
	}

	if( g_app.start() != 0 )
	{
		Stop();
		exit( 0 );
	}
	printf( "[Info] ʱ������ݿ���������ɹ���\n" );

	// Wait for the cmd service message.
	S_Cmd_Message msg;
	while( 1 )
	{
		if( msgrcv( g_msgId, &msg, sizeof( msg ) - sizeof( long ), MSG_NUM, MSG_NOERROR ) == -1 )
		{
			switch( errno )
			{
			case EFAULT :
				g_app.writeServiceLog( "������Ϣ�����ڴ滺������ַ��Ч��" );
				break;
			default :
				g_app.writeServiceLog( "������Ϣ����ϵͳ�ڲ�����" );
				break;
			}
			continue;
		}
		
		// Handle message.
		g_app.m_dbConn.execute( msg.szCmd );
	}
#endif
}

void Start()
{
	printf( "[Info] ʱ������ݿ����ʼ����\n" );
#if defined(_LINUX)
    FILE * fp = fopen( PID_FILE, "rb" );
    if( fp )
    {
		pid_t pid;
		fread( &pid, 1, sizeof( pid ), fp );
        fclose( fp );
        if( kill( pid, 0 ) )
            remove( PID_FILE );
        else
		{
			printf( "[Info] ʱ������ݿ�����������У��޷��ٴ�������\n" );
			return ;
		}
    }
#endif

	Service();
}

void Stop()
{

#if defined(_LINUX)
    FILE * fp = fopen( PID_FILE, "rb" );
    if( fp )
	{
		pid_t pid;
		fread( &pid, 1, sizeof( pid ), fp );
		kill( pid, SIGTERM );
	}
#endif
}

void Restart()
{
#if defined(_LINUX)
    FILE * fp = fopen( PID_FILE, "rb" );
    if( fp )
	{
		pid_t pid;
		fread( &pid, 1, sizeof( pid ), fp );
		kill( pid, SIGTERM );
	}
#endif

	Service();
}

// =================================================================================
//  Main Function Definition
int main( int argc, char * argv[] )
{
	// �����ź�
#if defined(_LINUX)
	signal( SIGCLD, SIG_IGN );
	signal( SIGILL, SIG_IGN );
	signal( SIGIOT, SIG_IGN );
	signal( SIGFPE, SIG_IGN );
	signal( SIGBUS, SIG_IGN );
	signal( SIGSYS, SIG_IGN );
	signal( SIGTRAP, SIG_IGN );
	signal( SIGSEGV, SIG_IGN );
#endif
	
	if( argc > 1 )
	{
		if( strcmp( argv[1], "start" ) == 0 )
		{
			Start();
			return 0;
		}
		else if( strcmp( argv[1], "stop" ) == 0 )
		{
			Stop();
			return 0;
		}
		else if( strcmp( argv[1], "restart" ) == 0 )
		{
			Restart();
			return 0;
		}
	}
	
	printf( " Usage   : ./TSADbService start|stop|restart\n" );
    return 0;
}


// =================================================================================
//  1.00    2006-12-30    Created By LinZaoGang
//  File End  
