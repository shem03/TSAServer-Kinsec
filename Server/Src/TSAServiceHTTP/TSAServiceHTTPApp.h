#ifndef __TSASERVICEHTTPAPP_H__
#define __TSASERVICEHTTPAPP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <cassert>
#include <sys/epoll.h>
#include <sys/types.h>
#include <dirent.h>

#include "../CommonUtil/TSACommonUtil.h"
#include "locker.h"
#include "time.h"
#include "threadpool.h"
#include "http_conn.h"

using namespace std;

#define MAX_FD 65536
#define MAX_EVENT_NUMBER 10000

class CTSAServiceHTTPApp
{
public:
    CTSAServiceHTTPApp(/* args */);
    ~CTSAServiceHTTPApp();
public:
    int start(); //��������
    void createTSASerialNumber(char *pszSN); //����Ψһʱ������к�
    void initSocket();
    void initEpoll();
    //void initThreadpool();

private:
    locker m_queuelocker;
    //threadpool< http_conn >* pool;

public:
    string m_strIP;
    int m_nHttpPort;
    int m_nCryptoAlg; //�����㷨��1Ӳ���㷨; 2���㷨
    
    //��־�ȼ�
    int m_nConsoleLogLevel; //����̨��־�ȼ�
    int m_nFileLogLevel; //�ļ���־�ȼ�
    int m_nDBLogLevel; //���ݿ���־�ȼ�

    //��֤��
    char m_SM2Cert_B64[8192];   //ʱ���֤��(Base64)
	char m_SM2PKey_B64[1024];   //ʱ���֤��˽Կ(Base64)
    unsigned char m_SM2Cert[8192];   //ʱ���֤��
	unsigned char m_SM2PKey[8192];   //ʱ���֤��˽Կ
    int m_SM2CertLen;           //ʱ���֤�鳤��
    int m_SM2PKeyLen;           //ʱ���֤��˽Կ����
    //���뿨
    int m_FMSM2CertLen;           //���뿨ʱ���֤�鳤��
    char m_FMSM2Cert_B64[8192];   //���뿨ʱ���֤��(Base64)
    unsigned char m_FMSM2Cert[8192];   //���뿨ʱ���֤��
    //��Ч��
	time_t m_SM2BeforeValid;
	time_t m_SM2AfterValid;

    //socket
    int m_nListenFD;

    //epoll
    epoll_event m_Events[ MAX_EVENT_NUMBER ];
    int m_nEpollFD;

    //class declare
    CTSACommonUtil util;
    CKTLogKit log;
};





#endif