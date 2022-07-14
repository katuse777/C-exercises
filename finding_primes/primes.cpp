/*Write a predicate method isPrime(n) that returns true if the integer n is prime, and false
  otherwise. To test your algorithm, write a main program that lists the prime
  numbers between 1 and 100.
*/

#include <iostream>


//FUNCTION PROTOTYPES
bool is_prime(int);
void print_primes();


//MAIN FUNCTION
int main()
{
    print_primes();
    system("pause>0");
    return 0;
}


/* is_prime(int)
   -------------
   this function takes an integer value as an argument and loops through all
   the numbers that are less than or equal to the given integer, if there are
   two numbers in this range that can completely divide the integer, then that number
   is a prime and the function returns true
*/
bool is_prime(int n)
{
    int num_of_divisors = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) ++num_of_divisors;
    }

    return num_of_divisors == 2;
}

/*print_primes()
  --------------
  this function will loop through the first 100 numbers and will print out all the primes to
  the console
*/

void print_primes()
{
    for (int i = 1; i <= 100; i++)
    {
        if (is_prime(i)) std::cout << i << '\n';
    }
}