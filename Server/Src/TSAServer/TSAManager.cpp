// =================================================================================
//  File    : TSAManager.cpp
//  Purpose : ʱ���������������
//  Author  : �����
//  Created : 2006-11-26
//  CopyRight (C) Fujian Kinsec
// =================================================================================

#pragma warning( disable : 4786 )

// =================================================================================
//  Include Header Files
#include "TSAManager.h"

// =================================================================================
//  Macro Definition
CTSAManager g_mgr;

// =================================================================================
//  Class Definition
// = Start.
int CTSAManager::start()
{
	// Get setting.
	if( this->m_setting.Load( SETTING_FILE ) != 0 )
	{
		printf( "[Error] Load TSASetting.xml Failed.\n" );
		return -1;
	}
	if( this->m_setting.GetSetting() != 0 )
		return -1;

	/*
	// Connect database.  �ɹ�����0
	if( this->m_dbConn.connect( this->m_setting.m_strDbName.c_str(), 
		this->m_setting.m_strDbUser.c_str(), this->m_setting.m_strDbPwd.c_str(), 
		this->m_setting.m_strDbServer.c_str(), this->m_setting.m_nDbPort ) != 0 )
	{
		printf( "[Error] Load Database Connection Failed.\n" );
		return -1;
	}
	*/

	return 0;
}


// =================================================================================
//  1.00    2006-11-26    Created By LinZaoGang
//  File End  
