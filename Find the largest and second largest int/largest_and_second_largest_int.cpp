/*write a program that finds both the
  largest and the second-largest number in a list, prior to the entry of a sentinel.
  Once again using 0 as the sentinel, a sample run of this program might look like
  this:
*/

//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
void find_largest_and_second_largest(int);  
void connecting(); //this function will accept the numbers entered by the user and will call another function to process the numbers 

//GLOBAL VARIABLE DECLERATIONS
int largest = 0;
int second_largest = 0;


//MAIN FUNCTION
int main()
{
    std::cout << "Give me a list of numbers and I will give you the two largest numbers in that list: \n";
    connecting();
    std::cout << "The Largest Number: " << largest << "\n";
    std::cout << "The Second largest Number: " << second_largest << "\n";

    system("pause>0");
    return 0;
}


//FUNCTION DEFINITIONS

void connecting()
{
    int list_item;
    do
    {
        std::cin >> list_item;
        find_largest_and_second_largest(list_item);
        
    } while (list_item != 0);
    
}

void find_largest_and_second_largest(int user_num)
{
    if (user_num > largest)
        largest = user_num;
    else if (user_num > second_largest)
        second_largest = user_num;    
}