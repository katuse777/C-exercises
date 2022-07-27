/*write a program that reads in an integer and then displays the
  number that has the same digits in the reverse order
*/

//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
int reverse_digits(int); // this function takes in a number as  argument and returns the number with it's digits reversed

//GLOBAL VARIABLE DECLERATIONS
int user_number;

//MAIN FUNCTION
int main()
{
  std::cout << "Enter a number and i will return that number with the digits in reversed order: ";
  std::cin >> user_number;
  std::cout << reverse_digits(user_number);


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
int reverse_digits(int user_num)
{
  int last_digit = 0;

  while (user_num > 0)
  {
    last_digit *= 10;
    last_digit += user_num % 10;  //returns the last digit in user_num and stores it in the last digit variable  
    user_num /= 10;  //removes the last digit from the user_num and assings the new value to the user_num variable

  }

  return last_digit;
}