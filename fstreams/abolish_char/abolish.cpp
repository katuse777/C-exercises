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
void open_output_file();
void write_to_output_file();


//GLOBAL VARIABLE DECLERATIONS
std::ifstream fin;
std::ofstream fout;
std::string filename;
std::string output_filename;

//MAIN FUNCTION
int main()
{
    write_to_output_file();

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
    fin.close();
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

void open_output_file()
{
    do
    {
        std::cout << "Enter the name of the file you want to write to: ";
        getline(std::cin, output_filename);
        fout.open(output_filename.c_str());
        if (fout.fail())    std::cout << "Failed to open " << output_filename << std::endl;
    } while (fout.fail());
}

void write_to_output_file()
{
    std::string input_file_strings;
    char ch;
    get_input_file_from_user();
    open_output_file();
    input_file_strings = get_input_file_strings();
    for (int i = 0; i < input_file_strings.length(); i++)
    {
        ch = input_file_strings[i];
        fout.put(ch);
    }
    fout.close();
}