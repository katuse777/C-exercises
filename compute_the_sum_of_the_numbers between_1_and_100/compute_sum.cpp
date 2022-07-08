/*  compute the sum of the numbers between 1 and 100  */
//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES


//GLOBAL VARIABLE DECLERATIONS
double sum = 0; //this variable will hold the sum of all the numbers between 1 and 100 
double min; //this variable will hold the minimum value which will be given by the user
double max; //this variable will hold the maximum value which will be given by the user


//MAIN FUNCTION 
int main()
{
    std::cout << "I can find the sum of all the numbers between any two numbers, where should i start: ";
    std::cin >> min;
    std::cout << "And where should I stop: ";
    std::cin >> max;

    for (int i = min; i <= max; i++)
    {
        sum += i;
    }
    std::cout << sum << std::endl;


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS