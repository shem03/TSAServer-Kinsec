#ifndef _KTSDKERR__H
#define _KTSDKERR__H

#define KTSDK_ERR_OK						0
#define KTSDK_ERR_INDATA					1001
#define KTSDK_ERR_MEMORY					1002
#define KTSDK_ERR_NOTSUPPORTED				1003
#define KTSDK_ERR_OBJNOTFOUND				1004
#define KTSDK_ERR_FILE						1005

#define KTSDK_ERR_INITIALIZE				1011
#define KTSDK_ERR_FINALIZE					1012

#define KTSDK_ERR_BASE64ENCODE				1021
#define KTSDK_ERR_JAVADATAENCODE			1022
#define KTSDK_ERR_CERTENCODE				1023
#define KTSDK_ERR_GETCERTINFO				1024

#define KTSDK_ERR_HASHDATA					1031
#define KTSDK_ERR_HASHDATANOTMATCH			1032
#define KTSDK_ERR_ENCRYPTDATA				1033
#define KTSDK_ERR_DECRYPTDATA				1034

#define KTSDK_ERR_RSASIGN					1041
#define KTSDK_ERR_RSAVERIFYSIGN				1042
#define KTSDK_ERR_RSAENCRYPT				1043
#define KTSDK_ERR_RSADECRYPT				1044

#define KTSDK_ERR_SM2ENCODE					1051
#define KTSDK_ERR_SM3HASH					1052
#define KTSDK_ERR_SM2YCL					1053
#define KTSDK_ERR_SM2SIGN					1054
#define KTSDK_ERR_SM2VERIFYSIGN				1055
#define KTSDK_ERR_SM2ENCRYPT				1056
#define KTSDK_ERR_SM2DECRYPT				1057

#define KTSDK_ERR_PKCS7SIGN						1061
#define KTSDK_ERR_PKCS7VERIFY					1062
#define KTSDK_ERR_GETPKCS7SIGNINFO				1063
#define KTSDK_ERR_PKCS7ENVELOPE					1064
#define KTSDK_ERR_PKCS7UNENVELOPE				1065
#define KTSDK_ERR_PKCS7SIGNANDENVELOPE			1066
#define KTSDK_ERR_PKCS7UNENVELOPEANDVERIFY		1067
#define KTSDK_ERR_GETPKCS7SIGNANDENVELOPEINFO	1068

#define KTSDK_ERR_DEVICE_LOADLIBRARY		1101
#define KTSDK_ERR_DEVICE_GETFUNCTIONLIST	1102
#define KTSDK_ERR_DEVICE_INITIALIZE			1103
#define KTSDK_ERR_DEVICE_FINALIZE			1104
#define KTSDK_ERR_DEVICE_GETDEVICECOUNT		1105
#define KTSDK_ERR_DEVICE_DEVICENOTFOUND		1106
#define KTSDK_ERR_DEVICE_GETINFO			1107
#define KTSDK_ERR_DEVICE_INITDEVICE			1108

#define KTSDK_ERR_DEVICE_OPENSESSION		1111
#define KTSDK_ERR_DEVICE_SESSIONNOTOPENED	1112
#define KTSDK_ERR_DEVICE_CLOSESESSION		1113
#define KTSDK_ERR_DEVICE_LOGIN				1114
#define KTSDK_ERR_DEVICE_LOGOUT				1115
#define KTSDK_ERR_DEVICE_SETPIN				1116
#define KTSDK_ERR_DEVICE_GETREMAINRETRYCOUT	1117
#define KTSDK_ERR_DEVICE_GETSESSIONINFO		1118

#define KTSDK_ERR_DEVICE_LOOKUPCERT			1121
#define KTSDK_ERR_DEVICE_CERTNOTFOUND		1122
#define KTSDK_ERR_DEVICE_READCERT			1123
#define KTSDK_ERR_DEVICE_WRITECERT			1124
#define KTSDK_ERR_DEVICE_DELETECERT			1125

#define KTSDK_ERR_DEVICE_LOOKUPPUBKEY		1131
#define KTSDK_ERR_DEVICE_PUBKEYNOTFOUND		1132
#define KTSDK_ERR_DEVICE_GETPUBKEY			1133
#define KTSDK_ERR_DEVICE_GENKEY				1134
#define KTSDK_ERR_DEVICE_IMPORTPUBKEY		1135
#define KTSDK_ERR_DEVICE_DELETEPUBKEY		1136

