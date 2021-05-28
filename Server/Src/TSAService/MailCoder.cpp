/*
*
*	�������ʵ��
*	����		Tintin  Tintin2000@263.net
*	����		2001-4-15
*	����޸�	2001-4-19
*
*/
#include "MailCoder.h"

//����ʱ���ÿ�еĳ���
unsigned int CMailCoder::m_LineWidth = 76;
//------------------------------------------------------------------------------

//Base64�����
const char CMailCoder::BASE64_ENCODE_TABLE[64] = {
	 65,  66,  67,  68,  69,  70,  71,  72,  // 00 - 07
	 73,  74,  75,  76,  77,  78,  79,  80,  // 08 - 15
	 81,  82,  83,  84,  85,  86,  87,  88,  // 16 - 23
	 89,  90,  97,  98,  99, 100, 101, 102,  // 24 - 31
	103, 104, 105, 106, 107, 108, 109, 110,  // 32 - 39
	111, 112, 113, 114, 115, 116, 117, 118,  // 40 - 47
	119, 120, 121, 122,  48,  49,  50,  51,  // 48 - 55
	 52,  53,  54,  55,  56,  57,  43,  47 };// 56 - 63
	
	//Base64�����
const unsigned int CMailCoder::BASE64_DECODE_TABLE[256] = {
	255, 255, 255, 255, 255, 255, 255, 255, //  00 -  07
	255, 255, 255, 255, 255, 255, 255, 255, //  08 -  15
	255, 255, 255, 255, 255, 255, 255, 255, //  16 -  23
	255, 255, 255, 255, 255, 255, 255, 255, //  24 -  31
	255, 255, 255, 255, 255, 255, 255, 255, //  32 -  39
	255, 255, 255,  62, 255, 255, 255,  63, //  40 -  47
	 52,  53,  54,  55,  56,  57,  58,  59, //  48 -  55
	 60,  61, 255, 255, 255, 255, 255, 255, //  56 -  63
	255,   0,   1,   2,   3,   4,   5,   6, //  64 -  71
	  7,   8,   9,  10,  11,  12,  13,  14, //  72 -  79
	 15,  16,  17,  18,  19,  20,  21,  22, //  80 -  87
	 23,  24,  25, 255, 255, 255, 255, 255, //  88 -  95
	255,  26,  27,  28,  29,  30,  31,  32, //  96 - 103
	 33,  34,  35,  36,  37,  38,  39,  40, // 104 - 111
	 41,  42,  43,  44,  45,  46,  47,  48, // 112 - 119
	 49,  50,  51, 255, 255, 255, 255, 255, // 120 - 127
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255 };
//------------------------------------------------------------------------------
		
//Quoted�����
const unsigned char CMailCoder::QUOTED_ENCODE_TABLE[256] = {
	255, 255, 255, 255, 255, 255, 255, 255, // 00 -  07
	255, 255,  10, 255, 255,  13, 255, 255, // 08 - 15
	255, 255, 255, 255, 255, 255, 255, 255, // 16 - 23
	255, 255, 255, 255, 255, 255, 255, 255, // 24 - 31
	255,  33,  34,  35,  36,  37,  38,  39,
	 40,  41,  42,  43,  44,  45,  46,  47,
	 48,  49,  50,  51,  52,  53,  54,  55,
	 56,  57,  58,  59,  60, 255,  62,  63,
	 64,  65,  66,  67,  68,  69,  70,  71,
	 72,  73,  74,  75,  76,  77,  78,  79,
	 80,  81,  82,  83,  84,  85,  86,  87,
	 88,  89,  90,  91,  92,  93,  94,  95,
	 96,  97,  98,  99, 100, 101, 102, 103,
	104, 105, 106, 107, 108, 109, 110, 111,
	112, 113, 114, 115, 116, 117, 118, 119,
	120, 121, 122, 123, 124, 125, 126, 127,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255,
	255, 255, 255, 255, 255, 255, 255, 255 };
//------------------------------------------------------------------------------
			
