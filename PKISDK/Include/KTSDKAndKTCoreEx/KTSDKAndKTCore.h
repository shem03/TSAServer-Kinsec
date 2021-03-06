#ifndef _KTSDKANDKTCORE_H
#define _KTSDKANDKTCORE_H

#include "KTSDKAndKTCoreDef.h"

typedef void *				HANDLE;

#define KTDEVTYPE_FT		5	// 飞天
#define KTDEVTYPE_HT		6	// 海泰
#define KTDEVTYPE_AXTX		10	// 安信天行
#define KTDEVTYPE_WDC		15	// 文鼎创
#define KTDEVTYPE_FT_US		20	// 飞天u盘key
#define KTDEVTYPE_FT_GM		22	// 飞天gm key

#define KTDEVTYPE_SD_HT		101	// 海泰SD卡
#define KTDEVTYPE_SD_FT		102	// 飞天SD卡

#define KTDEVTYPE_SD_HS		201	// 华申SD卡
#define KTDEVTYPE_SD_SS		202	// 三所SD卡
#define KTDEVTYPE_SD_YDX	203	// 赢达信SD卡
#define KTDEVTYPE_SD_YW		204	// 渔翁SD卡
#define KTDEVTYPE_NFC_HS	205	// 华申NFC卡
#define KTDEVTYPE_BT_GM		206	// 国民蓝牙SIM卡
#define KTDEVTYPE_BT_HT		207 // 海泰蓝牙卡

#define KTDEVTYPE_CC		301	// BJCA云证书

#define KTDEVTYPE_PFX		401	// 软证书（测试用）

#define KTDEVTYPE_MK		501	// 北京创原手机盾

#define KTSGD_SM3				0x00000001	//SM3杂凑算法
#define KTSGD_SHA1				0x00000002	//SHA1杂凑算法
#define KTSGD_SHA256			0x00000004	//SHA256杂凑算法

#define KTSGD_SM1_ECB			0x00000101	//SM1算法ECB加密模式
#define KTSGD_SM1_CBC			0x00000102	//SM1算法CBC加密模式
#define KTSGD_SM1_CFB			0x00000104	//SM1算法CFB加密模式
#define KTSGD_SM1_OFB			0x00000108	//SM1算法OFB加密模式
#define KTSGD_SM1_MAC			0x00000110	//SM1算法MAC运算
#define KTSGD_SSF33_ECB			0x00000201	//SSF33算法ECB加密模式
#define KTSGD_SSF33_CBC			0x00000202	//SSF33算法CBC加密模式
#define KTSGD_SSF33_CFB			0x00000204	//SSF33算法CFB加密模式
#define KTSGD_SSF33_OFB			0x00000208	//SSF33算法OFB加密模式
#define KTSGD_SSF33_MAC			0x00000210	//SSF33算法MAC运算
#define KTSGD_SM4_ECB			0x00000401	// SM4算法ECB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define KTSGD_SM4_CBC			0x00000402	// SM4算法CBC加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define KTSGD_SM4_CFB			0x00000404	// SM4算法CFB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define KTSGD_SM4_OFB			0x00000408	// SM4算法OFB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define KTSGD_SM4_MAC			0x00000410	// SM4算法MAC加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加

/************************************************************************/
/*	辅助函数												    		*/
/************************************************************************/
// 初始化
int KTSDKANDKTCORE_SetLogFilePath(char *pszLogFilePath);
int KTSDKANDKTCORE_Initialize();
int KTSDKANDKTCORE_Finalize();
const char *KTSDKANDKTCORE_GetErrorString(int nErrorCode);

// 写日志
void KTSDKANDKTCORE_WriteToLog(const char *format, ...);

// 设置
// 设置时间戳服务提供者编号
// 1－bjca
// 2－得安
// 3－fjca先安
// 其它－kinsec
int KTSDKANDKTCORE_SetTSSProvider(int nTSSProvider);
int KTSDKANDKTCORE_GetTSSProvider();

