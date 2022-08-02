/*Write a program
  that asks the user for an input file, an output file, and a string of letters to be
  eliminated. The program should then copy the input file to the output file,
  deleting any of the letters that appear in the string of censored letters, no
  matter whether they appear in uppercase or lowercase form.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

//FUNCTION PROTOTYPES
void get_input_file_from_user();
std::string letter_to_abolish(std::string letters);
std::string get_input_file_strings();
bool is_same_as_abolish_char(char ch,std::string abolish_chars);



//GLOBAL VARIABLE DECLERATIONS
std::ifstream fin;
std::ofstream fout;
std::string filename;
std::string output_filename;

//MAIN FUNCTION
int main()
{
    get_input_file_from_user();
    std::cout << get_input_file_strings();


    return 0;
}

void get_input_file_from_user()
{
    do
    {
        std::cout << "Enter filename: ";
        getline(std::cin, filename);
        fin.open(filename.c_str());
        if (fin.fail())  std::cout << "File not found: " << filename << std::endl;
    } while (fin.fail());    
}

std::string letter_to_abolish(std::string letters)
{
    return letters;
} 

std::string get_input_file_strings()
{
    char ch;
    std::string words_to_abolish;
    std::cout << "Which letters should i remove from each word: " << std::endl;
    getline(std::cin, words_to_abolish);
    std::string abolish = letter_to_abolish(words_to_abolish);
    std::string new_string = "";
    do
    {
        ch = fin.get();
        if (ch == EOF) break;
        if (is_same_as_abolish_char(ch, abolish))  continue;
        else new_string += ch;
    } while ( true);
    return new_string;
}

bool is_same_as_abolish_char(char ch,std::string abolish_chars)
{
    for (int i = 0; i < abolish_chars.length(); i++)
    {
        if (isupper(abolish_chars[i]))
        {
            if (ch == abolish_chars[i] || ch == tolower(abolish_chars[i])) return true;
        }
        else if (islower(abolish_chars[i]))
        {
            if (ch == abolish_chars[i] || ch == toupper(abolish_chars[i])) return true;
        }
    }
    return false;
}