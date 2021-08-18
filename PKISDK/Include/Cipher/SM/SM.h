#ifndef __SM_H__
#define __SM_H__

// KTINTEGERת��Ϊ���ݴ�������Ϊ32������
int KTINTEGER2SMData(const KTINTEGER& in, KTByteArray& out);
int KTINTEGER2SMData(const KTINTEGER& in, unsigned char *out, int *outlen);
// ���ݴ�������Ϊ32������ת��ΪKTINTEGER
int SMData2KTINTEGER(KTByteArray& in, KTINTEGER& out);
int SMData2KTINTEGER(unsigned char *in, int inlen, KTINTEGER& out);

// ȡ��ԿX����
int GetXFromSM2PublicKey(const KTBITSTRING& in, KTByteArray& out);
int GetXFromSM2PublicKey(const KTBITSTRING& in, unsigned char *out, int *outlen);
// ȡ��ԿY����
int GetYFromSM2PublicKey(const KTBITSTRING& in, KTByteArray& out);
int GetYFromSM2PublicKey(const KTBITSTRING& in, unsigned char *out, int *outlen);

// SM3�Ӵ��㷨
KTINT32 K_SM3_Digest(const KTBYTE *pInput, KTUINT nInputLen,
				KTBYTE *pOutput, KTUINT *pnOutputLen);

// SM2Ԥ����
KTINT32 K_SM2_YCL(CSM2PublicKey *pKey,
				const KTBYTE *pInput, KTUINT nInputLen,
				KTBYTE *pOutput, KTUINT *pnOutputLen);

// SM2�ǶԳ��㷨������˽Կǩ���͹�Կ��֤ǩ������Կ���ܺ�˽Կ����
// ��֤ǩ��ʱ��pInputΪԭ�����ݣ�pOutputΪǩ�����ݣ���Ϊ��������
KTINT32 K_SM2_Cipher(EM_MODE mode, CKey *pKey,
				const KTBYTE *pInput, KTUINT nInputLen,
				KTBYTE *pOutput, KTUINT *pnOutputLen);

#endif