#define KTSDK_ERR_DEVICE_LOOKUPPRVKEY		1141
#define KTSDK_ERR_DEVICE_PRVKEYNOTFOUND		1142
#define KTSDK_ERR_DEVICE_IMPORTPRVKEY		1143
#define KTSDK_ERR_DEVICE_DELETEPRVKEY		1144

#define KTSDK_ERR_DEVICE_RSASIGN			1151
#define KTSDK_ERR_DEVICE_RSAVERIFYSIGN		1152
#define KTSDK_ERR_DEVICE_RSAENCRYPT			1153
#define KTSDK_ERR_DEVICE_RSADECRYPT			1154

#define KTSDK_ERR_DEVICE_SM3HASH			1161
#define KTSDK_ERR_DEVICE_SM2YCL				1162
#define KTSDK_ERR_DEVICE_SM2SIGN			1163
#define KTSDK_ERR_DEVICE_SM2VERIFYSIGN		1164
#define KTSDK_ERR_DEVICE_SM2ENCRYPT			1165
#define KTSDK_ERR_DEVICE_SM2DECRYPT			1166

#define KTSDK_ERR_DEVICE_IMPORTSYMMKEY		1171
#define KTSDK_ERR_DEVICE_ENCRYPTINIT		1172
#define KTSDK_ERR_DEVICE_ENCRYPTUPDATE		1173
#define KTSDK_ERR_DEVICE_ENCRYPTFINAL		1174
#define KTSDK_ERR_DEVICE_DECRYPTINIT		1175
#define KTSDK_ERR_DEVICE_DECRYPTUPDATE		1176
#define KTSDK_ERR_DEVICE_DECRYPTFINAL		1177
#define KTSDK_ERR_DEVICE_DELETESYMMKEY		1178

#define KTSDK_ERR_DEVICE_ENUMFILE			1181
#define KTSDK_ERR_DEVICE_CREATEFILE			1182
#define KTSDK_ERR_DEVICE_DELETEFILE			1183
#define KTSDK_ERR_DEVICE_GETFILEINFO		1184
#define KTSDK_ERR_DEVICE_READFILE			1185
#define KTSDK_ERR_DEVICE_WRITEFILE			1186
#define KTSDK_ERR_DEVICE_LOOKUPFILE			1187
#define KTSDK_ERR_DEVICE_FILENOTFOUND		1188
#define KTSDK_ERR_DEVICE_FILEEXISTS			1189

// skf??????
#define KTSDK_ERR_SKF_OK					0
#define KTSDK_ERR_SKF_PARAMETER				2101
#define KTSDK_ERR_SKF_NOTSUPPORTED			2102
#define KTSDK_ERR_SKF_MEMORY				2103
#define KTSDK_ERR_SKF_BASE64				2104
#define KTSDK_ERR_SKF_CERT					2105
#define KTSDK_ERR_SKF_USERCANCEL			2106
#define KTSDK_ERR_SKF_LOADDLL				2107
#define KTSDK_ERR_SKF_INIT					2108

#define KTSDK_ERR_SKF_DEV_NOTFOUND			2111
#define KTSDK_ERR_SKF_DEV_OPEN				2112
#define KTSDK_ERR_SKF_DEV_NOTOPEN			2113
#define KTSDK_ERR_SKF_DEV_GETINFO			2114
#define KTSDK_ERR_SKF_DEV_GENRANDOM			2115
#define KTSDK_ERR_SKF_DEV_AUTH				2116

#define KTSDK_ERR_SKF_APPLICATION_NOTFOUND	2121
#define KTSDK_ERR_SKF_APPLICATION_OPEN		2122
#define KTSDK_ERR_SKF_APPLICATION_CREATE	2123
#define KTSDK_ERR_SKF_APPLICATION_DELETE	2124

#define KTSDK_ERR_SKF_CONTAINER_NOTFOUND	2131
#define KTSDK_ERR_SKF_CONTAINER_OPEN		2132
#define KTSDK_ERR_SKF_CONTAINER_CREATE		2133
#define KTSDK_ERR_SKF_CONTAINER_DELETE		2134
#define KTSDK_ERR_SKF_CONTAINER_TOOMANY		2135

#define KTSDK_ERR_SKF_VERIFYPIN				2141
#define KTSDK_ERR_SKF_CHANGEPIN				2142
#define KTSDK_ERR_SKF_PINLOCKED				2143
#define KTSDK_ERR_SKF_UNLOCKPIN				2144

