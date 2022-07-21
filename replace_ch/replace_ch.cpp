/*Write a function, string replaceAll(string str, char c1, char c2);
  that returns a copy of str with every occurrence of c1 replaced by c2. For
  example, calling replaceAll("nannies", 'n', 'd');
  should return "daddies".
*/

#include <iostream>
#include <string>

//FUNCTION PROTOTYPES
std::string replace_all(std::string str, char c1, char c2);


std::string user_string;
char c1, c2;
//MAIN FUNCTION
int main()
{
    std::cout << "This program can read a string and replace any character in that string with any character you want it's place.\n"
    "So, enter a string: ";
    getline(std::cin, user_string);
    std::cout << "Which character should be replaced: ";
    std::cin >> c1;
    std::cout << "With which character should it be replaced with: ";
    std::cin >> c2;
    std::cout << replace_all(user_string, c1, c2);

    system("pause>0");
    return 0;
}

std::string replace_all(std::string str, char c1, char c2)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == c1)   str[i] = c2;
    }
    return str;
}