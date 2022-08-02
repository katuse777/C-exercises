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


/*void get_input_file_from_user()
  -------------------------------
  this function will ask the user to enter the name of the file to read from
  then open the file, if the file doesn't exist, the user will be asked to enter
  the name of the file again.
  I'll call this function in the defintion of the get_input_file_strings() function
*/
void get_input_file_from_user()
{
    do
    {
        std::cout << "Enter the name of the file to read from: ";
        getline(std::cin, filename);
        fin.open(filename.c_str());
        if (fin.fail())  std::cout << "File not found: " << filename << std::endl;
    } while (fin.fail());    
}

/*std::string get_input_file_strings()
  ------------------------------------
  this function calls the get_input_file() function and opens the input file then 
  asks the user which the user which letters should be removed from the words being
  read when printed to the output file, these letters will be stored in a variable.
  The function reads the input file character by character and if the character
  that is being read is one of the the letters to be removed, it won't get added to 
  the new_string variable. Once the end of the file is reached the loop stops, the file
  is closed and the string containing all the characters from the input file besides
  those that are to be removed is returned
*/
std::string get_input_file_strings()
{
    get_input_file_from_user();
    char ch;
    std::string abolish;
    std::cout << "Which letters should i remove from each word: ";
    getline(std::cin, abolish);
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


/*bool is_same_as_abolish_char(char ch,std::string abolish_chars)
  ---------------------------------------------------------------
  this function takes in a char and checks if that char matches any of the chars in
  the abolish_chars string, and if so returns true, otherwise returns false
  I'll call this function in the defintion of the get_input_file_strings() function
*/
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


/*void open_output_file()
  -----------------------
  this function will open the output file
*/
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


/*void write_to_output_file()
  ---------------------------
  this function writes to the output file, it calls the get_input_file_strings() function to read the input file
  and uses the return value which is a string with user specified characters removed and stores it in the
  input_file_strings string variable.
  The function loops through the string variable, taking each char and putting it into the output file.
  when that's done the file is closed 
*/
void write_to_output_file()
{
    std::string input_file_strings;
    char ch;
    input_file_strings = get_input_file_strings();
    open_output_file();
    for (int i = 0; i < input_file_strings.length(); i++)
    {
        ch = input_file_strings[i];
        fout.put(ch);
    }
    fout.close();
}