#define KTSDK_ERR_SKF_READCERT				2151
#define KTSDK_ERR_SKF_WRITECERT				2152
#define KTSDK_ERR_SKF_GENKEYPAIR			2153
#define KTSDK_ERR_SKF_GETPUBKEY				2154
#define KTSDK_ERR_SKF_CREATEREQ				2155
#define KTSDK_ERR_SKF_CREATEREQ_SETDN		2156
#define KTSDK_ERR_SKF_PARSEKEYPAIR			2157
#define KTSDK_ERR_SKF_IMPORTKEYPAIR			2158
#define KTSDK_ERR_SKF_GENCONTAINERNAME		2159

#define KTSDK_ERR_SKF_HASHDATA				2161
#define KTSDK_ERR_SKF_RSASIGN				2162
#define KTSDK_ERR_SKF_RSAVERIFYSIGN			2163
#define KTSDK_ERR_SKF_RSAENCRYPT			2164
#define KTSDK_ERR_SKF_RSADECRYPT			2165
#define KTSDK_ERR_SKF_SM2SIGN				2166
#define KTSDK_ERR_SKF_SM2VERIFYSIGN			2167
#define KTSDK_ERR_SKF_SM2ENCRYPT			2168
#define KTSDK_ERR_SKF_SM2DECRYPT			2169

#define KTSDK_ERR_SKF_SETSYMMKEY			2171
#define KTSDK_ERR_SKF_ENCRYPTINIT			2172
#define KTSDK_ERR_SKF_ENCRYPTUPDATE			2173
#define KTSDK_ERR_SKF_ENCRYPTFINAL			2174
#define KTSDK_ERR_SKF_DECRYPTINIT			2175
#define KTSDK_ERR_SKF_DECRYPTUPDATE			2176
#define KTSDK_ERR_SKF_DECRYPTFINAL			2177
#define KTSDK_ERR_SKF_IMPORTSESSIONKEY		2178

#define KTSDK_ERR_SKF_ENUMFILE				2181
#define KTSDK_ERR_SKF_CREATEFILE			2182
#define KTSDK_ERR_SKF_DELETEFILE			2183
#define KTSDK_ERR_SKF_GETFILEINFO			2184
#define KTSDK_ERR_SKF_READFILE				2185
#define KTSDK_ERR_SKF_WRITEFILE				2186

// could cert??????
#define KTSDK_ERR_CC_OK						0
#define KTSDK_ERR_CC_PARAMETER				3101
#define KTSDK_ERR_CC_NOTSUPPORTED			3102
#define KTSDK_ERR_CC_MEMORY					3103
#define KTSDK_ERR_CC_BASE64					3104
#define KTSDK_ERR_CC_CERT					3105
#define KTSDK_ERR_CC_USERCANCEL				3106
#define KTSDK_ERR_CC_LOADDLL				3107
#define KTSDK_ERR_CC_INIT					3108

#define KTSDK_ERR_CC_NOTFOUND				3111
#define KTSDK_ERR_CC_OPEN					3112
#define KTSDK_ERR_CC_NOTOPEN				3113
#define KTSDK_ERR_CC_GETINFO				3114
#define KTSDK_ERR_CC_GENRANDOM				3115
#define KTSDK_ERR_CC_AUTH					3116

#define KTSDK_ERR_CC_VERIFYPIN				3121
#define KTSDK_ERR_CC_CHANGEPIN				3122
#define KTSDK_ERR_CC_PINLOCKED				3123
#define KTSDK_ERR_CC_UNLOCKPIN				3124

#define KTSDK_ERR_CC_READCERT				3131
#define KTSDK_ERR_CC_WRITECERT				3132
#define KTSDK_ERR_CC_GENKEYPAIR				3133
#define KTSDK_ERR_CC_GETPUBKEY				3134
#define KTSDK_ERR_CC_CREATEREQ				3135
#define KTSDK_ERR_CC_CREATEREQ_SETDN		3136
#define KTSDK_ERR_CC_PARSEKEYPAIR			3137
#define KTSDK_ERR_CC_IMPORTKEYPAIR			3138

