#ifndef _MYSMLIBFUNC_H
#define _MYSMLIBFUNC_H

#define MYSMERR_SUCCESS			0
#define MYSMERR_PARAMETER		1
#define MYSMERR_MEMORY			2
#define MYSMERR_NOTSUPPORT		3
#define MYSMERR_BNOPERATION		4
#define MYSMERR_ECCOPERATION	5
#define MYSMERR_CERT			6
#define MYSMERR_NOTECCCERT		7
#define MYSMERR_FILEOPERATION	8
#define MYSMERR_ECCSIGN			11
#define MYSMERR_ECCVERIFYSIGN	12
#define MYSMERR_ECCENCRYPT		13
#define MYSMERR_ECCDECRYPT		14
#define MYSMERR_ECCKEYEXCHANGE	21

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

/************************************************************************/
/*	��ʼ��		 														*/
/************************************************************************/
long MYSM_Initialize(KTBOOL32 bFormal = TRUE);	// TRUEʹ����ʽ���ߣ�FALSEʹ�ò�������
long MYSM_Finalize();
long MYSM_SetParam(KTBOOL32 bFormal = TRUE);

/************************************************************************/
/*	SM3�����Ӵ��㷨														*/
/************************************************************************/
long MYSM_SM3Init(
	HANDLE			*phHandle);		// OUT

long MYSM_SM3Update(
	HANDLE			hHandle,		// IN
	unsigned char	*in,			// IN
	long			inlen);			// IN

long MYSM_SM3Final(
	HANDLE			hHandle,		// IN
	unsigned char	*out,			// OUT
	long			*outlen);		// IN OUT

long MYSM_SM3(
	unsigned char	*in,			// IN
	long			inlen,			// IN
	unsigned char	*out,			// OUT
	long			*outlen);		// IN OUT

/************************************************************************/
/*	SM2��Բ���߹�Կ�����㷨 											*/
/************************************************************************/
// ��֤���ȡECC��Կ����
long MYSM_ECCGetPubKeyFromCert(
	unsigned char	*cert,			// IN
	long			certlen,		// IN
	unsigned char	*pubkey_x,		// OUT
	long			*pubkeylen_x,	// IN OUT
	unsigned char	*pubkey_y,		// OUT
	long			*pubkeylen_y);	// IN OUT

// ����ECC˽Կ����ECC��Կ
long MYSM_ECCCalcPubKey(
	unsigned char	*prvkey,		// IN
	unsigned char	*pubkey_x,		// OUT
	unsigned char	*pubkey_y,		// OUT
	long			ecclen = 32);	// IN 256bits

// ����ECC��Կ��
long MYSM_ECCGenKeyPair(
	unsigned char	*prvkey,		// OUT
	unsigned char	*pubkey_x,		// OUT
	unsigned char	*pubkey_y,		// OUT
	long			ecclen = 32);	// IN 256bits

// Ԥ����1
// Z = SM3(ENTL��ID��a��b��Gx��Gy��Px��Py)
long MYSM_ECCGetZ(
	unsigned char	*userid,		// IN
	long			useridlen,		// IN
	unsigned char	*pubkey_x,		// IN
	unsigned char	*pubkey_y,		// IN
	unsigned char	*out,			// OUT
	long			*outlen,		// IN OUT
	long			ecclen = 32);	// IN 256bits

// Ԥ����2
// H = SM3(Z��M)
long MYSM_ECCGetH(
	unsigned char	*z,				// IN
	long			zlen,			// IN
	unsigned char	*in,			// IN
	long			inlen,			// IN
	unsigned char	*out,			// OUT
	long			*outlen);		// IN OUT

// Ԥ����2
// H = SM3(Z��M)
long MYSM_ECCGetFileH(
	unsigned char	*z,				// IN
	long			zlen,			// IN
	char			*infile,		// IN
	unsigned char	*out,			// OUT
	long			*outlen);		// IN OUT

// ECCǩ���㷨
long MYSM_ECCSign(
	unsigned char	*dgst,			// IN
	long			dgstlen,		// IN
	unsigned char	*sign_r,		// OUT
	unsigned char	*sign_s,		// OUT
	unsigned char	*prvkey,		// IN
	long			ecclen = 32);	// IN 256bits

