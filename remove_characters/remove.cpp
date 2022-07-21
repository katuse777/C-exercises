/*Write a function, string removeCharacters(string str, string remove);
  that returns a new string consisting of the characters in str after removing all
  instances of the characters in remove. For example, if you call
  removeCharacters("counterrevolutionaries", "aeiou")
  the function should return "cntrrvltnrs", which is the original string after
  removing all of its vowels.
*/

#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
std::string remove_characters(std::string & str, std::string remove);


std::string user_string, remove_ch;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string: ";
    getline(std::cin, user_string);
    std::cout << "Enter a string all the character's you'd like me to remove from your string: ";
    std::cin >> remove_ch;
    std::cout << remove_characters(user_string, remove_ch);


    system("pause>0)");
    return 0;
}


/*std::string remove_characters(std::string & str, std::string remove)
  --------------------------------------------------------------------
  this function loops through the str, given by the user and compares
  each character of the string with each character of the string 'remove'
  and if the character in str match a letter in 'remove', that letter 
  is deleted from str and returns str
*/
std::string remove_characters(std::string & str, std::string remove)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < remove.length(); j++)
        {
            if (str[i] == remove[j])
            {
                str.erase(i,1);
                j = 0;
            }
        }
    }
    return str;
}