#define KTSDK_ERR_CC_HASHDATA				3141
#define KTSDK_ERR_CC_RSASIGN				3142
#define KTSDK_ERR_CC_RSAVERIFYSIGN			3143
#define KTSDK_ERR_CC_RSAENCRYPT				3144
#define KTSDK_ERR_CC_RSADECRYPT				3145
#define KTSDK_ERR_CC_SM2SIGN				3146
#define KTSDK_ERR_CC_SM2VERIFYSIGN			3147
#define KTSDK_ERR_CC_SM2ENCRYPT				3148
#define KTSDK_ERR_CC_SM2DECRYPT				3149

// pfx??????
#define KTSDK_ERR_PFX_OK					0
#define KTSDK_ERR_PFX_PARAMETER				4101
#define KTSDK_ERR_PFX_NOTSUPPORTED			4102
#define KTSDK_ERR_PFX_MEMORY				4103
#define KTSDK_ERR_PFX_BASE64				4104
#define KTSDK_ERR_PFX_CERT					4105
#define KTSDK_ERR_PFX_USERCANCEL			4106
#define KTSDK_ERR_PFX_LOADDLL				4107
#define KTSDK_ERR_PFX_KEY					4108

#define KTSDK_ERR_PFX_NOTFOUND				4111
#define KTSDK_ERR_PFX_OPEN					4112
#define KTSDK_ERR_PFX_NOTOPEN				4113
#define KTSDK_ERR_PFX_GETINFO				4114
#define KTSDK_ERR_PFX_GENRANDOM				4115
#define KTSDK_ERR_PFX_AUTH					4116

#define KTSDK_ERR_PFX_VERIFYPIN				4121
#define KTSDK_ERR_PFX_CHANGEPIN				4122
#define KTSDK_ERR_PFX_PINLOCKED				4123
#define KTSDK_ERR_PFX_UNLOCKPIN				4124

#define KTSDK_ERR_PFX_CERT_NOTFOUND			4131
#define KTSDK_ERR_PFX_READCERT				4132
#define KTSDK_ERR_PFX_WRITECERT				4133
#define KTSDK_ERR_PFX_GENKEYPAIR			4134
#define KTSDK_ERR_PFX_GETPUBKEY				4135
#define KTSDK_ERR_PFX_CREATEREQ				4136
#define KTSDK_ERR_PFX_CREATEREQ_SETDN		4137
#define KTSDK_ERR_PFX_PARSEKEYPAIR			4138
#define KTSDK_ERR_PFX_IMPORTKEYPAIR			4139

#define KTSDK_ERR_PFX_KEY_NOTFOUND			4141
#define KTSDK_ERR_PFX_READKEY				4142
#define KTSDK_ERR_PFX_WRITEKEY				4143
#define KTSDK_ERR_PFX_ISSUECERT				4144

#define KTSDK_ERR_PFX_HASHDATA				4151
#define KTSDK_ERR_PFX_RSASIGN				4152
#define KTSDK_ERR_PFX_RSAVERIFYSIGN			4153
#define KTSDK_ERR_PFX_RSAENCRYPT			4154
#define KTSDK_ERR_PFX_RSADECRYPT			4155
#define KTSDK_ERR_PFX_SM2SIGN				4156
#define KTSDK_ERR_PFX_SM2VERIFYSIGN			4157
#define KTSDK_ERR_PFX_SM2ENCRYPT			4158
#define KTSDK_ERR_PFX_SM2DECRYPT			4159

// mkey??????
#define KTSDK_ERR_MK_OK						0
#define KTSDK_ERR_MK_PARAMETER				5101
#define KTSDK_ERR_MK_NOTSUPPORTED			5102
#define KTSDK_ERR_MK_MEMORY					5103
#define KTSDK_ERR_MK_BASE64					5104
#define KTSDK_ERR_MK_CERT					5105
#define KTSDK_ERR_MK_USERCANCEL				5106
#define KTSDK_ERR_MK_LOADDLL				5107
#define KTSDK_ERR_MK_INIT					5108

#define KTSDK_ERR_MK_DEV_NOTFOUND			5111
#define KTSDK_ERR_MK_DEV_OPEN				5112
#define KTSDK_ERR_MK_DEV_NOTOPEN			5113
#define KTSDK_ERR_MK_DEV_GETINFO			5114
#define KTSDK_ERR_MK_DEV_GENRANDOM			5115
#define KTSDK_ERR_MK_DEV_AUTH				5116

