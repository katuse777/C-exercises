/*Write a function acronym that takes a string and returns the acronym formed from
  that string. To ensure that your function treats hyphenated compounds like
  self-contained as two words, it should define the beginning of a word as any
  alphabetic character that appears either at the beginning of the string or after a
  nonalphabetic character.
*/

#include <iostream>
#include <string>
#include <cctype>

//FUNCTION PROTOTYPES
std::string acronym(std::string str);




std::string user_string;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a string and I'll return it's acronym: ";
    getline(std::cin, user_string);
    std::cout << acronym(user_string) << '\n';
    system("pause>0");
    return 0;
}


/*std::string acronym(std::string str)
  ------------------------------------
  this function loops through the string passed in as a arguement and looks for an alphabet
  and when it finds a letter it add it to the acronym variable and ignores all the other letters
  in that word until it encounters a character that is not a letter and then it will start looking
  for the next letter to add to the acronym variable and it does so until the end of the string
*/
std::string acronym(std::string str)
{
    std::string acronym = "";
    int number_of_strings = 0;
    bool looking_for_new_string = true;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]) && looking_for_new_string)
        {
            acronym += str[i];
            looking_for_new_string = false;
        }
        else if (!isalpha(str[i]))
        {
            looking_for_new_string = true;
        }
    }
    return acronym;
}