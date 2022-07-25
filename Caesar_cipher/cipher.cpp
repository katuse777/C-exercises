/**To implement a Caesar cipher, you should first define a function
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
char shift_characters(char ch, int shift);



std::string user_string;
int shift_val = 0;
//MAIN FUNCTION
int main()
{
	std::cout << "This program encodes a message using Caesar's Cipher.\n"
		"Enter the number of character positions to shift: ";
	std::cin >> shift_val;
	std::cout << encode_caesar_cipher("IBM 9000", shift_val);

	system("pause>0");
	return 0;
}


/*std::string encode_caesar_cipher(std::string str, int shift)
* ------------------------------------------------------------
  this function takes the string str and passes all it's individual charcters
  into the shift_characters() function and uses the form a new string called encoded_msg,
  this string is formed by shifting all the characters in str by the value of the shift parameter
  and is the return value of this function
*/
std::string encode_caesar_cipher(std::string str, int shift)
{
	std::string encoded_msg = "";
	for (int i = 0; i < str.length(); i++)
	{
		encoded_msg += shift_characters(str[i], shift);
	}
	return encoded_msg;
}



/*char shift_characters(char ch, int shift)
* -----------------------------------------
  this function takes in a character (ch) and and integer (shift) and stores
  ch in a integer called char_code so that we can perform a character shift 
  by performing addition on the character code of (ch), if ch is a lower case
  letter than to shift it by (shift) units we just add the value of shift to 
  ch's character code (char_code) and if the character code is bigger than 122
  which is the character code for the last lower case letter, we need the values
  to circle back to the value of first character code for lower case letters,
  thus we track by how many units the character code has overflown and add that 
  number to the value of the first lower case character code and assign it to the 
  (shifted_char) variable, and this is also done for uppercase letters
*/
char shift_characters(char ch, int shift)
{
	int char_code = ch;
	wchar_t shifted_char = ' ';  // I'm using the wide char beacuse the normal char was too small to contain
	int over_flow = 0;           //the values that i want to store in the shifted_char variable beacuse 
	if (isalpha(ch) && islower(ch))
	{
		shifted_char = char_code + shift;
		if (shifted_char > 122)
		{
			over_flow = shifted_char - 123;
			shifted_char = 97 + over_flow;
		}
	}
	else if (isalpha(ch) && isupper(ch))
	{
		shifted_char = char_code + shift;
		if (shifted_char > 90)
		{
			over_flow = shifted_char - 91;
			shifted_char = 65 + over_flow;

		}
	}
	else return ch;
	return shifted_char;
}