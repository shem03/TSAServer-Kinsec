#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main( int argc, char * argv[] )
{
	if( argc > 1 )
	{
		if( strcmp( argv[1], "start" ) == 0 )
		{
			system( "./TSATimeSync start" );
			sleep(5);
			system( "./TSAServer start" );
			system( "./TSService start" );
			//system( "./TSADbService start" );
			//system( "./TSAService start" );
			//system( "./TSAMonitor start" );
			return 0;
		}
		else if( strcmp( argv[1], "stop" ) == 0 )
		{
			system( "./TSService stop" );
			system( "./TSATimeSync stop" );
			system( "./TSAServer stop" );
			//system( "./TSAMonitor stop" );
			//system( "./TSAService stop" );
			//system( "./TSADbService stop" );
			
			return 0;
		}
		else if( strcmp( argv[1], "restart" ) == 0 )
		{
			system( "./TSService stop" );
			system( "./TSATimeSync stop" );
			system( "./TSAServer stop" );
			//system( "./TSAMonitor stop" );
			//system( "./TSAService stop" );
			//system( "./TSADbService stop" );

			system( "./TSATimeSync start" );
			sleep(5);
			system( "./TSAServer start" );
			system( "./TSService start" );
			//system( "./TSADbService start" );
			//system( "./TSAService start" );
			//system( "./TSAMonitor start" );
			return 0;
		}
	}

	printf( "--------------------------------------------------------\n" );
	printf( " System  : �����Ű�ʱ���������\n" );
	printf( " Version : V1.2\n" );
	printf( " Company : ����������Ϣ��ȫ�������޹�˾\n" );
	printf( " Copyright (C) ����������Ϣ��ȫ�������޹�˾.\n\n" );
	printf( " Usage   : TSAAdmin [Option]\n" );
	printf( " Option  : start     - �������з���\n" );
	printf( "           stop      - ֹͣ���з���\n" );
	printf( "           restart   - �����������з���\n" );
	printf( "           help      - ϵͳ������\n" );
	printf( " Thank you for using this system.\n" );
	printf( "--------------------------------------------------------\n" );
    return 0;
}


