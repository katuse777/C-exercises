/*In official Obenglobish, the ob characters are added only before vowels
  ob should be added before every vowel in the
  English word except
  • Vowels that follow other vowels
  • An e that occurs at the end of the word
  Write a function obenglobish that takes an English word and returns its
  Obenglobish equivalent, using the translation rule given above. For example,
  if you used your function with the main program
*/

#include <iostream>
#include <string>



//FUNCTION PROTOTYPES
bool is_vowel(char ch);
bool consecutive_vowels(std::string word);


std::string vowels = "aeiou";
//MAIN FUNCTION
int main()
{
    std::cout << consecutive_vowels("yes");

    system("pause>0");
    return 0;
}

bool is_vowel(char ch)
{
    for (int i = 0; i < vowels.length(); i++)
    {
        if (ch == vowels[i])
            return true;
    }
    return false;
}

bool consecutive_vowels(std::string word)
{
    int num_of_vowels_in_a_row = 0;
    for (int i = 0; i < word.length(); i++)
    {
        if (is_vowel(word[i]))
            ++num_of_vowels_in_a_row;
        else
            num_of_vowels_in_a_row = 0;

        if (num_of_vowels_in_a_row == 2)
            return true;         
    }
    return false;
}