//��ȡBase64���볤��
int CMailCoder::Base64EncodeSize(int iSize)
{
	int nSize, nCR;
	nSize = (iSize + 2) / 3 * 4 ;
	nCR = nSize / m_LineWidth; //����س�����
	nSize+= nCR * 2;
	return nSize;
}
	
//------------------------------------------------------------------------------
	
//��ȡBase64���볤��
int CMailCoder::Base64DecodeSize(int iSize)
{
	return (iSize + 3) / 4 * 3;
}

//------------------------------------------------------------------------------

//��ȡUUCode���볤��
int CMailCoder::UUEncodeSize(int iSize)
{
	int nSize, nCR;
	nSize = (iSize + 2) / 3 * 4 ;
	nCR = nSize / m_LineWidth + 2; //����س�����
	nSize+= nCR * 3 + 2;
	return nSize;
}
			
//------------------------------------------------------------------------------

//��ȡUUCode���볤��
int CMailCoder::UUDecodeSize(int iSize)
{
	return (iSize + 3) / 4 * 3;
}
			
//------------------------------------------------------------------------------

//��ȡQuoted���볤��
int CMailCoder::QuotedEncodeSize(int iSize)
{
	int nSize = iSize * 3 + 1;
	int nCR = nSize / m_LineWidth;
	nSize+= nCR * 3;
	return nSize;
}

//------------------------------------------------------------------------------

//Base64����
int CMailCoder::base64_encode(char *pSrc, unsigned int nSize, char *pDest)
{
	if ((pSrc == NULL) || (nSize <= 0)) return 0;
		
	unsigned int iB, iInMax3, Len;
	char *pInPtr, *pInLimitPtr;
	char *OutPtr ;
			
	pInPtr = pSrc;
	iInMax3 = nSize / 3 * 3;
	OutPtr = pDest;
	pInLimitPtr = pInPtr + iInMax3;
				
	while (pInPtr != pInLimitPtr)
	{
		Len = 0;
		while ((Len < m_LineWidth) && (pInPtr != pInLimitPtr))
		{
			iB = (unsigned char) *pInPtr++;
			iB = iB << 8;
				
			iB = iB | (unsigned char) *pInPtr++;
			iB = iB << 8;
						
			iB = iB | (unsigned char) *pInPtr++;
						
			//��4 byte����д���������
			OutPtr[3] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[2] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[1] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[0] = BASE64_ENCODE_TABLE[iB];
			OutPtr+=4;
			Len+=4;
		}
		if (Len >= m_LineWidth)
		{
			*OutPtr++ = '\r'; //���ϻس����з�
			*OutPtr++ = '\n';
		}
	}
	//����β��
	switch (nSize - iInMax3)
	{
		case 1:
			iB = (unsigned char) *pInPtr;
			iB = iB << 4;
			OutPtr[1] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[0] = BASE64_ENCODE_TABLE[iB];
			OutPtr[2] = '='; //��'='Ҳ����64�����ʣ�ಿ��
			OutPtr[3] = '=';
			OutPtr+=4;
			break;
		case 2:
			iB = (unsigned char) *pInPtr++;
			iB = iB << 8;
			iB = iB | (unsigned char) *pInPtr;
			iB = iB << 2;
			OutPtr[2] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[1] = BASE64_ENCODE_TABLE[iB & 0x3F];
			iB = iB >> 6;
			OutPtr[0] = BASE64_ENCODE_TABLE[iB];
			OutPtr[3] = '='; // Fill remaining byte.
			OutPtr+=4;
			break;
	}
	return (unsigned int) (OutPtr - pDest);
}
			
//------------------------------------------------------------------------------
//Base64����

