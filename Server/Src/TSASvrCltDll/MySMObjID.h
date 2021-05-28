#ifndef _MYSMOBJID_H
#define _MYSMOBJID_H

////////////////////////////////////////////////////////////////
// RSA�ȶ����ʶ��

// 3DES�㷨
#define TXT_des_ede3_cbc					"1.2.840.113549.3.7"

// RSA�㷨
#define TXT_rsa								"1.2.840.113549.1.1.1"

// PKCS7����
#define TXT_pkcs7_data						"1.2.840.113549.1.7.1"
// PKCS7ǩ������
#define TXT_pkcs7_signed_data				"1.2.840.113549.1.7.2"
// PKCS7�����ŷ�����
#define TXT_pkcs7_enveloped_data			"1.2.840.113549.1.7.3"
// PKCS7ǩ���������ŷ�����
#define TXT_pkcs7_signedandenveloped_data	"1.2.840.113549.1.7.4"

////////////////////////////////////////////////////////////////
// ���ܶ����ʶ��

// ͨ�ö����ʶ��
#define OBJ_gjmmglj						1L,2L,156L,197L					// ������������
#define TXT_gjmmglj						"1.2.156.197"

#define OBJ_gjmmbzjswyh					1L,2L,156L,10197L				// ���������׼����ίԱ��
#define TXT_gjmmbzjswyh					"1.2.156.10197"

#define OBJ_gm_crypto_algor				OBJ_gjmmbzjswyh,1L				// �����㷨
#define TXT_gm_crypto_algor				TXT_gjmmbzjswyh".1"

// ���������㷨�����ʶ��
#define OBJ_gm_block_cipher_algor		OBJ_gm_crypto_algor,100L		// ���������㷨
#define TXT_gm_block_cipher_algor		TXT_gm_crypto_algor".100"

#define OBJ_gm_sm1						OBJ_gm_crypto_algor,102L		// SM1���������㷨
#define TXT_gm_sm1						TXT_gm_crypto_algor".102"

#define OBJ_gm_ssf33					OBJ_gm_crypto_algor,103L		// SSF33���������㷨
#define TXT_gm_ssf33					TXT_gm_crypto_algor".103"

#define OBJ_gm_sm4						OBJ_gm_crypto_algor,104L		// SM4���������㷨
#define TXT_gm_sm4						TXT_gm_crypto_algor".104"

// ���������㷨�����ʶ��
#define OBJ_gm_stream_cipher_algor		OBJ_gm_crypto_algor,200L		// ���������㷨
#define TXT_gm_stream_cipher_algor		TXT_gm_crypto_algor".200"

#define OBJ_gm_zuc						OBJ_gm_crypto_algor,201L		// ���֮���������㷨
#define TXT_gm_zuc						TXT_gm_crypto_algor".201"

// ��Կ�����㷨�����ʶ��
#define OBJ_gm_publickey_crypto_algor	OBJ_gm_crypto_algor,300L		// ��Կ�����㷨
#define TXT_gm_publickey_crypto_algor	TXT_gm_crypto_algor".300"

#define OBJ_gm_sm2						OBJ_gm_crypto_algor,301L		// SM2��Բ���߹�Կ�����㷨
#define TXT_gm_sm2						TXT_gm_crypto_algor".301"

#define OBJ_gm_sm2_1					OBJ_gm_sm2,1L					// SM2-1����ǩ���㷨
#define TXT_gm_sm2_1					TXT_gm_sm2".1"

#define OBJ_gm_sm2_2					OBJ_gm_sm2,2L					// SM2-2��Կ����Э��
#define TXT_gm_sm2_2					TXT_gm_sm2".2"

#define OBJ_gm_sm2_3					OBJ_gm_sm2,3L					// SM2-3��Կ�����㷨
#define TXT_gm_sm2_3					TXT_gm_sm2".3"

#define OBJ_gm_sm9						OBJ_gm_crypto_algor,302L		// SM9��ʶ�����㷨
#define TXT_gm_sm9						TXT_gm_crypto_algor".302"

