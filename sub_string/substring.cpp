/*Without using the built-in string method substr, implement a free function
  substr(str, pos, n) that returns the substring of str beginning at position
  pos and containing at most n characters. Make sure that your function
  correctly applies the following rules:
  • If n is missing or greater than the length of the string, the substring should
  extend through the end of the original string.
  • If pos is greater than the length of the string, substr should call error
  with an appropriate message.
*/

#include <iostream>
#include <string>



//FUNCTION PROTOTYPES
std::string substr(std::string,int, int);


std::string user_string;
int position, number_of_characters;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string: ";
    getline(std::cin, user_string);
    std::cout << "Now I can extract a piece of that string, enter the starting position for the extraction: ";
    std::cin >> position;
    std::cout << "How many characters to extract: ";
    std::cin >> number_of_characters;
    std::string new_string;
    new_string = substr(user_string, position, number_of_characters);
    std::cout << "New string: " << new_string;


    system("pause>0");
    return 0;
}

std::string substr(std::string str,int pos,int n)
{
    std::string sub_string = "";    
    for (int i = 1; i <= n; i++)
    {
        sub_string += str[pos];
        pos++;
    }
    return sub_string;
}