int CMailCoder::base64_decode(char *pSrc, unsigned int nSize, char *pDest)
{
	if ((pSrc == NULL) || (pDest == NULL) || (nSize <= 0)) return 0;
			
	unsigned int lByteBuffer, lByteBufferSpace;
	unsigned int C; //��ʱ�Ķ�����
	int reallen;
	char *InPtr, *InLimitPtr;
	char *OutPtr;
				
	lByteBuffer = 0; lByteBufferSpace = 4;
				
	InPtr = pSrc;
	InLimitPtr= InPtr + nSize;
	OutPtr = pDest;
				
	while (InPtr != InLimitPtr)
	{
		C = BASE64_DECODE_TABLE[*InPtr]; // Read from InputBuffer.
		InPtr++;
		if (C == 0xFF) continue; //����255�Ƿ��ַ�
		lByteBuffer = lByteBuffer << 6 ;
		lByteBuffer = lByteBuffer | C ;
		lByteBufferSpace--;
		if (lByteBufferSpace != 0) continue; //һ�ζ���4���ֽ�
		//����д��3���ֽڵ�����
		OutPtr[2] = lByteBuffer;
		lByteBuffer = lByteBuffer >> 8;
		OutPtr[1] = lByteBuffer;
		lByteBuffer = lByteBuffer >> 8;
		OutPtr[0] = lByteBuffer;
		//׼��д���3λ
		OutPtr+= 3; lByteBuffer = 0; lByteBufferSpace = 4;
	}
	reallen = (unsigned int)OutPtr - (unsigned int)pDest;
	//����β�� ����ʵ�ʳ���
	switch (lByteBufferSpace)
	{
		case 1:
			lByteBuffer = lByteBuffer >> 2;
			OutPtr[1] = lByteBuffer;
			lByteBuffer = lByteBuffer >> 8;
			OutPtr[0] = lByteBuffer;
			return reallen + 2;
		case 2:
			lByteBuffer = lByteBuffer >> 4;
			OutPtr[0] = lByteBuffer;
			return reallen + 1;
		default:
			return reallen;
	}
}

//------------------------------------------------------------------------------

//UUCode����
int CMailCoder::UU_encode(char *pSrc, unsigned int nSize, char *pDest)
{
	if ((pSrc == NULL) || (pDest == NULL) || (nSize <= 0)) return 0;
				
	unsigned int lByteBufferSpace, Len;
	unsigned char B[3]; //��ʱ�Ķ�����
	char *InPtr, *InLimitPtr;
	char *OutPtr;
			
	InPtr = pSrc;
	InLimitPtr= InPtr + nSize;
	OutPtr = pDest;
				
	while (InPtr < InLimitPtr)
	{
		Len = 0;
					
		while ((InPtr < InLimitPtr) && (Len < m_LineWidth))
		{
			lByteBufferSpace = (unsigned int) InLimitPtr - (unsigned int) InPtr;
			if (lByteBufferSpace > 3) lByteBufferSpace = 3; //���ò���
			//ȡֵ
			for (unsigned int i = 0; i < lByteBufferSpace; i++ )
			{
				B[i] = *InPtr++;
			}
			if (Len == 0)
			{
				*OutPtr++ = 'M';
				Len++;
			}
			//��������
			OutPtr[0] = B[0] >> 2;
			OutPtr[1] = (unsigned int) (B[0] << 4 & 0x30) + (unsigned int) (B[1] >> 4 & 0x0F);
			OutPtr[2] = (unsigned int) (B[1] << 2 & 0x3C) + (unsigned int) (B[2] >> 6 & 0x03);
			OutPtr[3] = B[2] & 0x3F;
			for (unsigned int i = 0; i < 4; i++)
			{
				if (OutPtr[i] == NULL)
					OutPtr[i] = '`';//(unsigned char) (OutPtr[i] + 0x60);
				else 
					OutPtr[i] = ' ' + OutPtr[i];//(unsigned char) (OutPtr[i] + 0x20);
			}	
			OutPtr+=4;
			Len+=4;
		}
					
		*OutPtr++ = '\r'; //���ûس�
		*OutPtr++ = '\n';
	}
	return (unsigned int) (OutPtr - pDest);
}

//------------------------------------------------------------------------------

