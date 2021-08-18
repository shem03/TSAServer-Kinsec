#ifndef __MAILCODER_H__
#define __MAILCODER_H__
/*
*
*  ���������Ĺ�����
*  ����		Tintin Tintin2000@263.net
*  ����		2001-4-15
*  ����޸� 2001-4-19	
*
*/

#include <stdio.h>
#include <string.h>

class CMailCoder
{
public:
	static unsigned int m_LineWidth;						//ָ�������ÿ�еĳ��ȣ�ȱʡ��76
	static const char BASE64_ENCODE_TABLE[64];				//Base64�����
	static const unsigned int BASE64_DECODE_TABLE[256];		//Base64�����
	static const unsigned char QUOTED_ENCODE_TABLE[256];	//Quoted�����
private:
	static unsigned char DecToHex(unsigned char B);		//ΪQuoted������������ַ�ת��
	static unsigned char HexToDec(unsigned char C);		//ΪQuoted������������ַ�ת��
public:
	static int Base64EncodeSize(int iSize);		//�����ļ�ʵ�ʳ��Ȼ�ȡ����Base64��ĳ���  
	static int Base64DecodeSize(int iSize);		//�����ѱ����ļ����Ȼ�ȡBase64�Ľ��볤��
	static int UUEncodeSize(int iSize);			//�����ļ�ʵ�ʳ��Ȼ�ȡUUCode�����ĳ���
	static int UUDecodeSize(int iSize);			//�����ѱ����ļ����Ȼ�ȡUUCode�����ĳ���
	static int QuotedEncodeSize(int iSize);		//����ʵ���ļ��ĳ��Ȼ�ȡQuoted����

	/*
	*  ��һ��Buffer����Base64����
	*
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*
	*	 ע: ���Buffer�ĳ��ȿ���ʹ�� Base64EncodeSize(int) ����ȡ��
	*/
	static int base64_encode(char *pSrc, unsigned int nSize, char *pDest);

	/*
	*  ��һ��Buffer����Base64����
	*	
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*		return	������ʵ�ʳ���
	*
	*	 ע: ���Buffer�ĳ��ȿ���ʹ�� Base64DecodeSize(int) ����ȡ��
	*/
	static int  base64_decode(char *pSrc, unsigned int nSize, char *pDest);

	/*
	*  ��һ��Buffer����UUCODE����
	*
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*
	*	 ע: ���Buffer�ĳ��ȿ���ʹ�� UUEncodeSize(int) ����ȡ��
	*/
	static int UU_encode(char *pSrc, unsigned int nSize, char *pDest);
	
	/*
	*  ��һ��Buffer����UUCODE����
	*
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*
	*	 ע: ���Buffer�ĳ��ȿ���ʹ�� UUDecodeSize(int) ����ȡ��
	*/
	static int UU_decode(char *pSrc, unsigned int nSize, char *pDest);
	/*
	*  ��һ��Buffer����Quoted-Printble����
	*
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*		return	������ʵ�ʳ���
	*
	*	 ע: ���Buffer�ĳ��ȿ���ʹ�� QuotedDecodeSize(int) ����ȡ��
	*/
	static int quoted_encode(char *pSrc, unsigned int nSize, char *pDest);
	
	/*
	*  ��һ��Buffer����Quoted-Printble����
	*
	*	 	pSrc	����Buffer
	*		nSize	Buffer����
	*		pDest	�������
	*		return	������ʵ�ʳ���
	*
	*	 ע������û���ṩ������볤�ȵķ��� ֱ��ʹ������Buffer�����Buffer�Ϳ�����
	*/
	static int quoted_decode(char *pSrc, unsigned int nSize, char *pDest);
	
};

#endif //__MAILCODER_H__
