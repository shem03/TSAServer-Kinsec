#ifndef _STFDEFINE_H_
#define _STFDEFINE_H_

typedef unsigned char SGD_UINT8;
typedef unsigned int SGD_UINT32;

//error code
#define STF_TS_OK 0								//��������
#define STF_TS_ERROR_BASE 0X04000000		
#define STF_TS_INDATA_TOOLONG 0X04000001		//������û���Ϣ�����涨��Χ
#define STF_TS_NOT_ENOUGH_MEMORY 0X04000002 	//������ڴ�ռ䲻��
#define STF_TS_SERVER_ERROR 0X04000003			//�Ҳ�����������ʱ��Ӧ
#define STF_TS_MALFORMAT 0X04000004				//ʱ�����ʽ����
#define STF_TS_INVALID_ITEM 0X04000005			//�������Ŀ�����Ч
#define STF_TS_INVALID_SIGNATURE 0X04000006		//ǩ����Ч
#define STF_TS_INVALID_ALG 0X04000007			//����ʹ���˲�֧�ֵ��㷨
#define STF_TS_INVALID_REQUEST 0X04000008		//�Ƿ�������
#define STF_TS_INVALID_DATAFORMAT 0X04000009	//���ݸ�ʽ����
#define STF_TS_TIME_NOTAVALIABLE 0X0400000A		//TSA�Ŀ���ʱ��Դ��������
#define STF_TS_UNACCEPTED_POLICY 0X0400000B 	//��֧��������Ϣ�������Ĳ���
#define STF_TS_UNACCEPTED_EXTENSION 0X0400000C	//������Ϣ�а����˲�֧�ֵ���չ
#define STF_TS_ADDINFO_NOT_AVALIABLE 0X0400000D	//�в����򲻿��õĸ�����Ϣ
#define STF_TS_SYSTEM_FAILURE 0X04000000E		//ϵͳ�ڲ����� 

#define STF_TS_CONNECT_TIMEOUT 0X0400000021		//����ָ����ַ��ʱ	
#define STF_TS_SEND_TIMEOUT	0X0400000022		//���ݰ����ͳ�ʱ
#define STF_TS_RECV_TIMEOUT 0X0400000023		//���ݰ����ճ�ʱ


//����ʱ��ص���ϸ��Ϣ-Itemnumber
#define STF_TIME_OF_STAMP 0X00000001		//ǩ��ʱ��
#define STF_CN_OF_TSSIGNER 0X00000002		//ǩ���ߵ�ͨ����
#define STF_ORIGINAL_DATA 0X00000003		//ʱ��������ԭʼ��Ϣ
#define STF_CERT_OF_TSSERVER 0X00000004		//ʱ�����������֤��		
#define STF_CERTCHAIN_OF_TSSERVER 0X00000005		//ʱ�����������֤����	
#define STF_SOURCE_OF_TIME 0X00000006		//ʱ��Դ����Դ
#define STF_TIME_PRECISION 0X00000007		//ʱ�侫��
#define STF_RESPONSE_TYPE 0X00000008		//��Ӧ��ʽ
#define STF_SUBJECT_COUNTRY_OF_TSSIGNER 0X00000009		//ǩ���߹���
#define STF_SUBJECT_ORGNIZATION_OF_TSSIGNER 0X0000000A		//ǩ������֯
#define STF_SUBJECT_CITY_OF_TSSIGNER 0X0000000B		//ǩ���߳���
#define STF_SUBJECT_EMIAL_OF_TSSIGNER 0X0000000C	//ǩ���ߵ�������


#endif
