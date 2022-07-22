/*Devise a rule that determines what suffix should be added to each number, and then use this rule
  to write a function createOrdinalForm(n) that returns the ordinal form of
  the number n as a string.
*/

#include <iostream>
#include <string>


//FUNCTION PROTOTYPES
std::string ordinal_form(int num);

//MAIN FUNCTION
int main()
{
    std::cout << ordinal_form(33) << '\n';

    system("pause>0");
    return 0;
}

/*std::string ordinal_form(int num)
  ---------------------------------
  this function takes in a number a turns it into a string containing said number and checking the 
  value of the of the last digit in the number, if the last digit is 1 and the second last digit
  is also 1 then the ordinal form should have the suffix 'th' but if the second last digit is not
  1 then the suffix should be 'st', if the last digit is 2, then sthe suffix should be 'nd' and
  if the last digit is 3 then the suffix should be 'rd'. all other cases should have the suffix 'th'
*/
std::string ordinal_form(int num)
{
    std::string ordinal_num = std::to_string(num);
    if (num % 10 == 1)    // checking the value of the of the last digit in the number, 
    {                     //if the last digit is 1 and the second last digit
        num = num / 10;   //is also 1 then the ordinal form should have the suffix 'th'
        if (num % 10 == 1) //but if the second last digit is not 1 then the suffix should be 'st'
        {
            ordinal_num += "th";
        }
        else ordinal_num += "st";
    }
    else if (num % 10 == 2) ordinal_num += "nd";
    else if (num % 10 == 3) ordinal_num += "rd";
    else ordinal_num += "th";

    return ordinal_num;
}