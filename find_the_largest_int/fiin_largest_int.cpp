/*Write a program that reads in a list of integers from the user until the user
  enters the value 0 as a sentinel. When the sentinel appears, your program
  should display the largest value in the list, as illustrated in the following sample
  run:
*/

//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
int get_user_input();
int largest_num(int);  //this function returns the largest number



//GLOBAL VARIABLE DECLERATIONS
const int SENTINEL = 0;  // this variable holds the stop number
int max = 0;   //this variable will hold the largest number in the list

//MAIN FUNCTION
int main()
{
    std::cout << "Enter as many numbers as you want and Will return the largest number from the numbers you have entered.\n"
        "TO STOP THE PROGRAM, ENTER THE NUMBER ZERO(0): \n";
    int absolute_max = get_user_input();
    std::cout << "The largest number you have entered is: " << absolute_max << "\n";


    system("pause>0");
    return 0;
}


//FUNCTION DEFINITIONS
int largest_num(int user_num)
{
    if (user_num == 0)
        ;
    else if (max < user_num)
        max = user_num;


    return max;
}

int get_user_input()
{
    int user_num;  //this variable holds the entered by the  user and will be used to print list of values
    int maximum_number;
    do
    {
        std::cin >> user_num;
        maximum_number = largest_num(user_num);

    } while (user_num != SENTINEL);

    return maximum_number;
}