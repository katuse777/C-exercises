/*  compute the sum of the numbers between 1 and 100  */
//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES


//GLOBAL VARIABLE DECLERATIONS
int sum = 0; //this variable will hold the sum of all the numbers between 1 and 100 

//MAIN FUNCTION 
int main()
{
    for (int i = 1; i <=100; i++)
    {
        sum += i;
    }
    std::cout << sum << std::endl;


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS