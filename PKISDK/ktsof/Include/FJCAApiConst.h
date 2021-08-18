#ifndef _FJCAAPICONST_H
#define _FJCAAPICONST_H

// �ӿڷ���ֵ�����б�
#define SAR_OK							0			// �ɹ�
#define SAR_UnknownErr					0X0B000001	// �쳣����
#define SAR_NotSupportYetErr			0X0B000002	// ��֧�ֵķ���
#define SAR_FileErr						0X0B000003	// �ļ���������
#define SAR_ProviderTypeErr				0X0B000004	// �����ṩ�߲������ʹ���
#define SAR_LoadProviderErr				0X0B000005	// ��������ṩ�߽ӿڴ���
#define SAR_LoadDevMngApiErr			0X0B000006	// �����豸����ӿڴ���
#define SAR_AlgoTypeErr					0X0B000007	// �㷨���ʹ���
#define SAR_NameLenErr					0X0B000008	// ���Ƴ��ȴ���
#define SAR_KeyUsageErr					0X0B000009	// ��Կ��;����
#define SAR_ModulusLenErr				0X0B000010	// ģ�ĳ��ȴ���
#define SAR_NotInitializeErr			0X0B000011	// δ��ʼ��
#define SAR_ObjErr						0X0B000012	// �������
#define SAR_MemoryErr					0X0B000100	// �ڴ����
#define SAR_TimeoutErr					0X0B000101	// ����ʱ
#define SAR_IndataLenErr				0X0B000200	// �������ݳ��ȴ���
#define SAR_IndataErr					0X0B000201	// �������ݴ���
#define SAR_GenRandErr					0X0B000300	// �������������
#define SAR_HashObjErr					0X0B000301	// HASH�����
#define SAR_HashErr						0X0B000302	// HASH�������
#define SAR_GenRsaKeyErr				0X0B000303	// ����RSA��Կ��
#define SAR_RsaModulusLenErr			0X0B000304	// RSA��Կģ������
#define SAR_CspImprtPubKeyErr			0X0B000305	// CSP�����빫Կ����
#define SAR_RsaEncErr					0X0B000306	// RSA���ܴ���
#define SAR_RSGDecErr					0X0B000307	// RSA���ܴ���
#define SAR_HashNotEqualErr				0X0B000308	// HASHֵ�����
#define SAR_KeyNotFountErr				0X0B000309	// ��Կδ����
#define SAR_CertNotFountErr				0X0B000310	// ֤��δ����
#define SAR_NotExportErr				0X0B000311	// ����δ����
#define SAR_DecryptPadErr				0X0B000400	// ����ʱ����������
#define SAR_MacLenErr					0X0B000401	// MAC���ȴ���
#define SAR_KeyInfoTypeErr				0X0B000402	// ��Կ���ʹ���
#define SAR_NULLPointerErr				0X0B000403	// ĳһ������Ϊ��ָ��
#define SAR_APPNOTFOUNDErr				0X0B000404	// û���ҵ���Ӧ��
#define SAR_CERTENCODEErr				0X0B000405	// ֤������ʽ����
#define SAR_CERTINVALIDErr				0X0B000406	// ֤����Ч�����ǿ���ca�䷢��֤��
#define SAR_CERTHASEXPIREDErr			0X0B000407	// ֤���ѹ���
#define SAR_CERTREVOKEDErr				0X0B000408	// ֤���Ѿ�������
#define SAR_SIGNDATAErr					0X0B000409	// ǩ��ʧ��
#define SAR_VERIFYSIGNDATAErr			0X0B000410	// ��֤ǩ��ʧ��
#define SAR_READFILEErr					0X0B000411	// ���ļ��쳣�������ļ������ڻ�û�ж�ȡȨ�޵�
#define SAR_WRITEFILEErr				0X0B000412	// д�ļ��쳣�������ļ������ڻ�û��дȨ�޵�
#define SAR_SECRETSEGMENTErr			0X0B000413	// �����㷨��Կ�ָ�ʧ��
#define SAR_SECERTRECOVERYErr			0X0B000414	// ���޻ָ�ʧ��
#define SAR_ENCRYPTDATAErr				0X0B000415	// �����ݵĶԳƼ���ʧ��
#define SAR_DECRYPTDATAErr				0X0B000416	// �Գ��㷨�����ݽ���ʧ��
#define SAR_PKCS7ENCODEErr				0X0B000417	// PKCS#7�����ʽ����
#define SAR_XMLENCODEErr				0X0B000418	// ���ǺϷ���xml��������
#define SAR_PARAMETERNOTSUPPORTErr		0X0B000419	// ��֧�ֵĲ���
#define SAR_LoginErr					0X0B000420	// ��¼ʧ��
#define SAR_AddP7BErr					0X0B000421	// ��������б�ʧ��
#define SAR_CertRevokedErr				0X0B000422	// ֤����ע��
// ���
#define SAR_BASE64ENCODEDECODEErr		0X0B000500	// Base64�����ʧ��
#define SAR_PINErr						0X0B000501	// �˶�֤�����ʧ��
#define SAR_ObjNotFountErr				0X0B000502	// ����δ����
#define SAR_COMMUNICATIONErr			0X0B000503	// ͨѶ���ݴ������
#define SAR_DATABASEErr					0X0B000504	// �������ݿ�ʱ������ϵͳ����
#define SAR_CERTNOTYETVALIDErr			0X0B000505	// ֤��δ��Ч
#define SAR_CERTNOTINRLErr				0X0B000506	// ��ҵ���ں������У���ҵ��δ�����Ϸ����
#define SAR_CERTNOTINDZBErr				0X0B000507	// ��ҵ���ڶ��ձ��У���������δ���
#define SAR_SERVICEHASEXPIREDErr		0X0B000508	// �����ѹ���
#define SAR_TSSERVERErr					0X0B000509	// ʱ����������ڲ�����
#define SAR_CREATETSREQUESTErr			0X0B000510	// ����ʱ�������ʧ��
#define SAR_SIGNTSErr					0X0B000511	// ǩ��ʱ���ʧ��
#define SAR_TSENCODEErr					0X0B000512	// ʱ��������ʽ����
#define SAR_VERIFYTSErr					0X0B000513	// ��֤ʱ���ʧ��
#define SAR_ObjExistErr					0X0B000514	// �����Ѵ���
#define SAR_CRLENCODEErr				0X0B000515	// CRL�����ʽ����
#define SAR_CRLINVALIDErr				0X0B000516	// ���ǿ���ca�䷢��CRL
#define SAR_ECCCERTENCODEErr			0X0B000517	// ECC֤������ʽ����
#define SAR_ECCOPERErr					0X0B000518	// ECC�������
#define SAR_ECCSIGNErr					0X0B000519	// ECCǩ������
#define SAR_ECCVERIFYSIGNErr			0X0B000520	// ECC��֤ǩ������
#define SAR_ECCENCErr					0X0B000521	// ECC���ܴ���
#define SAR_ECCDECErr					0X0B000522	// ECC���ܴ���
#define SAR_ECCDATAErr					0X0B000523	// ECC���ݱ������
#define SAR_DATAENCODEErr				0X0B000524	// ���ݱ���ת��ʧ��
#define SAR_NotLogin					0X0B000800	// û�е�¼
#define SAR_VERIFYCERTErr				0X0B000801	// ��֤֤��ʧ��
#define SAR_GETCERTTRUSTLEVELErr		0X0B000802	// ��ȡ֤�����������򼶱�ʧ��

// ��������
#define SGD_TRUE						0x00000001
#define SGD_FALSE						0x00000000

// ȫ�ֲ�������
// �Գ��㷨
#define SGD_STR_SM1_ECB					"SM1_ECB"	// SM1�㷨ECB����ģʽ
#define SGD_STR_SM1_CBC					"SM1_CBC"	// SM1�㷨CBC����ģʽ
#define SGD_STR_SM1_CFB					"SM1_CFB"	// SM1�㷨CFB����ģʽ
#define SGD_STR_SM1_OFB					"SM1_OFB"	// SM1�㷨OFB����ģʽ
#define SGD_STR_SM1_MAC					"SM1_MAC"	// SM1�㷨MAC����ģʽ
#define SGD_STR_SSF33_ECB				"SSF33_ECB"	// SSF33�㷨ECB����ģʽ
#define SGD_STR_SSF33_CBC				"SSF33_CBC"	// SSF33�㷨CBC����ģʽ
#define SGD_STR_SSF33_CFB				"SSF33_CFB"	// SSF33�㷨CFB����ģʽ
#define SGD_STR_SSF33_OFB				"SSF33_OFB"	// SSF33�㷨OFB����ģʽ
#define SGD_STR_SSF33_MAC				"SSF33_MAC"	// SSF33�㷨MAC����ģʽ
#define SGD_STR_SM4_ECB					"SM4_ECB"	// SM4�㷨ECB����ģʽ
#define SGD_STR_SM4_CBC					"SM4_CBC"	// SM4�㷨CBC����ģʽ
#define SGD_STR_SM4_CFB					"SM4_CFB"	// SM4�㷨CFB����ģʽ
#define SGD_STR_SM4_OFB					"SM4_OFB"	// SM4�㷨OFB����ģʽ
#define SGD_STR_SM4_MAC					"SM4_MAC"	// SM4�㷨MAC����ģʽ
#define SGD_STR_ZUC_EEA3				"ZUC_EEA3"	// ZUC���֮�������㷨128-EEA3�㷨
#define SGD_STR_ZUC_EIA3				"ZUC_EIA3"	// ZUC���֮�������㷨128-EIA3�㷨
// �ǶԳ��㷨
#define SGD_STR_RSA						"RSA"		// RSA�㷨
#define SGD_STR_SM2						"SM2"		// SM2��Բ���������㷨
#define SGD_STR_SM2_1					"SM2_1"		// SM2��Բ����ǩ���㷨
#define SGD_STR_SM2_2					"SM2_2"		// SM2��Բ������Կ����Э��
#define SGD_STR_SM2_3					"SM2_3"		// SM2��Բ���߼����㷨
// �Ӵ��㷨
#define	SGD_STR_SM3						"SM3"		// SM3�Ӵ��㷨
#define SGD_STR_SHA1					"SHA1"		// SHA_1�Ӵ��㷨
#define SGD_STR_SHA256					"SHA256"	// SHA_256�Ӵ��㷨
// ǩ���㷨
#define SGD_STR_SM3_RSA					"SM3_RSA"	// ����SM3�㷨��RSA�㷨��ǩ��
#define SGD_STR_SHA1_RSA				"SHA1_RSA"	// ����SHA_1�㷨��RSA�㷨��ǩ��
#define SGD_STR_SHA256_RSA				"SHA256_RSA"// ����SHA_256�㷨��RSA�㷨��ǩ��
#define SGD_STR_SM3_SM2					"SM3_SM2"	// ����SM3�㷨��SM2�㷨��ǩ��

