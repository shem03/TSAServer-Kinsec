/*
 * 根据国密局《智能IC卡及智能密码钥匙密码应用接口规范20091217厂商版》PDF文档整理而成。
 * 2010.04.12
 */


#ifndef _SKF_API_H_
#define _SKF_API_H_

#define SAR_OK							0x00000000				//成功
#define SAR_FAIL						0x0A000001				//失败
#define SAR_UNKNOWNERR					0x0A000002				//异常错误
#define SAR_NOTSUPPORTYETERR			0x0A000003				//不支持的服务
#define SAR_FILEERR						0x0A000004				//文件操作错误
#define SAR_INVALIDHANDLEERR			0x0A000005				//无效的句柄
#define SAR_INVALIDPARAMERR				0x0A000006				//无效的参数
#define SAR_READFILEERR					0x0A000007				//读文件错误
#define SAR_WRITEFILEERR				0x0A000008				//写文件错误
#define SAR_NAMELENERR					0x0A000009				//文件名称错误
#define SAR_KEYUSAGEERR					0x0A00000A				//密钥用途错误
#define SAR_MODULUSLENERR				0x0A00000B				//模的长度错误
#define SAR_NOTINITIALIZEERR			0x0A00000C				//未初始化
#define SAR_OBJERR						0x0A00000D				//对象错误
#define SAR_MEMORYERR					0x0A00000E				//内存错误
#define SAR_TIMEOUTERR					0x0A00000F				//超时
#define SAR_INDATALENERR				0x0A000010				//输入数据长度错误
#define SAR_INDATAERR					0x0A000011				//输入数据错误
#define SAR_GENRANDERR					0x0A000012				//生成随机数错误
#define SAR_HASHOBJERR					0x0A000013				//HASH对象错误
#define SAR_HASHERR						0x0A000014				//HASH运算错误
#define SAR_GENRSAKEYRR					0x0A000015				//产生RSA密钥错误
#define SAR_RSAMODULUSLENERR			0x0A000016				//RSA密钥模长错误
#define SAR_CSPIMPRTPUBKEYERR			0x0A000017				//CSP服务导入公钥错误
#define SAR_RSAENCERR					0x0A000018				//RSA加密错误
#define SAR_RSADECERR					0x0A000019				//RSA解密错误
#define SAR_HASHNOTEQUALERR				0x0A00001A				//HASH值不相等
#define SAR_KEYNOTFOUNDERR				0x0A00001B				//密钥未发现
#define SAR_CERTNOTFOUNDERR				0x0A00001C				//证书未发现
#define SAR_NOTEXPORTERR				0x0A00001D				//对象未导出
#define SAR_DECRYPTPADERR				0x0A00001E				//解密时做补丁错误
#define SAR_MACLENERR					0x0A00001F				//MAC长度错误
#define SAR_BUFFER_TOO_SMALL			0x0A000020				//缓冲区不足
#define SAR_KEYINFOTYPEERR				0x0A000021				//密钥类型错误
#define SAR_NOT_EVENTERR				0x0A000022				//无事件错误
#define SAR_DEVICE_REMOVED				0x0A000023				//设备已移除
#define SAR_PIN_INCORRECT				0x0A000024				//PIN不正确
#define SAR_PIN_LOCKED					0x0A000025				//PIN被锁死
#define SAR_PIN_INVALID					0x0A000026				//PIN无效
#define SAR_PIN_LEN_RANGE				0x0A000027				//PIN长度错误
#define SAR_USER_ALREADY_LOGGED_IN		0x0A000028				//用户已经登录
#define SAR_USER_PIN_NOT_INITIALIZED	0x0A000029				//没有初始化用户口令
#define SAR_USER_TYPE_INVALID			0x0A00002A				//PIN类型错误
#define SAR_APPLICATION_NAME_INVALID	0x0A00002B				//应用名称无效
#define SAR_APPLICATION_EXISTS			0x0A00002C				//应用已经存在
#define SAR_USER_NOT_LOGGED_IN			0x0A00002D				//用户没有登录
#define SAR_APPLICATION_NOT_EXISTS		0x0A00002E				//应用不存在
#define SAR_FILE_ALREADY_EXIST			0x0A00002F				//文件已经存在
#define SAR_NO_ROOM						0x0A000030				//空间不足
#define SAR_FILE_NOT_EXIST				0x0A000031				//文件不存在
#define SAR_FILE_NAME_INVALID			0x0A000032				//文件名无效
#define SAR_DATA_LEN_RANGE				0x0A000033				//数据长度错误
#define SAR_INSUFFICIENT_PRIVILEGES		0x0A000034				//操作权限不足

#ifdef _WIN32
#define DEVAPI __stdcall
#else
#define DEVAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define	IN
#define OUT

/*
*布尔类型定义
*/
#undef TRUE
#undef FALSE
#define TRUE			0x00000001	//布尔值为真
#define FALSE			0x00000000	//布尔值为假

/*
*基本数据类型
*/
typedef signed char         INT8;
typedef signed short        INT16;
typedef signed int          INT32;
typedef unsigned char       UINT8;
typedef unsigned short      UINT16;
typedef unsigned int	    UINT32;

typedef UINT8				BYTE;
typedef char				CHAR;
typedef INT16				SHORT;
typedef UINT16				USHORT;
#ifndef _WIN32
typedef INT32				LONG;
typedef UINT32				ULONG;
#endif
typedef UINT32				UINT;
typedef UINT16				WORD;
#ifndef _WIN32
typedef UINT32				DWORD;
#endif
typedef UINT32				FLAGS;
typedef CHAR *				LPSTR;
typedef void *				HANDLE;
typedef int					BOOL32;

typedef HANDLE				DEVHANDLE;
typedef HANDLE				HAPPLICATION;
typedef HANDLE				HCONTAINER;

/*
*临界值定义
*/
#define MAX_IV_LEN			32		//初始化向量的最大长度
#define	MAX_FILE_NAME_LEN	32		//文件名最大长度
#define MAX_CONTAINER_NAME_LEN	128	//容器名最大长度
#define MIN_PIN_LEN			6		//最小的PIN长度

#define MAX_RSA_MODULUS_LEN 256		//RSA算法模数的最大长度
#define MAX_RSA_EXPONENT_LEN 4		//RSA算法指数的最大长度

#define ECC_MAX_XCOORDINATE_BITS_LEN 512	//ECC算法X座标的最大长度
#define ECC_MAX_YCOORDINATE_BITS_LEN 512	//ECC算法Y座标的最大长度
#define ECC_MAX_MODULUS_BITS_LEN 512		//ECC算法模数的最大长度

/*
 *算法标识符
 */
#define SGD_3DES_ECB	0x00000001  //3DES算法ECB加密模式

#define SGD_SM1_ECB		0x00000101	//SM1算法ECB加密模式
#define SGD_SM1_CBC		0x00000102	//SM1算法CBC加密模式
#define SGD_SM1_CFB		0x00000104	//SM1算法CFB加密模式
#define SGD_SM1_OFB		0x00000108	//SM1算法OFB加密模式
#define SGD_SM1_MAC		0x00000110	//SM1算法MAC运算
#define SGD_SSF33_ECB	0x00000201	//SSF33算法ECB加密模式
#define SGD_SSF33_CBC	0x00000202	//SSF33算法CBC加密模式
#define SGD_SSF33_CFB	0x00000204	//SSF33算法CFB加密模式
#define SGD_SSF33_OFB	0x00000208	//SSF33算法OFB加密模式
#define SGD_SSF33_MAC	0x00000210	//SSF33算法MAC运算
#define SGD_SMS4_ECB	0x00000401	//SMS4算法ECB加密模式
#define SGD_SMS4_CBC	0x00000402	//SMS4算法CBC加密模式
#define SGD_SMS4_CFB	0x00000404	//SMS4算法CFB加密模式
#define SGD_SMS4_OFB	0x00000408	//SMS4算法OFB加密模式
#define SGD_SMS4_MAC	0x00000410	//SMS4算法MAC运算
#define SGD_SM4_ECB		0x00000401	// SM4算法ECB加密模式
#define SGD_SM4_CBC		0x00000402	// SM4算法CBC加密模式
#define SGD_SM4_CFB		0x00000404	// SM4算法CFB加密模式
#define SGD_SM4_OFB		0x00000408	// SM4算法OFB加密模式
#define SGD_SM4_MAC		0x00000410	// SM4算法MAC加密模式
#define SGD_ZUC_EEA3	0x00000801	// ZUC祖冲之机密性算法128-EEA3算法
/*	0x00000400-0x800000xx	为其它分组密码算法预留	*/

#define SGD_RSA			0x00010000	//RSA算法
#define SGD_SM2_1		0x00020100	//椭圆曲线签名算法
#define SGD_SM2_2		0x00020200	//椭圆曲线密钥交换协议
#define SGD_SM2_3		0x00020400	//椭圆曲线加密算法
/*	0x00000400～0x800000xx	为其它非对称密码算法预留	*/

#define SGD_SM3			0x00000001	//SM3杂凑算法
#define SGD_SHA1		0x00000002	//SHA1杂凑算法
#define SGD_SHA256		0x00000004	//SHA256杂凑算法
/*	0x00000010～0x000000FF	为其它密码杂凑算法预留	*/

/*
 *设备状态
 */
#define	DEV_ABSENT_STATE	0x00000000		//设备不存在
#define	DEV_PRESENT_STATE	0x00000001		//设备存在
#define DEV_UNKNOW_STATE        0x00000002     //设备状态未知

