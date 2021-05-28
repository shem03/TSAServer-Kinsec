#ifndef _STF_TSA_FUNCTION_H_
#define _STF_TSA_FUNCTION_H_

#include <stdio.h>
#include <string>
#include <map>
#include "../CommonUtil/TSACommonUtil.h"
#include "STFDefine.h"
#include "KSSignLibFunc.h"
#include "MyToolLibFunc.h"
//#include "ktsgd.h"

/****************************************************************
 * ����������
 ****************************************************************/
#define TSA_INIT_ENVIRONMENT 1001
#define TSA_CLEAR_ENVIRONMENT 1002
#define TSA_CREATE_TS_REQUEST 1003
#define TSA_CREATE_TS_RESPONSE 1004
#define TSA_VERIFY_TS_VALIDITY 1005
#define TSA_GET_TS_INFO 1006
#define TSA_GET_TS_DETAIL 1007
/****************************************************************/

/****************************************************************
 * �����ַ�
 ****************************************************************/
SGD_UINT32 TSAFunctionAssign(
	int function_define, 
	map<string, string> mrequestdata, 
	map<string, string> &mresponsedata);
/****************************************************************/

/*
����ʱ����������
phTSHandle[OUT]:ʱ��ػ������ָ�롣
����ֵ�� 0:�ɹ�; ����:ʧ�ܡ�
*/
SGD_UINT32 STF_InitEnvironment(void **phTSHandle = NULL);

/*
���ʱ��ػ��������
����:
hTSHandle[IN]:ʱ��ػ��������
����ֵ:
0:�ɹ�; ����:ʧ�ܡ�
*/
SGD_UINT32 STF_ClearEnvironment(void* hTSHandle = NULL);

/*
��ָ���㷨��ʱ���������Ϣindata���������Ӵ�����,����ʱ����������
����:
hTSHandle[IN];ʱ����������
pucInData[IN];��Ҫ�Ӹ�ʱ��ص��û���Ϣ
uiInDataLength [IN]:�û���Ϣ�ĳ���
uiReqType[IN]:�����ʱ��ط�������
pucTSExt[IN]:ʱ����������������չ��DER�����ʽ
uiTSExtLength[IN]:ʱ����������չ�ĳ���
uiHashAlgID[IN]:�����Ӵ��㷨��ʶ
pucTSRequest [OUT]:ʱ�������
puiTSRequestLength [IN/OUT]:ʱ�������ĳ���
����ֵ:
0:�ɹ�;����;ʧ�ܡ�
��ע:
uiReqType: 0����ʱ�����ӦӦ�ð���ʱ�����������֤��;1����ʱ�����Ӧ����ʱ�����������֤�顣
puiTSRequestLength[IN/OUT]:���ֵΪָ�������ڴ��ʱ���������ַ�������󳤶�,����ֵΪʱ��������ʵ�ʳ��ȡ�
*/
/*
HTTP Post ����body��
in_data(Base64), in_data_length, hash_alg_id(SGD_SM3,SGD_SHA1,SGD_SHA256)
HTTP Post ��Ӧbody��
ts_request(Base64), ts_request_length
*/
SGD_UINT32 STF_CreateTSRequest( void* hTSHandle, 
	SGD_UINT8 *pucInData, 
	SGD_UINT32 uiInDataLength, 
	SGD_UINT32 uiReqType, 
	SGD_UINT8 *pucTSExt,
	SGD_UINT32 *uiTSExtLength,
	SGD_UINT32 uiHashAlgID, 
	SGD_UINT8 *pucTSRequest, 
	SGD_UINT32 *puiTSRequestLength);

/*
����ʱ������������ʱ�����Ӧ����
����:
hTSHandle[IN]:ʱ��ػ������
pucTSRequest [IN]:ʱ�������
uiTSRequestLength [IN]:ʱ�������ĳ���
uiSignatureAlgID[IN];ǩ���㷨��ʶ
pucTSResponse [OUT]:ʱ�����Ӧ
puiTSResponseLength [IN/OUT]:ʱ�����Ӧ�ĳ���
����ֵ:
0 :�ɹ�;����:ʧ�ܡ�
��ע:
puiTSResponseLength[IN/OUT]:���ֵΪָ�������ڴ��ʱ������ַ��������󳤶�,����ֵΪʱ�����ʵ�ʳ��ȡ�
*/
/*
HTTP Post ����body��
ts_request(Base64), ts_request_length, signature_alg_id
HTTP Post ��Ӧbody��
ts_response(Base64), ts_response_length
*/
SGD_UINT32 STF_CreateTSResponse(void* hTSHandle,
	SGD_UINT8 *pucTSRequest,
	SGD_UINT32 uiTSRequestLength,
	SGD_UINT32 uiSignatureAlgID,
	SGD_UINT8 *pucTSResponse, 
	SGD_UINT32 *puiTSResponseLength);

