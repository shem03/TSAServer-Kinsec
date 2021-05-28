#ifndef _HTTP_FUNCTION_H_
#define _HTTP_FUNCTION_H_

#include <string>
#include <map>
#include "STFTSAFunction.h"

using namespace std;

class http_function
{
public:
    http_function(char *fname, char *rdata);
    ~http_function();

public:
    int FunctionName2FunctionDefine();  //������ת��
    bool FunctionProcess(char *response_body); //���ܴ���
    //������������
    //data1=111&data2=222&data3=333
    bool ParseRequestData();
    //��װ��Ӧ����
    bool EncapsulationResponseData();

private:
    string function_name;
    string request_data;
    string response_data;
    map<string, string> mrequestdata;
    map<string, string> mresponsedata;
};


#endif