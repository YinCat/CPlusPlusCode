#include "BitSet.h"



void BitSetInit(BitSet *pbs, size_t n)
{
	assert(pbs);
	pbs->_bits = (char*)malloc((n >> 3) + 1);
	memset(pbs->_bits, 0, (n >> 3) + 1);
	pbs->_N = n;
}
void BitSetDestroy(BitSet *pbs)
{
	assert(pbs);
	free(pbs->_bits);
	pbs->_bits = NULL;
	pbs->_N = 0;
}

void BitSetSet(BitSet *pbs, size_t x)
{
	size_t index = 0;
	size_t num = 0;
	assert(pbs);
	index = x >> 3;
	num = x % 8;
	//左移就是向高位移动，右移就是向低位移动（跟机器的大小端是没有关系的）
	pbs->_bits[index] |= (1 << num);
}
void BitSetReset(BitSet *pbs, size_t x)
{
	size_t num = 0;
	size_t index = 0;
	assert(pbs);
	index = x >> 3;
	num = x % 8;

	pbs->_bits[index] &= ~(1 << num);
}

size_t BitSetTest(BitSet *pbs, size_t x)
{
	size_t num = 0;
	size_t index = 0;  
	assert(pbs);
	index = x >> 3;
	num = x % 8;
	return (pbs->_bits[index] & (1 << num)) == 0 ? 0 : 1;
}