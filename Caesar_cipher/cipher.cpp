/*To implement a Caesar cipher, you should first define a function
  string encodeCaesarCipher(string str, int shift);
  that returns a new string formed by shifting every letter in str forward the
  number of letters indicated by shift, cycling back to the beginning of the
  alphabet if necessary
*/

#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
std::string encode_caesar_cipher(std::string str, int shift);
char shift(char ch, int shift);


//MAIN FUNCTION
int main()
{
    std::cout << shift('T', 13);


    system("pause>0");
    return 0;
}


/*char shift(char ch, int shift)
  ------------------------------
  this function takes in a character and a integer, converts the the character to it's
  character code(an integer) and adds the integer (shift) to the character code and this
  results in a new character code. If we are trying to shift a capital letter, then the new
  letter should also be a capital letter, therefore no matter how big the shift is, the result 
  must always be the character code of a capital letter in this case so after shifting the 
  character code of the char passed in, we find the remainder when the new character code is divided
  by the largest character code for the capital letter plus one, to ensure that the new character code
  always falls in this range and we add the lowest character code of capital letters like so,
  (ch_code % (highest_ch_code + 1)) + lowest_ch_code
  the new character code will fall in the range: lowest_ch_code <= new_ch_code < highest_ch_code + 1
  and I did this for all lower case letters too
*/
char shift(char ch, int shift)
{
    int ch_code = ch;
    ch_code += shift;
    char shifted = ch_code;
    if (isalpha(ch) && islower(ch))
        shifted = (shifted % 123) + 96;
    else
        shifted = (shifted % 91) + 65;     
    
    return shifted;
}