/*
 *密钥类型
 */
#define KEYTYPE_PUBLIC_KEY		0x01		//公钥
#define KEYTYPE_PRIVATE_KEY		0x02		//私钥
#define KEYTYPE_SECRET_KEY		0x03		//密钥

/*
 *密钥应用类型
 */
#define AT_EXTERNAL_AUTHENTICATE_KEY	0x00000001		//用于设备对终端的认证

/*
 *权限类型
 */
#define SECURE_NEVER_ACCOUNT	0x00000000		//不允许
#define SECURE_ADM_ACCOUNT		0x00000001		//管理员权限
#define SECURE_USER_ACCOUNT		0x00000010		//用户权限
#define SECURE_EVERYONE_ACCOUNT	0x000000FF		//任何人

/*
 *PIN类型
 */
#define ADMIN_TYPE				0				//管理员PIN
#define USER_TYPE				1				//用户PIN

/*
 *容器属性
*/
#define CONTAINER_PROPERTY_UNKNOWN  0
#define CONTAINER_PROPERTY_RSA      1
#define CONTAINER_PROPERTY_ECC      2

#pragma pack(push, 1)

/*
 *版本
 */
typedef struct Struct_Version{
	BYTE	major;					//主版本号
	BYTE	minor;					//次版本号
} VERSION;

/*
 *设备信息
 */
typedef struct Struct_DEVINFO{
	VERSION Version;			
	CHAR	Manufacturer[64];		//设备厂商信息
	CHAR	Issuer[64];				//应用发行者信息
	CHAR	Label[32];				//标签
	CHAR	SerialNumber[32];		//序列号
	VERSION HWVersion;				//设备硬件版本
	VERSION FirmwareVersion;		//设备本身固件版本
	ULONG	AlgSymCap;				//支持对称算法标志
	ULONG	AlgAsymCap;				//支持非对称算法标志
	ULONG	AlgHashCap;				//支持杂凑算法标志
	ULONG	DevAuthAlgId;			//设备认证采用的算法标识
	ULONG	TotalSpace;				//设备存储空间
	ULONG	FreeSpace;				//设备剩余空间
	ULONG	MaxECCBufferSize;		//能够处理的ECC加密数据大小
	ULONG	MaxBufferSize;			//能够处理的分组运算和杂凑运算的数据大小
	BYTE	Reserved[64];			//保留扩展
} DEVINFO, *PDEVINFO;

#ifndef FJCA_COMMON_DEFINE2
/*
 *RSA公钥交换数据块
 */
typedef struct Struct_RSAPUBLICKEYBLOB{
	ULONG	AlgID;									//算法标识号
	ULONG	BitLen;									//模数的实际位长度，必须是8的倍数
	BYTE	Modulus[MAX_RSA_MODULUS_LEN];			//模数n=p*q，实际长度为BitLen/8字节
	BYTE	PublicExponent[MAX_RSA_EXPONENT_LEN];	//公开密钥e， 一般为00010001
} RSAPUBLICKEYBLOB, *PRSAPUBLICKEYBLOB;
#endif

/*
 *RSA私钥交换数据块
 */
typedef struct Struct_RSAPRIVATEKEYBLOB{
	ULONG	AlgID;									//算法标识号
	ULONG	BitLen;									//模数的实际位长度，必须是8的倍数
	BYTE	Modulus[MAX_RSA_MODULUS_LEN];			//模数n=p*q，实际长度为BitLen/8字节
	BYTE	PublicExponent[MAX_RSA_EXPONENT_LEN];	//公开密钥e， 一般为00010001
	BYTE	PrivateExponent[MAX_RSA_MODULUS_LEN];	//私有密钥d，实际长度为BitLen/8字节
	BYTE	Prime1[MAX_RSA_MODULUS_LEN/2];			//素数p，实际长度为BitLen/16字节
	BYTE	Prime2[MAX_RSA_MODULUS_LEN/2];			//素数q，实际长度为BitLen/16字节
	BYTE	Prime1Exponent[MAX_RSA_MODULUS_LEN/2];	//d mod (p-1)的值, 实际长度为BitLen/16字节
	BYTE	Prime2Exponent[MAX_RSA_MODULUS_LEN/2];	//d mod (q-1)的值，实际长度为BitLen/16字节
	BYTE	Coefficient[MAX_RSA_MODULUS_LEN/2];		//q模p的乘法逆元，实际长度为BitLen/16字节
} RSAPRIVATEKEYBLOB, *PRSAPRIVATEKEYBLOB;

#ifndef FJCA_COMMON_DEFINE2
/*
 *ECC公钥交换数据块
 */
typedef struct Struct_ECCPUBLICKEYBLOB{
	ULONG	BitLen;
	BYTE	XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE	YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];
}ECCPUBLICKEYBLOB, *PECCPUBLICKEYBLOB;
#endif

/*
 *ECC私钥交换数据块
 */
typedef struct Struct_ECCPRIVATEKEYBLOB{
	ULONG	BitLen;
	BYTE	PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];
}ECCPRIVATEKEYBLOB, *PECCPRIVATEKEYBLOB;

#ifndef FJCA_COMMON_DEFINE2
typedef struct Struct_ECCCIPHERBLOB{
	BYTE	XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE	YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];
	BYTE    HASH[32]; 
	ULONG	CipherLen;
	BYTE    Cipher[128];
} ECCCIPHERBLOB, *PECCCIPHERBLOB;
#endif

#define ECCCIPHERBLOB_SIZE(b) (sizeof(b.XCoordinate) \
									+ sizeof(b.XCoordinate) \
									+ sizeof(b.HASH) \
									+ sizeof(b.CipherLen) \
									+ b.CipherLen)

typedef struct Struct_ECCSIGNATUREBLOB{
	BYTE	r[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE	s[ECC_MAX_YCOORDINATE_BITS_LEN/8];
} ECCSIGNATUREBLOB, *PECCSIGNATUREBLOB;

#ifndef FJCA_COMMON_DEFINE
/*
 *分组密码参数
 */
typedef struct Struct_BLOCKCIPHERPARAM{
	BYTE	IV[MAX_IV_LEN];			//初始向量，MAX_IV_LEN为初始向量的最大长度
	ULONG	IVLen;					//初始向量实际长度，按字节计算
	ULONG	PaddingType;			//填充方式，0表示不填充，1表示按照PKCS#5方式进行填充
	ULONG	FeedBitLen;				//反馈值的位长度，按字节计算，只针对OFB、CFB模式
} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;
#endif

// 导入SM2加密密钥对的数据结构
typedef struct SKF_ENVELOPEDKEYBLOB{
	ULONG Version;                  // 当前版本为 1
	ULONG ulSymmAlgID;              // 对称算法标识，限定ECB模式
	ULONG ulBits;					// 加密密钥对的密钥位长度
	BYTE cbEncryptedPriKey[64];     // 加密密钥对私钥的密文
	ECCPUBLICKEYBLOB PubKey;        // 加密密钥对的公钥
	ECCCIPHERBLOB ECCCipherBlob;    // 用保护公钥加密的对称密钥密文。
}ENVELOPEDKEYBLOB, *PENVELOPEDKEYBLOB;

#ifndef FJCA_COMMON_DEFINE
/*
 *文件属性
 */
typedef struct Struct_FILEATTRIBUTE{
	CHAR	FileName[32];			//文件名
	ULONG	FileSize;				//文件大小
	ULONG	ReadRights;				//读权限
	ULONG	WriteRights;			//写权限
} FILEATTRIBUTE, *PFILEATTRIBUTE;
#endif

#pragma pack(pop)

// 设置应用程序包名
// 华申
typedef void (DEVAPI * FUNC_SKF_sd_set_package_name)(
	  IN const char *pszSDPath
	  );

#ifdef KT_ANDROID
// 华申NFC
typedef void (*FUNC_SKF_Init_Package)(const char *pszProviderPath, JNIEnv *jniEnv);
#endif

// 赢达信
typedef ULONG (DEVAPI * FUNC_SKF_SetPackageName)(
	  IN const char *pszPackageName
	  );

/************************************************************************/
/*	1. 设备管理															*/
/*	SKF_WaitForDevEvent													*/
/*	SKF_CancelWaitForDevEvent											*/
/*	SKF_EnumDev															*/
/*	SKF_ConnectDev														*/
/*	SKF_DisconnectDev													*/
/*	SKF_GetDevState														*/
/*	SKF_SetLabel														*/
/*	SKF_GetDevInfo														*/
/*	SKF_LockDev															*/
/*	SKF_UnlockDev														*/
/************************************************************************/

/*
 *	等待设备的插拔事件
 *	szDevName		[OUT]返回发生事件的设备名称
 *	pulDevNameLen	[IN OUT]输入/输出参数，当输入时表示缓冲区长度，输出时表示设备名称的有效长度,长度包含字符串结束符
 *	pulEvent		[OUT]事件类型。1表示插入，2表示拔出
 *	备注: 该函数是阻塞调用的
 */
typedef ULONG (DEVAPI * FUNC_SKF_WaitForDevEvent)(
	  OUT LPSTR szDevName,
	  OUT ULONG *pulDevNameLen,
	  OUT ULONG *pulEvent
	  );
/*
 *	取消等待设备的插拔事件
 */
typedef ULONG (DEVAPI * FUNC_SKF_CancelWaitForDevEvent)();

/*
 *	获得当前系统中的设备列表
 *	bPresent		[IN]为TRUE表示取当前设备状态为存在的设备列表。为FALSE表示取当前驱动支持的设备列表
 *	szNameList		[OUT]设备名称列表。如果该参数为NULL，将由pulSize返回所需要的内存空间大小。每个设备的名称以单个'\0'结束，以双'\0'表示列表的结束
 *	pulSize			[IN OUT]输入参数，输入设备名称列表的缓冲区长度，输出参数，返回szNameList所需要的空间大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_EnumDev)(
	  IN BOOL32 bPresent,
	  OUT LPSTR szNameList,
	  OUT ULONG* pulSize
	  );

/*
 *	通过设备名称连接设备，返回设备的句柄
 *	szName		[IN]设备名称
 *	phDev		[OUT]返回设备操作句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_ConnectDev)(
	  IN LPSTR szName,
	  OUT DEVHANDLE* phDev
	  );

/*
 *	断开一个已经连接的设备，并释放句柄。
 *	hDev		[IN]连接设备时返回的设备句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_DisConnectDev)(
	  IN DEVHANDLE hDev
	  );

/*
 *	获取设备是否存在的状态
 *	szDevName	[IN]连接名称
 *	pulDevState	[OUT]返回设备状态
 */
typedef ULONG (DEVAPI * FUNC_SKF_GetDevState)(
	  IN  LPSTR	 szDevName,
	  OUT ULONG* pulDevState
	  );

/*
 *	设置设备标签
 *	hDev		[IN]连接设备时返回的设备句柄
 *	szLabel		[OUT]设备标签字符串。该字符串应小于32字节
 */
typedef ULONG (DEVAPI * FUNC_SKF_SetLabel)(
	  IN DEVHANDLE hDev,
	  IN LPSTR szLabel);

/*
 *	获取设备的一些特征信息，包括设备标签、厂商信息、支持的算法等
 *	hDev		[IN]连接设备时返回的设备句柄
 *	pDevInfo	[OUT]返回设备信息
 */
typedef ULONG (DEVAPI * FUNC_SKF_GetDevInfo)(
	  IN DEVHANDLE	hDev,
	  OUT PDEVINFO	pDevInfo
	  );

/*
 *	获得设备的独占使用权
 *	hDev		[IN]连接设备时返回的设备句柄
 *	ulTimeOut	[IN]超时时间，单位为毫秒。如果为0xFFFFFFFF表示无限等待
 */	
typedef ULONG (DEVAPI * FUNC_SKF_LockDev)(
	  IN DEVHANDLE	hDev,
	  IN ULONG ulTimeOut
	  );

/*
 *	释放对设备的独占使用权
 *	hDev		[IN]连接设备时返回的设备句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_UnlockDev)(
	  IN DEVHANDLE	hDev
	  );


/************************************************************************/
/*  2. 访问控制				                                            */
/*	SKF_ChangeDevAuthKey												*/
/*	SKF_DevAuth															*/
/*	SKF_ChangePIN														*/
/*	SKF_GetPINInfo														*/
/*	SKF_VerifyPIN														*/
/*	SKF_UnblockPIN														*/
/*	SKF_ClearSecureState												*/
/************************************************************************/

/*
 *	更改设备认证密钥
 *	hDev		[IN]连接时返回的设备句柄
 *	pbKeyValue	[IN]密钥值
 *	ulKeyLen	[IN]密钥长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ChangeDevAuthKey)(
	  IN DEVHANDLE	hDev,
	  IN BYTE		*pbKeyValue,
	  IN ULONG		ulKeyLen
	  );

/*
 *	设备认证是设备对应用程序的认证
 *	hDev			[IN]连接时返回的设备句柄
 *	pbAuthData		[IN]认证数据
 *	ulLen			[IN]认证数据的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_DevAuth)(
	  IN DEVHANDLE	hDev,
	  IN BYTE*		pbAuthData,
	  IN ULONG		ulLen
	  );

/*
 *	修改PIN，可以修改Admin和User的PIN，如果原PIN错误，返回剩余重试次数，当剩余次数为0时，表示PIN已经被锁死
 *	hApplication	[IN]应用句柄
 *	ulPINType		[IN]PIN类型，可以为ADMIN_TYPE=0，或USER_TYPE=1
 *	szOldPIN		[IN]原PIN值
 *	szNewPIN		[IN]新PIN值
 *	pulRetryCount	[OUT]出错后重试次数
 */
typedef ULONG (DEVAPI * FUNC_SKF_ChangePIN)(
	  IN HAPPLICATION	hApplication,
	  IN ULONG			ulPINType,
	  IN LPSTR			szOldPIN,
	  IN LPSTR			szNewPIN,
	  OUT ULONG*		pulRetryCount
	  );

/*
 *	获取PIN码信息，包括最大重试次数、当前剩余重试次数，以及当前PIN码是否为出厂默认PIN码
 *	hApplication		[IN]应用句柄
 *	ulPINType			[IN]PIN类型
 *	pulMaxRetryCount	[OUT]最大重试次数
 *	pulRemainRetryCount	[OUT]当前剩余重试次数，当为0时表示已锁死
 *	pbDefaultPin		[OUT]是否为出厂默认PIN码
 */
typedef ULONG (DEVAPI * FUNC_SKF_GetPINInfo)(
	  IN HAPPLICATION	hApplication,
	  IN ULONG			ulPINType,
	  OUT ULONG*		pulMaxRetryCount,
	  OUT ULONG*		pulRemainRetryCount,
	  OUT BOOL32*		pbDefaultPin
	  );

/*
 *	校验PIN码。校验成功后，会获得相应的权限，如果PIN码错误，会返回PIN码的重试次数，当重试次数为0时表示PIN码已经锁死
 *	hApplication	[IN]应用句柄
 *	ulPINType		[IN]PIN类型，可以为ADMIN_TYPE=0，或USER_TYPE=1
 *	szPIN			[IN]PIN值
 *	pulRetryCount	[OUT]出错后返回的重试次数
 */
typedef ULONG (DEVAPI * FUNC_SKF_VerifyPIN)(
	  IN HAPPLICATION	hApplication,
	  IN ULONG			ulPINType,
	  IN LPSTR			szPIN,
	  OUT ULONG*		pulRetryCount
	  );

/*
 *	当用户的PIN码锁死后，通过调用该函数来解锁用户PIN码。
 *	解锁后，用户PIN码被设置成新值，用户PIN码的重试次数也恢复到原值。
 *	hApplication	[IN]应用句柄
 *	szAdminPIN		[IN]管理员PIN码
 *	szNewUserPIN	[IN]新的用户PIN码
 *	pulRetryCount	[OUT]管理员PIN码错误时，返回剩余重试次数
 */
typedef ULONG (DEVAPI * FUNC_SKF_UnblockPIN)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szAdminPIN,
	  IN LPSTR			szNewUserPIN,
	  OUT ULONG*		pulRetryCount
	  );

/*
 *	清除应用当前的安全状态
 *	hApplication	[IN]应用句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_ClearSecureState)(
	  IN HAPPLICATION	hApplication
	  );

/************************************************************************/
/*  3. 应用管理				                                            */
/*	SKF_CreateApplication												*/
/*	SKF_EnumApplication													*/
/*	SKF_DeleteApplication												*/
/*	SKF_OpenApplication													*/
/*	SKF_CloseApplication												*/
/************************************************************************/

/*
 *	创建一个应用
 *	hDev					[IN]连接设备时返回的设备句柄
 *	szAppName				[IN]应用名称
 *	szAdminPIN				[IN]管理员PIN
 *	dwAdminPinRetryCount	[IN]管理员PIN最大重试次数
 *	szUserPIN				[IN]用户PIN
 *	dwAdminPinRetryCount	[IN]用户PIN最大重试次数
 *	dwCreateFileRights		[IN]在该应用下创建文件和容器的权限
 *	phApplication			[OUT]应用的句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_CreateApplication)(
	  IN DEVHANDLE		hDev,
	  IN LPSTR			szAppName,
	  IN LPSTR			szAdminPIN,
	  IN DWORD			dwAdminPinRetryCount,
	  IN LPSTR			szUserPIN,
	  IN DWORD			dwUserPinRetryCount,
	  IN DWORD			dwCreateFileRights,
	  OUT HAPPLICATION*	phApplication
	  );

/*
 *	枚举设备中所存在的所有应用
 *	hDev			[IN]连接设备时返回的设备句柄
 *	szAppName		[OUT]返回应用名称列表, 如果该参数为空，将由pulSize返回所需要的内存空间大小。
 *						 每个应用的名称以单个'\0'结束，以双'\0'表示列表的结束。
 *	pulSize			[IN OUT]输入参数，输入应用名称的缓冲区长度，输出参数，返回szAppName所占用的的空间大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_EnumApplication)(
	  IN DEVHANDLE		hDev,
	  OUT LPSTR			szAppName,
	  OUT ULONG*		pulSize
	  );

/*
 *	删除指定的应用
 *	hDev			[IN]连接设备时返回的设备句柄
 *	szAppName		[IN]应用名称
 */
typedef ULONG (DEVAPI * FUNC_SKF_DeleteApplication)(
	  IN DEVHANDLE		hDev,
	  IN LPSTR			szAppName
	  );

/*
 *	打开指定的应用
 *	hDev			[IN]连接设备时返回的设备句柄
 *	szAppName		[IN]应用名称
 *	phApplication	[OUT]应用的句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_OpenApplication)(
	  IN DEVHANDLE		hDev,
	  IN LPSTR			szAppName,
	  OUT HAPPLICATION*	phApplication
	  );

/*
 *	关闭应用并释放应用句柄
 *	hApplication	[IN]应用的句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_CloseApplication)(
	  IN HAPPLICATION	hApplication
	  );


/************************************************************************/
/*  4. 文件管理				                                            */
/*	SKF_CreateFile														*/
/*	SKF_DeleteFile														*/
/*	SKF_EnumFiles														*/
/*	SKF_GetFileInfo														*/
/*	SKF_ReadFile														*/
/*	SKF_WriteFile														*/
/************************************************************************/

/*
 *	创建一个文件。创建文件时要指定文件的名称，大小，以及文件的读写权限
 *	hApplication		[IN]应用句柄
 *	szFileName			[IN]文件名称，长度不得大于32个字节
 *	ulFileSize			[IN]文件大小
 *	ulReadRights		[IN]文件读权限
 *	ulWriteRights		[IN]文件写权限
 */
typedef ULONG (DEVAPI * FUNC_SKF_CreateFile)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szFileName,
	  IN ULONG			ulFileSize,
	  IN ULONG			ulReadRights,
	  IN ULONG			ulWriteRights
	  );

/*
 *	删除指定文件，文件删除后，文件中写入的所有信息将丢失。文件在设备中的占用的空间将被释放。
 *	hApplication		[IN]要删除文件所在的应用句柄
 *	szFileName			[IN]要删除文件的名称
 */
typedef ULONG (DEVAPI * FUNC_SKF_DeleteFile)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szFileName
	  );

/*
 *	枚举一个应用下存在的所有文件
 *	hApplication		[IN]应用的句柄
 *	szFileList			[OUT]返回文件名称列表，该参数为空，由pulSize返回文件信息所需要的空间大小。每个文件名称以单个'\0'结束，以双'\0'表示列表的结束。
 *	pulSize				[OUT]输入为数据缓冲区的大小，输出为实际文件名称的大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_EnumFiles)(
	  IN HAPPLICATION	hApplication,
	  OUT LPSTR			szFileList,
	  OUT ULONG*		pulSize
	  );

/*
 *	获取应用文件的属性信息，例如文件的大小、权限等
 *	hApplication		[IN]文件所在应用的句柄
 *	szFileName			[IN]文件名称
 *	pFileInfo			[OUT]文件信息，指向文件属性结构的指针
 */
typedef ULONG (DEVAPI * FUNC_SKF_GetFileInfo)(
	  IN HAPPLICATION		hApplication,
	  IN LPSTR				szFileName,
	  OUT FILEATTRIBUTE*	pFileInfo
	  );

/*
 *	读取文件内容
 *	hApplication		[IN]文件所在的应用句柄
 *	szFileName			[IN]文件名
 *	ulOffset			[IN]文件读取偏移位置
 *	ulSize				[IN]要读取的长度
 *	pbOutData			[OUT]返回数据的缓冲区
 *	pulOutLen			[OUT]输入表示给出的缓冲区大小；输出表示实际读取返回的数据大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_ReadFile)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szFileName,
	  IN ULONG			ulOffset,
	  IN ULONG			ulSize,
	  OUT BYTE*			pbOutData,
	  OUT ULONG*		pulOutLen
	  );

/*
 *	写数据到文件中
 *	hApplication		[IN]文件所在的应用句柄
 *	szFileName			[IN]文件名
 *	ulOffset			[IN]写入文件的偏移量
 *	pbData				[IN]写入数据缓冲区
 *	ulSize				[IN]写入数据的大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_WriteFile)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szFileName,
	  IN ULONG			ulOffset,
	  IN BYTE*			pbData,
	  IN ULONG			ulSize
	  );


/************************************************************************/
/*  5. 容器管理				                                            */
/*	SKF_CreateContainer													*/
/*	SKF_DeleteContainer													*/
/*	SKF_OpenContainer													*/
/*	SKF_CloseContainer													*/
/*	SKF_EnumContainer													*/
/************************************************************************/

/*
 *	在应用下建立指定名称的容器并返回容器句柄
 *	hApplication		[IN]应用句柄
 *	szContainerName		[IN]ASCII字符串，表示所建立容器的名称，容器名称的最大长度不能超过64字节
 *	phContainer			[OUT]返回所建立容器的容器句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_CreateContainer)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szContainerName,
	  OUT HCONTAINER*	phContainer
	  );

/*
 *	在应用下删除指定名称的容器并释放容器相关的资源
 *	hApplication		[IN]应用句柄
 *	szContainerName		[IN]指向删除容器的名称
 */
typedef ULONG (DEVAPI * FUNC_SKF_DeleteContainer)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szContainerName
	  );

/*
 *	获取容器句柄
 *	hApplication		[IN]应用句柄
 *	szContainerName		[IN]容器名称
 *	phContainer			[OUT]返回所打开容器的句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_OpenContainer)(
	  IN HAPPLICATION	hApplication,
	  IN LPSTR			szContainerName,
	  OUT HCONTAINER*	phContainer
	  );

/*
 *	关闭容器句柄，并释放容器句柄相关资源
 *	hContainer			[OUT]容器句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_CloseContainer)(
	  IN HCONTAINER hContainer
	  );

/*
 *	枚举应用下的所有容器并返回容器名称列表
 *	hApplication		[IN]应用句柄
 *	szContainerName		[OUT]指向容器名称列表缓冲区，如果此参数为NULL时，pulSize表示返回数据所需要缓冲区的长度，如果此参数不为NULL时，返回容器名称列表，每个容器名以单个'\0'为结束，列表以双'\0'结束
 *	pulSize				[OUT]调用前表示szContainerName缓冲区的长度，返回容器名称列表的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_EnumContainer)(
	  IN HAPPLICATION	hApplication,
	  OUT LPSTR			szContainerName,
	  OUT ULONG*		pulSize
	  );

/************************************************************************/
/*  6. 密码服务				                                            */
/*	SKF_GetRandom														*/
/*	SKF_GenExtRSAKey													*/
/*	SKF_GenRSAKeyPair													*/
/*	SKF_ImportRSAKeyPair												*/
/*	SKF_RSASignData														*/
/*	SKF_RSAVerify														*/
/*	SKF_RSAExportSessionKey												*/
/*	SKF_ExtRSAPubKeyOperation											*/
/*	SKF_ExtRSAPriKeyOperation											*/
/*	SKF_GenECCKeyPair													*/
/*	SKF_ImportECCKeyPair												*/
/*	SKF_ECCSignData														*/
/*	SKF_ECCVerify														*/
/*	SKF_ECCExportSessionKey												*/
/*	SKF_ExtECCEncrypt													*/
/*	SKF_ExtECCDecrypt													*/
/*	SKF_ExtECCSign														*/
/*	SKF_ExtECCVerify													*/
/*	SKF_GenerateAgreementDataWithECC									*/
/*	SKF_GenerateAgreementDataAndKeyWithECC								*/
/*	SKF_GenerateKeyWithECC												*/
/*	SKF_ExportPublicKey													*/

/*	SKF_ImportSessionKey												*/
/*	SKF_SetSymmKey														*/
/*	SKF_EncryptInit														*/
/*	SKF_Encrypt															*/
/*	SKF_EncryptUpdate													*/
/*	SKF_EncryptFinal													*/
/*	SKF_DecryptInit														*/
/*	SKF_Decrypt															*/
/*	SKF_DecryptUpdate													*/
/*	SKF_DecryptFinal													*/
/*	SKF_DegistInit														*/
/*	SKF_Degist															*/
/*	SKF_DegistUpdate													*/
/*	SKF_DegistFinal														*/
/*	SKF_MACInit															*/
/*	SKF_MAC																*/
/*	SKF_MACUpdate														*/
/*	SKF_MACFinal														*/
/*	SKF_CloseHandle														*/
/************************************************************************/

