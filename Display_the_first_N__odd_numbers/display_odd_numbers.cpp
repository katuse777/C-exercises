/*Write a program that reads in a positive integer N and then calculates and
  displays the sum of the first N odd integers. For example, if N is 4, your
  program should display the value 16, which is 1 + 3 + 5 + 7.
*/
//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
unsigned number_of_odd_values(); // this function will take the value of N and use it to determine how odd numbers should be added together
void print_sum_of_odd_numbers();  //this function will print out the sum of the odd numbers
unsigned sum_of_odd_values(unsigned); //this function will compute the sum of the first N odd numbers


//GLOBAL VARIABLE DECLERATIONS
unsigned sum = 0;
unsigned odd_numbers_found = 0; //this variable will keep track of the number of variables found and will help make sure we don't add more numbers than we need 

//MAIN FUNCTION
int main()
{
    std::cout << "Give me a positive number (N) and I will give you the sum of the first (N) odd numbers: ";
    unsigned total_num_of_odds = number_of_odd_values();
    sum_of_odd_values(total_num_of_odds);
    std::cout << "The sum the first: " << total_num_of_odds << " odd numbers is equal to: " << sum;

    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
unsigned number_of_odd_values()
{
    unsigned N;
    std::cin >> N;

    return N;
}

unsigned sum_of_odd_values(unsigned N)
{
    int i = 1;
    while (true)
    {
        if (i % 2 != 0)
        {
            ++odd_numbers_found;
            sum += i;
        }   

        ++i;
        if (odd_numbers_found == N)
            break;
    }

    return sum;
} 
