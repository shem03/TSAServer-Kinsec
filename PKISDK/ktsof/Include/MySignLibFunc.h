#ifndef _MYSIGNLIBFUNC_H
#define _MYSIGNLIBFUNC_H

#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/conf.h>

#include <openssl/asn1t.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/sha.h>
#include <openssl/ts.h>

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
	unsigned char *pbCert,				// ǩ��֤��
	long lCertLen,						// ǩ��֤��ĳ���
	unsigned char *pbKey,				// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	long lKeyLen,						// ǩ��˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	unsigned char *pbOut,				// �������
	long *plOutLen,						// ������ݵĳ���
	bool bAttached = true,				// �Ƿ����ԭ��
	bool bHasAttr = false,				// �Ƿ����ǩ������
	bool bWithVerificationCode = false);// �Ƿ��У����
long MYSIGN_SignDataByP7(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	char *pszCert,						// ǩ��֤�飨base64���룩
	char *pszKey,						// ǩ��˽Կ��base64���롣��ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszOut,						// ������ݣ�base64���룩
	bool bAttached = true,				// �Ƿ����ԭ��
	bool bHasAttr = false,				// �Ƿ����ǩ������
	bool bWithVerificationCode = false);// �Ƿ��У����
// PKCS7��֤ǩ��
long MYSIGN_VerifySignedDataByP7(
	unsigned char *pbP7Sign,			// PKCS7ǩ��
	long lP7SignLen,					// PKCS7ǩ���ĳ���
	unsigned char *pbData = NULL,		// ԭ��
	long lDataLen = 0);					// ԭ�ĵĳ���
long MYSIGN_VerifySignedDataByP7(
	char *pszP7Sign,					// PKCS7ǩ����base64���룩
	unsigned char *pbData = NULL,		// ԭ��
	long lDataLen = 0);					// ԭ�ĵĳ���
// ��ȡPKCS7ǩ����Ϣ
long MYSIGN_GetP7SignDataInfo(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	long lType,							// ���ͣ�1��ԭ�ģ�2��ǩ��֤�飬3��ǩ��ֵ��4��ǩ���㷨��5��ԭ��ժҪ��6��ժҪ�㷨��7��ǩ�����ݰ汾��8��ǩ��ʱ��
	unsigned char *pbOut,				// �������
	long *plOutLen);					// ������ݵĳ���
long MYSIGN_GetP7SignDataInfo(
	char *pszIn,						// �������ݣ�base64���룩
	long lType,							// ���ͣ�1��ԭ�ģ�2��ǩ��֤�飬3��ǩ��ֵ��4��ǩ���㷨��5��ԭ��ժҪ��6��ժҪ�㷨��7��ǩ�����ݰ汾��8��ǩ��ʱ��
	unsigned char *pbOut,				// ������ݣ�ǩ��֤�顢ǩ��ֵ��ժҪֵΪbase64���룩
	long *plOutLen);					// ������ݵĳ���

// XMLǩ��
long MYSIGN_SignDataXML(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	char *pszCert,						// ǩ��֤�飨base64���룩
	char *pszKeyName,					// KeyName����Ϊǩ��֤��CN��NULL��
	char *pszKey,						// ǩ��˽Կ��base64���롣��ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszOut);						// ������ݣ�base64���룩
// XML��֤ǩ��
long MYSIGN_VerifySignedDataXML(
	char *pszIn);						// �������ݣ�base64���룩
// ��ȡXMLǩ����Ϣ
long MYSIGN_GetXMLSignatureInfo(
	char *pszIn,						// �������ݣ�base64���룩
	long lType,							// ���ͣ�1��xmlԭ�ģ�2��ժҪ��3��ǩ��ֵ��4��ǩ��֤�飬5��ժҪ�㷨��6��ǩ���㷨
	unsigned char *pbOut,				// ������ݣ�ժҪ��ǩ��֤���ǩ��ֵΪbase64���룩
	long *plOutLen);					// ������ݵĳ���

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
	char *pszEncCerts[],						// ����֤�飨base64���룩
	long lEncCertsCount,						// ����֤��ĸ���
	long lAlgID,								// �Գ��㷨
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen,								// ������ݵĳ���
	bool bWithVerificationCode = false);		// �Ƿ��У����
long MYSIGN_EnvelopeDataByP7(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	char *pszEncCerts[],						// ����֤�飨base64���룩
	long lEncCertsCount,						// ����֤��ĸ���
	long lAlgID,								// �Գ��㷨
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	char *pszOut,								// ������ݣ�base64���룩
	bool bWithVerificationCode = false);		// �Ƿ��У����
// PKCS7���������ŷ�
// ���Գ��㷨ʹ�����㷨����funcEncOrDecDataӦΪNULL��
// ��Ϊ����SKF�ӿڵ�Ӳ���豸������Ҫ����funcPrivDec��funcEncOrDecData�����˵���Գ���Կ�ͶԳƽ��ܡ�
long MYSIGN_UnenvelopeDataByP7(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	unsigned char *pbCert,						// ����֤��
	long lCertLen,								// ����֤��ĳ���
	unsigned char *pbKey,						// ����˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	long lKeyLen,								// ����˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	FUNC_PRIV_DEC funcPrivDec,					// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���
long MYSIGN_UnenvelopeDataByP7(
	char *pszIn,								// �������ݣ�base64���룩
	char *pszCert,								// ����֤�飨base64���룩
	char *pszKey,								// ����˽Կ��base64���롣��ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_DEC funcPrivDec,					// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���
// ��ȡPKCS7�����ŷ���Ϣ
long MYSIGN_GetP7EnvelopeDataInfo(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	long lType,									// ���ͣ�1��������֤��İ䷢��DN�����кţ�DN1;���к�1|DN2;���к�2...��
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���
long MYSIGN_GetP7EnvelopeDataInfo(
	char *pszIn,								// �������ݣ�base64���룩
	long lType,									// ���ͣ�1��������֤��İ䷢��DN�����кţ�DN1;���к�1|DN2;���к�2...��
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���

// PKCS7ǩ���������ŷ�
// lAlgIDȡֵ���£�
//   SGD_SM1_ECB
//   SGD_SM1_CBC
//   SGD_SSF33_ECB
//   SGD_SSF33_CBC
//   SGD_SM4_ECB
//   SGD_SM4_CBC
//   ����			3DES
// ���Գ��㷨ʹ�����㷨����funcEncOrDecDataӦΪNULL��
long MYSIGN_SignAndEnvelopeDataByP7(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	unsigned char *pbSignCert,					// ǩ��֤��
	long lSignCertLen,							// ǩ��֤��ĳ���
	unsigned char *pbSignKey,					// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	long lSignKeyLen,							// ǩ��˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	FUNC_PRIV_ENC funcPrivEnc,					// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszEncCerts[],						// ����֤�飨base64���룩
	long lEncCertsCount,						// ����֤��ĸ���
	long lAlgID,								// �Գ��㷨
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen,								// ������ݵĳ���
	bool bWithVerificationCode = false);		// �Ƿ��У����
// PKCS7���������ŷ⼰��֤ǩ��
// ���Գ��㷨ʹ�����㷨����funcEncOrDecDataӦΪNULL��
// ��Ϊ����SKF�ӿڵ�Ӳ���豸������Ҫ����funcPrivDec��funcEncOrDecData�����˵���Գ���Կ�ͶԳƽ��ܡ�
long MYSIGN_UnenvelopeAndVerifyDataByP7(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	unsigned char *pbEncCert,					// ����֤��
	long lEncCertLen,							// ����֤��ĳ���
	unsigned char *pbEncKey,					// ����˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	long lEncKeyLen,							// ����˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	FUNC_PRIV_DEC funcPrivDec,					// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	FUNC_SYMM_ENC_OR_DEC_DATA funcEncOrDecData,	// �ԳƼ��ܻ�������ݺ���
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���
// ��ȡPKCS7ǩ���������ŷ���Ϣ
long MYSIGN_GetP7SignAndEnvelopeDataInfo(
	unsigned char *pbIn,						// ��������
	long lInLen,								// �������ݵĳ���
	long lType,									// ���ͣ�2��ǩ��֤�飬3��ǩ��ֵ
	unsigned char *pbOut,						// �������
	long *plOutLen);							// ������ݵĳ���

#endif