/*
 *	产生指定长度的随机数
 *	hDev			[IN] 设备句柄
 *	pbRandom		[OUT] 返回的随机数
 *	ulRandomLen		[IN] 随机数长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenRandom)(
	  IN DEVHANDLE hDev, 
	  OUT BYTE *pbRandom,
	  IN ULONG ulRandomLen
	  );

/*
 *	由设备生成RSA密钥对并明文输出
 *	hDev			[IN] 设备句柄
 *	ulBitsLen		[IN] 密钥模长
 *	pBlob			[OUT] 返回的私钥数据结构
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenExtRSAKey)(
	  IN DEVHANDLE hDev, 
	  IN ULONG ulBitsLen,
	  OUT RSAPRIVATEKEYBLOB* pBlob
	  );

/*
 *	生成RSA签名密钥对并输出签名公钥
 *	hContainer		[IN] 容器句柄
 *	ulBitsLen		[IN] 密钥模长
 *	pBlob			[OUT] 返回的RSA公钥数据结构
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenRSAKeyPair)(
	  IN HCONTAINER hContainer, 
	  IN ULONG ulBitsLen,
	  OUT RSAPUBLICKEYBLOB *pBlob
	  );

/*
 *	导入RSA加密公私钥对
 *	hContainer		[IN] 容器句柄
 *	ulSymAlgId		[IN] 对称算法密钥标识
 *	pbWrappedKey	[IN] 使用该容器内签名公钥保护的对称算法密钥
 *	ulWrappedKeyLen	[IN] 保护的对称算法密钥长度
 *	pbEncryptedData	[IN] 对称算法密钥保护的RSA加密私钥。私钥的格式遵循PKCS #1 v2.1: RSA Cryptography Standard中的私钥格式定义
 *	ulEncryptedDataLen	[IN] 对称算法密钥保护的RSA加密公私钥对长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ImportRSAKeyPair)(
	  IN HCONTAINER hContainer, 
	  IN ULONG ulSymAlgId, 
	  IN BYTE *pbWrappedKey, 
	  IN ULONG ulWrappedKeyLen,
	  IN BYTE *pbEncryptedData, 
	  IN ULONG ulEncryptedDataLen
	  );

/*
 *	使用hContainer指定容器的签名私钥，对指定数据pbData进行数字签名。签名后的结果存放到pbSignature缓冲区，设置pulSignLen为签名的长度
 *	hContainer		[IN] 用来签名的私钥所在容器句柄
 *	pbData			[IN] 被签名的数据
 *	ulDataLen		[IN] 签名数据长度，应不大于RSA密钥模长-11
 *	pbSignature		[OUT] 存放签名结果的缓冲区指针，如果值为NULL，用于取得签名结果长度
 *	pulSigLen		[IN OUT] 输入为签名结果缓冲区大小，输出为签名结果长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_RSASignData)(
	  IN HANDLE hContainer,
	  IN BYTE *pbData, 
	  IN ULONG ulDataLen, 
	  OUT BYTE *pbSignature, 
	  OUT ULONG *pulSigLen
	  );

/*
 *	验证RSA签名。用pRSAPubKeyBlob内的公钥值对待验签数据进行验签。
 *	hDev			[IN] 连接设备时返回的设备句柄
 *	pRSAPubKeyBlob	[IN] RSA公钥数据结构
 *	pbData			[IN] 待验证签名的数据
 *	ulDataLen		[IN] 数据长度，应不大于公钥模长-11
 *	pbSignature		[IN] 待验证的签名值
 *	ulSigLen		[IN] 签名值长度，必须为公钥模长
 */
typedef ULONG (DEVAPI * FUNC_SKF_RSAVerify)(
	  IN DEVHANDLE			hDev, 
	  IN RSAPUBLICKEYBLOB*	pRSAPubKeyBlob,
	  IN BYTE*				pbData, 
	  IN ULONG				ulDataLen, 
	  IN BYTE*				pbSignature, 
	  IN ULONG				ulSigLen
	  );

/*
 *	生成会话密钥并用外部公钥加密输出。
 *	hContainer		[IN] 容器句柄
 *	ulAlgID			[IN] 会话密钥的算法标识
 *	pPubKey			[IN] 加密会话密钥的RSA公钥数据结构
 *	pbData			[OUT] 导出的加密会话密钥密文，按照PKCS#1v1.5的要求封装
 *	pulDataLen		[OUT] 返回导出数据长度
 *	phSessionKey	[OUT] 导出的密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_RSAExportSessionKey)(
	  IN HCONTAINER hContainer,
	  IN ULONG ulAlgID,
	  IN RSAPUBLICKEYBLOB* pPubKey,
	  OUT BYTE* pbData,
	  OUT ULONG* pulDataLen,
	  OUT HANDLE* phSessionKey
	  );

/*
 *	使用外部传入的RSA公钥对输入数据做公钥运算并输出结果
 *	hDev			[IN] 设备句柄
 *	pRSAPubKeyBlob	[IN] RSA公钥数据结构
 *	pbInput			[IN] 指向待运算的原始数据缓冲区
 *	ulInputLen		[IN] 待运算原始数据的长度，必须为公钥模长
 *	pbOutput		[OUT] 指向RSA公钥运算结果缓冲区，如果该参数为NULL，则由pulOutputLen返回运算结果的实际长度
 *	pulOutputLen	[OUT] 调用前表示pbOutput缓冲区的长度，返回RSA公钥运算结果的实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtRSAPubKeyOperation)(
	  IN DEVHANDLE hDev,
	  IN RSAPUBLICKEYBLOB* pRSAPubKeyBlob,
	  IN BYTE* pbInput,
	  IN ULONG ulInputLen,
	  OUT BYTE* pbOutput,
	  OUT ULONG* pulOutputLen
	  );

/*
 *	直接使用外部传入的RSA私钥对输入数据做私钥运算并输出结果
 *	hDev			[IN] 设备句柄
 *	pRSAPriKeyBlob	[IN] RSA私钥数据结构
 *	pbInput			[IN] 指向待运算数据缓冲区
 *	ulInputLen		[IN] 待运算数据的长度，必须为公钥模长
 *	pbOutput		[OUT] RSA私钥运算结果，如果该参数为NULL，则由pulOutputLen返回运算结果的实际长度
 *	pulOutputLen	[OUT] 调用前表示pbOutput缓冲区的长度，返回RSA私钥运算结果的实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtRSAPriKeyOperation)(
	  IN DEVHANDLE hDev,
	  IN RSAPRIVATEKEYBLOB* pRSAPriKeyBlob,
	  IN BYTE* pbInput,
	  IN ULONG ulInputLen,
	  OUT BYTE* pbOutput,
	  OUT ULONG* pulOutputLen
	  );

/*
 *	生成ECC签名密钥对并输出签名公钥。
 *	hContainer		[IN] 容器句柄
 *	ulBitsLen		[IN] 密钥模长
 *	pBlob			[OUT] 返回ECC公钥数据结构
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenECCKeyPair)(
	  IN HCONTAINER hContainer, 
	  IN ULONG ulAlgId,
	  OUT ECCPUBLICKEYBLOB *pBlob
	  );

/*
 *	导入ECC公私钥对
 *	hContainer		[IN] 容器句柄
 *	pbWrapedData	[IN] 加密保护的ECC加密公私钥对密文
 *	ulWrapedLen		[IN] 数据长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ImportECCKeyPair)(
	  IN HCONTAINER hContainer, 
	  IN PENVELOPEDKEYBLOB pEnvelopedKeyBlob
	  );
/*
 *	ECC数字签名。采用ECC算法和指定私钥hKey，对指定数据pbData进行数字签名。签名后的结果存放到pbSignature缓冲区，设置pulSignLen为签名值的长度
 *	hContainer		[IN] 用来签名的私钥所在容器句柄
 *	pbData			[IN] 被签名的数据
 *	ulDataLen		[IN] 待签名数据长度，必须小于密钥模长
 *	pbSignature		[OUT] 签名值，为NULL时用于获得签名值的长度
 *	pulSigLen		[IN OUT] 返回签名值长度的指针 
 */
typedef ULONG (DEVAPI * FUNC_SKF_ECCSignData)(
	  IN HANDLE hContainer,
	  IN BYTE *pbData, 
	  IN ULONG ulDataLen, 
	  OUT PECCSIGNATUREBLOB pSignature
	  );

