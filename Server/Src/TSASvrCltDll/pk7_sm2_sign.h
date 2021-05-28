#ifndef _PK7_SM2_SIGN_H
#define _PK7_SM2_SIGN_H

#include "MySignLibFunc.h"

// PKCS7ǩ��
long MYSIGN_SignDataByP7_SM2(
	unsigned char *pbIn,				// ��������
	long lInLen,						// �������ݵĳ���
	char *pszCert,						// ǩ��֤��
	char *pszKey,						// ǩ��˽Կ����ʹ��Ӳ���豸��ӦΪNULL��
	FUNC_PRIV_ENC funcPrivEnc,			// ˽Կ���ܺ�������ʹ����˽Կ��ӦΪNULL��
	char *pszOut,						// �������
	bool bAttached = true);				// �Ƿ����ԭ��

// PKCS7��֤ǩ��
long MYSIGN_VerifySignedDataByP7_SM2(
	char *pszSign,
	unsigned char *pbData = NULL,
	long lDataLen = 0);

// PKCS7��֤ǩ��
long MYSIGN_VerifySignedDataByP7_SM2_Ex(
	char *pszSign,
	unsigned char *pbData = NULL,
	long lDataLen = 0,
	unsigned char *pbCACert = 0,
	long lCACertLen = 0);

// ��ȡPKCS7ǩ����Ϣ
long MYSIGN_GetP7SignDataInfo_SM2(
	char *pszIn,
	long lType,
	unsigned char *pbOut,
	long *plOutLen);


#endif

