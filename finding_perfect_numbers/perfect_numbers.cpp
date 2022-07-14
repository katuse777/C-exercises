/*a proper divisor of n is any divisor less than n itself
 *numbers that are equal to the sum of their proper divisors are called perfect numbers
 *Write a predicate function isPerfect that takes an integer n and returns
  true if n is perfect, and false otherwise. Test your implementation by
  writing a main program that uses the isPerfect function to check for perfect
  numbers in the range 1 to 9999 by testing each number in turn. When a perfect
  number is found, your program should display it on the screen.
*/

#include <iostream>
int sum_of_proper_divisors(int);
bool is_perfect(int);

//FUNCTION PROTOTYPES



//MAIN FUNCTION
int main()
{

    std::cout << is_perfect(28);
    system("pause>0");
    return 0;
}

/* is_perfect()
   ------------
   this function takes the sum of all the proper divisors of n and checks if it's equal to the value
   of (n) and returns true or false 
*/

bool is_perfect(int n)
{
    return sum_of_proper_divisors(n) == n;
}

/* sum_of_proper_divisors()
   -------------------------
   this function loops through all the numbers less then (n) and if they are a proper divisor, 
   the will be added to the sum and this sum is the return value of this function 
*/
int sum_of_proper_divisors(int num)
{
    int sum_of_proper_divisors = 0;
    for (int i = 1; i < num; i++)
    {
        if (i < num && num % i == 0)
            sum_of_proper_divisors += i;    
    }
    return sum_of_proper_divisors;
}