#define KTSDK_ERR_MK_APPLICATION_NOTFOUND	5121
#define KTSDK_ERR_MK_APPLICATION_OPEN		5122
#define KTSDK_ERR_MK_APPLICATION_CREATE		5123
#define KTSDK_ERR_MK_APPLICATION_DELETE		5124

#define KTSDK_ERR_MK_CONTAINER_NOTFOUND		5131
#define KTSDK_ERR_MK_CONTAINER_OPEN			5132
#define KTSDK_ERR_MK_CONTAINER_CREATE		5133
#define KTSDK_ERR_MK_CONTAINER_DELETE		5134
#define KTSDK_ERR_MK_CONTAINER_TOOMANY		5135

#define KTSDK_ERR_MK_VERIFYPIN				5141
#define KTSDK_ERR_MK_CHANGEPIN				5142
#define KTSDK_ERR_MK_PINLOCKED				5143
#define KTSDK_ERR_MK_UNLOCKPIN				5144

#define KTSDK_ERR_MK_READCERT				5151
#define KTSDK_ERR_MK_WRITECERT				5152
#define KTSDK_ERR_MK_GENKEYPAIR				5153
#define KTSDK_ERR_MK_GETPUBKEY				5154
#define KTSDK_ERR_MK_CREATEREQ				5155
#define KTSDK_ERR_MK_CREATEREQ_SETDN		5156
#define KTSDK_ERR_MK_PARSEKEYPAIR			5157
#define KTSDK_ERR_MK_IMPORTKEYPAIR			5158
#define KTSDK_ERR_MK_GENCONTAINERNAME		5159

#define KTSDK_ERR_MK_HASHDATA				5161
#define KTSDK_ERR_MK_RSASIGN				5162
#define KTSDK_ERR_MK_RSAVERIFYSIGN			5163
#define KTSDK_ERR_MK_RSAENCRYPT				5164
#define KTSDK_ERR_MK_RSADECRYPT				5165
#define KTSDK_ERR_MK_SM2SIGN				5166
#define KTSDK_ERR_MK_SM2VERIFYSIGN			5167
#define KTSDK_ERR_MK_SM2ENCRYPT				5168
#define KTSDK_ERR_MK_SM2DECRYPT				5169

#define KTSDK_ERR_MK_SETSYMMKEY				5171
#define KTSDK_ERR_MK_ENCRYPTINIT			5172
#define KTSDK_ERR_MK_ENCRYPTUPDATE			5173
#define KTSDK_ERR_MK_ENCRYPTFINAL			5174
#define KTSDK_ERR_MK_DECRYPTINIT			5175
#define KTSDK_ERR_MK_DECRYPTUPDATE			5176
#define KTSDK_ERR_MK_DECRYPTFINAL			5177

#define KTSDK_ERR_MK_ENUMFILE				5181
#define KTSDK_ERR_MK_CREATEFILE				5182
#define KTSDK_ERR_MK_DELETEFILE				5183
#define KTSDK_ERR_MK_GETFILEINFO			5184
#define KTSDK_ERR_MK_READFILE				5185
#define KTSDK_ERR_MK_WRITEFILE				5186

// smf??????
#define KTSDK_ERR_SMF_OK					0
#define KTSDK_ERR_SMF_PARAMETER				6001
#define KTSDK_ERR_SMF_NOTSUPPORTED			6002
#define KTSDK_ERR_SMF_MEMORY				6003
#define KTSDK_ERR_SMF_BASE64				6004
#define KTSDK_ERR_SMF_CERT					6005
#define KTSDK_ERR_SMF_USERCANCEL			6006
#define KTSDK_ERR_SMF_LOADDLL				6007
#define KTSDK_ERR_SMF_INIT					6008

#define KTSDK_ERR_SMF_DEV_NOTFOUND			6011
#define KTSDK_ERR_SMF_DEV_OPEN				6012
#define KTSDK_ERR_SMF_DEV_NOTOPEN			6013
#define KTSDK_ERR_SMF_DEV_GETINFO			6014
#define KTSDK_ERR_SMF_DEV_GENRANDOM			6015
#define KTSDK_ERR_SMF_DEV_AUTH				6016

#define KTSDK_ERR_SMF_APPLICATION_NOTFOUND	6021
#define KTSDK_ERR_SMF_APPLICATION_OPEN		6022
#define KTSDK_ERR_SMF_APPLICATION_CREATE	6023
#define KTSDK_ERR_SMF_APPLICATION_DELETE	6024