/*
 *	用ECC公钥对数据进行验签
 *	hDev			[IN] 设备句柄
 *	pECCPubKeyBlob	[IN] ECC公钥数据结构
 *	pbData			[IN] 待验证签名的数据
 *	ulDataLen		[IN] 数据长度
 *	pbSignature		[IN] 待验证的签名值
 *	ulSigLen		[IN] 签名值长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ECCVerify)(
	  IN DEVHANDLE			hDev,
	  IN ECCPUBLICKEYBLOB*	pECCPubKeyBlob,
	  IN BYTE*				pbData,
	  IN ULONG				ulDataLen,
	  IN PECCSIGNATUREBLOB pSignature
	  );

/*
 *	生成会话密钥并用外部公钥加密输出。
 *	hContainer		[IN] 容器句柄
 *	ulAlgID			[IN] 会话密钥的算法标识
 *	pPubKey			[IN] 用来导出密钥的密钥结构
 *	pbData			[OUT] 导出的加密会话密钥密文
 *	pulDataLen		[OUT] 返回导出数据长度
 *	phSessionKey	[OUT] 会话密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_ECCExportSessionKey)(
	  IN HCONTAINER hContainer,
	  IN ULONG ulAlgID,
	  IN ECCPUBLICKEYBLOB* pPubKey,
	  OUT PECCCIPHERBLOB pData,
	  OUT HANDLE* phSessionKey
	  );

/*
 *	使用外部传入的ECC公钥对输入数据做加密运算并输出结果
 *	hDev			[IN] 设备句柄
 *	pECCPubKeyBlob	[IN] ECC公钥数据结构
 *	pbPlainText		[IN] 待加密的明文数据
 *	ulPlainTextLen	[IN] 待加密明文数据的长度
 *	pbCipherText	[OUT] 指向密文数据缓冲区，如果该参数为NULL，则由pulCipherTextLen返回密文数据的实际长度
 *	pulCipherTextLen[OUT] 调用前表示pbCipherText缓冲区的长度，返回密文数据的实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtECCEncrypt)(
	  IN DEVHANDLE hDev,
	  IN ECCPUBLICKEYBLOB* pECCPubKeyBlob,
	  IN BYTE* pbPlainText,
	  IN ULONG ulPlainTextLen,
	  OUT PECCCIPHERBLOB pbCipherText
	  );

/*
 *	使用外部传入的ECC私钥对输入数据做解密运算并输出结果
 *	hDev			[IN] 设备句柄
 *	pRSAPriKeyBlob	[IN] ECC私钥数据结构
 *	pbInput			[IN] 待解密的密文数据
 *	ulInputLen		[IN] 待解密密文数据的长度
 *	pbOutput		[OUT] 返回明文数据，如果该参数为NULL，则由pulPlainTextLen返回明文数据的实际长度
 *	pulOutputLen	[OUT] 调用前表示pbPlainText缓冲区的长度，返回明文数据的实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtECCDecrypt)(
	  IN DEVHANDLE hDev,
	  IN ECCPRIVATEKEYBLOB* pECCPriKeyBlob,
	  IN PECCCIPHERBLOB pbCipherText,
	  OUT BYTE* pbPlainText,
	  OUT ULONG* pulPlainTextLen
	  );

/*
 *	使用外部传入的ECC私钥对输入数据做签名运算并输出结果。
 *	hDev			[IN] 设备句柄
 *	pRSAPriKeyBlob	[IN] ECC私钥数据结构
 *	pbData			[IN] 待签名数据
 *	ulDataLen		[IN] 待签名数据的长度
 *	pbSignature		[OUT] 签名值，如果该参数为NULL，则由pulSignatureLen返回签名结果的实际长度
 *	pulSignatureLen	[OUT] 调用前表示pbSignature缓冲区的长度，返回签名结果的实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtECCSign)(
	  IN DEVHANDLE hDev,
	  IN ECCPRIVATEKEYBLOB* pECCPriKeyBlob,
	  IN BYTE* pbData,
	  IN ULONG ulDataLen,
	  OUT PECCSIGNATUREBLOB pSignature
	  );

/*
 *	外部使用传入的ECC公钥做签名验证
 *	hDev			[IN] 设备句柄
 *	pECCPubKeyBlob	[IN] ECC公钥数据结构
 *	pbData			[IN] 待验证数据
 *	ulDataLen		[IN] 待验证数据的长度
 *	pbSignature		[OUT] 签名值
 *	ulSignLen		[OUT] 签名值的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExtECCVerify)(
	  IN DEVHANDLE hDev,
	  IN ECCPUBLICKEYBLOB* pECCPubKeyBlob,
	  IN BYTE* pbData,
	  IN ULONG ulDataLen,
	  IN PECCSIGNATUREBLOB pSignature
	  );

/*
 *	使用ECC密钥协商算法，为计算会话密钥而产生协商参数，返回临时ECC密钥对的公钥及协商句柄
 *	hContainer		[IN] 容器句柄
 *	ulAlgId			[IN] 会话密钥算法标识
 *	pTempECCPubKeyBlob	[OUT] 发起方临时ECC公钥
 *	pbID			[IN] 发起方的ID
 *	ulIDLen			[IN] 发起方ID的长度，不大于32
 *	phAgreementHandle	[OUT] 返回的密钥协商句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenerateAgreementDataWithECC)(
	  IN HCONTAINER hContainer,
	  IN ULONG ulAlgId,
	  OUT ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,
	  IN BYTE* pbID,
	  IN ULONG ulIDLen,
	  OUT HANDLE *phAgreementHandle
	  );

/*
 *	使用ECC密钥协商算法，产生协商参数并计算会话密钥，输出临时ECC密钥对公钥，并返回产生的密钥句柄
 *	hContainer					[IN] 容器句柄
 *	ulAlgId						[IN] 会话密钥算法标识
 *	pSponsorECCPubKeyBlob		[IN] 发起方的ECC公钥
 *	pSponsorTempECCPubKeyBlob	[IN] 发起方的临时ECC公钥
 *	pTempECCPubKeyBlob			[OUT] 响应方的临时ECC公钥
 *	pbID						[IN] 响应方的ID
 *	ulIDLen						[IN] 响应方ID的长度，不大于32
 *	pbSponsorID					[IN] 发起方的ID
 *	ulSponsorIDLen				[IN] 发起方ID的长度，不大于32
 *	phKeyHandle					[OUT] 返回的对称算法密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenerateAgreementDataAndKeyWithECC)(
	  IN HANDLE hContainer,
	  IN ULONG ulAlgId,
	  IN ECCPUBLICKEYBLOB* pSponsorECCPubKeyBlob,
	  IN ECCPUBLICKEYBLOB* pSponsorTempECCPubKeyBlob,
	  OUT ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,
	  IN BYTE* pbID,
	  IN ULONG ulIDLen,
	  IN BYTE *pbSponsorID,
	  IN ULONG ulSponsorIDLen,
	  OUT HANDLE *phKeyHandle
	  );

/*
 *	使用ECC密钥协商算法，使用自身协商句柄和响应方的协商参数计算会话密钥，同时返回会话密钥句柄
 *	hAgreementHandle			[IN] 密钥协商句柄
 *	pECCPubKeyBlob				[IN] 外部输入的响应方ECC公钥
 *	pTempECCPubKeyBlob			[IN] 外部输入的响应方临时ECC公钥
 *	pbID						[IN] 响应方的ID
 *	ulIDLen						[IN] 响应方ID的长度，不大于32
 *	phKeyHandle					[OUT] 返回的密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_GenerateKeyWithECC)(
	  IN HANDLE hAgreementHandle,
	  IN ECCPUBLICKEYBLOB* pECCPubKeyBlob,
	  IN ECCPUBLICKEYBLOB* pTempECCPubKeyBlob,
	  IN BYTE* pbID,
	  IN ULONG ulIDLen,
	  OUT HANDLE *phKeyHandle
	  );

/*
 *	导出容器中的签名公钥或者加密公钥
 *	hContainer		[IN] 容器句柄
 *	bSignFlag		[IN] TRUE表示导出签名公钥，FALSE表示导出加密公钥
 *	pbBlob			[OUT] 指向RSA公钥结构（RSAPUBLICKEYBLOB）或者ECC公钥结构（ECCPUBLICKEYBLOB），如果此参数为NULL时，由pulBlobLen返回pbBlob的长度
 *	pulBlobLen		[IN OUT] 调用时表示pbBlob的长度，返回导出公钥结构的大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExportPublicKey)(
	  IN HCONTAINER hContainer,
	  IN BOOL32 bSignFlag,
	  OUT BYTE* pbBlob,
	  OUT ULONG* pulBlobLen
	  );

/*
 *	导入会话密钥
 *	hContainer		[IN] 容器句柄
 *	ulAlgID			[IN] 会话密钥的算法标识
 *	pbWrapedData	[IN] 要导入的数据
 *	ulWrapedLen		[IN] 数据长度
 *	phKey			[OUT] 返回会话密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_ImportSessionKey)(
	  IN HCONTAINER hContainer,
	  IN ULONG ulAlgID, 
	  IN BYTE *pbWrapedData,
	  IN ULONG ulWrapedLen,
	  OUT HANDLE* phKey
	  );

/*
 *	设置明文对称密钥，返回密钥句柄
 *	hContainer		[IN] 容器句柄
 *	pbKey			[IN] 指向会话密钥值的缓冲区
 *	ulAlgID			[IN] 会话密钥的算法标识
 *	phKey			[OUT] 返回会话密钥句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_SetSymmKey)(
	  IN DEVHANDLE hDev,
	  IN BYTE* pbKey, 
	  IN ULONG ulAlgID,
	  OUT HANDLE* phKey
	  );

/*
 *	数据加密初始化。设置数据加密的算法相关参数。
 *	hKey			[IN] 加密密钥句柄
 *	EncryptParam	[IN] 分组密码算法相关参数：算法标识号、密钥长度、初始向量、初始向量长度、填充方法、加密模式、反馈值的位长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_EncryptInit)(
	  IN HANDLE hKey, 
	  IN BLOCKCIPHERPARAM EncryptParam
	  );

/*
 *	单一分组数据的加密操作。
	用指定加密密钥对指定数据进行加密，被加密的数据只包含一个分组，加密后的密文保存到指定的缓冲区中。
	SKF_Encrypt只对单个分组数据进行加密，在调用SKF_Encrypt之前，必须调用SKF_EncryptInit初始化加密操作。
	SKF_Encypt等价于先调用SKF_EncryptUpdate再调用SKF_EncryptFinal。
 *	hKey			[IN] 加密密钥句柄
 *	pbData			[IN] 待加密数据
 *	ulDataLen		[IN] 待加密数据长度
 *	pbEncryptedData [OUT] 加密后的数据缓冲区指针
 *	pulEncryptedLen [IN OUT] 输入，给出的缓冲区大小；输出，返回加密后的数据
长度
 *	成功: SAR_OK
 *	失败: SAR_FAIL SAR_MEMORYERR SAR_UNKNOWNERR  SAR_INVALIDPARAMERR SAR_BUFFER_TOO_SMALL   
 */
typedef ULONG (DEVAPI * FUNC_SKF_Encrypt)(
	  HANDLE	hKey, 
	  BYTE*		pbData, 
	  ULONG		ulDataLen, 
	  BYTE*		pbEncryptedData, 
	  ULONG*	pulEncryptedLen
	  );

