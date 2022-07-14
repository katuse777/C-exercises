/*You can use successive approximation to determine the square root of x by
  adopting the following strategy:
  1. Begin by guessing that the square root is x / 2. Call that guess g.
  2. The actual square root must lie between g and x / g. At each step in the
  successive approximation, generate a new guess by averaging g and x / g.
  3. Repeat step 2 until the values g and x / g are as close together as the
  machine precision allows. In C++, the best way to check for this condition
  is to test whether the average is equal to either of the values used to
  generate it.
  Use this strategy to write your own implementation of the sqrt function.
*/

#include <iostream>


//FUNCTION PROTOTYPES
int square_root(double);


double num;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a number, and I'll return it's square root: ";
    std::cin >> num;
    std::cout << square_root(num);
    system("pause>0");
    return 0;
}

int square_root(double x)
{
    double g = x/2;
    while (g != x/g)
    {
        g = (g + x/g)/2;
    }
    return g;
}