// ECC��֤ǩ���㷨
long MYSM_ECCVerifySign(
	unsigned char	*dgst,			// IN
	long			dgstlen,		// IN
	unsigned char	*sign_r,		// IN
	unsigned char	*sign_s,		// IN
	unsigned char	*pubkey_x,		// IN
	unsigned char	*pubkey_y,		// IN
	long			ecclen = 32);	// IN 256bits

// ECC�����㷨
long MYSM_ECCEncrypt(
	unsigned char	*in,			// IN
	long			inlen,			// IN
	unsigned char	*out_c1,		// OUT
	unsigned char	*out_c2,		// OUT
	unsigned char	*out_c3,		// OUT
	unsigned char	*pubkey_x,		// IN
	unsigned char	*pubkey_y,		// IN
	long			ecclen = 32);	// IN 256bits

// ECC�����㷨
long MYSM_ECCDecrypt(
	unsigned char	*in_c1,			// IN
	unsigned char	*in_c2,			// IN
	long			inlen_c2,		// IN
	unsigned char	*in_c3,			// IN
	unsigned char	*out,			// OUT
	long			*outlen,		// IN OUT
	unsigned char	*prvkey,		// IN
	long			ecclen = 32);	// IN 256bits

// ECC��ԿЭ��
/*
 *	ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ�������ʱECC��Կ�Թ�Կ�������ز�������Կ���
 *	B������
 *	A_id			A��ID
 *	A_idlen			A��ID����
 *	A_pubkey_x 		A����Կx����
 *	A_pubkey_y		A����Կy����
 *	A_temppubkey_x 	A����ʱ��Կx����
 *	A_temppubkey_y	A����ʱ��Կy����
 *	B_id			B��ID
 *	B_idlen 		B��ID����
 *	B_prvkey 		B��˽Կ
 *	B_pubkey_x 		B����Կx����
 *	B_pubkey_y		B����Կy����
 *	B_temppubkey_x 	B����ʱ��Կx����
 *	B_temppubkey_y	B����ʱ��Կy����
 *	algid			�Ự��Կ�㷨��ʶ
 *	key				�Ự��Կ
 *	keylen			�Ự��Կ����
 */
long MYSM_ECCKeyExchangeB(
	unsigned char	*A_id,				// IN
	long			A_idlen,			// IN
	unsigned char	*A_pubkey_x,		// IN
	unsigned char	*A_pubkey_y,		// IN
	unsigned char	*A_temppubkey_x,	// IN
	unsigned char	*A_temppubkey_y,	// IN
	unsigned char	*B_id,				// IN
	long			B_idlen,			// IN
	unsigned char	*B_prvkey,			// IN
	unsigned char	*B_pubkey_x,		// IN
	unsigned char	*B_pubkey_y,		// IN
	unsigned char	*B_temppubkey_x,	// OUT
	unsigned char	*B_temppubkey_y,	// OUT
	long			algid,				// IN
	unsigned char	*key,				// OUT
	long			keylen,				// IN
	long			ecclen = 32);		// IN 256bits

/*
 *	ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ�������ʱECC��Կ�Թ�Կ�������ز�������Կ���
 *	A������
 *	A_id			A��ID
 *	A_idlen			A��ID����
 *	A_prvkey 		A��˽Կ
 *	A_pubkey_x 		A����Կx����
 *	A_pubkey_y		A����Կy����
 *	A_tempprvkey 	A����ʱ˽Կ
 *	A_temppubkey_x 	A����ʱ��Կx����
 *	A_temppubkey_y	A����ʱ��Կy����
 *	B_id			B��ID
 *	B_idlen 		B��ID����
 *	B_pubkey_x 		B����Կx����
 *	B_pubkey_y		B����Կy����
 *	B_temppubkey_x 	B����ʱ��Կx����
 *	B_temppubkey_y	B����ʱ��Կy����
 *	algid			�Ự��Կ�㷨��ʶ
 *	key				�Ự��Կ
 *	keylen			�Ự��Կ����
 */
