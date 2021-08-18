#ifndef _MYSMDATA_H
#define _MYSMDATA_H

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

#include "MySMObjID.h"

////////////////////////////////////////////////////////////////
// ����SM2���ݽṹ

// SM2��Կ
typedef ASN1_BIT_STRING SM2_PUBLICKEY;

DECLARE_ASN1_FUNCTIONS(SM2_PUBLICKEY)

// SM2˽Կ
typedef ASN1_INTEGER SM2_PRIVATEKEY;

DECLARE_ASN1_FUNCTIONS(SM2_PRIVATEKEY)

// SM2ǩ��
typedef struct SM2_signature_st
{
	ASN1_INTEGER *r;
	ASN1_INTEGER *s;
} SM2_SIGNATURE;

DECLARE_ASN1_FUNCTIONS(SM2_SIGNATURE)

// SM2����
typedef struct SM2_cipher_st
{
	ASN1_INTEGER *x;
	ASN1_INTEGER *y;
	ASN1_OCTET_STRING *hash;
	ASN1_OCTET_STRING *cipherText;
} SM2_CIPHER;

DECLARE_ASN1_FUNCTIONS(SM2_CIPHER)

////////////////////////////////////////////////////////////////
// PKCS7_SM2���ݽṹ

// ����
typedef struct pkcs7_sm2_data_st
{
	ASN1_OBJECT *type;
	ASN1_OCTET_STRING *data;
} PKCS7_SM2_DATA;

DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_DATA)

// ǩ������
typedef struct pkcs7_sm2_signed_data_st
{
	ASN1_INTEGER				*version;			/* version 1 */
	STACK_OF(X509_ALGOR)		*digestAlgorithms;	/* md used */
	PKCS7_SM2_DATA				*contentInfo;
	STACK_OF(X509)				*certificates;		/* [ 0 ] */
	STACK_OF(X509_CRL)			*crls;				/* [ 1 ] */
	STACK_OF(PKCS7_SIGNER_INFO)	*signerInfos;
} PKCS7_SM2_SIGNED_DATA;

typedef struct pkcs7_sm2_signature_st
{
	ASN1_OBJECT *type;
	PKCS7_SM2_SIGNED_DATA *signedData;
} PKCS7_SM2_SIGNATURE;

DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNED_DATA)
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNATURE)

typedef STACK_OF(X509_ATTRIBUTE) X509_ATTRIBUTES;
DECLARE_ASN1_ENCODE_FUNCTIONS(X509_ATTRIBUTES, X509_ATTRIBUTES, X509_ATTRIBUTES)

// ǩ�����ݣ���У���룩
typedef struct pkcs7_signature_with_verification_code_st
{
	PKCS7 *signature;
	ASN1_OCTET_STRING	*verificationCode;
} PKCS7_SIGNATURE_WITH_VERIFICATION_CODE;
 
DECLARE_ASN1_FUNCTIONS(PKCS7_SIGNATURE_WITH_VERIFICATION_CODE)

typedef struct pkcs7_sm2_signature_with_verification_code_st
{
	PKCS7_SM2_SIGNATURE *signature;
	ASN1_OCTET_STRING	*verificationCode;
} PKCS7_SM2_SIGNATURE_WITH_VERIFICATION_CODE;
 
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNATURE_WITH_VERIFICATION_CODE)

// �����ŷ�����
typedef struct pkcs7_sm2_encrypted_contentinfo_st
{
	ASN1_OBJECT			*contentType;
	X509_ALGOR			*contentEncryptionAlgorithm;
	ASN1_OCTET_STRING	*encryptedContent;	/* [ 0 ] */
	ASN1_OCTET_STRING	*sharedInfo;		/* [ 1 ] */
	ASN1_OCTET_STRING	*sharedInfo2;		/* [ 2 ] */
} PKCS7_SM2_ENCRYPTED_CONTENTINFO;

typedef struct pkcs7_sm2_enveloped_data_st
{
	ASN1_INTEGER				*version;	/* version 1 */
	STACK_OF(PKCS7_RECIP_INFO)	*recipientInfos;
	PKCS7_SM2_ENCRYPTED_CONTENTINFO	*encryptedContentInfo;
} PKCS7_SM2_ENVELOPED_DATA;

typedef struct pkcs7_sm2_envelope_st
{
	ASN1_OBJECT *type;
	PKCS7_SM2_ENVELOPED_DATA *envelopedData;
} PKCS7_SM2_ENVELOPE;
 
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_ENCRYPTED_CONTENTINFO)
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_ENVELOPED_DATA)
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_ENVELOPE)

// �����ŷ����ݣ���У���룩
typedef struct pkcs7_sm2_envelope_with_verification_code_st
{
	PKCS7_SM2_ENVELOPE *envelope;
	ASN1_OCTET_STRING	*verificationCode;
} PKCS7_SM2_ENVELOPE_WITH_VERIFICATION_CODE;
 
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_ENVELOPE_WITH_VERIFICATION_CODE)

// ǩ���������ŷ�����
typedef struct pkcs7_sm2_signed_and_enveloped_data_st
{
	ASN1_INTEGER				*version;			/* version 1 */
	STACK_OF(PKCS7_RECIP_INFO)	*recipientInfos;
	STACK_OF(X509_ALGOR)		*digestAlgorithms;	/* md used */
	PKCS7_SM2_ENCRYPTED_CONTENTINFO	*encryptedContentInfo;
	STACK_OF(X509)				*certificates;		/* [ 0 ] */
	STACK_OF(X509_CRL)			*crls;				/* [ 1 ] */
	STACK_OF(PKCS7_SIGNER_INFO)	*signerInfos;
} PKCS7_SM2_SIGNED_AND_ENVELOPED_DATA;

typedef struct pkcs7_sm2_signature_and_envelope_st
{
	ASN1_OBJECT *type;
	PKCS7_SM2_SIGNED_AND_ENVELOPED_DATA *signedAndEnvelopedData;
} PKCS7_SM2_SIGNATURE_AND_ENVELOPE;

DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNED_AND_ENVELOPED_DATA)
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNATURE_AND_ENVELOPE)

// ǩ���������ŷ����ݣ���У���룩
typedef struct pkcs7_sm2_signature_and_envelope_with_verification_code_st
{
	PKCS7_SM2_SIGNATURE_AND_ENVELOPE *signAndEnvelope;
	ASN1_OCTET_STRING	*verificationCode;
} PKCS7_SM2_SIGNATURE_AND_ENVELOPE_WITH_VERIFICATION_CODE;
 
DECLARE_ASN1_FUNCTIONS(PKCS7_SM2_SIGNATURE_AND_ENVELOPE_WITH_VERIFICATION_CODE)

//BJCA TST_INFO�ṹ
typedef struct BJCA_Message_Imprint_st
{
	ASN1_OBJECT *algorithm;
	ASN1_OCTET_STRING *hashed_msg;
}BJCA_MESSAGE_IMPRINT;

typedef struct BJCA_TS_tst_info_st
{
	ASN1_INTEGER *version;
	ASN1_OBJECT *policy_id;
	BJCA_MESSAGE_IMPRINT *msg_imprint;
	ASN1_INTEGER *serial;
	ASN1_GENERALIZEDTIME *time;
} BJCA_TS_TST_INFO;
DECLARE_ASN1_FUNCTIONS(BJCA_MESSAGE_IMPRINT)
DECLARE_ASN1_FUNCTIONS(BJCA_TS_TST_INFO)
//

#endif
