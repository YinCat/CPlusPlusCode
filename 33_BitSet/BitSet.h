//
// Created by Tim on 2018/9/16.
//

#ifndef INC_33_BITSET_BITSET_H
#define INC_33_BITSET_BITSET_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct BitSet
{
    char* _bits;
    size_t _N; //位个数
}BitSet;

void BitSetInit(BitSet* pbs, size_t N);
void BitSetDestory(BitSet* pbs);

void BitSetSet(BitSet* pbs, size_t x);
void BitSetReset(BitSet* pbs, size_t x);
//  在 返回1
// 不在 返回0
int BitSetTest(BitSet* pbs, size_t x);

void TestBitSet(void);

#endif //INC_33_BITSET_BITSET_H
