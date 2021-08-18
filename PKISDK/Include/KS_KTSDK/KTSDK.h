#ifndef _KTSDK__H
#define _KTSDK__H

#define KTDEVTYPE_SD_HT		101	// ��̩SD��
#define KTDEVTYPE_SD_FT		102	// ����SD��

#define KTDEVTYPE_SD_HS		201	// ����SD��
#define KTDEVTYPE_SD_SS		202	// ����SD��
#define KTDEVTYPE_SD_YDX	203	// Ӯ����SD��
#define KTDEVTYPE_SD_YW		204	// ����SD��
#define KTDEVTYPE_NFC_HS	205	// ����NFC��
#define KTDEVTYPE_BT_GM		206	// ��������SIM��

#define KTDEVTYPE_CC		301	// BJCA��֤��

#define KTDEVTYPE_PFX		401	// ��֤�飨�����ã�

#define KTSGD_SM3				0x00000001	//SM3�Ӵ��㷨
#define KTSGD_SHA1				0x00000002	//SHA1�Ӵ��㷨
#define KTSGD_SHA256			0x00000004	//SHA256�Ӵ��㷨

#define KTSGD_SM1_ECB			0x00000101	//SM1�㷨ECB����ģʽ
#define KTSGD_SM1_CBC			0x00000102	//SM1�㷨CBC����ģʽ
#define KTSGD_SM1_CFB			0x00000104	//SM1�㷨CFB����ģʽ
#define KTSGD_SM1_OFB			0x00000108	//SM1�㷨OFB����ģʽ
#define KTSGD_SM1_MAC			0x00000110	//SM1�㷨MAC����
#define KTSGD_SSF33_ECB			0x00000201	//SSF33�㷨ECB����ģʽ
#define KTSGD_SSF33_CBC			0x00000202	//SSF33�㷨CBC����ģʽ
#define KTSGD_SSF33_CFB			0x00000204	//SSF33�㷨CFB����ģʽ
#define KTSGD_SSF33_OFB			0x00000208	//SSF33�㷨OFB����ģʽ
#define KTSGD_SSF33_MAC			0x00000210	//SSF33�㷨MAC����

/************************************************************************/
/*	��������												    		*/
/************************************************************************/
// ��ʼ��
int KTSDK_SetLogFilePath(char *pszLogFilePath);
int KTSDK_Initialize();
int KTSDK_Finalize();
const char *KTSDK_GetErrorString(int nErrorCode);

// д��־
void KTSDK_WriteToLog(const char *format, ...);

// ����
// ʱ�����������ַ���˿ڣ��磺192.168.5.177:80
// ����ʹ��ʱ�����������Ϊ��
int KTSDK_SetTSSURL(char *pszURL);
int KTSDK_GetTSSURL(char *pszURL);
// ֤����
// ��Ҫ��֤ʱ�������������֤����
int KTSDK_ClearCACerts();
int KTSDK_GetCACertsCount(int *pnCount);
int KTSDK_GetCACert(int nIndex, unsigned char *pbCert, int *pnCertLen);
int KTSDK_DeleteCACert(int nIndex);
int KTSDK_AddCACert(unsigned char *pbCert, int nCertLen);

/************************************************************************/
/*	֤�����												    		*/
/************************************************************************/
int KTSDK_ParseCert(unsigned char *pbCert, int nCertLen);
int KTSDK_IsSM2Cert(bool *pbSM2);
int KTSDK_GetCertSN(char *pszCertSN);
int KTSDK_GetCertIssuerDN(char *pszIssuerDN);
int KTSDK_GetCertDN(char *pszDN);
int KTSDK_GetCertCN(char *pszCertCN);
int KTSDK_GetCertNotBeforeTm(struct tm& tmNotBefore);
int KTSDK_GetCertNotAfterTm(struct tm& tmNotAfter);
int KTSDK_gmtTimeToLocalTmStr(struct tm& tmTime, char *pszTime);	// 2012��08��15��09ʱ35��54��
int KTSDK_gmtTimeToLocalTmStr2(struct tm& tmTime, char *pszTime);	// 2012-08-15 09:35:54
int KTSDK_GetCertKeyUsage(unsigned int *punKeyUsage);
int KTSDK_GetCertInfoByOid(char *pszOid, char *pszValue);

