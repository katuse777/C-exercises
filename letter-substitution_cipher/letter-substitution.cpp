/*Write a program that implements encryption using a letter-substitution
  cipher
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "QWERTYUIOPASDFGHJKLZXCVBNM" 
*/

#include <iostream>
#include <string>


//FUNCTION PROTOTYPES
char shift_characters(char ch);
std::string encode_message(std::string);

std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
//MAIN FUNCTION
int main()
{
    std::cout << encode_message("WORKERS OF THE WORLD UNITE!");

    system("pause>0");
    return 0;
}

std::string encode_message(std::string str)
{
    std::string encoded_msg = "";
    for (int i = 0; i < str.length(); i++)
    {
        encoded_msg += shift_characters(str[i]);
    }
    return encoded_msg;
}


char shift_characters(char ch)
{
    for (int i = 0; i < alphabet.length() ; i++)
    {
        if ( ch == alphabet[i] )
            return key[i];
    }
    return ch;
}