/*
 *	多个分组数据的加密操作。
	用指定加密密钥对指定数据进行加密，被加密的数据包含多个分组，加密后的密文保存到指定的缓冲区中。
	SKF_EncryptUpdate对多个分组数据进行加密，在调用SKF_EncryptUpdate之前，必须调用SKF_EncryptInit初始化加密操作；
	在调用SKF_EncryptUpdate之后，必须调用SKF_EncryptFinal结束加密操作。
 *	hKey			[IN] 加密密钥句柄
 *	pbData			[IN] 待加密数据
 *	ulDataLen		[IN] 待加密数据长度
 *	pbEncryptedData [OUT] 加密后的数据缓冲区指针
 *	pulEncryptedLen [OUT] 返回加密后的数据长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_EncryptUpdate)(
	  IN HANDLE		hKey,
	  IN BYTE*		pbData,
	  IN ULONG		ulDataLen,
	  OUT BYTE*		pbEncryptedData, 
	  OUT ULONG*	pulEncryptedLen
	  );

/*
 *	结束多个分组数据的加密，返回剩余加密结果。
	先调用SKF_EncryptInit初始化加密操作，
	再调用SKF_EncryptUpdate对多个分组数据进行加密，
	最后调用SKF_EncryptFinal结束多个分组数据的加密。
 *	hKey			[IN] 加密密钥句柄
 *	pbEncryptedData [OUT] 加密结果的缓冲区
 *	pulEncryptedLen [OUT] 加密结果的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_EncryptFinal)(
	  IN HANDLE hKey, 
	  OUT BYTE *pbEncryptedData, 
	  OUT ULONG *ulEncryptedDataLen 
	  );

/*
 *	数据解密初始化，设置解密密钥相关参数。
	调用SKF_DecryptInit之后，可以调用SKF_Decrypt对单个分组数据进行解密，
	也可以多次调用SKF_DecryptUpdate之后再调用SKF_DecryptFinal完成对多个分组数据的解密。
 *	hKey [IN] 解密密钥句柄
 *	DecryptParam [IN] 分组密码算法相关参数：算法标识号、密钥长度、初始向量、初始向量长度、填充方法、加密模式、反馈值的位长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_DecryptInit)(
	  IN HANDLE hKey, 
	  IN BLOCKCIPHERPARAM DecryptParam
	  );

/*
 *	单个分组数据的解密操作
	用指定解密密钥对指定数据进行解密，被解密的数据只包含一个分组，解密后的明文保存到指定的缓冲区中
	SKF_Decrypt只对单个分组数据进行解密，在调用SKF_Decrypt之前，必须调用SKF_DecryptInit初始化解密操作
	SKF_Decypt等价于先调用SKF_DecryptUpdate再调用SKF_DecryptFinal
 *	hKey			[IN] 解密密钥句柄
 *	pbEncryptedData [IN] 待解密数据
 *	ulEncryptedLen	[IN] 待解密数据长度
 *	pbData			[OUT] 指向解密后的数据缓冲区指针，当为NULL时可获得解密后的数据长度
 *	pulDataLen		[IN OUT] 返回解密后的数据长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_Decrypt)(
	  IN HANDLE hKey, 
	  IN BYTE*	pbEncryptedData, 
	  IN ULONG	ulEncryptedLen, 
	  OUT BYTE* pbData,
	  OUT ULONG* pulDataLen
	  );

/*
*	多个分组数据的解密操作。
	用指定解密密钥对指定数据进行解密，被解密的数据包含多个分组，解密后的明文保存到指定的缓冲区中。
	SKF_DecryptUpdate对多个分组数据进行解密，在调用SKF_DecryptUpdate之前，必须调用SKF_DecryptInit初始化解密操作；
	在调用SKF_DecryptUpdate之后，必须调用SKF_DecryptFinal结束解密操作。
 *	hKey			[IN] 解密密钥句柄
 *	pbEncryptedData [IN] 待解密数据
 *	ulEncryptedLen	[IN] 待解密数据长度
 *	pbData			[OUT] 指向解密后的数据缓冲区指针
 *	pulDataLen		[IN OUT] 返回解密后的数据长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_DecryptUpdate)(
	  IN HANDLE hKey, 
	  IN BYTE*	pbEncryptedData, 
	  IN ULONG	ulEncryptedLen, 
	  OUT BYTE* pbData,
	  OUT ULONG* pulDataLen
	  );

/*
 *	结束多个分组数据的解密。
 *	hKey				[IN] 解密密钥句柄
 *	pbPlainText			[OUT] 指向解密结果的缓冲区，如果此参数为NULL时，由pulPlainTextLen返回解密结果的长度
 *	pulDecyptedDataLen	[IN OUT] 调用时表示pbPlainText缓冲区的长度，返回解密结果的长度 
 */
typedef ULONG (DEVAPI * FUNC_SKF_DecryptFinal)(
	  IN HANDLE hKey, 
	  OUT BYTE *pbPlainText, 
	  OUT ULONG *pulPlainTextLen
	  );

/*
 *	初始化消息杂凑计算操作，指定计算消息杂凑的算法。
 *	hDev			[IN] 连接设备时返回的设备句柄
 *	ulAlgID			[IN] 杂凑算法标识
 *	phHash			[OUT] 杂凑对象句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_DigestInit)(
	  IN DEVHANDLE	hDev,
	  IN ULONG		ulAlgID,
	  IN ECCPUBLICKEYBLOB *pPubKey, 
	  IN unsigned char *pucID, 
	  IN ULONG ulIDLen,
	  OUT HANDLE*	phHash
	  );

/*
 *	对单一分组的消息进行杂凑计算。
 *	hHash			[IN] 杂凑对象句柄
 *	pbData			[IN] 指向消息数据的缓冲区
 *	ulDataLen		[IN] 消息数据的长度
 *	pbHashData		[OUT] 杂凑数据缓冲区指针，当此参数为NULL时，由pulHashLen返回杂凑结果的长度
 *	pulHashLen		[IN OUT] 调用时表示pbHashData缓冲区的长度，返回杂凑结果的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_Digest)(
	  IN HANDLE hHash, 
	  IN BYTE *pbData, 
	  IN ULONG ulDataLen, 
	  OUT BYTE *pbHashData, 
	  OUT ULONG *pulHashLen
	  );

/*
 *	对多个分组的消息进行杂凑计算。
 *	hHash			[IN] 杂凑对象句柄
 *	pbPart			[IN] 指向消息数据的缓冲区
 *	ulPartLen		[IN] 消息数据的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_DigestUpdate)(
	  IN HANDLE hHash,
	  IN BYTE *pbData,
	  IN ULONG ulDataLen
	  );

/*
 *	结束多个分组消息的杂凑计算操作，将杂凑保存到指定的缓冲区。
 *	hHash			[IN] 哈希对象句柄
 *	pHashData		[OUT] 返回的杂凑数据缓冲区指针，如果此参数NULL时，由pulHashLen返回杂凑结果的长度
 *	pulHashLen		[IN OUT] 调用时表示杂凑结果的长度，返回杂凑数据的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_DigestFinal)(
	  IN HANDLE hHash, 
	  OUT BYTE *pHashData,
	  OUT ULONG *pulHashLen
	  );

/*
 *	初始化消息认证码计算操作，设置计算消息认证码的密钥参数，并返回消息认证码句柄。
 *	hKey			[IN] 计算消息认证码的密钥句柄
 *	MacParam		[IN] 消息认证计算相关参数，包括初始向量、初始向量长度、填充方法等
 *	phMac			[OUT] 消息认证码对象句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_MacInit)(
	  IN HANDLE hKey, 
	  IN BLOCKCIPHERPARAM* MacParam, 
	  OUT HANDLE *phMac
	  );

/*
 *	SKF_Mac计算单一分组数据的消息认证码。
 *	hMac			[IN] 消息认证码句柄
 *	pbData			[IN] 指向待计算数据的缓冲区
 *	ulDataLen		[IN] 待计算数据的长度
 *	pbMacData		[OUT] 指向计算后的Mac结果，如果此参数为NULL时，由pulMacLen返回计算后Mac结果的长度
 *	pulMacLen		[IN OUT] 调用时表示pbMacData缓冲区的长度，返回计算Mac结果的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_Mac)(
	  IN HANDLE hMac, 
	  IN BYTE * pbData,
	  IN ULONG ulDataLen, 
	  OUT BYTE *pbMacData, 
	  OUT ULONG *pulMacLen
	  );

/*
 *	计算多个分组数据的消息认证码。
 *	hMac			[IN] 消息认证码句柄
 *	pbData			[IN] 指向待计算数据的缓冲区
 *	plDataLen		[IN] 待计算数据的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_MacUpdate)(
	  IN HANDLE hMac,
	  IN BYTE*	pbData, 
	  IN ULONG	ulDataLen
	  );

/*
 *	结束多个分组数据的消息认证码计算操作
 *	hMac			[IN] 消息认证码句柄
 *	pbMacData		[OUT] 指向消息认证码的缓冲区，当此参数为NULL时，由pulMacDataLen返回消息认证码返回的长度
 *	pulMacDataLen	[OUT] 调用时表示消息认证码缓冲区的最大长度，返回消息认证码的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_MacFinal)(
	  IN HANDLE hMac,
	  OUT BYTE*	pbMacData,
	  OUT ULONG* pulMacDataLen
	  );

/*
 *	关闭会话密钥、杂凑、消息认证码句柄。
 *	hHandle			[IN] 要关闭的对象句柄
 */
typedef ULONG (DEVAPI * FUNC_SKF_CloseHandle)(
	  IN HANDLE hHandle
	  );

/************************************************************************/
/*  7. 其它													            */
/*	SKF_Transmit														*/
/*	SKF_ImportCertificate												*/
/*	SKF_ExportCertificate												*/
/*	SKF_GetContainerProperty											*/
/*	SKF_GetContainerType												*/
/*	SKF_PrvKeyDecrypt													*/
/*	SKF_RSADecrypt														*/
/************************************************************************/

