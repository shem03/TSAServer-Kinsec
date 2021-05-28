// =================================================================================
//  File    : AppMonitor.cpp
//  Purpose : Ӧ�ó����س���
//  Author  : �����
//  Created : 2006-12-30
//  CopyRight (C) �����
// =================================================================================

// =================================================================================
//  Include Header Files
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#if defined(_WIN32)
#  include <windows.h>
#elif defined(_LINUX)
#  include <unistd.h>
#  include <dirent.h>
#  include <sys/stat.h>
#  include <sys/types.h>
#endif
#include "TSAMonitorApp.h"

// =================================================================================
//  Macro Definition
#define PID_FILE "Pid/TSAMonitor.pid"
CTSAMonitorApp g_app;

// =================================================================================
//  Global Function Definition
#if defined(_LINUX)
// = Before exit.
void OnBeforeExit( int signal )
{
	remove( PID_FILE );
	printf( "[Info] ϵͳ��ط���ֹͣ�ɹ���\n" );
	exit( 0 );
}
#endif

int TestPid( const char * szPidFile )
{
#if defined(_WIN32)
	return 0;
#elif defined(_LINUX)
	FILE * fp = fopen( szPidFile, "rb" );
	if( fp )
	{
		pid_t pid;
		fread( &pid, 1, sizeof( pid ), fp );
		fclose( fp );
		if( kill( pid, 0 ) )
			return -1;
		else
			return 0;
	}
	else
		return -1;
#endif
}

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
		printf( "[Error] ����ϵͳ��ط����������PID�ļ�ʧ�ܣ�\n" );
		exit( 0 );
	}

	// setup signal callback.
	signal( SIGTERM, OnBeforeExit );
#endif

	// Get setting.
	if( g_app.start() != 0 )
	{
		Stop();
		exit( 0 );
	}

	printf( "[Info] ϵͳ��ط��������ɹ���\n" );
	while( 1 )
	{
#if defined(_WIN32)
		Sleep( g_app.m_nInterval * 1000 );
#elif defined(_LINUX)
		sleep( g_app.m_nInterval );
#endif

		// Monitor TSADbService.
		if( TestPid( "Pid/TSADbService.pid" ) != 0 )
		{
			g_app.writeMonitorLog( "ʱ������ݿ�������в�������׼��������������" );
			system( "./TSADbService restart" );
		}
		
		// Monitor TSATimeSync.
		if( TestPid( "Pid/TSATimeSync.pid" ) != 0 )
		{
			g_app.writeMonitorLog( "ʱ��ͬ���������в�������׼��������������" );
			system( "./TSATimeSync restart" );
		}

		// Monitor TSAServer.
		if( TestPid( "Pid/TSAServer.pid" ) != 0 )
		{
			g_app.writeMonitorLog( "ʱ�������������������в�������׼��������������" );
			system( "./TSAServer restart" );
		}

		// Monitor TSAService.
		if( TestPid( "Pid/TSAService.pid" ) != 0 )
		{
			g_app.writeMonitorLog( "ʱ����䷢�������в�������׼��������������" );
			system( "./TSAService restart" );
		}
		/*char szServiceUrl[260];
		sprintf( szServiceUrl, "127.0.0.1:%d", g_app.m_nServicePort );
		std::string curTime;
		int nErr = TSA_GetCurrentTime( szServiceUrl, &curTime );
		if( nErr != 0 )
		{	
			g_app.writeMonitorLog( "ʱ����䷢�������в�������׼��������������" );
			system( "./TSAService restart" );
		}*/
	}
}

void Start()
{
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
			printf( "[Info] ϵͳ��ط����������У��޷��ٴ�������\n" );
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
		fclose( fp );
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
		fclose( fp );
		kill( pid, SIGTERM );
	}
#endif

	Service();
}

// =================================================================================
//  Main Function Definition
int main( int argc, char * argv[] )
{
#if defined( _WIN32 ) && defined( _DEBUG )
	Start();
#endif

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

	printf( " Usage   : ./TSAMonitor start|stop|restart\n" );
    return 0;
}


// =================================================================================
//  1.00    2006-11-22    Created By LinZaoGang
//  File End  
