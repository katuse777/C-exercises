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
bool ends_with_e(std::string word);
std::string to_obenglobish(std::string word);

std::string user_string;
std::string vowels = "aeiou";
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a word: ";
    std::cin >> user_string;
    std::cout << to_obenglobish(user_string) << '\n';

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

/*bool consecutive_vowels(std::string word)
  -----------------------------------------
  when a word is passed into this function, the is_vowel() function is called on each
  of the letters in the word. the num_of_vowels_in_a_row variable keeps track of the
  vowels, when a letter is a vowel, the variable is incremented and if the next letter
  is also a vowel, the variable is incremented again and when the value is 2, the function
  returns true but if the following letter is not a vowel, the value of the variable is reset
  and if the num_of_vowels_in_a_row never reaches 2 by the time the loop ends, the function
  returns false
*/
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

bool ends_with_e(std::string word)
{
    if (word[word.length() - 1] == 'e')
        return true;
    else return false;
}


/*std::string to_obenglobish(std::string word)
  --------------------------------------------
  this function applies the rules for converting an english word to onenglobish,
  if the word passed has two vowels that appear next to each other than the word "ob"
  will not be added infront of the vowels but will be added to the front any vowels
  in the same word that are not followed by another vowel.
  if there are no two vowels that appear next to each other then the word "ob" will be
  added infront of the vowels
*/
std::string to_obenglobish(std::string word)
{
    std::string obenglobish = "";    
    if (consecutive_vowels(word))
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (is_vowel(word[i]) && is_vowel(word[i + 1]))
            {
                obenglobish += word[i];
            }
            else if (is_vowel(word[i]) && !(is_vowel(word[i + 1])))
            {
                obenglobish += "ob";
                obenglobish += word[i];
            }
        }
    }
    else
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (is_vowel(word[i]) && i < word.length() - 1)
            {
                obenglobish += "ob";
                obenglobish += word[i];
            }
            else if (word[word.length() - 1] == 'e')
                obenglobish += word[i];   
            else
                obenglobish += word[i];
        }
    }
    return obenglobish;
}