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
std::string substitution = "QWERTYUIOPASDFGHJKLZXCVBNM";
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
    char new_char = ch;
    switch(ch)
    {
        case 'A':
            new_char = 'Q';
            break;
        case 'B':
            new_char = 'W';
            break;    
        case 'C':
            new_char = 'E';
            break;
        case 'D':
            new_char = 'R';
            break;    
        case 'E':
            new_char = 'T';
            break;
        case 'F':
            new_char = 'Y';
            break;
        case 'G':
            new_char = 'U';
            break;
        case 'H':
            new_char = 'I';
            break;
        case 'I':
            new_char = 'O';
            break;
        case 'J':
            new_char = 'P';
            break;
        case 'K':
            new_char = 'A';
            break;
        case 'L':
            new_char = 'S';
            break;
        case 'M':
            new_char = 'D';
            break;
        case 'N':
            new_char = 'F';
            break;
        case 'O':
            new_char = 'G';
            break;
        case 'P':
            new_char = 'H';
            break;
        case 'Q':
            new_char = 'J';
            break;
        case 'R':
            new_char = 'K';
            break;
        case 'S':
            new_char = 'L';
            break;
        case 'T':
            new_char = 'Z';
            break;
         case 'U':
            new_char = 'X';
            break;
        case 'V':
            new_char = 'C';
            break;
        case 'W':
            new_char = 'V';
            break;
        case 'X':
            new_char = 'B';
            break;
        case 'Y':
            new_char = 'N';
            break;
        case 'Z':
            new_char = 'M';
            break;                           
        default:
            new_char = ch;
    }
    return new_char;
}