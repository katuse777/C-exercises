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
int permutations(int n, int k);



int n, k;
//MAIN FUNCTION
int main()
{
    std::cout << "This program determines the number of ways you can choose k values\
     from a set of n elements when the order does matter.\n\n";
    std::cout << "How many elements are in the set\n n: ";
    std::cin >> n;
    std::cout << "How many values do you choose from this set\n k: ";
    std::cin >> k;
    std::cout << permutations(n,k);

    system("pause>0");
    return 0;
}

/*permutations(int n,int k)
  -------------------------
  this function is a more efficient version of: P(n,k) = n!/(n - k)!,
  this function uses the value of k determine how many numbers should the factorial
  of n, contain.
  for example, if n = 52 and k = 2, this function will determine that the factorial of n
  should contain 2 numbers... therefore n! = 52 x 51 = 2652 and this is the very same answer
  you would get if you used: P(n,k) = n!/(n - k)! 
*/

int permutations(int n,int k)
{
    for (int i = 1; i < k; ++i)
    {
        n = n * (n - 1);
    }
    return n;
}