/*In Pig Latin, words are formed from their English counterparts by applying the following rules:
  1. If the word contains no vowels, no translation is done, which means that the
  translated word is the same as the original.
  2. If the word begins with a vowel, the function adds the string "way" to the end
  of the original word.
  3. If the word begins with a consonant, the function extracts the string of
  consonants up to the first vowel, moves that collection of consonants to the end
  of the word, and adds the string "ay".
*/

#include <iostream>
#include <string>
#include <cctpye>


//FUNCTION PROTOTYPES
std::string to_pig_latin(std::string str);
bool contains_no_vowels(std::string str);
bool begins_with_consonant(std::string str);
std::string consonants_until_first_vowel(std::string str);


std::string vowels = "aeiou";
//MAIN FUNCTION
int main()
{

    system("pause>0");
    return 0;
}

std::string to_pig_latin(std::string str)
{

}

/*bool contains_vowels(std::string str)
  --------------------------------------
  this function determines whether the string passed in contains any vowels
*/
bool contains_no_vowels(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < vowels.length(); j++)
        {
            if (str[i] == vowels[j]) return false;
        }
    }
    return true;
}

/*bool begins_with_consonant(std::string str)
  -------------------------------------------
  this function determines whether the string passed in begins with a consonant
*/
bool begins_with_consonant(std::string str)
{
    for (int i = 0; i < vowels.length(); i++)
    {
        if (str[0] == vowels[i])    return false;
    }
    return true;
}

/*std::string consonants_until_first_vowel(std::string str)
  ---------------------------------------------------------
  this function will extract all the consonants before the first vowel in the string
  provided the string begins with a consonant
*/
std::string consonants_until_first_vowel(std::string str)
{
    std::string chars_before_vowel = "";
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < vowels.length(); j++)
        {
            if (!(str[i] == vowels[j]))
                chars_before_vowel += str[i];
            else return chars_before_vowel;    
        }
    }
    return chars_before_vowel;
}