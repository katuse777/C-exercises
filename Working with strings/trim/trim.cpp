/*The strlib.h function exports a function trim(str) that returns a new
  string formed by removing all whitespace characters from the beginning and
  end of str. Write the corresponding implementation
*/
#include <iostream>
#include <string>
#include <cctype>

//FUNCTION PROTOTYPES
std::string trim(std::string);
void trim_whitespace_before_first_ch(std::string & string);
void trim_whitespace_after_last_ch(std::string & string);


int index_of_first_white_space;
int index_of_last_ch;
int num_of_whitespace_before_ch1 = 0;
bool found_first_ch = false;
int num_of_whitespace_after_last_ch = 0;
std::string words;


//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string: ";
    getline(std::cin, words);
    std::cout << words  << '\n';

    system("pause>0");
    return 0;
}

std::string trim(std::string str)
{
    trim_whitespace_before_first_ch(str);    
    str.erase(index_of_first_white_space, num_of_whitespace_before_ch1);
    trim_whitespace_after_last_ch(str);
    return str;
}

/*void trim_whitespace_before_first_ch(std::string & string)
  ----------------------------------------------------------
  this function keeps track of the number of whitespaces at the beginning of the string and
  those numbers will be used to set the position and number of characters to erase when they 
  are used in the trim() function
*/

void trim_whitespace_before_first_ch(std::string & string)
{
    for (int i = 0; i < string.length(); i++)
    {
        if (isspace(string[i]))
        {
            index_of_first_white_space = 0;
            ++num_of_whitespace_before_ch1;

        }
        else
        {
            found_first_ch = true;
            break;
        }
    }
}

/*void trim_whitespace_after_last_ch(std::string & str)
  -----------------------------------------------------
  this function removes the whitespace after the last letter, by creating a new string
  that has the same length as the user_string but this new string is composed of whitespaces
  these two strings are compared to each other and on each iteration the lengths decrease as
  the check moves closer to the end of the string and if at any point the two strings are equal
  to each other, meaning that the user_string is left with whitespaces only, the function will
  erase the remaining whitespace
*/

void trim_whitespace_after_last_ch(std::string & str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (std::string(str.length() - i, ' ') == str.substr(i, str.length() - i))
        {
            str.erase(i, str.length());
        }
    }
}