// �Գ��㷨��ʶ
#define SGD_SM1_ECB						0x00000101	// SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC						0x00000102	// SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB						0x00000104	// SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB						0x00000108	// SM1�㷨OFB����ģʽ
#define SGD_SM1_MAC						0x00000110	// SM1�㷨MAC����ģʽ
#define SGD_SSF33_ECB					0x00000201	// SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC					0x00000202	// SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB					0x00000204	// SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB					0x00000208	// SSF33�㷨OFB����ģʽ
#define SGD_SSF33_MAC					0x00000210	// SSF33�㷨MAC����ģʽ
#define SGD_SM4_ECB						0x00000401	// SM4�㷨ECB����ģʽ				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_SM4_CBC						0x00000402	// SM4�㷨CBC����ģʽ				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_SM4_CFB						0x00000404	// SM4�㷨CFB����ģʽ				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_SM4_OFB						0x00000408	// SM4�㷨OFB����ģʽ				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_SM4_MAC						0x00000410	// SM4�㷨MAC����ģʽ				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_ZUC_EEA3					0x00000801	// ZUC���֮�������㷨128-EEA3�㷨	// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_ZUC_EIA3					0x00000802	// ZUC���֮�������㷨128-EIA3�㷨	// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
// �ǶԳ��㷨��ʶ
#define SGD_RSA							0x00010000	// RSA�㷨
#define SGD_SM2							0x00020100	// SM2��Բ���������㷨				// ������Ӧ�ñ�ʶ�淶����GM/T 0006-2012���¼�
#define SGD_SM2_1						0x00020100	// SM2��Բ����ǩ���㷨				// �롶����Ӧ�ñ�ʶ�淶����GM/T 0006-2012����һ�£�����Ϊ0x00020200��
#define SGD_SM2_2						0x00020200	// SM2��Բ������Կ����Э��			// �롶����Ӧ�ñ�ʶ�淶����GM/T 0006-2012����һ�£�����Ϊ0x00020400��
#define SGD_SM2_3						0x00020400	// SM2��Բ���߼����㷨				// �롶����Ӧ�ñ�ʶ�淶����GM/T 0006-2012����һ�£�����Ϊ0x00020800��
// �Ӵ��㷨��ʶ
#define	SGD_SM3							0x00000001	// SM3�Ӵ��㷨
#define SGD_SHA1						0x00000002	// SHA_1�Ӵ��㷨
#define SGD_SHA256						0x00000004	// SHA_256�Ӵ��㷨
// ǩ���㷨��ʶ
#define SGD_SM3_RSA						0x00001001	// ����SM3�㷨��RSA�㷨��ǩ��
#define SGD_SHA1_RSA					0x00001002	// ����SHA_1�㷨��RSA�㷨��ǩ��
#define SGD_SHA256_RSA					0x00001004	// ����SHA_256�㷨��RSA�㷨��ǩ��
#define SGD_SM3_SM2						0x00020101	// ����SM3�㷨��SM2�㷨��ǩ��		// �롶����Ӧ�ñ�ʶ�淶����GM/T 0006-2012����һ�£�����Ϊ0x00020201��

// �ӿ�������ʶ
#define SGD_PROVIDER_CSP				0x00000001	// CSP�ӿ�
#define SGD_PROVIDER_PKCS11				0x00000001	// PKCS#11�ӿ�
#define SGD_PROVIDER_SDS				0x00000001	// ���������豸Ӧ�ýӿ�
#define SGD_KEYUSAGE_SIGN				0x00000001	// ǩ��/��֤����Կ��;
#define SGD_KEYUSAGE_KEYEXCHANGE		0x00000001	// ��/���ܵ���Կ��;
#define SGD_MODE_ECB					0x00000001	// ECBģʽ
#define SGD_MODE_CBC					0x00000001	// CBCģʽ
#define SGD_MODE_CFB					0x00000001	// CFBģʽ
#define SGD_MODE_OFB					0x00000001	// OFBģʽ
#define SGD_KEYINFO_DEV_GENERATE		0x00000001	// �豸����
#define SGD_KEYINFO_KEY					0x00000001	// �ⲿ����KEY
#define SGD_KEYINFO_IV					0x00000001	// �ⲿ����IV
#define SGD_KEYINFO_PASSWORD_DERIVE_KEY	0x00000001	// ͨ����������KEY

// ֤�������ʶ
// �롶����Ӧ�ñ�ʶ�淶����GM/T 0006-2012����һ�£�����Ϊ0x00020201��
#define SGD_GET_CERT_VERSION			0x00000001	// ֤��汾
#define SGD_GET_CERT_SERIAL				0x00000002	// ֤�����к�
#define SGD_GET_CERT_SIGNALG			0x00000003	// ֤��ǩ���㷨��ʶ
#define SGD_GET_CERT_ISSUER_C			0x00000004	// ֤��䷢�߹���(C)
#define SGD_GET_CERT_ISSUER_O			0x00000005	// ֤��䷢����֯��(O)
#define SGD_GET_CERT_ISSUER_OU			0x00000006	// ֤��䷢�߲�����(OU)
#define SGD_GET_CERT_ISSUER_S			0x00000007	// ֤��䷢�����ڵ�ʡ����������ֱϽ��(S)
#define SGD_GET_CERT_ISSUER_CN			0x00000008	// ֤��䷢��ͨ������(CN)
#define SGD_GET_CERT_ISSUER_L			0x00000009	// ֤��䷢�����ڵĳ��С�����(L)
#define SGD_GET_CERT_ISSUER_E			0x00000010	// ֤��䷢��Email
#define SGD_GET_CERT_NOTBEFORE			0x00000011	// ֤����Ч�ڣ���ʼ����
#define SGD_GET_CERT_AFTER				0x00000012	// ֤����Ч�ڣ���ֹ����
#define SGD_GET_CERT_SUBJECT_C			0x00000013	// ֤��ӵ���߹���(C)
#define SGD_GET_CERT_SUBJECT_O			0x00000014	// ֤��ӵ������֯��(O)
#define SGD_GET_CERT_SUBJECT_OU			0x00000015	// ֤��ӵ���߲�����(OU)
#define SGD_GET_CERT_SUBJECT_S			0x00000016	// ֤��ӵ�������ڵ�ʡ����������ֱϽ��(S)
#define SGD_GET_CERT_SUBJECT_CN			0x00000017	// ֤��ӵ����ͨ������(CN)
#define SGD_GET_CERT_SUBJECT_L			0x00000018	// ֤��ӵ�������ڵĳ��С�����(L)
#define SGD_GET_CERT_SUBJECT_E			0x00000019	// ֤��ӵ����Email
#define SGD_GET_CERT_ISSUER_DN			0x00000020	// ֤��䷢��DN
#define SGD_GET_CERT_SUBJECT_DN			0x00000021	// ֤��ӵ����DN
#define SGD_GET_CERT_DER_PUBKEY			0x00000022	// ֤�鹫Կ��Ϣ
#define SGD_GET_CERT_DER_EXTENSIONS		0x00000023	// ֤����չ����Ϣ
#define SGD_EXT_AUTHORITYKEYIDENTIFIER	0x00000024	// �䷢����Կ��ʶ��
#define SGD_EXT_SUBJECTKEYIDENTIFIER	0x00000025	// ֤���������Կ��ʶ��
#define SGD_EXT_KEYUSAGE				0x00000026	// ��Կ��;
#define SGD_EXT_PRIVATEKEYUSAGEPERIOD	0x00000027	// ˽Կ��Ч��
#define SGD_EXT_CERTIFICATEPOLICIES		0x00000028	// ֤�����
#define SGD_EXT_POLICYMAPPINGS			0x00000029	// ����ӳ��
#define SGD_EXT_BASICCONSTRAINTS		0x00000030	// ��������
#define SGD_EXT_POLICYCONSTRAINTS		0x00000031	// ��������
#define SGD_EXT_EXTKEYUSAGE				0x00000032	// ��չ��Կ��;
#define SGD_EXT_CRLDISTRIBUTIONPOINTS	0x00000033	// CRL������
#define SGD_EXT_NETSCAPE_CERT_TYPE		0x00000034	// netscape����
#define SGD_EXT_CERT_UNIQUEID			0x00000035	// ֤��ʵ��Ψһ��ʶ
#define SGD_EXT_IDENTIFYCARDNUMBER		0x00000036	// �������֤����
#define SGD_EXT_INURANCENUMBER			0x00000037	// ������ᱣ�պ�
#define SGD_EXT_ICREGISTRATIONNUMBER	0x00000038	// ��ҵ����ע���
#define SGD_EXT_ORGANIZATIONCODE		0x00000039	// ��ҵ��֯��������
#define SGD_EXT_TAXATIONNUMBER			0x00000040	// ��ҵ˰��Ǽ�֤��
#define SGD_MAX_NAME_SIZE				0x00000080	// ������󳤶�
#define SGD_MAX_COUNT					0x00000100	// �б���󳤶�
#define SGD_MAX_CONTAINER				0x00000800	// ��������

// ֤����չ����Ϣ
#define SGD_EXT_OBJ_AUTHORITYKEYIDENTIFIER	"2.5.29.35"	// �䷢����Կ��ʶ��
#define SGD_EXT_OBJ_SUBJECTKEYIDENTIFIER	"2.5.29.14"	// ֤���������Կ��ʶ��
#define SGD_EXT_OBJ_KEYUSAGE				"2.5.29.15"	// ��Կ��;
#define SGD_EXT_OBJ_PRIVATEKEYUSAGEPERIOD	"2.5.29.16"	// ˽Կ��Ч��
#define SGD_EXT_OBJ_CERTIFICATEPOLICIES		"2.5.29.32"	// ֤�����
#define SGD_EXT_OBJ_POLICYMAPPINGS			"2.5.29.33"	// ����ӳ��
#define SGD_EXT_OBJ_BASICCONSTRAINTS		"2.5.29.19"	// ��������
#define SGD_EXT_OBJ_POLICYCONSTRAINTS		"2.5.29.36"	// ��������
#define SGD_EXT_OBJ_EXTKEYUSAGE				"2.5.29.37"	// ��չ��Կ��;
#define SGD_EXT_OBJ_CRLDISTRIBUTIONPOINTS	"2.5.29.31"	// CRL������
#define SGD_EXT_OBJ_NETSCAPE_CERT_TYPE		"2.16.840.1.113730.1.1"	// netscape����
#define SGD_EXT_OBJ_AUTHORITYINFOACCESS		"1.3.6.1.5.5.7.1.1"		// �䷢������Ϣ����

