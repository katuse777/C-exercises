/*Write a function removeDoubledLetters(str) that returns a new string in
  which any duplicated characters in str have been replaced by a single copy
*/

#include <iostream>
#include <string>


//FUNCTION PROTOTYPES
std::string remove_double_letters(std::string & str);




std::string user_string;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string with words that containletters that appear twice and next to each other: ";
    getline(std::cin, user_string);
    std::cout << remove_double_letters(user_string);

    system("pause>0");
    return 0;
}

/*std::string remove_double_letters(std::string & str)
  ----------------------------------------------------
  this function loops through the string passed in and checks if the current character is the same as the character
  that came before it and if so, deletes the previous character 
*/
std::string remove_double_letters(std::string & str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i - 1])
        {
            str.erase(i - 1, 1);
        }
    }
    return str;
}