/************************************************************************/
/*	�����㷨 												    		*/
/************************************************************************/
int KTSDK_Base64Encode(char *pszIn, int nInLen, char *pszOut, int *pnOutLen, bool bEncode = true);
int KTSDK_HashData(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, int nAlgID = KTSGD_SHA1);
int KTSDK_SM2YCL(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
int KTSDK_VerifySignedData(unsigned char *pbData, int nDataLen, unsigned char *pbSign, int nSignLen, unsigned char *pbCert, int nCertLen);
int KTSDK_EncryptWithCert(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);

/************************************************************************/
/*	�豸����												    		*/
/************************************************************************/
// ��ʼ��
int KTSDK_Device_Initialize(char *pszLibDir, char *pszAndroidPackageName = NULL);
int KTSDK_Device_Finalize();

// ��ʽ��
int KTSDK_Device_InitDevice(char *pszAdminPin, char *pszUserPin);
int KTSDK_Device_InitDevice_FT(char *pszAdminPin, char *pszUserPin);

// �豸����
int KTSDK_Device_SetPFXDir(char *pszPFXDir);						// PFX
int KTSDK_Device_SetProviderPath(char *pszProviderPath, void *env);	// NFC_HS
int KTSDK_Device_SetEnv(void *env, void *obj, char *pszClassName);	// CC
int KTSDK_Device_Open();
int KTSDK_Device_Open(int nDevType);
int KTSDK_Device_Close();
int KTSDK_Device_GetKeyType();
int KTSDK_Device_GetDevType();
int KTSDK_Device_GetDevSN(char *pszDevSN);
int KTSDK_Device_GenRandom(unsigned char *pbRandom, int nRandomLen);

// ���ʿ���
int KTSDK_Device_Login(char *pszPin, bool bUser = true);
int KTSDK_Device_Logout();
int KTSDK_Device_IsLogin(bool *pbLogin, bool bUser = true);
int KTSDK_Device_SetPin(char *pszPin, char *pszNewPin, bool bUser = true);
int KTSDK_Device_UnlockUserPin(char *pszAdminPin, char *pszUserPin);
int KTSDK_Device_GetRemainRetryCount(int *pnCount, bool bUser = true);

// ֤�����
int KTSDK_Device_RSAGetCertNo(int *pnCertNo);
int KTSDK_Device_SM2GetCertNo(int *pnCertNo);
int KTSDK_Device_GetCertNo(int *pnCertNo);
int KTSDK_Device_SetCurrentCert(int nCertNo);
int KTSDK_Device_RSAReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDK_Device_SM2ReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDK_Device_ReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDK_Device_RSAWriteCert(unsigned char *pbCert, int nCertLen);
int KTSDK_Device_SM2WriteCert(unsigned char *pbCert, int nCertLen);
int KTSDK_Device_WriteCert(unsigned char *pbCert, int nCertLen);

// ��Կ����
int KTSDK_Device_RSAGetPubKey(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_SM2GetPubKey(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_RSAGetPubKey_Tmp(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_SM2GetPubKey_Tmp(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_RSAGenKeyPair(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_SM2GenKeyPair(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDK_Device_RSAImportKeyPair(int nAlgID, unsigned char *pbWrappedKey, int nWrappedKeyLen, unsigned char *pbEncryptedData, int nEncryptedDataLen);
int KTSDK_Device_SM2ImportKeyPair(unsigned char *pbEnvelopedKeyBlob, int nEnvelopedKeyBlobLen);

// �ǶԳ��㷨
// ����Ϊԭ��
int KTSDK_Device_RSASign(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_SM2Sign(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
int KTSDK_Device_RSASignData(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_SM2SignData(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
// ����ΪժҪ
int KTSDK_Device_RSASignHash(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_SM2SignHash(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);

// ��ǰ��������
int KTSDK_Device_RSADecrypt(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_SM2Decrypt(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
// ����������
int KTSDK_Device_RSADecryptEx(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_SM2DecryptEx(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);

// �Գ��㷨
int KTSDK_Device_SetSymmKey(int nAlgID, unsigned char *pbKey, int nKeyLen, void **phKey);
int KTSDK_Device_EncryptInit(void *hKey, int nAlgID, unsigned char *pbIV, int nIVLen, int nPaddingType, int nFeedBitLen);
int KTSDK_Device_EncryptUpdate(void *hKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_EncryptFinal(void *hKey, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_DecryptInit(void *hKey, int nAlgID, unsigned char *pbIV, int nIVLen, int nPaddingType, int nFeedBitLen);
int KTSDK_Device_DecryptUpdate(void *hKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_DecryptFinal(void *hKey, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_CloseHandle(void *hKey);

// �ļ�����
int KTSDK_Device_EnumFiles(char *pszOut, int *pnOutLen);
int KTSDK_Device_CreateFile(char *pszFileName, int nFileSize, int nReadRights, int nWriteRights);
int KTSDK_Device_DeleteFile(char *pszFileName);
int KTSDK_Device_GetFileInfo(char *pszFileName, int *pnFileSize, int *pnReadRights, int *pnWriteRights);
int KTSDK_Device_ReadFile(char *pszFileName, int nOffset, int nSize, unsigned char *pbOut, int *pnOutLen);
int KTSDK_Device_WriteFile(char *pszFileName, int nOffset, unsigned char *pbIn, int nInLen);

// ֤������
int KTSDK_Device_RSACreateCertReq(bool bUpdateKeyPair, char *pszDN, unsigned char *pbCertReq, int *pnCertReqLen);
int KTSDK_Device_SM2CreateCertReq(bool bUpdateKeyPair, char *pszDN, unsigned char *pbCertReq, int *pnCertReqLen);
// ����ӽ�����Կ��
int KTSDK_Device_RSAImportEncKeyPair(unsigned char *pbEncCert, int nEncCertLen, unsigned char *pbEncPrvKey, int nEncPrvKeyLen);
int KTSDK_Device_SM2ImportEncKeyPair(unsigned char *pbEncCert, int nEncCertLen, unsigned char *pbEncPrvKey, int nEncPrvKeyLen);
// ����֤
int KTSDK_RSACreateSoftCert(char *pszPin, char *pszDN, char *pszIDNumber);
int KTSDK_SM2CreateSoftCert(char *pszPin, char *pszDN, char *pszIDNumber);

#endif
