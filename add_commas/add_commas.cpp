/*To make it easier for programmers to display numbers in this fashion,
  implement a function, string addCommas(string digits);
  that takes a string of decimal digits representing a number and returns the
  string formed by inserting commas at every third position, starting on the
  right
*/

#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
std::string add_commas(int num);



//MAIN FUNCTION
int main()
{
    std::cout << add_commas(1000);

    system("pause>0");
    return 0;
}

std::string add_commas(int num)
{
    int numbers_counted = 0;
    std::string num_with_commas = std::to_string(num);
    for (int i = num_with_commas.length() - 1; i >= 0 ; i--)
    {
        ++numbers_counted;
        if (numbers_counted % 3 == 0)
        {
            num_with_commas.insert(i,",");
        }

    }
    return num_with_commas;
}