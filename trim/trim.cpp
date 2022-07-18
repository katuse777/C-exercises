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
int num_of_whitespace_before_ch1;
bool found_first_ch;
int num_of_whitespace_after_last_ch;
std::string words;


//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string: ";
    getline(std::cin, words);
    std::cout << trim(words);

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


void trim_whitespace_after_last_ch(std::string & string)
{
    
}