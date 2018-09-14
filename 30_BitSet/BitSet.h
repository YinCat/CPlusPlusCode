#ifndef __BITSET_H__
#define __BITSET_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef struct BitSet
{
	char* _bits;
	size_t _N;//λ����
}BitSet;

//�����ٸ�λ��λͼ
void BitSetInit(BitSet *pbs,size_t n);
void BitSetDestroy(BitSet *pbs);

void BitSetSet(BitSet *pbs, size_t x);
void BitSetReset(BitSet *pbs, size_t x);

size_t BitSetTest(BitSet *pbs, size_t x);

#endif //!__BITSET_H__