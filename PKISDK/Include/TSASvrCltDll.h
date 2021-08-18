// =================================================================================
//  File       : TSASvrCltDll.h
//  Purpose    : ʱ����������ͻ��˽ӿڡ�
//  Programmer : �����
//  Created    : 2006-11-21
//  CopyRight (C) ����������Ϣ��ȫ�������޹�˾
// =================================================================================

// =================================================================================
//  Remark: 
//    1����C/C++��Ŀ��ʹ��ʱ������ͷ�ļ� TSASvrCltDll.h������ TSASvrCltDll.lib��
//    2��VCӦ������Ŀ���Ա���ѡ�����Ϊ /MDd �� /MD�����÷������£�
//       "Project" -> "Project Settings" -> "C/C++" -> "Code Generation"
//       ���԰� Use run-time library: Debug Multithreaded DLL
//       ������ Use run-time library: Multithreaded DLL
// =================================================================================

#ifndef __TSASVRCLTDLL_H__
#define __TSASVRCLTDLL_H__

// =================================================================================
//  Include Header Files
#include <string>
using namespace std;

// =================================================================================
//  Macro Definition
#if defined(_WIN32)
#  ifdef TSASVRCLTDLL_EXPORTS
#    define TSA_EXPORT __declspec( dllexport )
#  else
#    define TSA_EXPORT __declspec( dllimport )
#    if !defined(_MT)
#      error Please use the /MDd or /MT switch (Debug Multithreaded DLL)
#    endif
#	 ifdef _DEBUG
#		pragma comment( lib, "TSASvrCltDllD.lib" )
#		pragma message( "Automatically linking with TSASvrCltDllD.lib" )
#	 else
#		pragma comment( lib, "TSASvrCltDll.lib" )
#		pragma message( "Automatically linking with TSASvrCltDll.lib" )
#	 endif  // end if
#  endif
#pragma warning( disable:4786 )
#pragma warning( disable:4060 )
//#elif defined(_LINUX)
#else
#  define TSA_EXPORT
#endif

// =================================================================================
//  Interface Function Declear
// = TSA_Initialize
// Description: TSA�ӿڳ�ʼ��
TSA_EXPORT void TSA_Initialize ();


// =================================================================================
//  Interface Function Declear
// = TSA_Initialize
// Description: TSA�ӿ�����
TSA_EXPORT void TSA_UnInitialize();

// =================================================================================
//  Interface Function Declear
// = TSA_GetErrorString
// Description: ���ݴ����ȡ������Ϣ
// Params: 
//   nErrNum         - [�������] �����
// Return: ���ش�����Ϣ��std::string 
TSA_EXPORT std::string TSA_GetErrorString( int nErrNum );

// = TSA_GetCurrentTime
// Description: ȡ��ǰ��׼ʱ��
// Params: 
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   pTimeStampTime  - [�������] ʱ���ʱ�䣬�磺2006/11/21 15:05:16
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TSA_GetCurrentTime( const char * szUrl, 
								  std::string * pCurrentTime );

// = TSA_GetTSACert
// Description: ȡʱ���������֤��
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   pCertData       - [�������] ʱ���������֤���������ݡ���BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TSA_GetTSACert( const char * szUrl, std::string * pCertData );

// = TSA_TimeStamp
// Description: ����ʱ���
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   szSrc           - [�������] ������ʱ�����ԭ������
//   pTimeStampData  - [�������] �䷢���ص�ʱ����������ݡ���BASE64����
//   unSrcLen        - [�������] ԭ�����ݵĳ��ȣ�����'\0'��β��-1��Ĭ��Ϊ-1
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TSA_TimeStamp( const char * szUrl, 
							 const char * szSrc, 
							 std::string * pTimeStampData, 
							 unsigned int unSrcLen = -1 );
//
// = TSA_Verify
// Description: ��֤ʱ���
// Params: 
//   szSrc           - [�������] ʱ���ԭ��
//   timeStampData   - [�������] ʱ����������ݡ���BASE64����
//   pCertData       - [�������] ʱ���������֤���������ݡ���BASE64����
//   pTimeStampTime  - [�������] ʱ���ʱ�䣬�磺2006/11/21 15:05:16
//   unSrcLen        - [�������] ԭ�����ݵĳ��ȣ�����'\0'��β��-1��Ĭ��Ϊ-1
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TSA_Verify( const char * szSrc, 
						  std::string timeStampData, 
						  std::string * pCertData, 
						  std::string * pTimeStampTime, 
						  unsigned int unSrcLen = -1 );

// = TS_CreateReq
// Description: ����ʱ�������
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   SrcData         - [�������] ������ʱ�����ԭ������
//   pTimeStampData  - [�������] ���ص�ʱ����������ݡ���BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_CreateReq( const char* szUrl,const char* SrcData, std::string& ReqData);


// = TS_CreateResp
// Description: ����ʱ���
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   ReqData         - [�������] ʱ�����������
//   RespData        - [�������] ���ص�ʱ������ݡ���BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_CreateResp( const char* szUrl,const char* ReqData, std::string& RespData);



// = TS_Verify
// Description: ��֤ʱ���
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   SrcData         - [�������] ʱ�����������
//   RespData        - [�������] ʱ������ݡ���BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_Verify( const char* szUrl, const char* SrcData, const char* RespData);


// = TS_Verify
// Description: ��֤ʱ���
// Params:
//   SrcData         - [�������] ʱ���ԭ��
//   RespData        - [�������] ʱ������ݡ���BASE64����
//   cacert          - [�������] �м�CA֤�顪��BASE64����
//   rootcacert      - [�������] ��CA֤�顪��BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_Verify( const char* SrcData, const char* RespData, const char* cacert, const char* rootcacert);


// = TS_Verify
// Description: ��֤ʱ���
// Params:
//   SrcData         - [�������] ʱ���ԭ��(����������)
//   SrcDataLen      - [�������] ʱ���ԭ�����ݳ���
//   RespData        - [�������] ʱ������ݡ���BASE64����
//   cacert          - [�������] �м�CA֤�顪��BASE64����
//   rootcacert      - [�������] ��CA֤�顪��BASE64����
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_Verify( const unsigned char* SrcData, int SrcDataLen, const char* RespData, const char* cacert, const char* rootcacert);


// = TS_Verify
// Description: ����ʱ���
// Params:
//   szUrl           - [�������] ʱ�����������ַ���˿ڣ��磺192.168.1.60:103
//   RespData        - [�������] ʱ�������
//   PraseData       - [�������] ʱ���ʱ��
//   flag            - [�������] ��־ 0-ʱ��  1-֤��
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_Parse( const char* szUrl, const char* RespData,  std::string& ParseData ,int flag = 0);

// = TS_Verify
// Description: ����ʱ���
// Params:
//   RespData        - [�������] ʱ�������
//   PraseData       - [�������] ʱ���ʱ��
//   flag            - [�������] ��־ 0-ʱ��  1-֤��  2-ǩ������  3-ʱ���ԭ��ժҪ  4-ʱ���ԭ��ժҪ�㷨
// Return: �ɹ�����0��ʧ�ܷ��ش����
TSA_EXPORT int TS_Parse(const char* RespData,  std::string& ParseData , int flag = 0);



// =================================================================================
//  1.00    2006-11-21    Created By LinZaoGang
//  File End 
#endif // __TSASVRCLTDLL_H__
