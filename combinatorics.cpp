#include "combinatorics.h"

int permutations(int n,int k)
{
    for (int i = 1; i < k; ++i)
    {
        n = n * (n - 1);
    }
    return n;
}