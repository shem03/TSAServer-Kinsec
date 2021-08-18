#ifndef _KT_CGNT_API_H
#define _KT_CGNT_API_H

/**
  *@Name: KTCgntAPI.h
  *@Copyright: KTXA SoftWare
  *@Author: Hongwei Yu
  *@Date:  2003/03/25 14:16
  *@Description: all Cgnt function envelope
*/
#ifdef __cplusplus
extern "C"	{
  class KTCertificates;
  class KTCertificate;
  class KTCRLSequence;
  class KTCertificateList;
#ifndef KTCRL
  typedef KTCertificateList KTCRL;
#endif
  class KTSequenceOf;
  class CWnd;
#else
  typedef void KTCertificates; 
  typedef void KTCertificate; 
  typedef void KTCRL; 
  typedef void CWnd;
  typedef void KTSequenceOf;
#endif

KT_LIB_MODE int KTCgnt_GetLastErrNum();

KT_LIB_MODE int KTCgnt_Thread_Initialize();
KT_LIB_MODE int KTCgnt_Thread_Finalize();

KT_LIB_MODE void KTCgnt_ShowVerifyOptIfNoCRLDlg();

//�ṩ֤��ѡ����û�ѡ��ָ��֤��
KT_LIB_MODE BOOL KTCgnt_ShowCertSelectDlg( CWnd *pParent, 
				KTHANDLE *phHandles, 
				UINT *puSize, 
				LPCTSTR pcszCaption );

//�ṩ�Ի��������û�֤��
KT_LIB_MODE BOOL KTCgnt_ShowUCHttpDownload( KT_SESSION_HANDLE hSession,
							    CWnd* pParent, 
								LPCTSTR pcszTitle, 
								LPCTSTR pcszServer, 
								LPCTSTR pcszReqPath, 
								int iPort,
								KTCertificates* pCerts
								);

//�õ��û���������ڶԳƼ��ܵ�����
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetEncryptPassWord(
				CWnd*	pParent,
				int*	pnLen,		//input, ��������С(����64�ֽ�);output, �����
				KTChar*	pc_pwd,		
				bool*	pbUseBakCert );	//�Ƿ�ʹ�ñ���֤�� 	

//�õ��û���������ڶԳƽ��ܵ�����
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetDecryptPassWord(
				CWnd*	pParent,					  
				int*	pnLen,
				KTChar*	pc_pwd, 
				bool*	pbUseBakCert );


//�õ����ڼ���ǩ����֤��
//pc_addresser:		�����˵�ַ(�ļ��ӽ���ʱΪ"")
//pc_addressee:		�ռ��˵�ַ�б�, ��",'��";"�ָ�(�ļ��ӽ���ʱΪ"")
//bAbbreviation:	�Ƿ����Notes�ռ��˵�ַ�е�@�����Ժ󲿷�,һ��ֻ����NotesӦ���вŻ����
//bSelfEnvelop:		�Ƿ����Լ��ĸ���֤�����
//hSession:		�򿪵ĸ��˻Ự,��Ϊ��
//pnLen:		����ʱ�ǻ��������ȵ�ַ,����ʱ��֤�����ַ������ȵ�ַ(������������ʱ,������Ҫ�ĳ���)	
//pc_certHanles:	֤�����ַ���			
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetEnvelopSignCertHandle(
				const KTChar*	pc_addresser,		//������
				const KTChar*	pc_addressee,		//�ռ���
				bool	bNotesAbv,
				bool	bSelfEnvelop,
				KT_SESSION_HANDLE	hSession,
				int*	pnEnveHandleCount,
				KTHANDLE*	phEnveHandles,
				int*	pnSignHandleCount,
				KTHANDLE*	phSignHandles);

//�õ����ڼ��ܵ�֤��			
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetEnvelopCertHandle(
				const KTChar*	pc_addresser,		//������
				const KTChar*	pc_addressee,		//�ռ���
				bool	bNotesAbv,
				bool	bSelfEnvelop,
				KT_SESSION_HANDLE	hSession,
				int*	pnHandleCount,
				KTHANDLE*	phHandles );
										

//�õ�����ǩ����֤��
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetSignCertHandle( 
				const KTChar*	pc_addresser,			//������
				bool	bNotesAbv,
				KT_SESSION_HANDLE	hSession,
				int*	pnHandleCount,
				KTHANDLE*	phHandles );
	
/////�����㷨���� begin	

KT_LIB_MODE const KTChar* KTCgnt_GUI_UpdateAlgorithm(KT_SESSION_HANDLE hSession, CWnd* pParent,
                                      KT_ALGORITHM_INFO* pAlgoInfo);
/////�����㷨���� end

//////��ʾ֤�����Ժ��� begin
KT_LIB_MODE const KTChar* KTCgnt_ShowCertProp( CWnd* pParentWnd,		//CWnd*
						const KTCertificate* pCert );

KT_LIB_MODE const KTChar* KTCgnt_ShowCertitificateProp( CWnd* pParentWnd,   //CWnd*
						 UINT unDerCertLen,
						 BYTE* pbDerCertData );

KT_LIB_MODE const KTChar* KTCgnt_ShowCertitificateProperty( CWnd* pParentWnd,  //CWnd*
						KT_SESSION_HANDLE hSession,
						KTHANDLE hCertHandle );
//////��ʾ֤�����Ժ��� end

//////��ʾCRL���Ժ��� begin
KT_LIB_MODE const KTChar* KTCgnt_ShowCRLProp( CWnd* pParentWnd,		//CWnd*
						const KTCRL* pCRL );
KT_LIB_MODE const KTChar* KTCgnt_ShowCRLProp2( CWnd* pParentWnd,		//CWnd*
						KTByteArray& rCRL );
//////��ʾCRL���Ժ��� begin


///////////֤֤����Ч����غ�����ʼ

//////�Ƿ�ָ��֤���Root֤��
KT_LIB_MODE bool KTI_IsGrandFatherCA( KT_SESSION_HANDLE hSession, 
				            const KTCertificate* pCert, 
				            const KTCertificate* pCACert );

//////��֤��ǰ�û��Ƿ���Ч
KT_LIB_MODE const KTChar* KTCgnt_GUI_CheckUser( KT_SESSION_HANDLE hSession,
							 bool bNotesAbv, 
							 const KTChar* pc_userID );

//////����ָ����CA֤����֤��ǰ�û��Ƿ���Ч
KT_LIB_MODE const KTChar* KTCgnt_GUI_CheckUserEx( KT_SESSION_HANDLE hSession,
							   bool bNotesAbv,
							   const KTChar*  pc_userID,
							   KTChar* pc_b64DERCACerts );

KT_LIB_MODE const KTChar* KTCgnt_GetCertTrain(KT_SESSION_HANDLE hSession, 
						const KTCertificate* pCert, 
						const KTCertificates* pCertTrain);

KT_LIB_MODE const KTChar* KTCgnt_GetCertChainAndCRL( KT_SESSION_HANDLE hSession,
						const KTCertificate* pCert,
						KTCertificates* pCertChain,
                        bool* pbExistCACRL,
						KTCRL* pCRL );

KT_LIB_MODE const KTChar* KTCgnt_CheckCertsByCRL( KT_SESSION_HANDLE hSession, 
					 const KTCertificates* pCerts,
					 int nCertCount,
					 int* pnCertStatus,
					 CWnd* pParentWnd );

KT_LIB_MODE const KTChar* KTCgnt_CheckCertByCRL( KT_SESSION_HANDLE hSession,
					const KTCertificate* pCert,
					int* pnCertStatus,
					CWnd* pParentWnd );

KT_LIB_MODE const KTChar* KTCgnt_CheckHandleCertByCRL( KT_SESSION_HANDLE hSession,
					KTHANDLE hCert,
					int* pnCertStatus,
					CWnd* pParentWnd,
					struct tm *rtm = NULL);
//////��֤֤����Ч�Ժ�������


//////ldap������غ��� begin
KT_LIB_MODE const KTChar* KTCgnt_DownObj( 
					const KTChar* const pc_filter,
					const KTChar* const pc_attrNm,
					const KTChar* const pc_msg,
					CWnd* pParent, 
					bool bSilent /*= false */,
                    KTSequenceOf* pObjSequence);

KT_LIB_MODE const KTChar* KTCgnt_DownRootCertWithCommonName(
							const KTChar* const pc_commonName, ////if NULL, down all root cert 
							CWnd* pParent,
							bool bSilent,
                            KTCertificates* pCerts);

KT_LIB_MODE const KTChar* KTCgnt_DownInnerCACertWithCommonName(
							const KTChar* pc_commonName,  ////if NULL, down all CA cert
							CWnd* pParent,
							bool bSilent,
                            KTCertificates* pCerts);

//down root ca certs and inner cacerts
KT_LIB_MODE const KTChar* KTCgnt_DownCACertWithCommonName(
							const KTChar* const pc_commonName,  ////if NULL, down all CA cert
							CWnd* pParent,
							bool bSilent,
                            KTCertificates* pCerts);

KT_LIB_MODE const KTChar* KTCgnt_GUI_DownUserCert(
						    KTChar* pc_initEditText,
						    CWnd* pParent,
						    bool bSilent,
						    bool bOnlyCipherCert,
                            KTCertificates* pCerts);

KT_LIB_MODE const KTChar* KTCgnt_DownUserCertWithEmail(
							const KTChar* const pc_email,		//cann't be NULL
							CWnd* pParent,
							bool bSilent,
                            bool bOnlyCipherCert,
                            KTCertificates* pCerts );

KT_LIB_MODE const KTChar* KTCgnt_DownUserCertWithSerialNumber( 
							const KTChar* const pc_serialNumber, //cann't be NULL
							CWnd* pParent,
							bool bSilent,
                            bool bOnlyCipherCert,
                            KTCertificates* pCerts );

KT_LIB_MODE const KTChar* KTCgnt_DownUserCertWithCommonName(
							const KTChar* const pc_commonName, 
							CWnd* pParent,
							bool bSilent,
                            bool bOnlyCipherCert,
                            KTCertificates* pCerts);

KT_LIB_MODE const KTChar* KTCgnt_DownCRL(
						    CWnd* pParent,
						    bool bSilent,
                            KTCRLSequence* pCRLs );

KT_LIB_MODE const KTChar* KTCgnt_DownCRLAndImport_Open(
								KT_SESSION_HANDLE hSession,
								CWnd* pParent,
								bool bSilent,
								KTHANDLE& hCrl);
//////ldap������غ��� end

KT_LIB_MODE const KTChar* KTCgnt_PutCRLs(KT_SESSION_HANDLE hSession, const KTCRLSequence* pCRLs);
KT_LIB_MODE const KTChar* KTCgnt_PutCerts(KT_SESSION_HANDLE hSession,
					KT_TOKEN_OBJ_TYPE nType, const KTCertificates* pCerts);
KT_LIB_MODE const KTChar* KTCgnt_PutCertsEx(KT_SESSION_HANDLE hSession,
					KT_TOKEN_OBJ_TYPE nType, const KTCertificates* pCerts, KTHANDLE phHandles[], KTBOOL pbSuccess[]);

KT_LIB_MODE bool KTCgnt_GUI_IsTrustRootCert( CWnd* pParentWnd,
									const KTCertificate* pCert );

KT_LIB_MODE bool KTCgnt_B64CertOrCRLToDER( BYTE* pInput, UINT unInputLen, 
					 BYTE* pOutput, UINT* punOutputLen );

KT_LIB_MODE CWnd* KTCgnt_HWNDToCWnd(HWND hwnd);

enum enumPropPage
{
	PropPageLoginInfo=0x001,
	PropPageCertPersonal=0x002,
	PropPageCertUser=0x004,
	PropPageCertCA=0x008,
	PropPageCertRootCA=0x010,
	PropPageCRL=0x020,
	PropPageKey=0x040,
	PropPageSlot=0x080,
	PropPageCfgParam=0x100,
	PropPageSecSealManage=0x200,
	PropPageCfgParam2 = 0x400,
	PropPagesTssManage	= 0x800,		
	PropPagesCert=PropPageCertPersonal|PropPageCertUser|PropPageCertCA|PropPageCertRootCA,
	PropPagesPKIEgn=PropPagesCert|PropPageCRL|PropPageSlot|PropPageCfgParam|PropPageCfgParam2,
	PropPageCertThreeCA=0x009,
};

KT_LIB_MODE const KTChar* KTCgnt_RunPropSheet(KT_SESSION_HANDLE hSession, enumPropPage selectPage, CWnd* pParentWnd, 
									   KTUINT unPropPages, const KTChar* pc_caption);

KT_LIB_MODE BOOL KTCgnt_OpenFileNormal(LPCTSTR szFileNm, bool bWait, LPCTSTR szCmdLnParam);

/*
nOption  [7][6][5][4][3][2][1][0]	
	��0λ 0=ѯ���û��Ƿ�����, 1=�Զ�����
	��1λ 0=ѯ���û��Ƿ�װ, 1=�Զ���װ
	��2λ 0=����ʱ��ʾ�û���  1=�Զ��˳�

pc_updtSvrURL=NULL��"" ʱ�Զ���UICfgģ���ж�ȡ
nProductVersion=-1 ʱ�Զ���UICfgģ���ж�ȡ
nOption=-1 ʱ�Զ���UICfgģ���ж�ȡ
*/
KT_LIB_MODE const KTChar* KTCgnt_UpdtProduct(const char* pc_updtSvrURL, const char* pc_productNm, int nProductVersion, 
				 int nOption, HWND hParentWnd, const char* pc_msgTitle, const char* pc_workFolder, bool bBackground,
				 bool bWaitSetup);

KT_LIB_MODE const KTChar* KTCgnt_UpdtAllProducts(char* pc_moduleNm, int nOption, HWND hParentWnd, char* pc_msgTitle,
												 bool bBackground, bool bWaitSetup);

KT_LIB_MODE const KTChar* KTCgnt_UpdtProductEx(const char* pc_updtSvrURL, const char* pc_productNm, int nProductVersion, 
				 int nOption, HWND hParentWnd, const char* pc_msgTitle, const char* pc_workFolder, bool bBackground,
				 bool bWaitSetup, KTCertificate* pCert);

KT_LIB_MODE const KTChar* KTCgnt_UpdtAllProductsEx(char* pc_moduleNm, int nOption, HWND hParentWnd, char* pc_msgTitle,
												 bool bBackground, bool bWaitSetup, KTCertificate* pCert);


KT_LIB_MODE void KTCgnt_TransCertStatus( int nCertStatus, KTChar pc_certStatus[KT_MAX_PATH]);

KT_LIB_MODE bool KTCgnt_GetSingleField(KTChar* singleField, KTChar* buffField );

KT_LIB_MODE bool KTCgnt_CompareEmailAddr(const KTChar* const pc_email, 
					  const KTChar* const pc_emails,
					  bool bEmailsNotesAbv ); 

#ifdef __cplusplus


KT_LIB_MODE bool KTCgnt_IsGrandFatherCA( KT_SESSION_HANDLE hSession, 
				        const KTCertificate& cert, 
				        const KTCertificate& caCert );

KT_LIB_MODE bool KTCgnt_IsExistSuperiorCA( KT_SESSION_HANDLE hSession, 
				        const KTCertificate& cert, 
				        const KTCertificates& caCerts );

KT_LIB_MODE const KTChar* KTCgnt_GUI_CheckUserEx2( KT_SESSION_HANDLE hSession,
							 bool bNotesAbv, 
							 const KTChar* pc_userID,
							 const KTCertificates* pCACerts );

#if defined(_DLL)

KT_LIB_MODE void KTCgnt_TranslateCertStatus( int nCertStatus, 
							   KTString& strStatus );

KT_LIB_MODE void KTCgnt_NotesAbvString( const KTChar* const szEmail,
					        KTString& strEmail );

KT_LIB_MODE BOOL KTCgnt_ShowCertSelectDlgEx( CWnd* pParent, 
							KTHandleArray& arr, 
							LPCTSTR pcszCaption );

KT_LIB_MODE void  KTCgnt_ConvertStringToArray(const KTChar* const lpszEmails , 
						   bool bEmailsNotesAbv,
						   KTStringArray& strArray );

KT_LIB_MODE bool KTCgnt_CompareEmailAddrEx( KTStringArray& strArrAddressee,
						const KTStringArray& strArrEmail,
						KTUintArray & dwArrOffset );

//�õ����ڼ���ǩ����֤��
//Pc_objID:			�������ռ��˵�ַ��֤���ж�Ӧ��ID, ����ObjID_emailAddress
//pc_addresser:		�����˵�ַ(�ļ��ӽ���ʱΪ"")
//pc_addressee:		�ռ��˵�ַ�б�, ��",'��";"�ָ�(�ļ��ӽ���ʱΪ"")
//bAbbreviation:	�Ƿ����Notes�ռ��˵�ַ�е�@�����Ժ󲿷�,һ��ֻ����NotesӦ���вŻ����
//bSelfEnvelop:		�Ƿ����Լ��ĸ���֤�����
//hSession:			�򿪵ĸ��˻Ự,��Ϊ��	
//rHandle:			���ص�֤�����б�			
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetEnvelopSignCertHandleEx(
				const KTChar*	pc_objID,			//if NULL, get from config info
				const KTChar*	pc_addresser,		//������
				const KTChar*	pc_addressee,		//�ռ���
				bool	bNotesAbv,
				bool	bSelfEnvelop,
				KT_SESSION_HANDLE	hSession,
				KTHandleArray&	hArrEnvCert,
				KTHandleArray&	hArrSignCert);

//�õ����ڼ��ܵ�֤��			
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetEnvelopCertHandleEx(
				const KTChar*	pc_objID,			//if NULL, get from config info
				const KTChar*	pc_addresser,		//������
				const KTChar*	pc_addressee,		//�ռ���
				bool	bNotesAbv,
				bool	bSelfEnvelop,
				KT_SESSION_HANDLE	hSession,
				KTHandleArray&	rHandle);
										

//�õ�����ǩ����֤��
KT_LIB_MODE const KTChar* KTCgnt_GUI_GetSignCertHandleEx(
				const KTChar*	pc_objID,				//if NULL, get from config info											  
				const KTChar*	pc_addresser,			//������
				bool	bNotesAbv,
				KT_SESSION_HANDLE	hSession,
				KTHandleArray&	rHandle);

//ʹ��ʱ�������ǩ��
KT_LIB_MODE const KTChar* KTCgnt_TimeStamp( 
	const char *szUrl,/*[in]ʱ��������ַ*/
	const char *szSrc,/*[in]ԭ��*/
	KTString *pstrCipher,/*[out]ʱ���ǩ������*/
	bool bUIShow,/*[in]�Ƿ���ʾ����*/
	int &nRetSelID/*[out]��ѡ��UI��,���ضԻ���ѡ��İ�ťID*/
	);
KT_LIB_MODE const KTChar* KTCgnt_TimeStampEx( 
	const char *szUrl,/*[in]ʱ��������ַ*/
	const unsigned char *pbSrc,/*[in]ԭ��*/
	int nSrcLen,/*[in]ԭ�ĳ���*/
	unsigned char *pbCipher,/*[out]ʱ���ǩ������*/
	int *pnCipherLen/*[out]ʱ���ǩ�����ݳ���*/
	);
KT_LIB_MODE const KTChar* KTCgnt_TimeStampEx_WithStatus( 
	const char *szUrl,/*[in]ʱ��������ַ*/
	const unsigned char *pbSrc,/*[in]ԭ��*/
	int nSrcLen,/*[in]ԭ�ĳ���*/
	unsigned char *pbCipher,/*[out]ʱ���ǩ������*/
	int *pnCipherLen/*[out]ʱ���ǩ�����ݳ���*/
	);
//ʹ��ʱ���������֤
KT_LIB_MODE const KTChar* KTCgnt_VerifyTimeStamp(
	const char *szUrl,/*[in]ʱ��������ַ*/
	const char *szCipher,/*[in]ʱ���ǩ������*/
	const char *szSrc,/*[in]����ԭ��*/
	KTCertificate *pcertSign,/*[out]ǩ��֤��*/
	KTString *pstrStampTime,/*[out]ʱ���ʱ��(�ַ���)*/
	bool bUIShow = FALSE
	);
KT_LIB_MODE const KTChar* KTCgnt_VerifyTimeStampEx(
	const char *szUrl,/*[in]ʱ��������ַ*/
	const unsigned char *pbCipher,/*[in]ʱ���ǩ������*/
	int nCipherLen,/*[in]ʱ���ǩ�����ݳ���*/
	const unsigned char *pbSrc,/*[in]ԭ��*/
	int nSrcLen/*[in]ԭ�ĳ���*/
	);
//����ʱ���
KT_LIB_MODE const KTChar* KTCgnt_GetTimeStampInfoEx(
	const char *szUrl,/*[in]ʱ��������ַ*/
	const unsigned char *pbCipher,/*[in]ʱ���ǩ������*/
	int nCipherLen,/*[in]ʱ���ǩ�����ݳ���*/
	int nFlag,/*[in]��־ 0-ʱ��  1-֤��  2-ǩ������  3-ʱ���ԭ��ժҪ  4-ʱ���ԭ��ժҪ�㷨  10-Z��β��ʱ��*/
	unsigned char *pbParseData,/*[in]�������*/
	int *pnParseDataLen/*[in]������ݳ���*/
	);

//��ȡ��������
KT_LIB_MODE int KTCgnt_GetErrDescriptionByTS(
	const char *szUrl,/*[in]ʱ��������ַ*/
	int nError,/*[in]�����*/
	KTString& strError/*[out]��������*/
	);

KT_LIB_MODE const KTChar* KTCgnt_DownloadFile(
	const char *pszUrl,/*[in]�ļ����ص�ַ*/
	const char *pszDestPath/*[in]�ļ�����·��*/
	);

KT_LIB_MODE const KTChar* KTCgnt_DownloadFileEx(
	const char *pszCAFile,/*[in]CA֤���ļ�·��*/
	const char *pszUrl,/*[in]�ļ����ص�ַ*/
	const char *pszDestPath/*[in]�ļ�����·��*/
	);

KT_LIB_MODE const KTChar* KTCgnt_HTTPRequest(
	const char *pszCAFile,/*[in]CA֤���ļ�·��*/
	const char *pszUrl,/*[in]�����ַ*/
	const char *pszParam,/*[in]�������*/
	KTByteArray& rResult/*[out]��������*/
	);

//======================================
KT_LIB_MODE const KTChar*	KTBsc_CertFindPrvKeyEx(
					KT_SESSION_HANDLE hSession, 
					KTBYTE* pCert, 
					KTUINT nSize, 
					KTHANDLE& hPrvKey );

KT_LIB_MODE const KTChar*   KTBsc_ListData2( KT_SESSION_HANDLE		hSession,
				    KT_TOKEN_OBJ_TYPE		nObjectType,
				    const BYTE*				pPropHash,	//default=NULL
				    UINT 					nPropHashLen,
                    KTHandleArray&          handleArr);

KT_LIB_MODE const KTChar*   KTBsc_GetData2( KT_SESSION_HANDLE  hSession,    
                    KTHANDLE	            handle,
                    KTByteArray&            baData );
//�ɼ��𣬻�ȡ֤����
KT_LIB_MODE const KTChar*   KTBsc_ListDataByTrustLevel( KT_SESSION_HANDLE		hSession,
											KT_TOKEN_OBJ_TYPE				nObjectType,
											KTUINT32						nObjectTrustLevel,
											const BYTE*				pPropHash,	//default=NULL
											UINT 					nPropHashLen,
                    KTHandleArray&          handleArr);
//��CA��������ȡ֤����
KT_LIB_MODE const KTChar*   KTBsc_ListDataByCAAltName( KT_SESSION_HANDLE		hSession,
													   KT_TOKEN_OBJ_TYPE		nObjectType,
													   CHAR*			nObjectCAAltName,
													   const BYTE*				pPropHash,	//default=NULL
													   UINT 					nPropHashLen,
                    KTHandleArray&          handleArr);


} //extern "C"

#else

} //extern "C"

#include "./UICfg.hpp"
#include "./UIBasic.hpp"

KT_LIB_MODE const KTChar*	KTBsc_CertFindPrvKeyEx(
					KT_SESSION_HANDLE hSession, 
					KTBYTE* pCert, 
					KTUINT nSize, 
					KTHANDLE& hPrvKey );

inline const KTChar*   KTBsc_ListData2( KT_SESSION_HANDLE		hSession,
				KT_TOKEN_OBJ_TYPE		nObjectType,
				const BYTE*				pPropHash,	//default=NULL
				UINT 					nPropHashLen,
                KTHandleArray& handleArr)
{	
	int rv =0;
	KTUINT unSize=0;
	do{
		unSize = handleArr.size()+KT_MAX_PATH;
		handleArr.resize(unSize);
		rv = KTPKI_ListData( hSession, nObjectType, pPropHash, nPropHashLen, 
				&handleArr[0], &unSize );
	}while(rv==KT_ERR_BUFFER_SMALL);

	if( rv!=0 ) 
		return KTPKI_UI_SetErr( "���ܴ�֤��洢�豸�ж�ȡ�����б�,%s!\n\n��ǰ�Ự%d,��ǰ��������%d!", 
								 KTPKI_GetErrorString(rv), hSession, nObjectType );
	handleArr.resize(unSize);
	return NULL;	
}

