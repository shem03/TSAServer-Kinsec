#ifndef _KSSIGNLIBFUNC_H
#define _KSSIGNLIBFUNC_H

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
#ifdef WIN32
	typedef unsigned long   DWORD;
#else
	typedef unsigned int    DWORD;
#endif
#endif
#ifndef HANDLE
typedef void *				HANDLE;
#endif

////////////////////////////////////////////////////////////////
// �ص�����

// ���º����ɹ�����0��ʧ�ܷ�������
// ˽Կ����
typedef int (*KS_FUNC_PRIV_ENC)(
	void *h,
	unsigned char *in,
	int inlen,
	unsigned char *out,
	int *outlen);

// ˽Կ����
typedef int (*KS_FUNC_PRIV_DEC)(
	void *h,
	unsigned char *in,
	int inlen,
	unsigned char *out,
	int *outlen);

// ��֤����֤ǩ��
typedef int (*KS_FUNC_CERT_VRF_SIGN)(
	void *h,
	bool bIsDigest,
	unsigned char *data,				// ԭ�Ļ�ժҪ����ΪժҪ������RSA�㷨��ժҪΪԭ��ժҪ�Ľ��������SM2�㷨��ժҪΪԭ��ǩ��Ԥ����Ľ����
	int datalen,
	unsigned char *sign,
	int signlen,
	unsigned char *cert,
	int certlen);

// ��֤�����
typedef int (*KS_FUNC_CERT_ENC)(
	void *h,
	unsigned char *in,
	int inlen,
	unsigned char *cert,
	int certlen,
	unsigned char *out,
	int *outlen);

// �ԳƼ���
typedef int (*KS_FUNC_SYMM_ENC)(
	void *h,							// �豸���
	int algid,							// �Գ��㷨��ʶ
	bool padding,						// �Ƿ����
	unsigned char *key,					// ��Կ
	int keylen,							// ��Կ�ĳ���
	bool keyEncrypted,					// ��Կ�Ƿ�Ϊ����
	unsigned char *iv,					// ��ʼ����
	int ivlen,							// ��ʼ�����ĳ���
	unsigned char *in,					// ��������
	int inlen,							// �������ݵĳ���
	unsigned char *out,					// �������
	int *outlen);						// ������ݵĳ���

// �Գƽ���
typedef int (*KS_FUNC_SYMM_DEC)(
	void *h,							// �豸���
	int algid,							// �Գ��㷨��ʶ
	bool padding,						// �Ƿ�ȥ���
	unsigned char *key,					// ��Կ
	int keylen,							// ��Կ�ĳ���
	bool keyEncrypted,					// ��Կ�Ƿ�Ϊ����
	unsigned char *iv,					// ��ʼ����
	int ivlen,							// ��ʼ�����ĳ���
	unsigned char *in,					// ��������
	int inlen,							// �������ݵĳ���
	unsigned char *out,					// �������
	int *outlen);						// ������ݵĳ���

// ժҪ
typedef int (*KS_FUNC_DIGEST)(
	void *h,							// �豸���
	int algid,							// ժҪ�㷨��ʶ
	unsigned char *in,					// ��������
	int inlen,							// �������ݵĳ���
	unsigned char *cert,				// ֤�飨��֤��ΪNULL�������ժҪ���㣻��֤��ΪSM2֤�飬��ժҪ�㷨ΪSM3�������SM2ǩ��Ԥ�������㣩
	int certlen,						// ֤��ĳ���
	unsigned char *out,					// �������
	int *outlen);						// ������ݵĳ���

// �ļ�ժҪ
typedef int (*KS_FUNC_DIGEST_FILE)(
	void *h,							// �豸���
	int algid,							// ժҪ�㷨��ʶ
	char *infile,						// �����ļ�
	unsigned char *cert,				// ֤�飨��֤��ΪNULL�������ժҪ���㣻��֤��ΪSM2֤�飬��ժҪ�㷨ΪSM3�������SM2ǩ��Ԥ�������㣩
	int certlen,						// ֤��ĳ���
	unsigned char *out,					// �������
	int *outlen);						// ������ݵĳ���

////////////////////////////////////////////////////////////////
// ��ʼ��
int KSSIGN_Initialize();
int KSSIGN_Finalize();

