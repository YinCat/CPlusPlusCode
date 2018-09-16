//
// Created by Tim on 2018/9/16.
//
#include "BitSet.h"

void BitSetInit(BitSet* pbs, size_t N)
{
    assert(pbs);
    pbs->_bits = (char*)malloc((N>>3)+1);
    memset(pbs->_bits,0,sizeof((N>>3)+1));
    pbs->_N = N;
}

void BitSetDestory(BitSet* pbs)
{
    free(pbs->_bits);
    pbs->_bits = NULL;
    pbs->_N = 0;
}

void BitSetSet(BitSet* pbs, size_t x)
{

}
void BitSetReset(BitSet* pbs, size_t x);

int BitSetTest(BitSet* pbs, size_t x);

