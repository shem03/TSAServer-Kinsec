#ifndef _MYSIGNLIBFUNC_H
#define _MYSIGNLIBFUNC_H

#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/conf.h>

#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/sha.h>

#include <string>
#include <vector>
using namespace std;

#undef TRUE
#undef FALSE
#define TRUE				0x00000001	//����ֵΪ��
#define FALSE				0x00000000	//����ֵΪ��

#ifndef BYTE
typedef unsigned char       BYTE;
#endif
#ifndef KTBOOL32
typedef int					KTBOOL32;
#endif
#ifndef WORD
typedef unsigned short int	WORD;
#endif
#ifndef DWORD
#	ifdef WIN32
        typedef unsigned long   DWORD;
#	else
        typedef unsigned int    DWORD;
#	endif
#endif
#ifndef HANDLE
typedef void *				HANDLE;
#endif

#ifndef ByteArray
typedef std::vector<BYTE> ByteArray;
#endif

// ˽Կ����
typedef int (*FUNC_PRIV_ENC)(
	int flen,
	const unsigned char *from,
	unsigned char *to,
	RSA *rsa,
	int padding);
// ˽Կ����
typedef int (*FUNC_PRIV_DEC)(
	int flen,
	const unsigned char *from,
	unsigned char *to,
	RSA *rsa,
	int padding);

// �ԳƼ��ܻ��������
// ʧ�ܷ���0���ɹ�����1
typedef int (*FUNC_SYMM_ENC_OR_DEC_DATA)(
	bool bEncrypt,						// �Ƿ����
	int nAlgID,							// �Գ��㷨��ʶ
	unsigned char *pbKey,				// ��Կ
	int nKeyLen,						// ��Կ�ĳ���
	bool bKeyEncrypted,					// ��Կ�Ƿ�Ϊ����
	unsigned char *pbIV,				// ��ʼ����
	int nIVLen,							// ��ʼ�����ĳ���
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

long MYSIGN_Initialize();
long MYSIGN_Finalize();

// PKCS7ǩ��
long MYSIGN_SignDataByP7(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	char *pszCert,						// ǩ��֤��
	char *pszKey,						// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszOut,						// �������
	bool bAttached = true);				// �Ƿ����ԭ��
// PKCS7��֤ǩ��
long MYSIGN_VerifySignedDataByP7(
	char *pszSign,
	unsigned char *pbData = NULL,
	long lDataLen = 0);
// ��ȡPKCS7ǩ����Ϣ
long MYSIGN_GetP7SignDataInfo(
	char *pszIn,
	long lType,
	unsigned char *pbOut,
	long *plOutLen);

// XMLǩ��
long MYSIGN_SignDataXML(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	char *pszCert,						// ǩ��֤��
	char *pszKeyName,					// KeyName����Ϊǩ��֤��CN��NULL��
	char *pszKey,						// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszOut);						// �������
// XML��֤ǩ��
long MYSIGN_VerifySignedDataXML(
	char *pszIn);
// ��ȡXMLǩ����Ϣ
long MYSIGN_GetXMLSignatureInfo(
	char *pszIn,
	long lType,
	unsigned char *pbOut,
	long *plOutLen);

// PKCS7�����ŷ�
// lAlgIDȡֵ���£�
//   SGD_SM1_ECB
//   SGD_SM1_CBC
//   SGD_SSF33_ECB
//   SGD_SSF33_CBC
//   SGD_SM4_ECB
//   SGD_SM4_CBC
//   ����			3DES
// ���Գ��㷨ʹ�����㷨����funcEncOrDecDataӦΪNULL��
long MYSIGN_EnvelopeDataByP7(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	char *pszRcptCerts[],						// ����֤��
	long lRcptCount,							// ����֤��ĸ���
	long lAlgID,								// �Գ��㷨
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	char *pszOut);								// �������

// ����PKCS7�����ŷ�
// ���ǶԳ��㷨ʹ�����㷨����funcPrivDecӦΪNULL������pszKeyӦΪNULL��
// ���Գ��㷨ʹ�����㷨����funcEncOrDecDataӦΪNULL��
long MYSIGN_UnenvelopeDataByP7(
	char *pszIn,								// ��������
	char *pszCert,								// ����֤��
	char *pszKey,								// ����˽Կ
	FUNC_PRIV_DEC funcPrivDec,					// ˽Կ���ܺ���
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���

long MYSIGN_CipherDataByP7( 
	unsigned char *in, 
	long inlen,
	int cipher,
	char *cert,
	char *key,
	FUNC_PRIV_ENC funcprivenc,
	char *recipcerts,
	ByteArray &rOut );
long MYSIGN_DecipherDataByP7( 
	unsigned char *in, 
	long inlen,
	char *cert,
	char *key,
	FUNC_PRIV_DEC funcprivdec,
	char *chaincerts,
	char *outsigncert,
	ByteArray &rOut );

#endif
