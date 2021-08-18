#ifndef IMEMORYBLOCK_H
#define IMEMORYBLOCK_H
#include <vector>

// ��� std::vector<unsigned char> �� �ɵ��÷����죬���ɵ��÷������ͷ�
// �����÷����û����κ� IMemoryBlock ��ָ��
class IMemoryBlock
{
public:
	virtual  size_t __stdcall resize(size_t) = 0;
	virtual  size_t __stdcall size() const = 0; 
	virtual  unsigned char* __stdcall at(size_t) = 0;
	virtual const unsigned char* __stdcall at(size_t) const = 0;
	virtual  size_t __stdcall copy(size_t begin, const unsigned char* data, size_t size) = 0;
};

#endif