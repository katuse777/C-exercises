/*Write a program that reads in a positive integer N and then calculates and
  displays the sum of the first N odd integers. For example, if N is 4, your
  program should display the value 16, which is 1 + 3 + 5 + 7.
*/
//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
unsigned number_of_odd_values(); // this function will take the value of N and use it to determine how odd numbers should be added together
unsigned odd_numbers();  //this function will determine if a number is odd and if so it will be added to the sum
unsigned sum_of_odd_values(unsigned); //this function will compute the sum of the first N odd numbers


//GLOBAL VARIABLE DECLERATIONS



//MAIN FUNCTION
int main()
{
    std::cout << "Give me a positive number (N) and I will give you the sum of the first (N) odd numbers: ";
    number_of_odd_values();


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

} 

unsigned odd_numbers()
{
    int odd_num;
    
}