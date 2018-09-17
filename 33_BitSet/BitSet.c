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
    size_t index =  x >> 3;
    size_t num = x%8;
    assert(pbs);
    pbs->_bits[index] |= (1<<num);
}

void BitSetReset(BitSet* pbs, size_t x)
{
    size_t index = x>>3;
    size_t num = x%8;
    assert(pbs);
    //卧槽，怎么全是位操作！？！
    pbs->_bits[index] &= ~(1<<num);
}

int BitSetTest(BitSet* pbs, size_t x)
{
    size_t index = x>>3;
    size_t num = x%8;
    assert(pbs);
    return pbs->_bits[index] & (1<<num) == 0 ? 0:1;
}

void TestBitSet(void)
{

    BitSet bs;
    BitSetInit(&bs, 100);
    BitSetSet(&bs, 5);
    BitSetSet(&bs, 2);
    BitSetSet(&bs, 200);

    printf("%d\n", BitSetTest(&bs, 5));
    printf("%d\n", BitSetTest(&bs, 2));
    printf("%d\n", BitSetTest(&bs, 200));
    printf("%d\n", BitSetTest(&bs, 6));

    BitSetReset(&bs, 200);
    BitSetReset(&bs, 2);


    printf("%d\n", BitSetTest(&bs, 5));
    printf("%d\n", BitSetTest(&bs, 2));
    printf("%d\n", BitSetTest(&bs, 200));
    printf("%d\n", BitSetTest(&bs, 6));


}