#define KTSDK_ERR_SMF_CONTAINER_NOTFOUND	6031
#define KTSDK_ERR_SMF_CONTAINER_OPEN		6032
#define KTSDK_ERR_SMF_CONTAINER_CREATE		6033
#define KTSDK_ERR_SMF_CONTAINER_DELETE		6034
#define KTSDK_ERR_SMF_CONTAINER_TOOMANY		6035

#define KTSDK_ERR_SMF_VERIFYPIN				6041
#define KTSDK_ERR_SMF_CHANGEPIN				6042
#define KTSDK_ERR_SMF_PINLOCKED				6043
#define KTSDK_ERR_SMF_UNLOCKPIN				6044

#define KTSDK_ERR_SMF_READCERT				6051
#define KTSDK_ERR_SMF_WRITECERT				6052
#define KTSDK_ERR_SMF_GENKEYPAIR			6053
#define KTSDK_ERR_SMF_GETPUBKEY				6054
#define KTSDK_ERR_SMF_CREATEREQ				6055
#define KTSDK_ERR_SMF_CREATEREQ_SETDN		6056
#define KTSDK_ERR_SMF_PARSEKEYPAIR			6057
#define KTSDK_ERR_SMF_IMPORTKEYPAIR			6058
#define KTSDK_ERR_SMF_GENCONTAINERNAME		6059

#define KTSDK_ERR_SMF_HASHDATA				6061
#define KTSDK_ERR_SMF_RSASIGN				6062
#define KTSDK_ERR_SMF_RSAVERIFYSIGN			6063
#define KTSDK_ERR_SMF_RSAENCRYPT			6064
#define KTSDK_ERR_SMF_RSADECRYPT			6065
#define KTSDK_ERR_SMF_SM2SIGN				6066
#define KTSDK_ERR_SMF_SM2VERIFYSIGN			6067
#define KTSDK_ERR_SMF_SM2ENCRYPT			6068
#define KTSDK_ERR_SMF_SM2DECRYPT			6069

#define KTSDK_ERR_SMF_SETSYMMKEY			6071
#define KTSDK_ERR_SMF_ENCRYPTINIT			6072
#define KTSDK_ERR_SMF_ENCRYPTUPDATE			6073
#define KTSDK_ERR_SMF_ENCRYPTFINAL			6074
#define KTSDK_ERR_SMF_DECRYPTINIT			6075
#define KTSDK_ERR_SMF_DECRYPTUPDATE			6076
#define KTSDK_ERR_SMF_DECRYPTFINAL			6077

#define KTSDK_ERR_SMF_ENUMFILE				6081
#define KTSDK_ERR_SMF_CREATEFILE			6082
#define KTSDK_ERR_SMF_DELETEFILE			6083
#define KTSDK_ERR_SMF_GETFILEINFO			6084
#define KTSDK_ERR_SMF_READFILE				6085
#define KTSDK_ERR_SMF_WRITEFILE				6086

// ts??????
#define KTSDK_ERR_TS_BASE					6100
#define KTSDK_ERR_TS_PARAMETER				6101
#define KTSDK_ERR_TS_MEMORY					6102
#define KTSDK_ERR_TS_BASE64					6103

#define KTSDK_ERR_BJCATS_CONNECT			6111
#define KTSDK_ERR_BJCATS_SENDDATA			6112
#define KTSDK_ERR_BJCATS_RECVDATA			6113

#define KTSDK_ERR_BJCATS_TSACERT			6121
#define KTSDK_ERR_BJCATS_INVALIDTSACERT		6122

#define KTSDK_ERR_BJCATS_TSREQ				6131
#define KTSDK_ERR_BJCATS_INVALIDTSREQ		6132

#define KTSDK_ERR_BJCATS_TSRESP				6141
#define KTSDK_ERR_BJCATS_INVALIDTSRESP		6142

#define KTSDK_ERR_TS_VERIFYTS				6151
#define KTSDK_ERR_TS_TSCERTUNTRUSTED		6152

#define KTSDK_ERR_TS_PARSETS				6161

#define KTSDK_ERR_TS_TSACERT				6171
#define KTSDK_ERR_TS_TSREQ					6172
#define KTSDK_ERR_TS_TSRESP					6173

// ldap??????
#define KTSDK_ERR_LDAP_INITIALIZE			6301
#define KTSDK_ERR_LDAP_GETINFO				6302
#define KTSDK_ERR_LDAP_GETCERTINFO			6303

#endif
