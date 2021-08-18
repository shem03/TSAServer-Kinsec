/*************************************************************
 *				����ʡ���ְ�ȫ֤��������޹�˾				 * 
 *					 ����֤��ӿں���˵��					 * 
 *				   ���ò���ϵͳ:Windows���� 				 *
 *************************************************************/
#ifndef _FJCASCARDCERTFUNC_H_
#define _FJCASCARDCERTFUNC_H_

#ifndef FJCA_COMMON_DEFINE
#define FJCA_COMMON_DEFINE

/*
 *ǩ�������е�ժҪ�㷨
 */
//#define calg_md2	1
//#define calg_md4	2
#define calg_md5	3
#define calg_sha1	4
#define calg_sm3	5
#define calg_sha256 6

/*
 *�豸����
 */
#define DEVTYPE_MH	1				//����
#define DEVTYPE_WQ	2				//����
#define DEVTYPE_ZC	3				//�г�
#define DEVTYPE_HB	4				//�㱦
#define DEVTYPE_FT	5				//����
#define DEVTYPE_HT	6				//��̩

typedef HANDLE		DEVHANDLE;

/*
*�ٽ�ֵ����
*/
#define MAX_IV_LEN			32		//��ʼ����������󳤶�
#define MAX_FILE_NAME_LEN	32		//�ļ�����󳤶�
#define MAX_CONTAINER_NAME_LEN	128 //��������󳤶�

/*
 *�㷨��ʶ��
 */
#define SGD_SM1_ECB 	0x00000101	//SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC 	0x00000102	//SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB 	0x00000104	//SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB 	0x00000108	//SM1�㷨OFB����ģʽ
#define SGD_SM1_MAC 	0x00000110	//SM1�㷨MAC����
#define SGD_SSF33_ECB	0x00000201	//SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC	0x00000202	//SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB	0x00000204	//SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB	0x00000208	//SSF33�㷨OFB����ģʽ
#define SGD_SSF33_MAC	0x00000210	//SSF33�㷨MAC����
#define SGD_SMS4_ECB	0x00000401	//SMS4�㷨ECB����ģʽ
#define SGD_SMS4_CBC	0x00000402	//SMS4�㷨CBC����ģʽ
#define SGD_SMS4_CFB	0x00000404	//SMS4�㷨CFB����ģʽ
#define SGD_SMS4_OFB	0x00000408	//SMS4�㷨OFB����ģʽ
#define SGD_SMS4_MAC	0x00000410	//SMS4�㷨MAC����
/*	0x00000400-0x800000xx	Ϊ�������������㷨Ԥ��	*/

#define SGD_RSA 		0x00010000	//RSA�㷨
#define SGD_SM2_1		0x00020100	//��Բ����ǩ���㷨
#define SGD_SM2_2		0x00020200	//��Բ������Կ����Э��
#define SGD_SM2_3		0x00020400	//��Բ���߼����㷨
/*	0x00000400��0x800000xx	Ϊ�����ǶԳ������㷨Ԥ��	*/

#define SGD_SM3 		0x00000001	//SM3�Ӵ��㷨
#define SGD_SHA1		0x00000002	//SHA1�Ӵ��㷨
#define SGD_SHA256		0x00000004	//SHA256�Ӵ��㷨
/*	0x00000010��0x000000FF	Ϊ���������Ӵ��㷨Ԥ��	*/

/*
 *Ȩ������
 */
#define SECURE_NEVER_ACCOUNT	0x00000000		//������
#define SECURE_ADM_ACCOUNT		0x00000001		//����ԱȨ��
#define SECURE_USER_ACCOUNT 	0x00000010		//�û�Ȩ��
#define SECURE_EVERYONE_ACCOUNT 0x000000FF		//�κ���

#pragma pack(1)

/*
 *�����������
 */
typedef struct Struct_BLOCKCIPHERPARAM{
	BYTE	IV[MAX_IV_LEN]; 		//��ʼ������MAX_IV_LENΪ��ʼ��������󳤶�
	ULONG	IVLen;					//��ʼ����ʵ�ʳ��ȣ����ֽڼ���
	ULONG	PaddingType;			//��䷽ʽ��0��ʾ����䣬1��ʾ����PKCS#5��ʽ�������
	ULONG	FeedBitLen; 			//����ֵ��λ���ȣ����ֽڼ��㣬ֻ���OFB��CFBģʽ
} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

/*
 *�ļ�����
 */
typedef struct Struct_FILEATTRIBUTE{
	CHAR	FileName[32];			//�ļ���
	ULONG	FileSize;				//�ļ���С
	ULONG	ReadRights; 			//��Ȩ��
	ULONG	WriteRights;			//дȨ��
} FILEATTRIBUTE, *PFILEATTRIBUTE;

#pragma pack()

#endif

