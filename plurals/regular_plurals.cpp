/*Write a function createRegularPlural(word) that returns the plural of
  word formed by following these standard English rules:
  a. If the word ends in s, x, z, ch, or sh, add es to the word.
  b. If the word ends in a y preceded by a consonant, change the y to ies.
  c. In all other cases, add just an s.
*/

#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
std::string create_regular_plural(std::string word);
bool preceded_by_consonant(std::string word);


//MAIN FUNCTION
int main()
{
  std::cout << create_regular_plural("hike") << '\n';

  system("pause>0");
  return 0;
}

std::string create_regular_plural(std::string word)
{
  std::string last_two_ch = word.substr(word.length() - 2, 2);
  char last_char = word[word.length() - 1];
  if (last_char == 's' || last_char == 'x' || last_char == 'z' ||
   last_two_ch == "ch" ||last_two_ch == "sh")
  {
    word += "es";
  }
  else if (last_char == 'y' && preceded_by_consonant(word))
  {
    word.erase(word.length() - 1, 1);
    word.insert(word.length(), "ies");
  }
  else
  {
    word += 's';
  }

  return word;
}


bool preceded_by_consonant(std::string word)
{
  char second_last_char = word[word.length() - 2];
  bool is_a_consonant = true;
  std::string vowels = "aeiou";
  for (int i = 0; i < vowels.length(); i++)
  {
    if (second_last_char == vowels[i])  is_a_consonant = false;
  }
  return is_a_consonant;
}