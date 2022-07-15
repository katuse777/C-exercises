/*The combinations function C(n, k) described in this chapter determines the
number of ways you can choose k values from a set of n elements, ignoring the
order of the elements. If the order of the value matters—so that, in the case of
the coin example, choosing a quarter first and then a dime is seen as distinct
from choosing a dime and then a quarter—you need to use a different function,
which computes the number of permutations. This function is denoted as
P(n, k), and has the following mathematical formulation:
P(n,k) = n!/(n-k)!
Although this definition is mathematically correct, it is not well suited to
implementation in practice because the factorials involved can get much too
large to store in an integer variable, even when the answer is small

Write a function permutations(n, k) that computes the P(n, k) function
without calling the fact function.
*/

#include <iostream>

//FUNCTION PROTOTYPES


int main()
{


    system("pause>0");
    return 0;
}