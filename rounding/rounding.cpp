/*Write a function roundToNearestInt(x) that rounds the floating-point
  number x to the nearest integer. Show that your function works by writing a
  suitable main program to test it.
*/

//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
int round_to_nearest_int(float); //this function will take in a floating point number and round it off to hte nearest integer

//GLOVBAL VARIABLE DECLERATIONS
float user_number;

//MAIN FUNCTION
int main()
{
    std::cout << "Enter a floating point number and I will round it off to the nearest integer: ";
    std::cin >> user_number;
    std::cout << round_to_nearest_int(user_number);

    system("pause>0");
    return 0;    
}


//FUNCTION DEFINITIONS
int round_to_nearest_int(float num)
{
    num += 0.5;
    return num;
}