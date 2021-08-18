#ifndef __PKI_CLIENT_DEF_H__
#define __PKI_CLIENT_DEF_H__

#ifndef _IBM_AIX
#pragma pack(push, 1)
#else
#pragma pack(1)
#pragma options align=packed
#endif /*_IBM_AIX*/

#define MAX_PATH 260

//support TSS
enum enumKTTimeType{
	KTFLAG_TIMETYPE_NULL  = 0,
	KTFLAG_TIMETYPE_LOCAL,
	KTFLAG_TIMETYPE_TIMESTAMP
};
typedef struct _KT_SIGNER_INFO
{
	//unsigned int unSize;//support TSS
	//int nFlags;//support TSS,reference enumTimeTypeFlags; 
	struct tm	tmGMT;
//	KTHANDLE	hCertHandle;
	KTByteArray	rCert;
	int			nCertStatus;
}KT_SIGNER_INFO;

#define SIGN_INFO_FILENM_EXT		_KT(".l3v")
#define SIGN_INFO_FILENM_TAG		_KT("asbMHN")

///chenlinchan 2003/05/27 12:22 add two macros here BLOCK_BEGIN
#define ENVELOP_INFO_FILENM_EXT     _KT(".14v")
#define ENVELOP_INFO_FILENM_TAG		_KT("eifTAG")
///chenlinchan 2003/05/27 12:22 add two macros here BLOCK_END

#define MAX_SHOW_SIGN_NUM   10
#define MAX_SIGNER_NUM      10

typedef struct _KT_SIGN_INFO
{
	char            pc_signFileNm[MAX_PATH];
	int             nSigner;			//����ʱָ�������ɵ�KT_SIGNER_INFO�ĸ���
	KT_SIGNER_INFO  pSignerInfo[MAX_SIGNER_NUM];

}KT_SIGN_INFO;  

// ǩ���ļ��ṹ�İ汾���Ͷ���
enum{
	KT_SIGN_VER10,
	KT_ENCRYPT_VER10,
	KT_ENVELOP_VER10,
	KT_ENVELOP_SIGN_VER10,
	KT_ORIGINAL_SIGN_VER10,
	KT_SIGN_SUPPORT_TIMESTAMP_VER10
};

#define FLOPPY_PRV_KEY_FILENM	_KT("ethDwCus1.bin")
#define FLOPPY_PUB_KEY_FILENM	_KT("MbmBYt2mQ.bin")
#define FLOPPY_KEY				_KT("abcdefghigklmnop")

#define KT_CERT_FILE_EXT		_KT(".ktc")
#define KT_MAIL_FILE_EXT		_KT(".ktm")
#define KT_COFFER_FILE_EXT		_KT(".ktf")
#define KT_CIPHER_FILE_EXT		_KT(".kte")
#define KT_SIGNED_FILE_EXT		_KT(".kts")

#define KT_CERT_FILE_CER		_KT(".cer")
#define KT_CERT_FILE_DER		_KT(".der")	
#define KT_CERT_FILE_CRT		_KT(".crt")	
#define KT_CRL_FILE_EXT			_KT(".crl")			

#define CURRENT_THIRD_PARTY_ALGO_NAME	_KT("test")

#define CHAR_BLANK					_KT( ' ' )
//#define CHAR_QUESTION				_KT( '?' ) 
#define CHAR_DIRTAG					_KT( '\\')
#define CHAR_FILENMTAG				_KT( '\"' )
#define CHAR_FILENM_SPERATOR		_KT( '|' )
#define CIPHER_FILE_FILTER			_KT("�����ļ�(*.kte)\0*.kte\0�����ļ� (*.*)\0*.*\0\0")
#define SIGNED_FILE_FILTER			_KT("ǩ���ļ�(*.kts)\0*.kts\0�����ļ� (*.*)\0*.*\0\0")
#define ONLY_CIPHER_FILE_FILTER		_KT("�����ļ�(*.kte)\0*.kte\0\0")
#define ONLY_SIGNED_FILE_FILTER		_KT("ǩ���ļ�(*.kts)\0*.kts\0\0")
#define ALL_FILE_FILTER				_KT("�����ļ�(*.*)\0*.*\0\0")	

#ifndef _IBM_AIX
#pragma pack(pop)
#else
#pragma pack()
#pragma options align=reset
#endif

#endif
