/*Write a predicate function isSentencePalindrome(str) that returns
  true if the string str fits this definition of a sentence palindrome
*/

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

//FUNCTION PROTOTYPES
bool is_sentence_palindrome(std::string str);
std::string reverse_string(std::string str);

//MAIN FUNCTION
int main()
{
    std::cout << std::boolalpha;
    std::cout << is_sentence_palindrome("Not a palindrome") << '\n';

    system("pause>0");
    return 0;
}


/*bool is_sentence_palindrome(std::string str)
  -------------------------------------------
  this function removes all punctuation in the string passed in
  and calls the reverse_string() function which reverses the string
  and compares the reversed string and the unpunctuated string and if
  they are equal then it returns true, false otherwise
*/
bool is_sentence_palindrome(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
        if (!isalpha(str[i]))
        {
            str.erase(i, 1);
            i = 0;
        }
    }
    std::string initial_string = str;
    std::string reversed_string = reverse_string(str);
    std::cout << "Initial string: " << initial_string << '\n';
    std::cout << "Reversed string: " << reversed_string << '\n';
    return (initial_string == reversed_string);
}

std::string reverse_string(std::string str)
{
    std::string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    return reversed;
}