/*Implement the function endsWith(str, suffix), which returns true if
  str ends with suffix. Like its startsWith counterpart, the endsWith
  function should allow the second argument to be either a string or a character
*/

#include <iostream>
#include <string>
#include <iomanip>

//FUNCTION PROTOTYPES
void find_suffix(std::string str, std::string suffix);
bool ends_with(bool);

bool ends_with_suffix;

//MAIN FUNCTION
int main()
{
    std::string user_string, user_suffix;
    std::cout << "Give me a string: ";
    getline(std::cin, user_string);
    std::cout << "Enter and what does you string end with? ";
    getline(std::cin, user_suffix);
    find_suffix(user_string, user_suffix);
    std::cout << std::boolalpha;
    std::cout << ends_with(ends_with_suffix);
    system("pause>0");
    return 0;
}

/*void find_suffix(std::string str, std::string suffix)
  ------------------------------------------------------
  this procedure takes in twp strings, str is a string from the user and suffix
  is the string we are checking for in the user's string. this function will determine
  the length of the suffix( say three characters ) and take the same number of characters
  from the end of the str string and compare the two, to see if they are the same
*/

void find_suffix(std::string str, std::string suffix)
{
    int suffix_len = suffix.length();      //how long is the suffix
    int starting_index = str.length() - suffix_len;   // the starting position of the substr function
    std::string str_suffix = str.substr(starting_index, suffix_len);
    if (str_suffix == suffix)  ends_with_suffix = true;
    else    ends_with_suffix = false;
}

bool ends_with(bool ends_with)
{
    return ends_with;
}