//UUCode����
int CMailCoder::UU_decode(char *pSrc, unsigned int nSize, char *pDest)
{
	char C[4]; //��ʱ�Ķ�����
	char Tmp;
	int CurrIndex, Index;
	char *InPtr, *InLimitPtr;
	char *OutPtr;
		
	if ((pSrc == NULL) || (pDest == NULL) || (nSize <= 0)) return 0;
		
	CurrIndex = 0;
				
	InPtr = pSrc;
	InLimitPtr= InPtr + nSize;
	OutPtr = pDest;
				
	while (InPtr != InLimitPtr) //��ȡ4���ַ�
	{
		memset(C, 0, sizeof(C));
		Index = 0;
		do
		{
			Tmp = *InPtr++;
			if (Tmp == 0x60) 
			{
				Tmp = 0x20;       //Ϊ�˼���OutLook Express
			}
			else if (Tmp =='\r')  //�׸���ĸ������
			{
				InPtr++;
				CurrIndex = 0;
			}
			
			if ((Tmp > 0x20) || ( CurrIndex > 0 ))
			{
				Tmp = Tmp - 0x20;
				if (CurrIndex == 0) 
				{
					CurrIndex = Tmp;
				}
				else
				{
					C[Index] = Tmp;  // ��������׷���ַ�
					Index++;
				}
			}
		}
		while ((InPtr < InLimitPtr) && (Index < sizeof(C)));
					
		OutPtr[0] = (char) ((C[0] << 2) + (C[1] >> 4));
		OutPtr[1] = (char) ((C[1] << 4) + (C[2] >> 2));
		OutPtr[2] = (char) ((C[2] << 6) + C[3]);
		OutPtr+=3; //������ʼλ��
	}
	return (unsigned int)OutPtr - (unsigned int)pDest;
}

//------------------------------------------------------------------------------

//Quoted����
int CMailCoder::quoted_encode(char *pSrc, unsigned int nSize, char *pDest)
{
	unsigned int Len;
	unsigned char B; //��ʱ�Ķ�����
	char *InPtr, *InLimitPtr;
	char *OutPtr;
			
	if ((pSrc == NULL) || (pDest == NULL) || (nSize <= 0)) return 0;
			
	InPtr = pSrc;
	InLimitPtr= InPtr + nSize;
	OutPtr = pDest;
				
	while (InPtr < InLimitPtr)
	{
		Len = 0;
		while ((InPtr < InLimitPtr) && (Len < m_LineWidth))
		{
			B = *InPtr++;
			if (QUOTED_ENCODE_TABLE[ B ]  == 255)
			{
				*OutPtr++ = '=';
				*OutPtr++ = DecToHex(B >> 4);
				*OutPtr++ = DecToHex(B & 0x0f);
				Len+=3;
			}
			else
			{
				*OutPtr++ = B;
				Len++;
			}
		}
		if (Len >= m_LineWidth)
		{
			*OutPtr++ = '=';
			*OutPtr++ = '\r'; //��������
			*OutPtr++ = '\n';
		}
	}
	*OutPtr = '\0';
	return (unsigned int) (OutPtr - pDest);
}

//------------------------------------------------------------------------------

//Quoted����
int CMailCoder::quoted_decode(char *pSrc, unsigned int nSize, char *pDest)
{
	if ((pSrc == NULL) || (pDest == NULL) || (nSize <= 0)) return 0;
				
	unsigned char nA, nB;
	char C[2]; //��ʱ�Ķ�����
				
	char *InLimitPtr= pSrc + nSize;
	char *pDestOrg = pDest;
				
	while (pSrc < InLimitPtr)
	{
		C[0] = *pSrc++; //��ȡ��һ�ַ�
		if (C[0] == '=') //��������Ǿ��������
		{
			C[0] = *pSrc++;  //ȡ�����������ַ�
			C[1] = *pSrc++;

			if (C[0] != '\r')
			{
				nA = HexToDec(C[0]); //����任
				nB = HexToDec(C[1]);
				*pDest++ = (nA << 4) + nB;
			}
		}
		else //����ֱ�����
		{
			*pDest++ = C[0];
		}
	}
	return (unsigned int)(pDest - pDestOrg);
}

//------------------------------------------------------------------------------

//ʮ����-->ʮ������
unsigned char CMailCoder::DecToHex( unsigned char B)
{
	return B < 10 ? '0' + B:'A' + B - 10;
}

//------------------------------------------------------------------------------

//ʮ������-->ʮ����
unsigned char CMailCoder::HexToDec( unsigned char C )
{
	return C <= '9' ? C - '0' : C - 'A' + 10;
}

//------------------------------------------------------------------------------