#define OBJ_gm_sm9_1					OBJ_gm_sm9,1L					// SM9-1����ǩ���㷨
#define TXT_gm_sm9_1					TXT_gm_sm9".1"

#define OBJ_gm_sm9_2					OBJ_gm_sm9,2L					// SM9-2��Կ����Э��
#define TXT_gm_sm9_2					TXT_gm_sm9".2"

#define OBJ_gm_sm9_3					OBJ_gm_sm9,3L					// SM9-3��Կ��װ���ƺ͹�Կ�����㷨
#define TXT_gm_sm9_3					TXT_gm_sm9".3"

// �Ӵ��㷨�����ʶ��
#define OBJ_gm_hash_algor				OBJ_gm_crypto_algor,400L		// �Ӵ��㷨
#define TXT_gm_hash_algor				TXT_gm_crypto_algor".400"

#define OBJ_gm_sm3						OBJ_gm_crypto_algor,401L		// SM3�����Ӵ��㷨
#define TXT_gm_sm3						TXT_gm_crypto_algor".401"

#define OBJ_gm_sm3_1					OBJ_gm_sm3,1L					// SM3�����Ӵ��㷨������Կʹ��
#define TXT_gm_sm3_1					TXT_gm_sm3".1"

#define OBJ_gm_sm3_2					OBJ_gm_sm3,2L					// SM3�����Ӵ��㷨������Կʹ��
#define TXT_gm_sm3_2					TXT_gm_sm3".2"

// ��������㷨�����ʶ��
#define OBJ_gm_combined_operation		OBJ_gm_crypto_algor,500L		// ����������
#define TXT_gm_combined_operation		TXT_gm_crypto_algor".500"

#define OBJ_gm_sm3_sm2					OBJ_gm_crypto_algor,501L		// ����SM2�㷨��SM3�㷨��ǩ��
#define TXT_gm_sm3_sm2					TXT_gm_crypto_algor".501"

#define OBJ_gm_sha1_sm2					OBJ_gm_crypto_algor,502L		// ����SM2�㷨��SHA_1�㷨��ǩ��
#define TXT_gm_sha1_sm2					TXT_gm_crypto_algor".502"

#define OBJ_gm_sha256_sm2				OBJ_gm_crypto_algor,503L		// ����SM2�㷨��SHA_256�㷨��ǩ��
#define TXT_gm_sha256_sm2				TXT_gm_crypto_algor".503"

#define OBJ_gm_sm3_rsa					OBJ_gm_crypto_algor,504L		// ����RSA�㷨��SM3�㷨��ǩ��
#define TXT_gm_sm3_rsa					TXT_gm_crypto_algor".504"

// ��׼��ϵ�����ʶ��
#define OBJ_gm_std_sys					OBJ_gjmmbzjswyh,6L				// ��׼��ϵ
#define TXT_gm_std_sys					TXT_gjmmbzjswyh".6"

#define OBJ_gm_base_class				OBJ_gm_std_sys,1L				// ������
#define TXT_gm_base_class				TXT_gm_std_sys".1"

#define OBJ_gm_security_mechanism		OBJ_gm_base_class,4L			// ��ȫ����
#define TXT_gm_security_mechanism		TXT_gm_base_class".4"

// SM2����ǩ����Ϣ�����ʶ��
#define OBJ_gm_sm2_crypto_msg			OBJ_gm_security_mechanism,2L	// SM2����ǩ����Ϣ�﷨�淶
#define TXT_gm_sm2_crypto_msg			TXT_gm_security_mechanism".2"

#define OBJ_gm_data						OBJ_gm_sm2_crypto_msg,1L		// ��������
#define TXT_gm_data						TXT_gm_sm2_crypto_msg".1"

#define OBJ_gm_signed_data				OBJ_gm_sm2_crypto_msg,2L		// ǩ����������
#define TXT_gm_signed_data				TXT_gm_sm2_crypto_msg".2"

#define OBJ_gm_enveloped_data			OBJ_gm_sm2_crypto_msg,3L		// �����ŷ���������
#define TXT_gm_enveloped_data			TXT_gm_sm2_crypto_msg".3"

