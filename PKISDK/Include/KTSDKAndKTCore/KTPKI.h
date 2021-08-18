#ifndef _KTPKI_H
#define _KTPKI_H

// PKISDK�ӿ�
//const KTChar *KTPKI_GetErrorString(KTINT32 rv);

const KTChar *KTPKI_UI_SetErr(int nErr, const KTChar pc_format[], ...);
const KTChar *KTPKI_UI_SetErr(const KTChar pc_format[], ...);

KTINT32 KTPKI_Verify(
	KTCertificate& signCert,
	unsigned char *pbData,
	KTUINT32 unDataLen,
	unsigned char *pbSign,
	KTUINT32 unSignLen);

KTINT32 KTPKI_VerifyCert(
	const KTCertificate& cert,
	const KTCertificate& issuerCert,
	KTCRL *pCRL,						//may be NULL
	enumCertStatus *pnCertStatus);

KTINT32 KTPKI_VerifyCert(
	const KTCertificate& cert,
	const KTCertificates& certs,
	KTCRL *pCRL,						//may be NULL
	enumCertStatus *pnCertStatus);

void KTPKI_TransCertStatus(
	int nCertStatus,
	KTChar *pszCertStatus);

KTINT32 KTPKI_GetCertChain(
	KTCertificate& cert,
	KTCertificates& certs);

KTINT32 KTPKI_GenerateRandom(
	KTINT nRandomLen,
	KTBYTE *pOutput);

KTINT32 KTPKI_PKCS5Padding(
	BYTE *data,
	KTUINT& datalen,
	KTBOOL32 encrypt);

KTINT32 KTPKI_EncryptOrDecrypt(
	IN KTBOOL32				bEncrypt,				// �Ƿ����
	IN KTUINT				unAlgID,				// �Գ��㷨��ʶ
	IN BYTE					*pbKey,					// ��Կ
	IN KTUINT				unKeyLen,				// ��Կ�ĳ���
	IN KTBOOL32				bKeyEncrypted,			// ��Կ�Ƿ�Ϊ����
	IN BYTE					*pbIV,					// ��ʼ����
	IN KTUINT				unIVLen,				// ��ʼ�����ĳ���
	IN BYTE					*pbIn,					// ��������
	IN KTUINT				unInLen,				// �������ݵĳ���
	OUT BYTE				*pbOut,					// �������
	IN OUT KTUINT			*punOutLen);			// ������ݵĳ���

typedef std::vector<KTByteArray> 	KTByteArrayArray;

bool KTSDK_LoadCACerts2();

KTINT32 KTPKI_GetCertChain2(
	unsigned char *cert,
	int certlen,
	unsigned char *cacert,
	int *cacertlen);

KTINT32 KTPKI_GetCertChain2(
	unsigned char *cert,
	int certlen,
	KTByteArrayArray& certs);

KTINT32 KTPKI_VerifyRootCert(
	unsigned char *cert,
	int certlen);

KTINT32 KTPKI_VerifyCert2(
	unsigned char *cert,
	int certlen,
	unsigned char *cacert,
	int cacertlen,
	enumCertStatus *pnCertStatus);

#endif