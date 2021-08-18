#ifndef __PKI_X509_CERT_UTIL_H__
#define __PKI_X509_CERT_UTIL_H__

/**
  * @Name: PKIX509Util.h
  * @Copyright: KTXA SoftWare
  * @Author: Hongwei Yu
  * @Date:  2003/04/26 01:56
  * @Description: API functions about X.509 cert 
*/ 

#ifdef KT_WIN32
	#pragma pack(push,1)
#endif

#undef EXPORTS
#ifdef WIN32
	#ifndef STATIC_LIB
		#ifdef KT_DLL // assume this is defined when we build the dll
			#define EXPORTS __declspec( dllexport)
		#else
			#define EXPORTS __declspec( dllimport)
		#endif
	#else
		#define EXPORTS  
	#endif
#else
	#define EXPORTS
#endif  //WIN32

class KTCertificate;
class KTCertificates;
class KTEnvelopedData;
class KTCertificationRequest;
class CKey;

EXPORTS KTINT32 
KTPKI_Sign(
		IN KT_SESSION_HANDLE		hSession,
		IN KT_CIPHER_MECHANISM		nSignInfo,
		IN const KTCertificate&		cert,
		IN const BYTE*				pData,
		IN KTUINT					nDataLen,
		OUT BYTE*				pSignedData,
		IN OUT	KTUINT*			pnSignedDataLen
);

EXPORTS KTINT32 
KTPKI_SignCert(
		IN KT_SESSION_HANDLE		hSession,
		IN KT_CIPHER_MECHANISM		nSignInfo,		
			// KMT_SHA1_RSA_PKCS | KMT_SIGNATURE or KMT_MD5_RSA_PKCS | KMT_SIGNATURE
		IN const KTCertificate&		issuerCert,
		IN OUT	KTCertificate&		cert
);

EXPORTS KTINT32 
KTPKI_SignCRL(
		IN KT_SESSION_HANDLE		hSession,
		IN KT_CIPHER_MECHANISM		nSignInfo,		
			// KMT_SHA1_RSA_PKCS | KMT_SIGNATURE or KMT_MD5_RSA_PKCS | KMT_SIGNATURE
		IN const KTCertificate&		cert,
		IN OUT KTCRL&				crl
);

EXPORTS KTINT32 
KTPKI_Verify(
		IN KT_SESSION_HANDLE		hSession,
		IN const KTCertificate&		cert,
		IN const BYTE*				pData,
		IN KTUINT					nDataLen,
		IN const BYTE*				pSignedData,
		IN KTUINT					nSignedDataLen
);


EXPORTS KTINT32 
KTPKI_CertFindPrvKey(
		IN KT_SESSION_HANDLE		hSession,
		IN const KTCertificate&		cert,
		KTHANDLE*				phPrv
);



/////////////////////////////////////////////////////////////////////
//PKCS10 request
EXPORTS KTINT32
KTPKI_CreatePKCS10Request(
	IN KT_SESSION_HANDLE			hSession,
	IN KTINT						nKeyLen,
	IN KT_CIPHER_MECHANISM			nMech,	//KMT_SHA1_RSA_PKCS or KMT_MD5_RSA_PKCS
	IN OUT KTCertificationRequest&	CertReq,
	OUT KTHANDLE *					phPrvKey
);

EXPORTS KTINT32
KTPKI_CreatePKCS10Request2(
	IN KT_SESSION_HANDLE			hSession,
	IN KT_CIPHER_MECHANISM			nMech,	//KMT_SHA1_RSA_PKCS or KMT_MD5_RSA_PKCS
	IN KTHANDLE						hPubKey,
	IN OUT KTCertificationRequest&	CertReq
);        

EXPORTS KTINT32
KTPKI_CreatePKCS10RequestExportPrvKey(
	IN KT_SESSION_HANDLE			hSession,
	IN KTINT						nKeyLen,
	IN KT_CIPHER_MECHANISM			nMech,	//KMT_SHA1_RSA_PKCS or KMT_MD5_RSA_PKCS
	OUT BYTE*					pPubKey,
	IN OUT KTUINT32	*				pnPubKeyLen,
	OUT BYTE*					pPrvKey,
	IN OUT KTUINT32 *				pnPrvKeyLen,
	IN OUT KTCertificationRequest&	CertReq,
	IN KTBOOL						bKeepKey = FALSE,
	OUT KTHANDLE *					phPrvKey = NULL
);

