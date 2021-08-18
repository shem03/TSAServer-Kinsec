#pragma once

#pragma pack(push,1)

#define SGD_SM1_ECB		0x00000101	//SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC		0x00000102	//SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB		0x00000104	//SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB		0x00000108	//SM1�㷨OFB����ģʽ
#define SGD_SM1_MAC		0x00000110	//SM1�㷨MAC����
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
#define SGD_SM4_ECB		0x00000401	// SM4�㷨ECB����ģʽ
#define SGD_SM4_CBC		0x00000402	// SM4�㷨CBC����ģʽ
#define SGD_SM4_CFB		0x00000404	// SM4�㷨CFB����ģʽ
#define SGD_SM4_OFB		0x00000408	// SM4�㷨OFB����ģʽ
#define SGD_SM4_MAC		0x00000410	// SM4�㷨MAC����ģʽ
#define SGD_ZUC_EEA3	0x00000801	// ZUC���֮�������㷨128-EEA3�㷨
#define SGD_ZUC_EIA3	0x00000802	// ZUC���֮�������㷨128-EIA3�㷨
/*	0x00000400-0x800000xx	Ϊ�������������㷨Ԥ��	*/

#define SGD_RSA			0x00010000	//RSA�㷨
#define SGD_SM2_1		0x00020100	//��Բ����ǩ���㷨
#define SGD_SM2_2		0x00020200	//��Բ������Կ����Э��
#define SGD_SM2_3		0x00020400	//��Բ���߼����㷨
/*	0x00000400��0x800000xx	Ϊ�����ǶԳ������㷨Ԥ��	*/

#define SGD_SM3			0x00000001	//SM3�Ӵ��㷨
#define SGD_SHA1		0x00000002	//SHA1�Ӵ��㷨
#define SGD_SHA256		0x00000004	//SHA256�Ӵ��㷨
/*	0x00000010��0x000000FF	Ϊ���������Ӵ��㷨Ԥ��	*/

#define MAX_IV_LEN			32		//��ʼ����������󳤶�
#define	MAX_FILE_NAME_LEN	32		//�ļ�����󳤶�
#define MAX_CONTAINER_NAME_LEN	128	//��������󳤶�
#define MIN_PIN_LEN			6		//��С��PIN����

#define MAX_RSA_MODULUS_LEN 256		//RSA�㷨ģ������󳤶�
#define MAX_RSA_EXPONENT_LEN 4		//RSA�㷨ָ������󳤶�

#define ECC_MAX_XCOORDINATE_BITS_LEN 512	//ECC�㷨X�������󳤶�
#define ECC_MAX_YCOORDINATE_BITS_LEN 512	//ECC�㷨Y�������󳤶�
#define ECC_MAX_MODULUS_BITS_LEN 512		//ECC�㷨ģ������󳤶�

typedef struct Struct_BLOCKCIPHERPARAM {
	BYTE	IV[MAX_IV_LEN];			//��ʼ������MAX_IV_LENΪ��ʼ��������󳤶�
	ULONG	IVLen;					//��ʼ����ʵ�ʳ��ȣ����ֽڼ���
	ULONG	PaddingType;			//��䷽ʽ��0��ʾ����䣬1��ʾ����PKCS#5��ʽ�������
	ULONG	FeedBitLen;				//����ֵ��λ���ȣ����ֽڼ��㣬ֻ���OFB��CFBģʽ
} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

typedef struct st_device_state{
	BOOL isOn;
	BOOL isLogged;
	int timeLeft;
	char name[250];
}DEVICE_STATE;

typedef struct st_device_info{
	char szDeviceInfo[MAX_PATH];
	char szVID[8];
	char szPID[8];
	char szSN[64];
	char szPD[12];
	char szPI[MAX_PATH];
	char szAF[MAX_PATH];
	char szLabel[MAX_PATH];
	DWORD dwTotalSpace;
	DWORD dwFreeSpace;
	DWORD dwDeviceType;
}DEVICE_INFO;

typedef struct Struct_FILEATTRIBUTE {
    CHAR	FileName[32];			//�ļ���
    ULONG	FileSize;				//�ļ���С
    ULONG	ReadRights;				//��Ȩ��
    ULONG	WriteRights;			//дȨ��
} FILEATTRIBUTE, *PFILEATTRIBUTE;

typedef struct Struct_ECCCIPHERBLOB{
	BYTE	XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE	YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];
	BYTE    HASH[32]; 
	ULONG	CipherLen;
	BYTE    Cipher[128];
} ECCCIPHERBLOB, *PECCCIPHERBLOB;

#pragma pack(pop)