#define SGD_EXT_OBJ_FJCA_CERTCODE			"1.2.156.112578.1"		// ����CA֤�����
#define SGD_EXT_OBJ_CERT_UNIQUEID			"1.2.86.21.1.1"			// ����ϵͳ֤��ʵ��Ψһ��ʶ

// ������������֤���ʽ�淶��2010.8��������֤���ʽ���꣨2006��
#define SGD_EXT_OBJ_IDENTIFYCARDNUMBER		"1.2.156.10260.4.1.1"	// ������ݱ�ʶ��
#define SGD_EXT_OBJ_INURANCENUMBER			"1.2.156.10260.4.1.2"	// ������ᱣ�պ�
#define SGD_EXT_OBJ_ICREGISTRATIONNUMBER	"1.2.156.10260.4.1.3"	// ��ҵ����ע���
#define SGD_EXT_OBJ_ORGANIZATIONCODE		"1.2.156.10260.4.1.4"	// ��ҵ��֯��������
#define SGD_EXT_OBJ_TAXATIONNUMBER			"1.2.156.10260.4.1.5"	// ��ҵ˰��
// ������������֤���ʽ�淶��2010.4��
#define SGD_EXT_OBJ_IDENTIFYCARDNUMBER_0	"1.2.156.11.7.1"		// �������֤����
#define SGD_EXT_OBJ_INURANCENUMBER_0		"1.2.156.11.7.2"		// ������ᱣ�պ�
#define SGD_EXT_OBJ_ICREGISTRATIONNUMBER_0	"1.2.156.11.7.4"		// ��ҵ����ע���
#define SGD_EXT_OBJ_ORGANIZATIONCODE_0		"1.2.156.11.7.3"		// ��ҵ��֯��������
#define SGD_EXT_OBJ_TAXATIONNUMBER_0		"1.2.156.11.7.5"		// ��ҵ˰��Ǽ�֤��

// ֤���Ӧ��Ϣ
#define CERT_SUBJECT					1			// �û���
#define CERT_UNIQUEID					2			// ֤��ʵ��Ψһ��ʶ
#define CERT_DEPT						3			// ����
#define CERT_ISSUE						4			// �䷢��DN
#define CERT_DEVICETYPE					8			// ֤���������
#define CERT_CATYPE						9			// CA����
#define CERT_KEYTYPE					10			// �û�֤����Կ����(˫֤��֤)
#define CERT_DEVICENAME					13			// �û�֤���������
#define CERT_DEVICEPROVIDER				14			// �û�֤������ṩ�߼�csp����
#define CERT_DEVICEAFFIX				15			// �û�֤����ʸ��ӿ�
#define CERT_SIGNPATH					16			// �û�ǩ��֤��·��
#define CERT_EXCHPATH					17			// �û�����֤��·��
#define CERT_SIGNPFXPATH				18			// �û�ǩ��P12֤��·��
#define CERT_EXCHPFXPATH				19			// �û�����P12֤��·��
#define CERT_UNIQUEIDOID				22			// �û�֤��UniqueID��OID