////////////////////////////////////////////////////////////////
// PKCS7ǩ��
// nDigestAlgIDȡֵ���£�
//   SGD_SHA1
//   SGD_SHA256
//   SGD_SM3
int KSSIGN_SignDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_PRIV_ENC funcPrivEnc,		// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	bool bAttached,						// �Ƿ����ԭ��
	bool bCert,							// ǩ���Ƿ����֤��
	bool bHasAttr,						// �Ƿ����ǩ�����ԣ�authenticated attributes��
	bool bIsDigest,						// ���������Ƿ�ΪժҪ������SM2�㷨�����ǩ��������ǩ�����ԣ�ժҪΪԭ��ǩ��Ԥ����Ľ��������Ϊԭ��SM3ժҪ�Ľ����
	int nDigestAlgID,					// ժҪ�㷨
	bool bWithVerificationCode,			// �Ƿ��У����
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbCert,				// ǩ��֤��
	int nCertLen,						// ǩ��֤��ĳ���
	unsigned char *pbKey,				// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	int nKeyLen,						// ǩ��˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	unsigned char *pbTS,				// ʱ�������
	int nTSLen,							// ʱ������ݵĳ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// PKCS7��֤ǩ��
int KSSIGN_VerifySignedDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_CERT_VRF_SIGN funcCVS,		// ��֤ǩ����������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	unsigned char *pbP7Sign,			// PKCS7ǩ��
	int nP7SignLen,						// PKCS7ǩ���ĳ���
	unsigned char *pbCert,				// ǩ��֤��
	int nCertLen,						// ǩ��֤��ĳ���
	unsigned char *pbData = NULL,		// ԭ��
	int nDataLen = 0,					// ԭ�ĵĳ���
	bool bIsDigest = false);			// ԭ���Ƿ�ΪժҪ������SM2�㷨�����ǩ��������ǩ�����ԣ�ժҪΪԭ��ǩ��Ԥ����Ľ��������Ϊԭ��SM3ժҪ�Ľ����

// ��ȡPKCS7ǩ����Ϣ
int KSSIGN_GetP7SignDataInfo(
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	int nType,							// ���ͣ�1��ԭ�ģ�2��ǩ��֤�飬3��ǩ��ֵ��4��ǩ���㷨��5��ԭ��ժҪ��6��ժҪ�㷨��7��ǩ�����ݰ汾��8��ǩ��ʱ�䣬9��ʱ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

////////////////////////////////////////////////////////////////
// PKCS7�����ŷ�
// nSymmAlgIDȡֵ���£�
//   SGD_SM1_ECB
//   SGD_SM1_CBC
//   SGD_SSF33_ECB
//   SGD_SSF33_CBC
//   SGD_SM4_ECB
//   SGD_SM4_CBC
//   ����			3DES
int KSSIGN_EnvelopeDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_CERT_ENC funcCertEnc,		// ֤����ܺ�������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_SYMM_ENC funcEnc,			// �ԳƼ��ܺ�������ʹ�����㷨��ӦΪNULL��
	bool bWithVerificationCode,			// �Ƿ��У����
	int nSymmAlgID,						// �Գ��㷨
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	char *pszEncCerts[],				// ����֤�飨base64���룩
	int nEncCertsCount,					// ����֤��ĸ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// PKCS7���������ŷ�
int KSSIGN_UnenvelopeDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_PRIV_DEC funcPrivDec,		// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	KS_FUNC_SYMM_DEC funcDec,			// �Գƽ��ܺ�������ʹ�����㷨��ӦΪNULL��
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbCert,				// ����֤��
	int nCertLen,						// ����֤��ĳ���
	unsigned char *pbKey,				// ����˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	int nKeyLen,						// ����˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// ��ȡPKCS7�����ŷ���Ϣ
int KSSIGN_GetP7EnvelopeDataInfo(
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	int nType,							// ���ͣ�1��������֤��İ䷢��DN�����кţ�DN1;���к�1|DN2;���к�2...����2���ǶԳ��㷨��3���ǶԳ����ģ�4���Գ��㷨��5���Գ�����
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

////////////////////////////////////////////////////////////////
// PKCS7ǩ���������ŷ�
// nDigestAlgIDȡֵ���£�
//   SGD_SHA1
//   SGD_SHA256
//   SGD_SM3
// nSymmAlgIDȡֵ���£�
//   SGD_SM1_ECB
//   SGD_SM1_CBC
//   SGD_SSF33_ECB
//   SGD_SSF33_CBC
//   SGD_SM4_ECB
//   SGD_SM4_CBC
//   ����			3DES
int KSSIGN_SignAndEnvelopeDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_PRIV_ENC funcPrivEnc,		// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_CERT_ENC funcCertEnc,		// ֤����ܺ�������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_SYMM_ENC funcEnc,			// �ԳƼ��ܺ�������ʹ�����㷨��ӦΪNULL��
	bool bWithVerificationCode,			// �Ƿ��У����
	int nDigestAlgID,					// ժҪ�㷨
	int nSymmAlgID,						// �Գ��㷨
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbSignCert,			// ǩ��֤��
	int nSignCertLen,					// ǩ��֤��ĳ���
	unsigned char *pbSignKey,			// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	int nSignKeyLen,					// ǩ��˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	char *pszEncCerts[],				// ����֤�飨base64���룩
	int nEncCertsCount,					// ����֤��ĸ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// PKCS7���������ŷ⼰��֤ǩ��
int KSSIGN_UnenvelopeAndVerifyDataByP7(
	void *hDevice,						// �豸���
	KS_FUNC_PRIV_DEC funcPrivDec,		// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	KS_FUNC_SYMM_DEC funcDec,			// �Գƽ��ܺ�������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_CERT_VRF_SIGN funcCVS,		// ��֤ǩ����������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbEncCert,			// ����֤��
	int nEncCertLen,					// ����֤��ĳ���
	unsigned char *pbEncKey,			// ����˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	int nEncKeyLen,						// ����˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// ��ȡPKCS7ǩ���������ŷ���Ϣ
int KSSIGN_GetP7SignAndEnvelopeDataInfo(
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	int nType,							// ���ͣ�1��������֤��İ䷢��DN�����кţ�DN1;���к�1|DN2;���к�2...����2��ǩ��֤�飬3��ǩ��ֵ��4��ǩ���㷨��5��ԭ��ժҪ��6��ժҪ�㷨��7���汾��8��ǩ��ʱ��
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

////////////////////////////////////////////////////////////////
// ʱ�������
int KSSIGN_CreateTimeStampReq(
	void *hDevice,						// �豸���
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	int nDigestAlgID,					// ժҪ�㷨
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// ʱ���
int KSSIGN_CreateTimeStamp(
	void *hDevice,						// �豸���
	KS_FUNC_PRIV_ENC funcPrivEnc,		// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	int nDigestAlgID,					// ժҪ�㷨
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	unsigned char *pbCert,				// ʱ���֤��
	int nCertLen,						// ʱ���֤��ĳ���
	unsigned char *pbKey,				// ʱ���˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	int nKeyLen,						// ʱ���˽Կ�ĳ��ȣ���ʹ��Ӳ���豸��ӦΪ0��
	char *pszSN,						// ʱ������к�
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

// ��֤ʱ���
int KSSIGN_VerifyTimeStamp(
	void *hDevice,						// �豸���
	KS_FUNC_CERT_VRF_SIGN funcCVS,		// ��֤ǩ����������ʹ�����㷨��ӦΪNULL��
	KS_FUNC_DIGEST funcDigest,			// ժҪ��������ʹ�����㷨��ӦΪNULL��
	unsigned char *pbTS,				// ʱ�������
	int nTSLen,							// ʱ������ݵĳ���
	unsigned char *pbCert,				// ʱ���֤��
	int nCertLen,						// ʱ���֤��ĳ���
	unsigned char *pbData = NULL,		// ԭ��
	int nDataLen = 0,					// ԭ�ĵĳ���
	bool bIsDigest = false);			// ԭ���Ƿ�ΪժҪ

// ��ȡRSAʱ�����Ϣ
int KSSIGN_GetTimeStampInfo(
	unsigned char *pbIn,				// ��������
	int nInLen,							// �������ݵĳ���
	int nType,							// ���ͣ�1��ԭ�ģ�2��ʱ���֤�飬3��ǩ��ֵ��4��ǩ���㷨��5��ԭ��ժҪ��6��ժҪ�㷨��7���汾��8��ʱ���ʱ��
	unsigned char *pbOut,				// �������
	int *pnOutLen);						// ������ݵĳ���

#endif