#define OBJ_gm_signedandenveloped_data	OBJ_gm_sm2_crypto_msg,4L		// ǩ���������ŷ���������
#define TXT_gm_signedandenveloped_data	TXT_gm_sm2_crypto_msg".4"

#define OBJ_gm_encrypted_data			OBJ_gm_sm2_crypto_msg,5L		// ������������
#define TXT_gm_encrypted_data			TXT_gm_sm2_crypto_msg".5"

#define OBJ_gm_keyagreement_info		OBJ_gm_sm2_crypto_msg,6L		// ��ԿЭ������
#define TXT_gm_keyagreement_info		TXT_gm_sm2_crypto_msg".6"

////////////////////////////////////////////////////////////////
// RSA�ȶ������

// 3DES�㷨
static const unsigned char g_by3DES[]				= {0x06, 0x08, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x03, 0x07};

// RSA�㷨
static const unsigned char g_byRSA[]				= {0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x01, 0x01};

// PKCS7����
static const unsigned char g_byData[]				= {0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x01};
// PKCS7ǩ������
static const unsigned char g_bySignedData[]			= {0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x02};
// PKCS7�����ŷ�����
static const unsigned char g_byEnvelopedData[]		= {0x06, 0x09, 0x2A, 0x86, 0x48, 0x86, 0xF7, 0x0D, 0x01, 0x07, 0x03};

////////////////////////////////////////////////////////////////
// ���ܶ������

// ���������㷨
// SM1���������㷨
// 1.2.156.10197.1.102
static const unsigned char g_bySM1[]				= {0x06, 0x07, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x66};
// SSF33���������㷨
// 1.2.156.10197.1.103
static const unsigned char g_bySSF33[]				= {0x06, 0x07, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x67};
// SM4���������㷨
// 1.2.156.10197.1.104
static const unsigned char g_bySM4[]				= {0x06, 0x07, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x68};

// SM2��Բ���߹�Կ�����㷨
// SM2-1����ǩ���㷨
// 1.2.156.10197.1.301.1
static const unsigned char g_bySM2_1[]				= {0x06, 0x09, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x82, 0x2D, 0x01};
// SM2-2��Կ����Э��
// 1.2.156.10197.1.301.2
static const unsigned char g_bySM2_2[]				= {0x06, 0x09, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x82, 0x2D, 0x02};
// SM2-3��Կ�����㷨
// 1.2.156.10197.1.301.3
static const unsigned char g_bySM2_3[]				= {0x06, 0x09, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x82, 0x2D, 0x03};

// SM3�����Ӵ��㷨
// SM3�����Ӵ��㷨������Կʹ��
// 1.2.156.10197.1.401.1
static const unsigned char g_bySM3_1[]				= {0x06, 0x09, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x83, 0x11, 0x01};
// SM3�����Ӵ��㷨������Կʹ��
// 1.2.156.10197.1.401.2
static const unsigned char g_bySM3_2[]				= {0x06, 0x09, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x83, 0x11, 0x02};

// ����������
// ����SM2�㷨��SM3�㷨��ǩ��
// 1.2.156.10197.1.501
static const unsigned char g_bySM3_SM2[]			= {0x06, 0x08, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x83, 0x75};
// ����RSA�㷨��SM3�㷨��ǩ��
// 1.2.156.10197.1.504
static const unsigned char g_bySM3_RSA[]			= {0x06, 0x08, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x01, 0x83, 0x78};

// SM2�����㷨����ǩ����Ϣ�﷨�淶
// ����
// 1.2.156.10197.6.1.4.2.1
static const unsigned char g_bySM2Data[]			= {0x06, 0x0A, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x06, 0x01, 0x04, 0x02, 0x01};
// ǩ������
// 1.2.156.10197.6.1.4.2.2
static const unsigned char g_bySM2SignedData[]		= {0x06, 0x0A, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x06, 0x01, 0x04, 0x02, 0x02};
// �����ŷ�����
// 1.2.156.10197.6.1.4.2.3
static const unsigned char g_bySM2EnvelopedData[]	= {0x06, 0x0A, 0x2A, 0x81, 0x1C, 0xCF, 0x55, 0x06, 0x01, 0x04, 0x02, 0x03};

#endif
