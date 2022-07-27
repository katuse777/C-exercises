/*Write a program to display the prime factorization of a number n*/

//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
void factors_of_n(int); // this function will find all the factors of n and pass into another function that will determine if their primes or not 
bool is_prime(int);  //this function will check if the number passed in is prime

//GLOBAL VARIABLE DECLERATIONS
int n;

//MAIN FUNCTION 
int main()
{
    std::cout << "Give me a number and I'll give you all it's prime factorization: ";
    std::cin >> n;
    factors_of_n(n);
    
    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
void factors_of_n(int number)
{
    for (int i = 1; i < n; i++)
    {
        if (number % i == 0)
        {
            if (is_prime(i))
                std::cout << i << " " ;
        }
        else 
            continue;
    }
}

bool is_prime(int num)
{
    int number_of_factors = 0;            //to keep track of the number of factors, if this value is not equal to 2, then that number is not a prime

    for (int j = 1; j <= num; j++)
    {
        if (num % j == 0)
            ++number_of_factors;
    }
                                                 
    if (number_of_factors == 2)
        return true;
    else
        return false;     
}