// 时间戳服务器地址及端口，如：192.168.5.177:80
// 若不使用时间戳，设置其为空
int KTSDKANDKTCORE_SetTSSURL(char *pszURL);
int KTSDKANDKTCORE_GetTSSURL(char *pszURL);

// bjca时间戳服务器应用名
// 若为得安时间戳，该值为时间戳服务器证书DN
int KTSDKANDKTCORE_SetTSSApplicationName(char *pszApplicationName);
int KTSDKANDKTCORE_GetTSSApplicationName(char *pszApplicationName);

// 时间戳服务器证书颁发者
// 缺省为：福建省运营CA&&福建省运营根CA||FJCA&&ROOTCA||福建省政务CA||FJCASM2&&ROOTCA||Beijing SM2 CA&&ROOTCA||CEGN SM2 Class 2 CA&&Civil Servant ROOT
int KTSDKANDKTCORE_SetTSSCertIssuer(char *pszCertIssuer);
int KTSDKANDKTCORE_GetTSSCertIssuer(char *pszCertIssuer);

// 时间戳服务器证书关键字
int KTSDKANDKTCORE_SetTSSCertKeyWord(char *pszCertKeyWord);
int KTSDKANDKTCORE_GetTSSCertKeyWord(char *pszCertKeyWord);

// 证书链
// 若要验证时间戳，必须设置证书链
int KTSDKANDKTCORE_ClearCACerts();
int KTSDKANDKTCORE_GetCACertsCount(int *pnCount);
int KTSDKANDKTCORE_GetCACert(int nIndex, unsigned char *pbCert, int *pnCertLen);
int KTSDKANDKTCORE_DeleteCACert(int nIndex);
int KTSDKANDKTCORE_AddCACert(unsigned char *pbCert, int nCertLen);

int KTSDKANDKTCORE_SetCACertsDir(char *pszDir);

bool KTSDKANDKTCORE_IsBase64(unsigned char *in, int inlen);
bool KTSDKANDKTCORE_toder(unsigned char *in, int inlen, unsigned char *out, int *outlen);

