/**In Pig Latin, words are formed from their English counterparts by applying the following rules:
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
#include <cctype>


//FUNCTION PROTOTYPES
std::string extract_words(std::string str);
std::string to_pig_latin(std::string str);
std::string consonants_until_first_vowel(std::string & str);
bool contains_no_vowels(std::string str);
bool begins_with_consonant(std::string str);
bool begins_with_vowel(std::string str);
bool is_consonant(char ch);

std::string word = "pig";
std::string vowels = "aeiou";
//MAIN FUNCTION
int main()
{
    std::cout << consonants_until_first_vowel(word);

    system("pause>0");
    return 0;
}



/*std::string to_pig_latin(std::string str)
  ----------------------------------------
  this function takes a word as a argument and if that word contains no vowels, that word is
  the return value of the function, if the word begins with a vowel the word "way" is added 
  to the end of the word, if the word begins with  a consonant, all the characters before 
  the first vowel are moved to the end of the string and the word "ay" is also added to the end
  of the string. 
*/
std::string to_pig_latin(std::string word)
{
    std::string pig_latin = "";
    if (contains_no_vowels(word)) return word;
    else if (begins_with_vowel(word))
    {
        pig_latin += word + "way";
    }
    else if (begins_with_consonant(word))
    {
        std::string consonants_at_end = consonants_until_first_vowel(word);
        pig_latin += word + consonants_at_end + "ay";
    }
    return pig_latin;
}

/*bool begins_with_vowel(std::string str)
  ---------------------------------------
  this function determines whether the string passed in begins with a vowel
*/
bool begins_with_vowel(std::string str)
{
    for (int i = 0; i < vowels.length(); i++)
    {
        if (str[0] == vowels[i])
            return true;
    }
    return false;
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
            if (str[i] == vowels[j])
                return false;
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
        if (str[0] == vowels[i])
            return false;
    }
    return true;
}

/*std::string consonants_until_first_vowel(std::string str)
  ---------------------------------------------------------
  this function will extract all the consonants before the first vowel in the string
  provided the string begins with a consonant
*/
std::string consonants_until_first_vowel(std::string & str)
{
    std::string chars_before_vowel = "";
    int i = 0;
    int original_string_len = str.length();
    while (is_consonant(str[i]))
    {
        chars_before_vowel += str[i];
        str.erase(i, 1);

        if (str.length() < original_string_len)
            i = 0;
        else
            i++;
    }
    return chars_before_vowel;
}

bool is_consonant(char ch)
{
    for (int i = 0; i < vowels.length(); i++)
    {
        if (ch == vowels[i])
            return false;
    }
    return true;
}