/////////////////////////////////////////////////////////////////
EXPORTS KTINT32 
KTPKI_BasicEnvelop(
	IN KT_SESSION_HANDLE		hSession,
	IN const KTCertificate&		cert,
	IN const BYTE*				pData,
	IN KTUINT					nDataLen,
	OUT BYTE*				pEnvelopedData,
	IN OUT	KTUINT*			pnEnvelopedDataLen
);

EXPORTS KTINT32
KTPKI_BasicUnEnvelop(
	IN KT_SESSION_HANDLE		hSession,
	IN const KTCertificate&		cert,
	IN const BYTE*				pEnvelopedData,
	IN KTUINT					nEnvelopedDataLen,
	OUT BYTE*				pData,
	IN OUT	KTUINT*			pnDataLen
);

/////////////////////////////////////////////////////////////////////
//PKCS7

//����ǩ��
EXPORTS KTINT32
KTPKI_Pkcs7Sign(
	IN KT_SESSION_HANDLE		hSession,
	IN KTCertificates			&certs,
	IN KT_MECHANISM_TYPE		nDigestMech,
	IN const char* const		pcDataType,
	IN KTObject					&dataObj,
	OUT KTSignedData			&sSignedData
);

//��֤����ǩ��
EXPORTS KTINT32
KTPKI_Pkcs7Verify(
	IN KT_SESSION_HANDLE		hSession,
	IN KTCertificates			&certs,
	IN const BYTE*				pData,
	IN KTUINT					nDataLen
);

//�������ŷ�
EXPORTS KTINT32
KTPKI_Pkcs7Envelop(
	IN KT_SESSION_HANDLE		hSession,
	IN const KTCertificates&	certs,
	IN KT_CIPHER_MECHANISM		nMech,		//	�ԳƼ����㷨ģʽ��Ŀǰ֧��DES�㷨CBSģʽ
											//	Ӧ�ô���KMT_DES_CBC|KMT_ENCRYPT
	IN const char* const	    pcDataType,
	IN const BYTE*				pData,
	IN KTUINT					nDataLen,
	OUT KTEnvelopedData&		sEnvelopData,
	IN CKey						*pKey = NULL
	//	���ڽ�֧��DES�㷨CBSģʽ��Ӧ����ָ��CDESKey��ָ��
	//	����Pkcs#7�淶�����ݼ�����ԿӦ��ÿ��������ɣ��ʵ��ô˺���ʱӦ��������pKey����
);

//���ŷ�
EXPORTS KTINT32
KTPKI_Pkcs7UnEnvelop(
	IN KT_SESSION_HANDLE		hSession,
	IN KTCertificate&			cert,
	IN const BYTE*				pEnvelopedData,
	IN KTUINT					nEnvelopedDataLen,
	OUT BYTE*				    pData,
	IN OUT KTUINT*			    pnDataLen
);	


/////////////////////////////////////////////////////////////////////
// ֤��ʹ��
/* Description: ��ȡ֤����
 * Params: 
 *	hSession - [in] 
 *	Cert - [in] Ҫ������֤��
 *	Certs - [out] ���ص�֤��������˳��Ϊ��Cert��Cert parent, ...
 * Return:
 *	KT_OK : �ɹ���else: ʧ��
 */
EXPORTS KTINT32
KTPKI_GetCertChain(
  IN KT_SESSION_HANDLE	hSession,
  IN const KTCertificate& Cert,
  OUT KTCertificates& Certs
);

//����֤��������״̬���ж��Ƿ�Ҫ��ջ������
EXPORTS KTINT32
KTPKI_SetCertChainUpdataState(
  IN KTINT iState
);

EXPORTS KTINT32
KTPKI_GetCertTrustLevel(
  IN KT_SESSION_HANDLE	    hSession,
  IN const KTCertificate&   Cert,
  OUT KTUINT*			    pnTrustLevel);

enum enumCertStatus
{
	StatusOK,    			// ֤��û������
	StatusBeforeinEffect, 	// ֤����δ��Ч
	StatusExpired,   		// ֤���Ѿ�����
	StatusTimeBeforeIssuer, // ֤��ȷ���������Ч
	StatusTimeAfterIssuer,	// ֤��ȷ����ߺ�����
	StatusChainBad,   		// û����Ч֤����
	StatusUnAuthorized,  	// ǩ����֤ʧ��
	StatusParentCertError, 	// �ϼ�֤��δͨ����֤
	StatusRevoked,   		// ֤���ѱ��ϳ�
	StatusUnspecify,		// δָ������
	StatusOKWithTSS,		// ֤��û������,����֧��ʱ���
	StatusTSSCertNotTrust	// ʱ���֤�鲻������
	
};