/************************************************************************/
/*	证书解析												    		*/
/************************************************************************/
int KTSDKANDKTCORE_ParseCert(unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_IsSM2Cert(bool *pbSM2);
int KTSDKANDKTCORE_GetCertSN(char *pszCertSN);
int KTSDKANDKTCORE_GetCertIssuerDN(char *pszIssuerDN);
int KTSDKANDKTCORE_GetCertDN(char *pszDN);
int KTSDKANDKTCORE_GetCertCN(char *pszCertCN);
int KTSDKANDKTCORE_GetCertG(char *pszCertG);
int KTSDKANDKTCORE_GetCertNotBeforeTm(struct tm& tmNotBefore);
int KTSDKANDKTCORE_GetCertNotAfterTm(struct tm& tmNotAfter);
int KTSDKANDKTCORE_gmtTimeToLocalTmStr(struct tm& tmTime, char *pszTime);	// 2012年08月15日09时35分54秒
int KTSDKANDKTCORE_gmtTimeToLocalTmStr2(struct tm& tmTime, char *pszTime);	// 2012-08-15 09:35:54
int KTSDKANDKTCORE_LocalTmStrTogmtTime2(char *pszTime, struct tm& tmTime);
int KTSDKANDKTCORE_GetCertKeyUsage(unsigned int *punKeyUsage);
int KTSDKANDKTCORE_GetCertInfoByOid(char *pszOid, char *pszValue);

int KTSDKANDKTCORE_IsSM2Cert(unsigned char *pbCert, int nCertLen, bool *pbSM2);
int KTSDKANDKTCORE_GetCertSN(unsigned char *pbCert, int nCertLen, char *pszCertSN);
int KTSDKANDKTCORE_GetCertIssuerDN(unsigned char *pbCert, int nCertLen, char *pszIssuerDN);
int KTSDKANDKTCORE_GetCertDN(unsigned char *pbCert, int nCertLen, char *pszDN);
int KTSDKANDKTCORE_GetCertCN(unsigned char *pbCert, int nCertLen, char *pszCertCN);
int KTSDKANDKTCORE_GetCertG(unsigned char *pbCert, int nCertLen, char *pszCertCN);
int KTSDKANDKTCORE_GetCertNotBeforeTm(unsigned char *pbCert, int nCertLen, struct tm& tmNotBefore);
int KTSDKANDKTCORE_GetCertNotAfterTm(unsigned char *pbCert, int nCertLen, struct tm& tmNotAfter);
int KTSDKANDKTCORE_GetCertKeyUsage(unsigned char *pbCert, int nCertLen, unsigned int *punKeyUsage);
int KTSDKANDKTCORE_GetCertInfoByOid(unsigned char *pbCert, int nCertLen, char *pszOid, char *pszValue);

/************************************************************************/
/*	密码算法 												    		*/
/************************************************************************/
int KTSDKANDKTCORE_Base64Encode(char *pszIn, int nInLen, char *pszOut, int *pnOutLen, bool bEncode = true);

int KTSDKANDKTCORE_HashData(int nAlgID, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_HashFile(int nAlgID, char *pszFileIn, unsigned char *pbOut, int *pnOutLen);

int KTSDKANDKTCORE_SM2YCL(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_VerifySignedData(unsigned char *pbData, int nDataLen, unsigned char *pbSign, int nSignLen, unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_EncryptWithCert(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);

/************************************************************************/
/*	设备操作												    		*/
/************************************************************************/
// 初始化
int KTSDKANDKTCORE_Device_Initialize(char *pszLibDir, char *pszAndroidPackageName = NULL);
int KTSDKANDKTCORE_Device_Finalize();

// 格式化
int KTSDKANDKTCORE_Device_InitDevice(char *pszAdminPin, char *pszUserPin);
int KTSDKANDKTCORE_Device_InitDevice_FT(char *pszAdminPin, char *pszUserPin);

// 设备管理
typedef int (*KS_FUNC_CS_GetCert)(unsigned char *pbCert, int *pnCertLen);
typedef int (*KS_FUNC_CS_SM2Sign)(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SetFJCACloudSign(KS_FUNC_CS_GetCert funcCSGetCert, KS_FUNC_CS_SM2Sign funcCSSM2Sign);		// fjca cloud sign

int KTSDKANDKTCORE_Device_SetPFXDir(char *pszPFXDir);						// PFX
int KTSDKANDKTCORE_Device_SetProviderPath(char *pszProviderPath, void *env);	// NFC_HS
int KTSDKANDKTCORE_Device_SetHTBTEnv(char *pszMacAddress);					// BT_HT
int KTSDKANDKTCORE_Device_SetEnv(void *env, void *obj, char *pszClassName);	// CC
int KTSDKANDKTCORE_Device_SetMKEnv(char *pszPackagePath, char *pszPackageName, char *pszImei, char *pszApplicationNo, char *pszBusiUserName);// MK
int KTSDKANDKTCORE_Device_SetSMFEnv(HANDLE hProvider, HANDLE hApplication, char *pszContainerName);
int KTSDKANDKTCORE_Device_Open();
int KTSDKANDKTCORE_Device_Open(int nDevType);
int KTSDKANDKTCORE_Device_Close();
int KTSDKANDKTCORE_Device_GetKeyType();
int KTSDKANDKTCORE_Device_GetDevType();
int KTSDKANDKTCORE_Device_GetDevSN(char *pszDevSN);
int KTSDKANDKTCORE_Device_GenRandom(unsigned char *pbRandom, int nRandomLen);

// 访问控制
int KTSDKANDKTCORE_Device_Login(char *pszPin, bool bUser = true);
int KTSDKANDKTCORE_Device_Logout();
int KTSDKANDKTCORE_Device_IsLogin(bool *pbLogin, bool bUser = true);
int KTSDKANDKTCORE_Device_SetPin(char *pszPin, char *pszNewPin, bool bUser = true);
int KTSDKANDKTCORE_Device_UnlockUserPin(char *pszAdminPin, char *pszUserPin);
int KTSDKANDKTCORE_Device_GetRemainRetryCount(int *pnCount, bool bUser = true);

// 证书管理
int KTSDKANDKTCORE_Device_RSAGetCertNo(int *pnCertNo);
int KTSDKANDKTCORE_Device_SM2GetCertNo(int *pnCertNo);
int KTSDKANDKTCORE_Device_GetCertNo(int *pnCertNo);
int KTSDKANDKTCORE_Device_SetCurrentCert(int nCertNo);
int KTSDKANDKTCORE_Device_RSAReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDKANDKTCORE_Device_SM2ReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDKANDKTCORE_Device_ReadCert(unsigned char *pbCert, int *pnCertLen);
int KTSDKANDKTCORE_Device_RSAWriteCert(unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_Device_SM2WriteCert(unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_Device_WriteCert(unsigned char *pbCert, int nCertLen);

int KTSDKANDKTCORE_Device_MC_SM2WriteCert(unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_Device_MC_SM2DeleteCert();

// 密钥管理
int KTSDKANDKTCORE_Device_RSAGetPubKey(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_SM2GetPubKey(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_RSAGetPubKey_Tmp(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_SM2GetPubKey_Tmp(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_RSAGenKeyPair(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_SM2GenKeyPair(unsigned char *pbPubKey, int *pnPubKeyLen);
int KTSDKANDKTCORE_Device_RSAImportKeyPair(int nAlgID, unsigned char *pbWrappedKey, int nWrappedKeyLen, unsigned char *pbEncryptedData, int nEncryptedDataLen);
int KTSDKANDKTCORE_Device_SM2ImportKeyPair(unsigned char *pbEnvelopedKeyBlob, int nEnvelopedKeyBlobLen);

// 非对称算法
// 输入为原文
int KTSDKANDKTCORE_Device_RSASign(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SM2Sign(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
int KTSDKANDKTCORE_Device_RSASignData(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SM2SignData(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);
// 输入为摘要
int KTSDKANDKTCORE_Device_RSASignHash(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SM2SignHash(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen, unsigned char *pbCert, int nCertLen);

// 当前容器解密
int KTSDKANDKTCORE_Device_RSADecrypt(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SM2Decrypt(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
// 多容器解密
int KTSDKANDKTCORE_Device_RSADecryptEx(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_SM2DecryptEx(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);

// 对称算法
int KTSDKANDKTCORE_Device_ImportSessionKey(int nAlgID, unsigned char *pbWrapedData, int nWrapedDataLen, void **phKey);
int KTSDKANDKTCORE_Device_SetSymmKey(int nAlgID, unsigned char *pbKey, int nKeyLen, void **phKey);
int KTSDKANDKTCORE_Device_EncryptInit(void *hKey, int nAlgID, unsigned char *pbIV, int nIVLen, int nPaddingType, int nFeedBitLen);
int KTSDKANDKTCORE_Device_EncryptUpdate(void *hKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_EncryptFinal(void *hKey, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_DecryptInit(void *hKey, int nAlgID, unsigned char *pbIV, int nIVLen, int nPaddingType, int nFeedBitLen);
int KTSDKANDKTCORE_Device_DecryptUpdate(void *hKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_DecryptFinal(void *hKey, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_CloseHandle(void *hKey);

// 文件管理
int KTSDKANDKTCORE_Device_EnumFiles(char *pszOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_CreateFile(char *pszFileName, int nFileSize, int nReadRights, int nWriteRights);
int KTSDKANDKTCORE_Device_DeleteFile(char *pszFileName);
int KTSDKANDKTCORE_Device_GetFileInfo(char *pszFileName, int *pnFileSize, int *pnReadRights, int *pnWriteRights);
int KTSDKANDKTCORE_Device_ReadFile(char *pszFileName, int nOffset, int nSize, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_Device_WriteFile(char *pszFileName, int nOffset, unsigned char *pbIn, int nInLen);

// 证书请求
int KTSDKANDKTCORE_Device_RSACreateCertReq(bool bCreateNewContainer, bool bUpdateKeyPair, char *pszDN, unsigned char *pbCertReq, int *pnCertReqLen);
int KTSDKANDKTCORE_Device_SM2CreateCertReq(bool bCreateNewContainer, bool bUpdateKeyPair, char *pszDN, unsigned char *pbCertReq, int *pnCertReqLen);
// 导入加解密密钥对
int KTSDKANDKTCORE_Device_RSAImportEncKeyPair(unsigned char *pbEncCert, int nEncCertLen, unsigned char *pbEncPrvKey, int nEncPrvKeyLen);
int KTSDKANDKTCORE_Device_SM2ImportEncKeyPair(unsigned char *pbEncCert, int nEncCertLen, unsigned char *pbEncPrvKey, int nEncPrvKeyLen);
// 发软证
int KTSDKANDKTCORE_RSACreateSoftCert(char *pszPin, char *pszDN, char *pszIDNumber);
int KTSDKANDKTCORE_SM2CreateSoftCert(char *pszPin, char *pszDN, char *pszIDNumber);

/************************************************************************/
/*	密码算法2 												    		*/
/************************************************************************/
// 对称算法
int KTSDKANDKTCORE_EncryptData(int nAlgID, unsigned char *pbKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_DecryptData(int nAlgID, unsigned char *pbKey, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_EncryptFile(int nAlgID, unsigned char *pbKey, char *pszFileIn, char *pszFileOut);
int KTSDKANDKTCORE_DecryptFile(int nAlgID, unsigned char *pbKey, char *pszFileIn, char *pszFileOut);

/************************************************************************/
/*	PKCS7运算 												    		*/
/************************************************************************/
int KTSDKANDKTCORE_SignDataByP7(bool bAttached, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_SignDataByP7Ex(bool bAttached, bool bHasAttr, unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_VerifySignedDataByP7(unsigned char *pbP7Sign, int nP7SignLen, unsigned char *pbData, int nDataLen);
int KTSDKANDKTCORE_GetP7SignDataInfo(unsigned char *pbIn, int nInLen, int nType, unsigned char *pbOut, int *pnOutLen);

int KTSDKANDKTCORE_EnvelopeDataByP7(int nAlgID, unsigned char *pbIn, int nInLen, char *pszEncCertsB64, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_UnenvelopeDataByP7(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);

int KTSDKANDKTCORE_SignAndEnvelopeDataByP7(int nAlgID, unsigned char *pbIn, int nInLen, char *pszEncCertsB64, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_UnenvelopeAndVerifyDataByP7(unsigned char *pbIn, int nInLen, unsigned char *pbOut, int *pnOutLen);
int KTSDKANDKTCORE_GetP7SignAndEnvelopeDataInfo(unsigned char *pbIn, int nInLen, int nType, unsigned char *pbOut, int *pnOutLen);

/************************************************************************/
/*	时间戳 													    		*/
/************************************************************************/
int KTSDKANDKTCORE_GetTSACert_ks(unsigned char *pbCertData, int *pnCertDataLen);
int KTSDKANDKTCORE_CreateTSReq_ks(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbReqData, int *pnReqDataLen);
int KTSDKANDKTCORE_CreateTSResp_ks(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_CreateTSResp_WithStatus_ks(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);

int KTSDKANDKTCORE_GetTSACert_bjca(unsigned char *pbCertData, int *pnCertDataLen);
int KTSDKANDKTCORE_CreateTSReq_bjca(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbReqData, int *pnReqDataLen);
int KTSDKANDKTCORE_CreateTSResp_bjca(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_CreateTSResp_WithStatus_bjca(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);

int KTSDKANDKTCORE_CreateTSReq_da(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbReqData, int *pnReqDataLen);
int KTSDKANDKTCORE_CreateTSResp_da(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_CreateTSResp_WithStatus_da(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);

int KTSDKANDKTCORE_CreateTSReq_xa(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbReqData, int *pnReqDataLen);
int KTSDKANDKTCORE_CreateTSResp_xa(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_CreateTSResp_WithStatus_xa(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);

int KTSDKANDKTCORE_CreateTSReq(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbReqData, int *pnReqDataLen);
int KTSDKANDKTCORE_CreateTSResp(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_CreateTSResp_WithStatus(unsigned char *pbReqData, int nReqDataLen, unsigned char *pbRespData, int *pnRespDataLen);
int KTSDKANDKTCORE_VerifyTS(unsigned char *pbSrcData, int nSrcDataLen, unsigned char *pbRespData, int nRespDataLen);
// 标志: 0-时间  1-证书  2-签名数据  3-时间戳原文摘要  4-时间戳原文摘要算法  10-Z结尾的时间
int KTSDKANDKTCORE_ParseTS(unsigned char *pbRespData, int nRespDataLen, int nFlag, unsigned char *pbParseData, int *pnParseDataLen);

/************************************************************************/
/*	KTSDKANDKTCORE_ 													    		*/
/************************************************************************/
// PKISDK接口
//const KTChar *KTSDKANDKTCORE_GetErrorString(KTINT32 rv);

const KTChar *KTSDKANDKTCORE_UI_SetErr(int nErr, const KTChar pc_format[], ...);
const KTChar *KTSDKANDKTCORE_UI_SetErr(const KTChar pc_format[], ...);

KTINT32 KTSDKANDKTCORE_Verify(
	KTCertificate& signCert,
	unsigned char *pbData,
	KTUINT32 unDataLen,
	unsigned char *pbSign,
	KTUINT32 unSignLen);

KTINT32 KTSDKANDKTCORE_VerifyCert(
	const KTCertificate& cert,
	const KTCertificate& issuerCert,
	KTCRL *pCRL,						//may be NULL
	enumCertStatus *pnCertStatus);

KTINT32 KTSDKANDKTCORE_VerifyCert(
	const KTCertificate& cert,
	const KTCertificates& certs,
	KTCRL *pCRL,						//may be NULL
	enumCertStatus *pnCertStatus);

void KTSDKANDKTCORE_TransCertStatus(
	int nCertStatus,
	KTChar *pszCertStatus);

KTINT32 KTSDKANDKTCORE_GetCertChain(
	KTCertificate& cert,
	KTCertificates& certs);

KTINT32 KTSDKANDKTCORE_GenerateRandom(
	KTINT nRandomLen,
	KTBYTE *pOutput);

KTINT32 KTSDKANDKTCORE_PKCS5Padding(
	BYTE *data,
	KTUINT& datalen,
	KTBOOL32 encrypt);

KTINT32 KTSDKANDKTCORE_EncryptOrDecrypt(
	IN KTBOOL32				bEncrypt,				// 是否加密
	IN KTUINT				unAlgID,				// 对称算法标识
	IN BYTE					*pbKey,					// 密钥
	IN KTUINT				unKeyLen,				// 密钥的长度
	IN KTBOOL32				bKeyEncrypted,			// 密钥是否为密文
	IN BYTE					*pbIV,					// 初始向量
	IN KTUINT				unIVLen,				// 初始向量的长度
	IN BYTE					*pbIn,					// 输入数据
	IN KTUINT				unInLen,				// 输入数据的长度
	OUT BYTE				*pbOut,					// 输出数据
	IN OUT KTUINT			*punOutLen);			// 输出数据的长度

typedef std::vector<KTByteArray> 	KTByteArrayArray;

bool KTSDKANDKTCORE_LoadCACerts2();

KTINT32 KTSDKANDKTCORE_GetCertChain2(
	unsigned char *cert,
	int certlen,
	unsigned char *cacert,
	int *cacertlen);

KTINT32 KTSDKANDKTCORE_GetCertChain2(
	unsigned char *cert,
	int certlen,
	KTByteArrayArray& certs);

KTINT32 KTSDKANDKTCORE_VerifyRootCert(
	unsigned char *cert,
	int certlen);

KTINT32 KTSDKANDKTCORE_VerifyCert2(
	unsigned char *cert,
	int certlen,
	unsigned char *cacert,
	int cacertlen,
	enumCertStatus *pnCertStatus);

/************************************************************************/
/*	KTCORE 													    		*/
/************************************************************************/
int KTSDKANDKTCORE_KTCore_Initialize();
int KTSDKANDKTCORE_KTCore_Finalize();

// 软对称算法
#define SOFT_3DES			0x00
#define SOFT_CEA			0x01
// 国密对称算法标识
#define SGD_SM1_ECB						0x00000101	// SM1算法ECB加密模式
#define SGD_SM1_CBC						0x00000102	// SM1算法CBC加密模式
#define SGD_SM1_CFB						0x00000104	// SM1算法CFB加密模式
#define SGD_SM1_OFB						0x00000108	// SM1算法OFB加密模式
#define SGD_SM1_MAC						0x00000110	// SM1算法MAC加密模式
#define SGD_SSF33_ECB					0x00000201	// SSF33算法ECB加密模式
#define SGD_SSF33_CBC					0x00000202	// SSF33算法CBC加密模式
#define SGD_SSF33_CFB					0x00000204	// SSF33算法CFB加密模式
#define SGD_SSF33_OFB					0x00000208	// SSF33算法OFB加密模式
#define SGD_SSF33_MAC					0x00000210	// SSF33算法MAC加密模式
#define SGD_SM4_ECB						0x00000401	// SM4算法ECB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_SM4_CBC						0x00000402	// SM4算法CBC加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_SM4_CFB						0x00000404	// SM4算法CFB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_SM4_OFB						0x00000408	// SM4算法OFB加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_SM4_MAC						0x00000410	// SM4算法MAC加密模式				// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_ZUC_EEA3					0x00000801	// ZUC祖冲之机密性算法128-EEA3算法	// 《密码应用标识规范》（GM/T 0006-2012）新加
#define SGD_ZUC_EIA3					0x00000802	// ZUC祖冲之完整性算法128-EIA3算法	// 《密码应用标识规范》（GM/T 0006-2012）新加
int KTSDKANDKTCORE_KTCore_SetEncryptMethod(int nEncryptMethod);
int KTSDKANDKTCORE_KTCore_GetEncryptMethod();

const KTChar *KTSDKANDKTCORE_KTCore_Sign(
	const char *pszPlainFile,			// 原文件（待签名文件）绝对路径
	const char *pszSignatureFile,		// 数字签名文件绝对路径
	bool bPlainInSignature);			// 签名中是否包含原文件内容

const KTChar *KTSDKANDKTCORE_KTCore_VerifySign(
	const char *pszSignatureFile,		// 数字签名文件绝对路径
	const char *pszPlainFile,			// 原文件（待验证签名文件）绝对路径。若签名中包含原文件内容，则将原文件输出
	KTSDKANDKTCORE_SIGN_INFO *pSignInfo);	// 签名信息

const KTChar *KTSDKANDKTCORE_KTCore_Envelop(
	const char *pszPlainFiles,			// 原文件（待加密文件或目录）绝对路径，以'|'分隔
	const char *pszCipherFile,			// 数字信封文件绝对路径
	const char *pszEnvelopCerts);		// 加密证书，以'|'分隔

const KTChar *KTSDKANDKTCORE_KTCore_Develop(
	const char *pszCipherFile,			// 数字信封文件绝对路径
	const char *pszPlainFileOrFolder);	// 原文件（解密文件或目录）绝对路径

const KTChar *KTSDKANDKTCORE_KTCore_EnvelopSign(
	const char *pszPlainFiles,			// 原文件（待加密签名文件或目录）绝对路径，以'|'分隔
	const char *pszCipherSignatureFile, // 加密签名文件绝对路径
	const char *pszEnvelopCerts);		// 加密证书，以'|'分隔

const KTChar *KTSDKANDKTCORE_KTCore_GetDecryptedFileNames(
	int *pnLen,							// 取解密文件名的缓冲区大小
	char *pszFileName);					// 取解密文件名的缓冲区

#endif