long MYSM_ECCKeyExchangeA(
	unsigned char	*A_id,				// IN
	long			A_idlen,			// IN
	unsigned char	*A_prvkey,			// IN
	unsigned char	*A_pubkey_x,		// IN
	unsigned char	*A_pubkey_y,		// IN
	unsigned char	*A_tempprvkey,		// IN
	unsigned char	*A_temppubkey_x,	// IN
	unsigned char	*A_temppubkey_y,	// IN
	unsigned char	*B_id,				// IN
	long			B_idlen,			// IN
	unsigned char	*B_pubkey_x,		// IN
	unsigned char	*B_pubkey_y,		// IN
	unsigned char	*B_temppubkey_x,	// IN
	unsigned char	*B_temppubkey_y,	// IN
	long			algid,				// IN
	unsigned char	*key,				// OUT
	long			keylen,				// IN
	long			ecclen = 32);		// IN 256bits

/************************************************************************/
/*	SM4���������㷨														*/
/************************************************************************/
// SM4�����ʼ������Կ��չ��
// ��ԿΪ16�ֽ�
// ���ܣ�dwFlag = 0
// ���ܣ�dwFlag = 1
long MYSM_SM4Init(
	unsigned char	*key,				// IN
	DWORD			dwFlag,				// IN
	HANDLE			*phHandle);			// OUT

// SM4���㣬��ѭ����ε���
// ԭ�ĳ���Ϊ16����
long MYSM_SM4Update(
	HANDLE			hHandle,			// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

// ����SM4����
// �����������ȥ���
long MYSM_SM4Final(
	HANDLE			hHandle,			// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

// SM4����
// �����������ȥ���
// ��ԿΪ16�ֽ�
// ���ܣ�dwFlag = 0
// ���ܣ�dwFlag = 1
long MYSM_SM4(
	unsigned char	*key,				// IN
	DWORD			dwFlag,				// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

///////////////////////////////////////////////////////////
// gmssl

// SM4�����ʼ��
// ��ԿΪ16�ֽ�
// cbcģʽivΪ16�ֽ�
// ecbģʽ��dwMode = 1
// cbcģʽ��dwMode = 2
// ���ܣ�dwFlag = 0
// ���ܣ�dwFlag = 1
long MYSM_SMS4Init(
	unsigned char	*key,				// IN
	unsigned char	*iv,				// IN
	DWORD			dwMode,				// IN
	DWORD			dwFlag,				// IN
	HANDLE			*phHandle);			// OUT

// SM4���㣬��ѭ����ε���
// ԭ�ĳ���Ϊ16����
long MYSM_SMS4Update(
	HANDLE			hHandle,			// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

// ����SM4����
// �����������ȥ���
long MYSM_SMS4Final(
	HANDLE			hHandle,			// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

// SM4����
// �����������ȥ���
// ��ԿΪ16�ֽ�
// cbcģʽivΪ16�ֽ�
// ecbģʽ��dwMode = 1
// cbcģʽ��dwMode = 2
// ���ܣ�dwFlag = 0
// ���ܣ�dwFlag = 1
long MYSM_SMS4(
	unsigned char	*key,				// IN
	unsigned char	*iv,				// IN
	DWORD			dwMode,				// IN
	DWORD			dwFlag,				// IN
	unsigned char	*in,				// IN
	long			inlen,				// IN
	unsigned char	*out,				// OUT
	long			*outlen);			// IN OUT

/************************************************************************/
/*	֤�����															*/
/************************************************************************/
KTBOOL32 MYTOOL_ParseExtCertificatePolicies(unsigned char *extvalue, long extvaluelen, char *out, long *outlen);
KTBOOL32 MYTOOL_ParseExtExtKeyUsage(unsigned char *extvalue, long extvaluelen, DWORD *extkeyusage, char *out, long *outlen);
KTBOOL32 MYTOOL_ParseExtCrlDistributionPoints(unsigned char *extvalue, long extvaluelen, char *out, long *outlen);
KTBOOL32 MYTOOL_ParseExtNetScapeCertType(unsigned char *extvalue, long extvaluelen, char *out, long *outlen);
KTBOOL32 MYTOOL_ParseExtAuthorityInfoAccess(unsigned char *extvalue, long extvaluelen, char *out, long *outlen);

#endif
