/*Write a program that calculates an approximation of π consisting of the first
  10,000 terms in Leibniz’s series
*/

//INCLUDE DIRECTIVES
#include <iostream>
#include <iomanip>
#include <ios>

//FUNCTION PROTOTYPES
bool is_odd(int);  //this function will take in a number as an argument and retun true if that number is an odd number
void calculating_PI(); 
void leibniz_series(double);   //this functin will execute leibniz_series 

//GLOBAL VARIABLE DECLERATIONS
long double  PI = 0;
int number_of_odd_numbers = 0; //this variable will keep track of the number of odd numbers and will ensure that the program uses 10000 odd numbers
int number_of_iterations = 0; //this variable will kep track on the number of cycles completed and will help to decide wether the computer should add or subtract

//MAIN FUNCTION
int main()
{
    calculating_PI();
    std::cout << PI;

    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
bool is_odd(int num)
{
    return (num % 2 != 0) ? true : false; 
}

void calculating_PI()
{
    int i = 1;

    while (number_of_odd_numbers < 10000)
    {
        if (is_odd(i))
        {
            ++number_of_iterations;
            ++number_of_odd_numbers;
            leibniz_series(i);
        }

        i++;    
    }
    PI *= 4;
}

void leibniz_series(double odd_number)
{
    if (number_of_iterations % 2 == 0)         //to decide whether to add or subtract, the computer will check on which iteration the loop is on if the cycle
        PI -= 1/odd_number;                    //number is a even number than it should subtract, else it should sadd beacuse on the second cycle which is an
    else                                      //odd number we subtracted and thus we should do so for all the even values of the (number_of_iterations variable
        PI += 1/odd_number;    
}