// �Զ��峣��
#define SGD_CURRENT_VERSION				0x00010001	// �汾�ŵĸ�ʽΪ��0xAAAABBBB������AAAAΪ���汾�ţ�BBBBΪ�ΰ汾��

#define SGD_SIZE_DATABLOCK				4096		// ÿ�β��������ݿ��С��4k
#define SGD_SIZE_CERT					4096		// ֤�鳤�ȣ�4k
#define SGD_SIZE_RSADATA				1024		// RSA���ݳ��ȣ�1024
#define SGD_SIZE_ASYMDATA				1024		// �ǶԳ����ݳ��ȣ�1024
#define SGD_SIZE_PINMIN					2			// ������С����
#define SGD_SIZE_PINMAX					16			// ������󳤶�
#define SGD_SIZE_SM3HASH				32			// SM3�Ӵճ���
#define SGD_SIZE_ECC					32			// ECC����
#define SGD_SIZE_ECC_64					64			// ECC��󳤶�

#define SGD_STR_SEPARATOR				"\r\n"				// DN�еķָ���
#define SGD_STR_SEPARATOR2				","					// DN�еķָ���2
#define SGD_STR_RETURN					"\r\n"				// �س�����
#define SGD_STR_ECCUSERID				"1234567812345678"	// user id

#define SGD_KEYUSAGE_SIGNATURE			1			// ��Կ�÷���ǩ��
#define SGD_KEYUSAGE_EXCHANGE			2			// ��Կ�÷�������

#define SGD_CSPNAME_MH					"Antaeus & Mingwah Aohan eKey RSA Cryptographic Provider v1.0"
#define SGD_CSPNAME_WQ					"Watchdata CSP v3.4 For FJCA"
#define SGD_CSPNAME_ZC					"NJA EKEY CSP V1.0"
#define SGD_CSPNAME_HB					"HENGBAO USB KEY CSP1.0.0 For FJCA"
#define SGD_CSPNAME_FT					"EnterSafe ePass3003 CSP For FJCA v1.0"
#define SGD_CSPNAME_HT					"HaiTai Cryptographic Service Provider For FJCA"
#define SGD_CSPNAME_MH_L				L"Antaeus & Mingwah Aohan eKey RSA Cryptographic Provider v1.0"
#define SGD_CSPNAME_WQ_L				L"Watchdata CSP v3.4 For FJCA"
#define SGD_CSPNAME_ZC_L				L"NJA EKEY CSP V1.0"
#define SGD_CSPNAME_HB_L				L"HENGBAO USB KEY CSP1.0.0 For FJCA"
#define SGD_CSPNAME_FT_L				L"EnterSafe ePass3003 CSP For FJCA v1.0"
#define SGD_CSPNAME_HT_L				L"HaiTai Cryptographic Service Provider For FJCA"

#define SGD_KEYTYPE_MH					1
#define SGD_KEYTYPE_WQ					2
#define SGD_KEYTYPE_ZC					3
#define SGD_KEYTYPE_HB					4
#define SGD_KEYTYPE_FT					5
#define SGD_KEYTYPE_HT					6
#define SGD_KEYTYPE_MH_STR				"����"
#define SGD_KEYTYPE_WQ_STR				"����"
#define SGD_KEYTYPE_ZC_STR				"�г�"
#define SGD_KEYTYPE_HB_STR				"�㱦"
#define SGD_KEYTYPE_FT_STR				"����"
#define SGD_KEYTYPE_HT_STR				"��̩"

// openssl key usage
#define X509v3_KU_DIGITAL_SIGNATURE	0x0080
#define X509v3_KU_NON_REPUDIATION	0x0040
#define X509v3_KU_KEY_ENCIPHERMENT	0x0020
#define X509v3_KU_DATA_ENCIPHERMENT	0x0010
#define X509v3_KU_KEY_AGREEMENT		0x0008
#define X509v3_KU_KEY_CERT_SIGN		0x0004
#define X509v3_KU_CRL_SIGN			0x0002
#define X509v3_KU_ENCIPHER_ONLY		0x0001
#define X509v3_KU_DECIPHER_ONLY		0x8000
#define X509v3_KU_UNDEF				0xffff

#endif
