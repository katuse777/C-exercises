/*Implement a function capitalize(str) that returns a string in which the
  initial character is capitalized (if it is a letter) and all other letters are converted
  to lowercase. Characters other than letters are not affected. For example, both
  capitalize("BOOLEAN") and capitalize("boolean") should return
  the string "Boolean".
*/

#include <iostream>
#include <string>
#include <cctype>

//FUNCTION PROTOTYPES
std::string capitalize(std::string & str);


std::string user_string;
//MAIN FUNCTION
int main()
{
    std::cout << "Give me a string and I'll make sure only the first letter is a capital letter: ";
    getline(std::cin, user_string);
    std::cout << capitalize(user_string) << '\n';

    system("pause>0");
    return 0;
}


/*std::string capitalize(std::string & str)
  -----------------------------------------
  this function will loop through the string passed into it and capitalize the first letter it encounters
  and convert all the letters that follow to lowercase  
*/
std::string capitalize(std::string & str)
{
    bool first_aplha_is_found = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (first_aplha_is_found == false && isalpha(str[i]))
        {
            first_aplha_is_found = true;
            str[i] = toupper(str[i]);
        }
        else if (first_aplha_is_found == true && isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
        }
    }
    return str;
}