inline const KTChar*   KTBsc_GetData2( KT_SESSION_HANDLE  hSession,    
              KTHANDLE	    handle,
              KTByteArray&  baData )
{
	KTUINT unSize=0;
    const KTChar* pc_err = KTBsc_GetDataSize(hSession, handle, &unSize);
    if(pc_err)  return pc_err;

    baData.resize(unSize);
    return KTBsc_GetData(hSession, handle, &baData[0], &unSize);
}

#endif

#endif

/// Rivison history
/// ----------------------------------------------------------------------------
/// 	Version	       Date        Author      Note
/// ----------------------------------------------------------------------------
///   1.0.0.0  2003/03/25 14:23  Hongwei Yu   Created 
///   1.0.0.1  2003/05/09 09:23  Hongwei Yu   move C++ API functions from KTCgnt.h
///   1.0.0.2  2003/06/03 16:46  Hongwei Yu   added KTCgnt_GUI_Get***HandleEx functions
///   1.0.0.3  2003/06/11 21:35  Hongwei Yu   added const in some function paramters
///   1.0.0.4  2003/08/29 12:26  Hongwei Yu   added KTBsc* and KTCgnt_DownObj
///   1.0.0.5  2003/10/16 15:34  Hongwei Yu   supported KTBsc* in MT and auto update
///   1.0.0.6  2003/12/10 16:48  ChenLingChan added KTCgnt_ShowCertSelectDlg**
///   1.0.0.7  2003/12/11 14:55  Hongwei Yu   added KTCgnt_TransCertStatus
///   1.0.0.8  2003/12/29 18:58  Chenlc		  added KTCgnt_ShowUCHttpDownload
///   1.0.0.9  2003/12/30 17:19  Hongwei Yu   added KTCgnt_OpenFileNormal

#endif