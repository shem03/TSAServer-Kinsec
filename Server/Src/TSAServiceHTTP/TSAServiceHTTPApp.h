#ifndef __TSASERVICEHTTPAPP_H__
#define __TSASERVICEHTTPAPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "../CommonUtil/TSACommonUtil.h"
#include "locker.h"
#include "time.h"

using namespace std;

class CTSAServiceHTTPApp
{
public:
    CTSAServiceHTTPApp(/* args */);
    ~CTSAServiceHTTPApp();
public:
    int start(); //��������
    void createTSASerialNumber(char *pszSN); //����Ψһʱ������к�

private:
    CTSACommonUtil util;
    locker m_queuelocker;

public:
    string m_strIP;
    int m_nHttpPort;

    //��֤��
    char m_SM2Cert_B64[8192];   //ʱ���֤��(Base64)
	char m_SM2PKey_B64[1024];   //ʱ���֤��˽Կ(Base64)
    unsigned char *m_SM2Cert;   //ʱ���֤��
	unsigned char *m_SM2PKey;   //ʱ���֤��˽Կ
    int m_SM2CertLen;           //ʱ���֤�鳤��
    int m_SM2PKeyLen;           //ʱ���֤��˽Կ����
	//X509* m_SM2Ca;
	//X509* m_SM2RootCa;
	time_t m_SM2BeforeValid;
	time_t m_SM2AfterValid;

};





#endif