/*
��֤ʱ�����Ӧ�Ƿ���Ч��
����:
hTSHandle[IN]:ʱ��ػ������
pucTSResponse [IN]:��ȡ��ʱ�����Ӧ
uiTSResponseLength[IN]:ʱ�����Ӧ�ĳ���
uiHashAlgID[IN]:�����Ӵ��㷨��ʶ
uiSignatureAlgID[IN]:ǩ���㷨��ʶ
pucTSCert[IN]:TSA��֤��,DER�����ʽ
uiTSCertLength [IN]:TSA֤��ĳ���
����ֵ:
0:�ɹ�;����:ʧ�ܡ�
��ע:
�ú�����֤ʱ�����Ӧ�Ƿ���Ч�����ڲ�����ʱ���������֤�����Ӧ,��Ҫָ��ʱ�����������֤����ܽ�����֤;
���ڰ���ʱ���������֤�����Ӧ,���԰���ڵ�֤�������Ϊ��,ʹ����Ӧ���Դ���֤�������֤,����ʹ��ָ����֤�������֤,
��ָ����֤���������Դ���֤�顣
*/
/*
HTTP Post ����body��
ts_response(Base64), ts_response_length, hash_alg_id(SGD_SM3,SGD_SHA1,SGD_SHA256), signature_alg_id,
ts_cert(Base64), ts_cert_length
HTTP Post ��Ӧbody��
verify_result(0�ɹ�)
*/
SGD_UINT32 STF_VerifyTSValidity(void* hTSHandle,
	SGD_UINT8 *pucTSResponse, 
	SGD_UINT32 uiTSResponseLength, 
	SGD_UINT32 uiHashAlgID, 
	SGD_UINT32 uiSignatureAlgID, 
	SGD_UINT8 *pucTSCert, 
	SGD_UINT32 uiTSCertLength);

/*
��ȡʱ�������Ҫ��Ϣ��
����:
hTSHandle[IN]:ʱ����������
pucTSResponse[IN]:��ȡ��ʱ�����Ӧ
uiTSResponseLength [IN]:ʱ�����Ӧ�ĳ���
pucIssuerName [OUT]:TSA��ͨ����
puiIssuerNameLength[IN/OUT]:TSAͨ�����ĳ���
pucTime [OUT]:ʱ�����ע��ʱ��ֵ
puiTimeLength [IN/OUT]:ʱ�����ע��ʱ��ֵ����
����ֵ:
0:�ɹ�;����:ʧ�ܡ�
��ע:
�ú�������ʱ�������Ҫ��Ϣ,����TSA��ͨ������ʱ�����ǩ��ʱ�䡣
puilssuerNameLength[IN/OUT]:���ֵΪָ�������ڴ��ǩ�������Ƶ��ַ��������󳤶�,����ֵΪǩ�������Ƶ�ʵ�ʳ��ȡ�
puiTimeLength[IN/OUT]:���ֵΪָ�������ڴ��ʱ��ر�עʱ��ֵ���ַ��������󳤶�,����ֵΪʱ�����ע��ʱ��ֵ��ʵ�ʳ��ȡ�
*/
/*
HTTP Post ����body��
ts_response(Base64), ts_response_length
HTTP Post ��Ӧbody��
issuer_name, issuer_name_length, time, time_length
*/
SGD_UINT32 STF_GetTSInfo(void* hTSHandle, 
	SGD_UINT8 *pucTSResponse, 
	SGD_UINT32 uiTSResponseLength, 
	SGD_UINT8 *pucIssuerName, 
	SGD_UINT32 *puiIssuerNameLength, 
	SGD_UINT8 *pucTime, 
	SGD_UINT32 *puiTimeLength);

/*
����ʱ��ص���ϸ��Ϣ��
����:
hTSHandle[IN]:ʱ��ػ������
pucTSResponse[IN]:��ȡ��ʱ�����Ӧ
uiTSResponseLength [IN]:ʱ�����Ӧ�ĳ���
uiItemnumber [IN]:ָ����ȡʱ�����ϸ��Ϣ����Ŀ���, ���STFDefine.h
pucItemValue [OUT]:�����õ���ʱ��������Ϣ
puiItemValueLength [IN/OUT]:ʱ��������Ϣ�Ķ�Ӧ����
����ֵ:
0:�ɹ�;����:ʧ�ܡ�
��ע��
��ʱ�����Ӧ������ʱ���������֤��,���øú�������ʱ�����������֤���֤����ʱ,���ص��Ƕ�Ӧ��֤�����кš�
��ʱ,�޷�����ǩ���ߵĹ��ҡ���֯�����к͵���������Ϣ;��������������ǩ��ʱ�䡢ǩ����ͨ������ʱ��������ԭʼ��Ϣ��
pulItemValueLength [IN/OUT]:���ʱָ�����ڴ��ʱ��������Ϣ���ַ��������󳤶�,����ʱΪʱ��������Ϣ��ʵ�ʳ��ȡ�
*/
/*
HTTP Post ����body��
ts_response(Base64), ts_response_length, item_number
HTTP Post ��Ӧbody��
item_value, item_value_length
*/
SGD_UINT32 STF_GetTSDetail(void* hTSHandle, 
	SGD_UINT8 *pucTSResponse, 
	SGD_UINT32 uiTSResponseLength, 
	SGD_UINT32 uiItemnumber, 
	SGD_UINT8 *pucItemValue, 
	SGD_UINT32 *puiItemValueLength);


#endif