#ifdef __cplusplus
extern "C"{
#endif

/************************************************************************/
/*	1. �豸���� 														*/
/*	FJCA_SCardGetDevStateX												*/
/*	FJCA_SCardGetDevState												*/
/*	FJCA_InitSCard														*/
/*	FJCA_GetKeyType														*/
/*	FJCA_GetDevType														*/
/*	FJCA_ExitSCard														*/
/*	FJCA_SCardGetDeviceInfo 											*/
/*	FJCA_SCardGetRandom 												*/
/************************************************************************/

/*
 *	����ָ���豸��״ֵ̬��
 *	nDevType			�豸����
 *	pbState 			�豸״ֵ̬
 *	��ע��
		��ÿ�����͵��豸�������Key��ţ������ţ���0��ʼ�������ӡ�
		�²����Keyʹ�ÿ�����š���û�п�����ţ���ʹ���µ���š�
		����Key���γ�������ſ��С�
		��Keyδ�γ��������ʼ�ձ��ֲ��䡣
		�������£�
		��������Key���������Ϊ0��1��2���ú�������ʱ��
			pbState[0] = 0x31;
			pbState[1] = 0x31;
			pbState[2] = 0x31;
			pbState[3] = 0x0;
			pbState[4] = 0x0;
			pbState[5] = 0x0;
			pbState[6] = 0x0;
			pbState[7] = 0x0;
		�²���һ��Key���������Ϊ3���ú�������ʱ��
			pbState[0] = 0x31;
			pbState[1] = 0x31;
			pbState[2] = 0x31;
			pbState[3] = 0x31;
			pbState[4] = 0x0;
			pbState[5] = 0x0;
			pbState[6] = 0x0;
			pbState[7] = 0x0;
		�γ��ڶ�������Key�����Ϊ1��2�����ú�������ʱ��
			pbState[0] = 0x31;
			pbState[1] = 0x0;
			pbState[2] = 0x0;
			pbState[3] = 0x31;
			pbState[4] = 0x0;
			pbState[5] = 0x0;
			pbState[6] = 0x0;
			pbState[7] = 0x0;
		�²���һ��Key���������Ϊ1���ú�������ʱ��
			pbState[0] = 0x31;
			pbState[1] = 0x31;
			pbState[2] = 0x0;
			pbState[3] = 0x31;
			pbState[4] = 0x0;
			pbState[5] = 0x0;
			pbState[6] = 0x0;
			pbState[7] = 0x0;
  */
BOOL FJCA_SCardGetDevStateX(
	IN int				nDevType,
	OUT BYTE			*pbState
	);

/*
 *	���������豸��״ֵ̬��
 *	byState 			�豸״ֵ̬
 *	pbState 			�豸״ֵ̬
 *	��ע��
		byStateΪ��ά���飬�����ÿһ�б�ʾһ���豸��״̬���磺
			byState[0]Ϊ������״̬
			byState[1]Ϊ�����״̬
			�Դ����ơ�
		pbStateΪһά���飺
			pbState[0]��pbState[7]Ϊ������״̬
			pbState[8]��pbState[15]Ϊ�����״̬
			�Դ����ơ�
 */
BOOL FJCA_SCardGetDevState(
	OUT BYTE			byState[][8]
	);
BOOL FJCA_SCardGetDevState2(
	OUT BYTE			*pbState
	);

/*
 *	�����豸�������豸�ľ����
 *	nDevType			�豸����
 *	szDevName			����USB��д����Key��ָ��Ҫ�򿪵����ܿ���д�豸
						szDevNameΪUSB1��USB2 ...
						USBX��XΪKey��ż�1���Ȳ�����豸ΪUSB1��������ΪUSB2
 *	phDev				�����豸�������
 *	��ע��				��nDevTypeʹ��ȱʡ���������豸����˳������������...������Ѱ���豸���������ҵ��ĵ�һ���豸��
 */
BOOL FJCA_InitSCard(
	IN int				nDevType = 0,
	IN char 			*szDevName = "USB1",
	OUT HANDLE			*phDev = NULL
	);

/*
 *	��ȡ�豸���͡�
 *	hDev				�����豸ʱ���ص��豸���
 */
int FJCA_GetKeyType(
	IN HANDLE			hDev = NULL
	);

int FJCA_GetDevType(
	IN HANDLE			hDev = NULL
	);

/*
 *	�Ͽ�һ���Ѿ����ӵ��豸�����ͷž����
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_ExitSCard(
	IN HANDLE			hDev = NULL
	);

/*
 *	ȡ�豸��Ϣ��
 *	szDeviceInfo		�豸����ϸ��Ϣ�����ޣ��ɷ��ؿմ�
 *	szVID				Vender ID�������̱�ţ�����4�ֽڡ��磺"D6A3"
 *	szPID				Product ID������Ʒ��ţ�����4�ֽڡ��磺"2599"
 *	szSN				Serial Number������ƷΨһ���кš��磺"03081612130000001895"
 *	szPD				Produce Date�����������ڣ�����8�ֽڡ��磺"20061213"
 *	szPI				������Ϣ�����ޣ��ɷ��ؿմ�
 *	szAF				Ԥ�������ޣ��ɷ��ؿմ�
 *	szLabel 			��ǩ
 *	pdwTotalSpace		�豸�洢�ռ�
 *	pdwFreeSpace		�豸ʣ��ռ�
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���صĸ����ַ�����������ֻ�����ɴ�ӡ�ַ���
						����Ӧ��֤����ÿ��Key��pszVID��pszPID��pszSN��3���������Ľ����Ψһ�ġ�
 */
BOOL FJCA_SCardGetDeviceInfo(
	OUT char			*szDeviceInfo,
	OUT char			*szVID,
	OUT char			*szPID,
	OUT char			*szSN,
	OUT char			*szPD,
	OUT char			*szPI,
	OUT char			*szAF,
	OUT char			*szLabel,
	OUT DWORD			*pdwTotalSpace,
	OUT DWORD			*pdwFreeSpace,
	IN HANDLE			hDev = NULL
	);

/*
 *	�����������
 *	dwRandomDataLen 	������ĳ���
 *	pbRandomData		�����
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardGetRandom(
	IN DWORD			dwRandomDataLen,
	OUT BYTE			*pbRandomData,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	2. ���ʿ��� 														*/
/*	FJCA_SCardInitKey													*/
/*	FJCA_SCardVerifyUserPin 											*/
/*	FJCA_SCardVerifyAdminPin											*/
/*	FJCA_SCardChangeUserPin 											*/
/*	FJCA_SCardChangeAdminPin											*/
/*	FJCA_SCardUnlockPin 												*/
/*	FJCA_GetPinTimes	 												*/
/************************************************************************/

/*
 *	��ʼ��Key��
 *	pbUserPin				�û�����
 *	byUserPinLen			�û�����ĳ���
 *	dwUserPinMaxRetryCount	�û�����������Դ���
 *	pbAdminPin				����Ա����
 *	byAdminPinLen			����Ա����ĳ���
 *	dwAdminPinMaxRetryCount ����Ա����������Դ���
 *	hDev					�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardInitKey(
	IN BYTE 				*pbUserPin,
	IN BYTE 				byUserPinLen,
	IN DWORD				dwUserPinMaxRetryCount,
	IN BYTE 				*pbAdminPin,
	IN BYTE 				byAdminPinLen,
	IN DWORD				dwAdminPinMaxRetryCount,
	IN HANDLE				hDev = NULL
	);

/*
 *	�˶��û����
 *	pbUserPin			�û�����
 *	byUserPinLen		�û�����ĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				��У�����ʧ�ܣ����ں�������ǰ����SetLastError���ô����룺
							0x6983		Key�ѱ�����
							0x63CX		XΪKey����ɳ��Դ���
 */
BOOL FJCA_SCardVerifyUserPin(
	IN BYTE 			*pbUserPin,
	IN BYTE 			byUserPinLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�˶Թ���Ա���
 *	pbAdminPin			����Ա����
 *	byAdminPinLen		����Ա����ĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				��У�����ʧ�ܣ����ں�������ǰ����SetLastError���ô����룺
							0x6983		Key�ѱ�����
							0x63CX		XΪKey����ɳ��Դ���
 */
BOOL FJCA_SCardVerifyAdminPin(
	IN BYTE 			*pbAdminPin,
	IN BYTE 			byAdminPinLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�˶Բ��޸��û����
 *	pbOldUserPin		���û�����
 *	byOldUserPinLen 	���û�����ĳ���
 *	pbNewUserPin		���û�����
 *	byNewUserPinLen 	���û�����ĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				��У�����ʧ�ܣ����ں�������ǰ����SetLastError���ô����룺
							0x6983		Key�ѱ�����
							0x63CX		XΪKey����ɳ��Դ���
 */
BOOL FJCA_SCardChangeUserPin(
	IN BYTE 			*pbOldUserPin,
	IN BYTE 			byOldUserPinLen,
	IN BYTE 			*pbNewUserPin,
	IN BYTE 			byNewUserPinLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�˶Բ��޸Ĺ���Ա���
 *	pbOldAdminPin		�ɹ���Ա����
 *	byOldAdminPinLen	�ɹ���Ա����ĳ���
 *	pbNewAdminPin		�¹���Ա����
 *	byNewAdminPinLen	�¹���Ա����ĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				��У�����ʧ�ܣ����ں�������ǰ����SetLastError���ô����룺
							0x6983		Key�ѱ�����
							0x63CX		XΪKey����ɳ��Դ���
 */
BOOL FJCA_SCardChangeAdminPin(
	IN BYTE 			*pbOldAdminPin,
	IN BYTE 			byOldAdminPinLen,
	IN BYTE 			*pbNewAdminPin,
	IN BYTE 			byNewAdminPinLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	���û�����������ͨ�����øú����������û����
	�������û�������ó���ֵ���û���������Դ���Ҳ�ָ���ԭֵ��
 *	pbAdminPin			����Ա����
 *	byAdminPinLen		����Ա����ĳ���
 *	pbNewUserPin		���û�����
 *	byNewUserPinLen 	���û�����ĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				��У�����ʧ�ܣ����ں�������ǰ����SetLastError���ô����룺
							0x6983		Key�ѱ�����
							0x63CX		XΪKey����ɳ��Դ���
 */
BOOL FJCA_SCardUnlockPin(
	IN BYTE 			*pbAdminPin,
	IN BYTE 			byAdminPinLen,
	IN BYTE 			*pbNewUserPin,
	IN BYTE 			byNewUserPinLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	���Ͽ�����غ�������ʧ��ʱ����ȡ����ɳ��Դ�����
 *	pbPinTimes			����ɳ��Դ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_GetPinTimes(
	OUT BYTE			*pbPinTimes,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	3. �ļ����� 														*/
/*	FJCA_SCardCreateFile												*/
/*	FJCA_SCardDeleteFile												*/
/*	FJCA_SCardEnumFiles 												*/
/*	FJCA_SCardGetFileInfo												*/
/*	FJCA_SCardReadFile													*/
/*	FJCA_SCardWriteFile 												*/
/************************************************************************/

/*
 *	����һ���ļ���
 *	szFileName			�ļ����ƣ����Ȳ��ô���32���ֽ�
 *	ulFileSize			�ļ���С
 *	ulReadRights		�ļ���Ȩ��
 *	ulWriteRights		�ļ�дȨ��
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardCreateFile(
	IN CHAR 			*szFileName,
	IN ULONG			ulFileSize,
	IN ULONG			ulReadRights,
	IN ULONG			ulWriteRights,
	IN HANDLE			hDev = NULL
	);

/*
 *	ɾ��ָ���ļ����ļ�ɾ�����ļ���д���������Ϣ����ʧ���ļ����豸�е�ռ�õĿռ佫���ͷš�
 *	szFileName			Ҫɾ���ļ�������
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDeleteFile(
	IN CHAR 			*szFileName,
	IN HANDLE			hDev = NULL
	);

/*
 *	ö�������ļ���
 *	szFileList			�����ļ������б�
						ÿ���ļ������Ե���'\0'��������˫'\0'��ʾ�б�Ľ���
 *	pulSize 			����Ϊ���ݻ������ĳ��ȣ����Ϊʵ���ļ����Ƶĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardEnumFiles(
	OUT CHAR			*szFileList,
	IN OUT ULONG		*pulSize,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ȡ�ļ���������Ϣ�������ļ��Ĵ�С��Ȩ�޵ȡ�
 *	szFileName			�ļ�����
 *	pFileInfo			�ļ���Ϣ��ָ���ļ����Խṹ��ָ��
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardGetFileInfo(
	IN CHAR 			*szFileName,
	OUT FILEATTRIBUTE	*pFileInfo,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ȡ�ļ����ݡ�
 *	szFileName			�ļ���
 *	ulOffset			��ȡ�ļ���ƫ��λ��
 *	ulSize				Ҫ��ȡ�ĳ���
 *	pbData				��ȡ����
 *	pulDataLen			����Ϊ���ݻ������ĳ��ȣ����Ϊʵ�ʶ�ȡ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardReadFile(
	IN CHAR 			*szFileName,
	IN ULONG			ulOffset,
	IN ULONG			ulSize,
	OUT BYTE			*pbData,
	IN OUT ULONG		*pulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	д���ݵ��ļ��С�
 *	szFileName			�ļ���
 *	ulOffset			д���ļ���ƫ����
 *	pbData				д������
 *	ulSize				д�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardWriteFile(
	IN CHAR 			*szFileName,
	IN ULONG			ulOffset,
	IN BYTE 			*pbData,
	IN ULONG			ulSize,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	4. ֤����� 														*/
/*	FJCA_SCardGetCertNo 												*/
/*	FJCA_SCardSetCertNo 												*/
/*	FJCA_SCardReadCert													*/
/*	FJCA_SCardWriteCert 												*/
/*	FJCA_SCardGetContainerName											*/
/*	FJCA_SCardSetupIECert												*/
/************************************************************************/

/*
 *	���ؿ��ڴ�ŵ�֤��״̬:
		0				������֤��
		1				���ڴ��ڵ�һ��֤�� 
		2				���ڴ��ڵڶ���֤��	 
		3				���ڴ��ڶ���֤��
 *	pbCertNo			֤��״̬
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardGetCertNo(
	OUT BYTE			*pbCertNo,
	IN HANDLE			hDev = NULL
	);

/*
 *	ѡ��ǰ������֤�飬����Ϊ��һ��֤�顣
 *	byCertNo			֤��ţ�1-2��
						��Key�ڴ��˫֤��ʱ����һ��֤��Ϊǩ��֤�飬�ڶ���֤��Ϊ����֤�顣
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardSetCertNo(
	IN BYTE 			byCertNo,
	IN HANDLE			hDev = NULL
	);

/*
 *	�����ܿ���Key�ж�ȡ��ǰ֤�飨DER���룩��
 *	pbCert				֤������
 *	pdwCertLen			����Ϊ֤�����ݻ������ĳ��ȣ����Ϊʵ��֤�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardReadCert(
	OUT BYTE			*pbCert,
	IN OUT DWORD		*pdwCertLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��DER�����֤��д�����ܿ���Key�С�
 *	pbCert				֤������
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardWriteCert(
	IN BYTE 			*pbCert,
	IN HANDLE			hDev = NULL
	);

/*
 *	ȡ��ǰ֤���������������ơ�
 *	szContainerName 	֤����������
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardGetContainerName(
	OUT char			*szContainerName,
	IN HANDLE			hDev = NULL
	);

/*
 *	����Key����ʱ�������������ʾ�û�������������У��ɹ���Key��֤���Զ�ע�ᵽIE��
 *	����Key�γ�ʱ��Key��֤���IE��ɾ����
 *	nDevType			�豸����
 *	pnKeyStatus 		Key��״̬
 *	pnKeyIndex			Key����ţ���0��ʼ
 *	pbOperation 		�Ƿ���֤�����
 *	pszPin				�û�����Ŀ���
 *	��ע��
 *		��������WM_DEVICECHANGE��Ϣ�������е���FJCA_SCardSetupIECert��
 *		�����εĲ��Ǳ�����Key��*pnKeyStatus = 0
 *		����б�����Key���룬*pnKeyStatus = 1��*pnKeyIndex���Key����š�
 *			����û�֤�鱻����IE��*pbOperation = TRUE, pszPin����û�����Ŀ��
 *		����б�����Key�γ���*pnKeyStatus = 2��*pnKeyIndex���Key����š�
 *			����û�֤���IE��ɾ����*pbOperation = TRUE��
 */
BOOL FJCA_SCardSetupIECert(
	IN int				nDevType,
	OUT int 			*pnKeyStatus,
	OUT int 			*pnKeyIndex,
	OUT BOOL			*pbOperation,
	OUT char			*pszPin
	);

/************************************************************************/
/*	5. RSA����															*/
/*	FJCA_SCardGenRSAKey 												*/
/*	FJCA_SCardGetPubKey 												*/
/*	FJCA_SCardImportRSAKey												*/
/*	FJCA_SCardSign														*/
/*	FJCA_SCardSignDigest												*/
/*	FJCA_SCardVerifyDigest												*/
/*	FJCA_SCardRSAEncrypt												*/
/*	FJCA_SCardRSADecrypt												*/
/************************************************************************/

/*
 *	����RSA��Կ�ԣ��������Կ��DER���룩��
 *	pbPubKey			��Կ����
 *	pdwPubKeyLen		����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardGenRSAKey(
	OUT BYTE			*pbPubKey,
	IN OUT DWORD		*pdwPubKeyLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��RSA��Կ���ݣ�DER���룩��
 *	pbPubKey			��Կ����
 *	pdwPubKeyLen		����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardGetPubKey(
	OUT BYTE			*pbPubKey,
	IN OUT DWORD		*pdwPubKeyLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	����RSA����˽Կ��
 *	pbPriKey			ʹ�öԳ���Կ������RSA����˽Կ
 *	dwPriKeyLen 		ʹ�öԳ���Կ������RSA����˽Կ�ĳ���
 *	pbSymmKey			ʹ��ǩ����Կ�����ĶԳ���Կ
 *	dwSymmKeyLen		ʹ��ǩ����Կ�����ĶԳ���Կ�ĳ���
 *	dwSymmAlgID 		�Գ��㷨
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardImportRSAKey(
	IN BYTE 			*pbPriKey,
	IN DWORD			dwPriKeyLen,
	IN BYTE 			*pbSymmKey,
	IN DWORD			dwSymmKeyLen,
	IN DWORD			dwSymmAlgID,
	IN HANDLE			hDev = NULL
	);

/*
 *	��RSA˽Կ�����ݽ��м��ܡ�
 *	pbData				����������
 *	dwDataLen			���������ݵĳ���
 *	pbSignedData		��������
 *	pdwSignedDataLen	����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardSign(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	OUT BYTE			*pbSignedData,
	IN OUT DWORD		*pdwSignedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��RSA˽Կ�����ݽ���ǩ����
 *	pbData				��ǩ������
 *	dwDataLen			��ǩ�����ݵĳ���
 *	byHashAlgID 		ժҪ�㷨
 *	pbSignedData		ǩ������
 *	pdwSignedDataLen	����Ϊǩ�����ݻ������ĳ��ȣ����Ϊʵ��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardSignDigest(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN BYTE 			byHashAlgID,
	OUT BYTE			*pbSignedData,
	IN OUT DWORD		*pdwSignedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��֤RSA����ǩ����
 *	pbSignedData		ǩ������
 *	dwSignedDataLen 	ǩ�����ݵĳ���
 *	byHashAlgID 		ժҪ�㷨
 *	pbData				��ǩ������
 *	dwDataLen			��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardVerifyDigest(
	IN BYTE 			*pbSignedData,
	IN DWORD			dwSignedDataLen,
	IN BYTE 			byHashAlgID,
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	RSA���ݼ��ܡ�
 *	pbData				����������
 *	dwDataLen			���������ݵĳ���
 *	pbEncryptedData 	��������
 *	pdwEncryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardRSAEncrypt(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	OUT BYTE			*pbEncryptedData,
	IN OUT DWORD		*pdwEncryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��RSA˽Կ�����ݽ��н��ܡ�
 *	pbEncryptedData 	�Ѽ�������
 *	dwEncryptedDataLen	�Ѽ������ݵĳ���
 *	pbDecryptedData 	��������
 *	pdwDecryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʽ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardRSADecrypt(
	IN BYTE 			*pbEncryptedData,
	IN DWORD			dwEncryptedDataLen,
	OUT BYTE			*pbDecryptedData,
	IN OUT DWORD		*pdwDecryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	6. ���������㷨���� 												*/
/*	FJCA_SCardSetSymmKey												*/
/*	FJCA_SCardEncryptInit												*/
/*	FJCA_SCardEncrypt													*/
/*	FJCA_SCardEncryptUpdate 											*/
/*	FJCA_SCardEncryptFinal												*/
/*	FJCA_SCardDecryptInit												*/
/*	FJCA_SCardDecrypt													*/
/*	FJCA_SCardDecryptUpdate 											*/
/*	FJCA_SCardDecryptFinal												*/
/*	FJCA_SCardCloseHandle												*/
/************************************************************************/

/*
 *	�������ĶԳ���Կ��������Կ�����
 *	pbKey				�Ự��Կֵ
 *	ulAlgID 			�Ự��Կ���㷨��ʶ
 *	phKey				���ػỰ��Կ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardSetSymmKey(
	IN BYTE 			*pbKey,
	IN ULONG			ulAlgID,
	OUT HANDLE			*phKey,
	IN HANDLE			hDev = NULL
	);

/*
 *	���ݼ��ܳ�ʼ�����������ݼ��ܵ��㷨��ز�����
 *	hKey				������Կ���
 *	EncryptParam		���������㷨��ز���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardEncryptInit(
	IN HANDLE			hKey,
	IN BLOCKCIPHERPARAM EncryptParam,
	IN HANDLE			hDev = NULL
	);

/*
 *	��һ�������ݵļ��ܲ�����
	��ָ��������Կ��ָ�����ݽ��м��ܣ������ܵ�����ֻ����һ�����飬���ܺ�����ı��浽ָ���Ļ������С�
	SKF_Encryptֻ�Ե����������ݽ��м��ܡ�
	�ڵ���SKF_Encrypt֮ǰ���������SKF_EncryptInit��ʼ�����ܲ�����
	SKF_Encypt�ȼ����ȵ���SKF_EncryptUpdate�ٵ���SKF_EncryptFinal��
 *	hKey				������Կ���
 *	pbData				����������
 *	ulDataLen			���������ݳ���
 *	pbEncryptedData 	��������
 *	pulEncryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardEncrypt(
	IN HANDLE			hKey,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	OUT BYTE			*pbEncryptedData,
	IN OUT ULONG		*pulEncryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	����������ݵļ��ܲ�����
	��ָ��������Կ��ָ�����ݽ��м��ܣ������ܵ����ݰ���������飬���ܺ�����ı��浽ָ���Ļ������С�
	SKF_EncryptUpdate�Զ���������ݽ��м��ܡ�
	�ڵ���SKF_EncryptUpdate֮ǰ���������SKF_EncryptInit��ʼ�����ܲ�����
	�ڵ���SKF_EncryptUpdate֮�󣬱������SKF_EncryptFinal�������ܲ�����
 *	hKey				������Կ���
 *	pbData				����������
 *	ulDataLen			���������ݳ���
 *	pbEncryptedData 	��������
 *	pulEncryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardEncryptUpdate(
	IN HANDLE			hKey,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	OUT BYTE			*pbEncryptedData,
	IN OUT ULONG		*pulEncryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��������������ݵļ��ܣ�����ʣ����ܽ����
	�ȵ���SKF_EncryptInit��ʼ�����ܲ�����
	�ٵ���SKF_EncryptUpdate�Զ���������ݽ��м��ܣ�
	������SKF_EncryptFinal��������������ݵļ��ܡ�
 *	hKey				������Կ���
 *	pbData				����������
 *	ulDataLen			���������ݳ���
 *	pbEncryptedData 	��������
 *	pulEncryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardEncryptFinal(
	IN HANDLE			hKey,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	OUT BYTE			*pbEncryptedData,
	IN OUT ULONG		*pulEncryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	���ݽ��ܳ�ʼ�������ý�����Կ��ز�����
	����SKF_DecryptInit֮�󣬿��Ե���SKF_Decrypt�Ե����������ݽ��н��ܣ�
	Ҳ���Զ�ε���SKF_DecryptUpdate֮���ٵ���SKF_DecryptFinal��ɶԶ���������ݵĽ��ܡ�
 *	hKey				������Կ���
 *	DecryptParam		���������㷨��ز���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDecryptInit(
	IN HANDLE			hKey,
	IN BLOCKCIPHERPARAM DecryptParam,
	IN HANDLE			hDev = NULL
	);

/*
 *	�����������ݵĽ��ܲ�����
	��ָ��������Կ��ָ�����ݽ��н��ܣ������ܵ�����ֻ����һ�����飬���ܺ�����ı��浽ָ���Ļ������С�
	SKF_Decryptֻ�Ե����������ݽ��н��ܡ�
	�ڵ���SKF_Decrypt֮ǰ���������SKF_DecryptInit��ʼ�����ܲ�����
	SKF_Decypt�ȼ����ȵ���SKF_DecryptUpdate�ٵ���SKF_DecryptFinal��
 *	hKey				������Կ���
 *	pbEncryptedData 	����������
 *	ulEncryptedDataLen	���������ݳ���
 *	pbData				��������
 *	pulDataLen			����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʽ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDecrypt(
	IN HANDLE			hKey,
	IN BYTE 			*pbEncryptedData,
	IN ULONG			ulEncryptedDataLen,
	OUT BYTE			*pbData,
	IN OUT ULONG		*pulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	����������ݵĽ��ܲ�����
	��ָ��������Կ��ָ�����ݽ��н��ܣ������ܵ����ݰ���������飬���ܺ�����ı��浽ָ���Ļ������С�
	SKF_DecryptUpdate�Զ���������ݽ��н��ܡ�
	�ڵ���SKF_DecryptUpdate֮ǰ���������SKF_DecryptInit��ʼ�����ܲ�����
	�ڵ���SKF_DecryptUpdate֮�󣬱������SKF_DecryptFinal�������ܲ�����
 *	hKey				������Կ���
 *	pbEncryptedData 	����������
 *	ulEncryptedDataLen	���������ݳ���
 *	pbData				��������
 *	pulDataLen			����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʽ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDecryptUpdate(
	IN HANDLE			hKey,
	IN BYTE 			*pbEncryptedData,
	IN ULONG			ulEncryptedDataLen,
	OUT BYTE			*pbData,
	IN OUT ULONG		*pulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��������������ݵĽ��ܡ�
 *	hKey				������Կ���
 *	pbEncryptedData 	����������
 *	ulEncryptedDataLen	���������ݳ���
 *	pbData				��������
 *	pulDataLen			����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʽ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDecryptFinal(
	IN HANDLE			hKey,
	IN BYTE 			*pbEncryptedData,
	IN ULONG			ulEncryptedDataLen,
	OUT BYTE			*pbData,
	IN OUT ULONG		*pulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�رջỰ��Կ���Ӵա���Ϣ��֤������
 *	hHandle 			Ҫ�رյĶ�����
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardCloseHandle(
	IN HANDLE			hHandle,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	7. �Ӵա���Ϣ��֤������ 											*/
/*	FJCA_SCardDigestInit												*/
/*	FJCA_SCardDigest													*/
/*	FJCA_SCardDigestUpdate												*/
/*	FJCA_SCardDigestFinal												*/
/*	FJCA_SCardMacInit													*/
/*	FJCA_SCardMac														*/
/*	FJCA_SCardMacUpdate 												*/
/*	FJCA_SCardMacFinal													*/
/************************************************************************/

/*
 *	��ʼ����Ϣ�Ӵռ��������ָ��������Ϣ�Ӵյ��㷨��
 *	ulAlgID 			�Ӵ��㷨��ʶ
 *	phHash				�Ӵն�����
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDigestInit(
	IN ULONG			ulAlgID,
	OUT HANDLE			*phHash,
	IN HANDLE			hDev = NULL
	);

/*
 *	�Ե�һ�������Ϣ�����Ӵռ��㡣
 *	hHash				�Ӵն�����
 *	pbData				��Ϣ����
 *	ulDataLen			��Ϣ���ݵĳ���
 *	pbHashData			�Ӵ�����
 *	pulHashLen			����Ϊ�Ӵ����ݻ������ĳ��ȣ����Ϊʵ���Ӵ����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDigest(
	IN HANDLE			hHash,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	OUT BYTE			*pbHashData,
	IN OUT ULONG		*pulHashLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�Զ���������Ϣ�����Ӵռ��㡣
 *	hHash				�Ӵն�����
 *	pbData				��Ϣ����
 *	ulDataLen			��Ϣ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDigestUpdate(
	IN HANDLE			hHash,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�������������Ϣ���Ӵռ�����������Ӵձ��浽ָ���Ļ�������
 *	hHash				�Ӵն�����
 *	pHashData			�Ӵ�����
 *	pulHashLen			����Ϊ�Ӵ����ݻ������ĳ��ȣ����Ϊʵ���Ӵ����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardDigestFinal(
	IN HANDLE			hHash,
	OUT BYTE			*pHashData,
	IN OUT ULONG		*pulHashLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ʼ����Ϣ��֤�������������ü�����Ϣ��֤�����Կ��������������Ϣ��֤������
 *	hKey				������Ϣ��֤�����Կ���
 *	MacParam			��Ϣ��֤������ز�����������ʼ��������ʼ�������ȡ���䷽����
 *	phMac				��Ϣ��֤�������
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardMacInit(
	IN HANDLE			hKey,
	IN BLOCKCIPHERPARAM *MacParam,
	OUT HANDLE			*phMac,
	IN HANDLE			hDev = NULL
	);

/*
 *	���㵥һ�������ݵ���Ϣ��֤�롣
 *	hMac				��Ϣ��֤����
 *	pbData				����������
 *	ulDataLen			���������ݵĳ���
 *	pbMacData			Mac����
 *	pulMacLen			����ΪMac���ݻ������ĳ��ȣ����Ϊʵ��Mac���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardMac(
	IN HANDLE			hMac,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	OUT BYTE			*pbMacData,
	IN OUT ULONG		*pulMacLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	�������������ݵ���Ϣ��֤�롣
 *	hMac				��Ϣ��֤����
 *	pbData				����������
 *	plDataLen			���������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardMacUpdate(
	IN HANDLE			hMac,
	IN BYTE 			*pbData,
	IN ULONG			ulDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��������������ݵ���Ϣ��֤����������
 *	hMac				��Ϣ��֤����
 *	pbMacData			Mac����
 *	pulMacLen			����ΪMac���ݻ������ĳ��ȣ����Ϊʵ��Mac���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardMacFinal(
	IN HANDLE			hMac,
	OUT BYTE			*pbMacData,
	IN OUT ULONG		*pulMacDataLen,
	IN HANDLE			hDev = NULL
	);

/************************************************************************/
/*	8. ECC֤�����														*/
/*	FJCA_SCardECCGetCertNo												*/
/*	FJCA_SCardECCSetCertNo												*/
/*	FJCA_SCardECCReadCert												*/
/*	FJCA_SCardECCWriteCert												*/
/*	FJCA_SCardECCGetContainerName										*/
/*	FJCA_SCardECCSetupIECert											*/
/************************************************************************/

/*
 *	���ؿ��ڴ�ŵ�֤��״̬:
		0				������֤��
		1				���ڴ��ڵ�һ��֤�� 
		2				���ڴ��ڵڶ���֤��	 
		3				���ڴ��ڶ���֤��
 *	pbCertNo			֤��״̬
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardECCGetCertNo(
	OUT BYTE			*pbCertNo,
	IN HANDLE			hDev = NULL
	);

/*
 *	ѡ��ǰ������֤�飬����Ϊ��һ��֤�顣
 *	byCertNo			֤��ţ�1-2��
						��Key�ڴ��˫֤��ʱ����һ��֤��Ϊǩ��֤�飬�ڶ���֤��Ϊ����֤�顣
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardECCSetCertNo(
	IN BYTE 			byCertNo,
	IN HANDLE			hDev = NULL
	);

/*
 *	�����ܿ���Key�ж�ȡ��ǰ֤�飨DER���룩��
 *	pbCert				֤������
 *	pdwCertLen			����Ϊ֤�����ݻ������ĳ��ȣ����Ϊʵ��֤�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCReadCert(
	OUT BYTE			*pbCert,
	IN OUT DWORD		*pdwCertLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��DER�����֤��д�����ܿ���Key�С�
 *	pbCert				֤������
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCWriteCert(
	IN BYTE 			*pbCert,
	IN HANDLE			hDev = NULL
	);

/*
 *	ȡ��ǰ֤���������������ơ�
 *	szContainerName 	֤����������
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCGetContainerName(
	OUT char			*szContainerName,
	IN HANDLE			hDev = NULL
	);

/*
 *	����Key����ʱ�������������ʾ�û�������������У��ɹ���Key��֤���Զ�ע�ᵽIE��
 *	����Key�γ�ʱ��Key��֤���IE��ɾ����
 *	nDevType			�豸����
 *	pnKeyStatus 		Key��״̬
 *	pnKeyIndex			Key����ţ���0��ʼ
 *	pbOperation 		�Ƿ���֤�����
 *	pszPin				�û�����Ŀ���
 *	��ע��
 *		��������WM_DEVICECHANGE��Ϣ�������е���FJCA_SCardECCSetupIECert��
 *		�����εĲ��Ǳ�����Key��*pnKeyStatus = 0
 *		����б�����Key���룬*pnKeyStatus = 1��*pnKeyIndex���Key����š�
 *			����û�֤�鱻����IE��*pbOperation = TRUE, pszPin����û�����Ŀ��
 *		����б�����Key�γ���*pnKeyStatus = 2��*pnKeyIndex���Key����š�
 *			����û�֤���IE��ɾ����*pbOperation = TRUE��
 */
BOOL FJCA_SCardECCSetupIECert(
	IN int				nDevType,
	OUT int 			*pnKeyStatus,
	OUT int 			*pnKeyIndex,
	OUT BOOL			*pbOperation,
	OUT char			*pszPin
	);

/************************************************************************/
/*	9. ECC����															*/
/*	FJCA_SCardECCGenKey 												*/
/*	FJCA_SCardECCGetPubKey												*/
/*	FJCA_SCardECCImportKey												*/
/*	FJCA_SCardECCSign													*/
/*	FJCA_SCardExtECCVerify												*/
/*	FJCA_SCardECCSignDigest 											*/
/*	FJCA_SCardExtECCVerifyDigest										*/
/*	FJCA_SCardExtECCEncrypt 											*/
/*	FJCA_SCardECCDecrypt												*/
/*	FJCA_SCardECCGetTempPubKey											*/
/*	FJCA_SCardECCKeyExchange											*/
/************************************************************************/
//	��ע��
//	x||y��x��y��ƴ��

/*
 *	����ECC��Կ�ԣ��������Կ��
 *	pbECCPubKey 		��Կ���ݣ���ʽ��x||y
 *	pdwECCPubKeyLen 	����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCGenKey(
	OUT BYTE			*pbECCPubKey,
	IN OUT DWORD		*pdwECCPubKeyLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ECC��Կ���ݡ�
 *	pbECCPubKey 		��Կ���ݣ���ʽ��x||y
 *	pdwECCPubKeyLen 	����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCGetPubKey(
	OUT BYTE			*pbECCPubKey,
	IN OUT DWORD		*pdwECCPubKeyLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	����ECC��Կ��
 *	pbEncryptKey		ʹ�öԳ���Կ������ECC���ܹ�˽Կ��
 *	dwEncryptKeyLen 	ʹ�öԳ���Կ������ECC���ܹ�˽Կ�Եĳ���
 *	pbSymmKey			ʹ��ǩ����Կ�����ĶԳ���Կ
 *	dwSymmKeyLen		ʹ��ǩ����Կ�����ĶԳ���Կ�ĳ���
 *	dwSymmAlgID 		�Գ��㷨
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardECCImportKey(
	IN BYTE 			*pbEncryptKey,
	IN DWORD			dwEncryptKeyLen,
	IN BYTE 			*pbSymmKey,
	IN DWORD			dwSymmKeyLen,
	IN DWORD			dwSymmAlgID,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ECC��Կ������ǩ����
 *	pbData				��ǩ�����ݣ�����Ϊ32�ֽ�
 *	dwDataLen			��ǩ�����ݵĳ���
 *	pbSignedData		ǩ�����ݣ���ʽ��r||s
 *	pdwSignedDataLen	����Ϊǩ�����ݻ������ĳ��ȣ����Ϊʵ��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCSign(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	OUT BYTE			*pbSignedData,
	IN OUT DWORD		*pdwSignedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ʹ���ⲿ�����ECC��Կ��ǩ����֤��
 *	pbSignedData		ǩ�����ݣ���ʽ��r||s
 *	dwSignedDataLen 	ǩ�����ݵĳ���
 *	pbECCPubKey 		��Կ���ݣ���ʽ��x||y
 *	dwECCPubKeyLen		��Կ���ݵĳ���
 *	pbData				��ǩ�����ݣ�����Ϊ32�ֽ�
 *	dwDataLen			��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardExtECCVerify(
	IN BYTE 			*pbSignedData,
	IN DWORD			dwSignedDataLen,
	IN BYTE 			*pbECCPubKey,
	IN DWORD			dwECCPubKeyLen,
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	��ECC��Կ������ǩ����
 *	pbData				��ǩ������
 *	dwDataLen			��ǩ�����ݵĳ���
 *	byHashAlgID 		ժҪ�㷨
						��byHashAlgIDΪSM3��dwUserIDLen��Ϊ0�������pbUserID��Ч
						��ʱִ��SM2�㷨ǩ��Ԥ����1��Ԥ����2����
 *	pbUserID			�û�ID
 *	dwUserIDLen 		�û�ID�ĳ���
 *	pbSignedData		ǩ�����ݣ���ʽ��r||s
 *	pdwSignedDataLen	����Ϊǩ�����ݻ������ĳ��ȣ����Ϊʵ��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCSignDigest(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN BYTE 			byHashAlgID,
	IN BYTE 			*pbUserID,
	IN DWORD			dwUserIDLen,
	OUT BYTE			*pbSignedData,
	IN OUT DWORD		*pdwSignedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ʹ���ⲿ�����ECC��Կ��ǩ����֤��
 *	pbSignedData		ǩ�����ݣ���ʽ��r||s
 *	dwSignedDataLen 	ǩ�����ݵĳ���
 *	byHashAlgID 		ժҪ�㷨
						��byHashAlgIDΪSM3��dwUserIDLen��Ϊ0�������pbUserID��Ч
						��ʱִ��SM2�㷨ǩ��Ԥ����1��Ԥ����2����
 *	pbECCPubKey 		��Կ���ݣ���ʽ��x||y
 *	dwECCPubKeyLen		��Կ���ݵĳ���
 *	pbUserID			�û�ID
 *	dwUserIDLen 		�û�ID�ĳ���
 *	pbData				��ǩ������
 *	dwDataLen			��ǩ�����ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardExtECCVerifyDigest(
	IN BYTE 			*pbSignedData,
	IN DWORD			dwSignedDataLen,
	IN BYTE 			byHashAlgID,
	IN BYTE 			*pbECCPubKey,
	IN DWORD			dwECCPubKeyLen,
	IN BYTE 			*pbUserID,
	IN DWORD			dwUserIDLen,
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ʹ���ⲿ�����ECC��Կ���������㡣
 *	pbData				����������
 *	dwDataLen			���������ݵĳ���
 *	pbECCPubKey 		��Կ���ݣ���ʽ��x||y
 *	dwECCPubKeyLen		��Կ���ݵĳ���
 *	pbEncryptedData 	�������ݣ���ʽ��C1����(DWORD)||C1||C2����(DWORD)||C2||C3����(DWORD)||C3
 *	pdwEncryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʼ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 */
BOOL FJCA_SCardExtECCEncrypt(
	IN BYTE 			*pbData,
	IN DWORD			dwDataLen,
	IN BYTE 			*pbECCPubKey,
	IN DWORD			dwECCPubKeyLen,
	OUT BYTE			*pbEncryptedData,
	IN OUT DWORD		*pdwEncryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ECC���ݽ��ܡ�
 *	pbEncryptedData 	�Ѽ������ݣ���ʽ��C1����(DWORD)||C1||C2����(DWORD)||C2||C3����(DWORD)||C3
 *	dwEncryptedDataLen	�Ѽ������ݵĳ���
 *	pbDecryptedData 	��������
 *	pdwDecryptedDataLen ����Ϊ�������ݻ������ĳ��ȣ����Ϊʵ�ʽ������ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCDecrypt(
	IN BYTE 			*pbEncryptedData,
	IN DWORD			dwEncryptedDataLen,
	OUT BYTE			*pbDecryptedData,
	IN OUT DWORD		*pdwDecryptedDataLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ʹ��ECC��ԿЭ���㷨��Ϊ����Ự��Կ������Э�̲�����������ʱECC��Կ�ԵĹ�Կ��
 *	pbTempECCPubKey 	��ʱ��Կ���ݣ���ʽ��x||y
 *	pdwTempECCPubKeyLen ����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCGetTempPubKey(
	OUT BYTE			*pbTempECCPubKey,
	IN OUT DWORD		*pdwTempECCPubKeyLen,
	IN HANDLE			hDev = NULL
	);

/*
 *	ʹ��ECC��ԿЭ���㷨������Э�̲���������Ự��Կ�������ʱECC��Կ�Թ�Կ�������ز�������Կ���
 *	bRole				��ɫ��1���𷽣�0���շ�
 *	pbID��				�ѷ�ID
 *	dwIDLen��			�ѷ�ID����
 *	pbTempECCPubKey 	�ѷ���ʱ��Կ���ݣ���ʽ��x||y
 *	pdwTempECCPubKeyLen ����Ϊ��Կ���ݻ������ĳ��ȣ����Ϊʵ�ʹ�Կ���ݵĳ���
 *	pbOID�� 			�Է�ID
 *	dwOIDLen			�Է�ID����
 *	pbOECCPubKey		�Է���Կ���ݣ���ʽ��x||y
 *	dwOECCPubKeyLen 	��Կ���ݵĳ���
 *	pbOTempECCPubKey	�Է���ʱ��Կ���ݣ���ʽ��x||y
 *	dwOTempECCPubKeyLen ��Կ���ݵĳ���
 *	ulAlgId 			�Ự��Կ�㷨��ʶ
 *	phKey				�Ự��Կ���
 *	hDev				�����豸ʱ���ص��豸���
 *	��ע��				���ȵ���FJCA_SCardECCSetCertNoѡ��ǰ������֤�顣
 */
BOOL FJCA_SCardECCKeyExchange( 
	IN BYTE 			bRole,
	IN BYTE 			*pbID,
	IN DWORD			dwIDLen,
	OUT BYTE			*pbTempECCPubKey,
	IN OUT DWORD		*pdwTempECCPubKeyLen,
	IN BYTE 			*pbOID,
	IN DWORD			dwOIDLen,
	IN BYTE 			*pbOECCPubKey,
	IN DWORD			dwOECCPubKeyLen,
	IN BYTE 			*pbOTempECCPubKey,
	IN DWORD			dwOTempECCPubKeyLen,
	IN ULONG			ulAlgId,
	OUT HANDLE			*phKey,
	IN HANDLE			hDev = NULL
	);

#ifdef __cplusplus
}
#endif

#endif


