/*Implement the function endsWith(str, suffix), which returns true if
  str ends with suffix. Like its startsWith counterpart, the endsWith
  function should allow the second argument to be either a string or a character
*/

#include <iostream>
#include <string>
#include <cctype>

//FUNCTION PROTOTYPES
void find_suffix(std::string str, std::string suffix);


//MAIN FUNCTION
int main()
{
    std::string user_string, user_suffix;
    std::cout << "Give me a string: ";
    getline(std::cin, user_string);
    std::cout << "Enter and what does you string end with? ";
    getline(std::cin, user_suffix);
    find_suffix(user_string, user_suffix);
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
    if (str_suffix == suffix)
        std::cout << "The string does end with the suffix\n";
    else 
        std::cout << "No it does not\n";    

    std::cout << str_suffix << std::endl;
    std::cout << suffix << std::endl;    
}