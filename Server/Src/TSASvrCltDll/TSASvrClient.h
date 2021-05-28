// =================================================================================
//  File       : TSASvrClient.h
//  Programmer : �����
//  Created    : 2006-11-28
//  CopyRight (C) �����
// =================================================================================

#ifndef __TSASVRCLIENT_H__
#define __TSASVRCLIENT_H__

// =================================================================================
//  Include Header Files
#include <string>
#include "TSASvrStream.h"
#include "TSASvrContent.h"

// =================================================================================
//  Macro Definition
#define ERROR_INFO_CODE           "ErrorCode"
#define TSERR_INVALID_URL         500  // ��Ч��������ַ��
#define TSERR_INVALID_SRC         501  // ��Ч��ԭ�ģ�
#define TSERR_INVALID_OUTPUT      502  // ��Ч�����������
#define TSERR_TS_FORMAT_FAILED    503  // �����ʱ������ݸ�ʽ����
#define TSERR_CER_FORMAT_FAILED   504  // �����֤���ʽ����
#define TSERR_INVALID_CONNECT     510  // ���ӷ�������ʱ����ȷ�Ϸ�������ַ�Ƿ���ȷ��
#define TSERR_SEND_TIMEOUT        511  // �������ݳ�ʱ�������ԣ�
#define TSERR_RECV_TIMEOUT        512  // �������ݳ�ʱ�������ԣ�
#define TSERR_INVALID_REQ         513  // ��Ч����������
#define TSERR_INVALID_METHOD      514  //��֧�ֵķ���

#define TSERR_SERVER              520  // �������ڲ�����

#define TSERR_ISSUER_FAILED       530  // ʱ���ǩ��ʧ�ܣ�
#define TSERR_VERIFY_FAILED       531  // ʱ�����֤ʧ�ܣ�


// =================================================================================
//  Class Definition
class CTSASvrClient
{
public :
	// = Initialize soap client interface.
	int Initialize( const char * szUrl, long lConnTimeoutSecs = 20 );

	// = Get current time.
	int GetTSATime( std::string & curTime );

	// = Get tsa cert.
	int GetTSACert( std::string & certData );

	// = Issuer time stamp.
	int IssuerTimeStamp( const char * szSrc, std::string & timeStampData );

	int TS_Req( const char * SrcData, std::string & ReqData );
	
	int TS_Resp( const char * ReqData, std::string & RespData );
	
	int TS_Verify( const char* SrcData, const char* RespData);
	
	int TS_Parse( const char* RespData, std::string& ParseData , int flag);

protected :
	// = Call remote method.
	int CallRemoteMethod( const char * szMethodName, CTSASvrContent & request, 
		CTSASvrContent & response );

	// = Send request data.
	int SendRequestData( const CTSASvrStream & stream, CTSASvrContent & request );

	// = Recv response data.
	int RecvResponseData( const CTSASvrStream & stream, CTSASvrContent & response );

	// = Remote ip address.
	char remote_ip_[64];

	// = Remote port.
	short remote_port_;

	// = Connect timeout seconds.
	long conn_timeout_;
};

// =================================================================================
//  1.00    2006-11-28    Created By LinZaoGang
//  File End 
#endif  // __TSASVRCLIENT_H__