/* Description: ��֤֤��
 * Params:
 *	hSession - [in] 
 *	Cert - [in] ��Ҫ��֤��֤��
 *	pCerts - [in] ���������ڵ�֤��������ΪNULL, ����TOKEN�еõ�����֤����
 *	pCRL - [in] ����������ΪNULL���������һ��
 *	bChainVerify - [in] TRUE:��֤����֤������FALSE:ֻ��֤Cert
 *	pnCertStatus - [out] ��֤�������enumCertStatus����
 * Return:
 *	KT_OK : �ɹ�������֤��״̬��Σ�һ���ܷ��ش�ֵ��
 *	Else: ����ʧ�ܣ�������֤����֤ʧ�ܡ�
 */
EXPORTS KTINT32 
KTPKI_VerifyCert(
  IN KT_SESSION_HANDLE	hSession,
  IN const KTCertificate& Cert,
  IN KTCertificates* const pCerts,	// may be=NULL, use Certs in hSession
  IN KTCRL *const pCRL,				// may be=NULL
  IN const KTBOOL bChainVerify,		// verify cert chain
  OUT enumCertStatus *pnCertStatus
);
 
/* Description: ��֤֤��
 * Params:
 *	hSession - [in] 
 *	Cert - [in] ��Ҫ��֤��֤��
 *	pCerts - [in] ���������ڵ�֤��������ΪNULL, ����TOKEN�еõ�����֤����
 *	bCheckCRL - [in] �Ƿ���CRL
 *	bChainVerify - [in] TRUE:��֤����֤������FALSE:ֻ��֤Cert
 *	pnCertStatus - [out] ��֤�������enumCertStatus����
 * Return:
 *	KT_OK : �ɹ�������֤��״̬��Σ�һ���ܷ��ش�ֵ��
 *	Else: ����ʧ�ܣ�������֤����֤ʧ�ܡ�
 */
EXPORTS KTINT32
KTPKI_VerifyCert2(
  IN KT_SESSION_HANDLE	hSession,
  IN const KTCertificate& Cert,
  IN KTCertificates* const pCerts,
  IN const KTBOOL bCheckCRL,
  IN const KTBOOL bChainVerify,
  OUT enumCertStatus *pnCertStatus
);

/* Description: ��hSession�еõ�CA֤��ĺ�������CRL��
 * Params:
 *	hSession - [in] 
 *	Cert - [in] ����CRL��֤��
 *	crl - [out] �ҵ��ĺ�����
 * Return:
 *	KT_OK : �ɹ����ҵ�������
 *	KT_ERR_OBJ_NOT_FOUND: ������δ�ҵ�
 *	Else: ����ʧ��
 */
EXPORTS KTINT32
KTPKI_GetCACRL(
  IN KT_SESSION_HANDLE	hSession,
  IN const KTCertificate& CACert,
  OUT KTCRL& crl
);


EXPORTS KTINT32
KTPKI_GetCACRL_Open(
  IN KT_SESSION_HANDLE hSession,
  IN const KTCertificate& CACert,
  OUT COpenCRL& OpenCRL
);

EXPORTS KTINT32
KTPKI_VerifyCert_Open(
  IN KT_SESSION_HANDLE hSession,
  IN const KTCertificate& Cert,
  IN const KTCertificates* pCerts,
  IN const COpenCRL* pOpenCRL,
  IN const KTBOOL bChainVerify,		// verify cert chain
  OUT enumCertStatus *pnCertStatus
);

EXPORTS KTINT32
KTPKI_VerifyCert2_Open(
  IN KT_SESSION_HANDLE	hSession,
  IN const KTCertificate& Cert,
  IN const KTCertificates* pCerts,
  IN const KTBOOL bCheckCRL,
  IN const KTBOOL bChainVerify,
  OUT enumCertStatus *pnCertStatus
);

EXPORTS KTINT32
KTPKI_Util_Thread_Initialize();

EXPORTS KTINT32
KTPKI_Util_Thread_Finalize();

#ifdef KT_WIN32
	#pragma pack(pop)
#endif

/// Rivison history
/// ----------------------------------------------------------------------------
/// 	Version	       Date        Author      Note
/// ----------------------------------------------------------------------------
///   1.0.0.0  2003/04/26 01:56  Hongwei Yu   created 

#endif