/*
 *	将命令直接发送给设备，并返回结果
 *	hDev			[IN] 设备句柄
 *	pbCommand		[IN] 设备命令
 *	ulCommandLen	[IN] 命令长度
 *	pbData			[OUT] 返回结果数据
 *	pulDataLen		[OUT] 输入时表示结果数据缓冲区长度，输出时表示结果数据实际长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_Transmit)(
	  IN DEVHANDLE hDev, 
	  IN BYTE* pbCommand,
	  IN ULONG ulCommandLen,
	  OUT BYTE* pbData,
	  OUT ULONG* pulDataLen
	  );

/*
 *	往容器中导入签名证书或者加密证书
 *	hContainer		[IN] 容器句柄
 *	bSignFlag		[IN] TRUE表示导入签名证书，FALSE表示导入加密证书
 *	pbCert			[IN] 指向证书数据的缓冲区
 *	ulCertLen		[IN] 证书数据的长度
 */
typedef ULONG (DEVAPI * FUNC_SKF_ImportCertificate)(
	  IN HCONTAINER hContainer,
	  IN BOOL32 bSignFlag,
	  IN BYTE* pbCert,
	  IN ULONG ulCertLen
	  );

/*
 *	导出容器中的签名证书或者加密证书
 *	hContainer		[IN] 容器句柄
 *	bSignFlag		[IN] TRUE表示导出签名证书，FALSE表示导出加密证书
 *	pbCert			[OUT] 指向证书数据的缓冲区
 *	pulCertLen		[IN OUT] 调用时表示pbCert的长度，返回导出证书的大小
 */
typedef ULONG (DEVAPI * FUNC_SKF_ExportCertificate)(
	  IN HCONTAINER hContainer,
	  IN BOOL32 bSignFlag,
	  OUT BYTE* pbCert,
	  IN OUT ULONG* pulCertLen
	  );

/*
 *	获取容器的属性
 *	hContainer		[IN] 容器句柄
 *	pulConProperty	[OUT] 获得的容器属性。指针指向的值为0表示未知、尚未分配属性或者为空容器，为1表示为RSA容器，为2表示为ECC容器。
 */
typedef ULONG (DEVAPI * FUNC_SKF_GetContainerProperty)(
	  IN HCONTAINER hContainer, 
	  OUT ULONG *pulConProperty
	  );

typedef ULONG (DEVAPI * FUNC_SKF_GetContainerType)(
	  IN HCONTAINER hContainer, 
	  OUT ULONG *pulConProperty
	  );

/*
*	获取ECC的Z值
*	hDev			[IN] 设备句柄
*	pECCPubKeyBlob	[IN] ECC公钥数据结构
*	pUserID			[IN] 用户ID
*	iUserIDLen		[IN] 用户ID长度
*	pDataOut		[OUT] 指向Z值的缓冲区
*	piDataOutLen	[IN OUT] 调用时表示pDataOut的长度，返回Z值的大小
*/
/* UID使用默认的 "1234567812345678" */
typedef ULONG (DEVAPI * FUNC_SKF_ECCGetZ)(
	  IN DEVHANDLE hDev, 
	  IN ECCPUBLICKEYBLOB* pECCPubKeyBlob, 
	  IN BYTE *pUserID, 
	  IN ULONG iUserIDLen,
	  OUT BYTE *pDataOut, 
	  IN OUT ULONG *piDataOutLen
	  );

/*
*	ECC私钥解密 (此接口按江南所要求添加)
*	hContainer		[IN] 容器句柄
*	dwKeySpec   	[IN] 私钥类型，1为加密私钥，2为签名私钥
*	pCipherText		[IN] 加密数据结构
*	pbData  		[OUT] 指向解密结果的缓冲区,如果值为NULL，用于取得解密后数据长度
*	pdwDataLen  	[IN OUT] 调用时表示pbData的长度，返回解密数据的大小
*/
typedef ULONG (DEVAPI * FUNC_SKF_PrvKeyDecrypt)(
	  IN HCONTAINER hContainer, 
	  IN DWORD dwKeySpec, 
	  IN PECCCIPHERBLOB pCipherText, 
	  OUT BYTE *pbData, 
	  IN OUT DWORD *pdwDataLen
	  );

typedef ULONG (DEVAPI * FUNC_SKF_PriEccDecrypt)(
	  IN HCONTAINER hContainer,
	  IN BOOL32 bSign,
	  IN PECCCIPHERBLOB pCipherText,
	  OUT BYTE *pbData,
	  IN OUT ULONG *pdwDataLen
	  );

/*
*	RSA私钥解密 
*	hContainer		[IN] 容器句柄
*	dwKeySpec   	[IN] 私钥类型，1为加密私钥，2为签名私钥
*	pbIn			[IN] 待解密的数据
*	ulInLen			[IN] 待解密数据的长度
*	pbOut  			[OUT] 指向解密结果的缓冲区。如果值为NULL，用于取得解密后数据长度
*	pulOutLen  		[IN OUT] 调用时表示pbOut的长度，返回解密数据的大小
*/
typedef ULONG (DEVAPI * FUNC_SKF_RSADecrypt)(
	IN HCONTAINER hContainer,
	IN DWORD dwKeySpec, 
	IN BYTE *pbIn,
	IN ULONG  ulInLen,
	OUT BYTE *pbOut,
	IN OUT ULONG *pulOutLen
	);

typedef ULONG (DEVAPI * FUNC_SKF_PriRsaDecrypt)(
	  IN HCONTAINER hContainer,
	  IN BOOL32 bSign,
	  IN BYTE *pbData,
	  IN ULONG ulDataLen,
	  OUT BYTE *pbPlain,
	  IN OUT ULONG *pulPlainLen
	  );

/*
*	使用容器中指定的私钥解密数据
*	hContainer			[IN] 容器句柄
*	bSignFlag			[IN] TRUE表示使用签名私钥解密，FALSE表示使用加密私钥解密
*	pbWrappedData		[IN] 待解密的数据 当容器为ECC类型时，此参数为ECCCIPHERBLOB密文数据，当容器为RSA类型时，此参数为RSA公钥加密后的数据。
*	ulWrappedDataLen	[IN] 待解密的数据长度
*	pbData				[OUT] 指向解密后的数据缓冲区指针，当为NULL时可获得解密后的数据长度。
*	pulDataLen			[IN OUT] 输入时表示结果数据缓冲区长度，输出时表示结果数据实际长度。
*/
typedef ULONG (DEVAPI * FUNC_SKFX_PriKeyDecrypt)(
	IN HCONTAINER hContainer,
	IN BOOL32 bSignFlag,
	IN BYTE *pbWrappedData,
	IN ULONG ulWrappedDataLen,
	OUT BYTE *pbData,
	IN OUT ULONG *pulDataLen
	);

// 赢达信扩展函数
/*
*	使用容器中解密私钥解密数据
*	hContainer			[IN] 密钥容器句柄
*	pbCiphertext		[IN] 待解密的数据。此参数为ECCCIPHERBLOB密文数据
*	ulCiphertextLen		[IN] 待解密数据长度
*	pbPlaintext			[OUT] 解密后的明文，如果该参数为NULL，将由pulPlaintextLen返回所需要的内存空间大小
*	pulPlaintextLen		[IN OUT] 输入时表示pbPlaintext缓冲区的长度，输出时表示密文结果的长度
*/
// typedef ULONG (DEVAPI * FUNC_SKF_ECCDecrypt)(
// 	  IN HCONTAINER hContainer,
// 	  IN BYTE *pbCiphertext,
// 	  IN ULONG ulCiphertextLen,
// 	  OUT BYTE *pbPlaintext,
// 	  IN OUT ULONG *pulPlaintextLen
// 	  );
typedef ULONG (DEVAPI * FUNC_SKF_ECCDecrypt)(
	IN HCONTAINER hContainer, 
	IN BOOL32 bSignFlag, 
	IN PECCCIPHERBLOB pCipherText, 
	OUT BYTE *pbData, 
	IN OUT DWORD *pdwDataLen
	);

/*
*	使用容器中解密私钥解密数据
*	hContainer		[IN] 密钥容器句柄
*	pCipherText		[IN] 待解密的数据。此参数为ECCCIPHERBLOB密文数据
*	pbPlaintext		[OUT] 解密后的明文，如果该参数为NULL，将由pulPlaintextLen返回所需要的内存空间大小
*	pulPlaintextLen	[IN OUT] 输入时表示pbPlaintext缓冲区的长度，输出时表示密文结果的长度
*/
typedef ULONG (DEVAPI * FUNC_SKF_ECCDecryptEx)(
	  IN HCONTAINER hContainer,
	  IN PECCCIPHERBLOB pCipherText,
	  OUT BYTE *pbPlaintext,
	  IN OUT ULONG *pulPlaintextLen
	  );

/*
*	RSA解密
*	hContainer		[IN] 密钥容器句柄
*	pbIn			[IN] 输入数据
*	ulInLen			[IN] 输入数据长度
*	pbOut			[OUT] 输出数据
*	pulOutLen		[IN OUT] 输入时表示pbOut缓冲区的长度，输出时表示密文结果的长度
*	bSignFlag       [IN] 非0，表示使用签名密钥对；0，表示加密密钥对
*/
typedef ULONG (DEVAPI * FUNC_SKF_RSAPriKeyOperation)(
	  IN HCONTAINER hContainer,
	  IN BYTE *pbIn,
	  IN ULONG ulInLen,
	  OUT BYTE *pbOut,
	  IN OUT ULONG *pulOutLen,
	  IN BOOL32 bSignFlag
	  );

#ifdef __cplusplus
}
#endif

#endif