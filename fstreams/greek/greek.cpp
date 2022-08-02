/*Write a program that reads characters from an input file and displays them
  on the console after making the appropriate random substitutions. Your
  program should replace every uppercase character in the input by a random
  uppercase character and every lowercase character by a random lowercase
  one. Nonalphabetic characters should remain unchanged.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>
#include <ctime>


//FUNCTION PROTOTYPES
void get_file_from_user();
int random_num_in_range(int min, int max);
char get_chars_from_file();
char random_lower_letters(char ch);
char random_upper_letters(char ch);
std::string greek_text();


//GLOBAL VARIABLE DECLERATIONS
std::ifstream fin;
std::string filename;



//MAIN FUNCTION
int main()
{
    srand(time(NULL));
    get_file_from_user();
    char ch;
    std::cout << greek_text() << std::endl;
    return 0;
}

/*void get_file_from_user()
  -------------------------
  this function will ask the user to enter the name of a file for reading
  and will open that file but if the the file can't be opened, the user will be
  notified and asked to enter a valid file name 
*/
void get_file_from_user()
{
    std::cout << "Enter the name of the file: \n";
    do
    {
        getline(std::cin, filename);
        fin.open(filename.c_str());
        if (fin.fail())
        {
            std::cout << "ERROR: " << filename << " is not a valid file" << std::endl;
            std::cout << "Try again: ";
        }
    } while (fin.fail());
}

/*int random_num_in_range(int min, int max)
  -----------------------------------------
  this function takes in two arguments, min will be the lowest and max will be the highest
  this means the number returned must be (min <= num <= max). 

*/
int random_num_in_range(int min, int max)
{
    int random_num;
    random_num = (rand() % (max - min)) + min;
    return random_num;
}


/*char random_upper_letters(char ch)
  ----------------------------------
  this function takes in a alphabet named ch and returns it as a random alphabet that 
  has the same case as ch, e.g a uppercase letter will return a random letter uppercase
  letter
*/
char random_upper_letters(char ch)
{
    ch = random_num_in_range(65, 90);
    return ch;
}


/*char random_upper_letters(char ch)
  ----------------------------------
  this function takes in a alphabet named ch and returns it as a random alphabet that 
  has the same case as ch, e.g a lower letter will return a random letter lowercase
  letter
*/
char random_lower_letters(char ch)
{
    ch = random_num_in_range(97, 122);
    return ch;
}


/*char get_chars_from_file()
  -------------------------
  this function gets the next character from the file and returns it as it is
*/
char get_chars_from_file()
{
    char ch;
    ch = fin.get();
    return ch;
}


/*std::string greek_text()
  ------------------------
  this function calls the get_chars_from_file() functions and passes each of those charcters
  through the random_letters() functions depending on whether the character is upper or lower case
  and after changing the character (if it's a alphabetic character), the character is
  added to a string and when the end of the file is reached the file is then closed 
*/
std::string greek_text()
{
    char original_char;
    char new_char;
    std::string greek = "";
    while (true)
    {
        original_char = get_chars_from_file();
        if (original_char == EOF) break;
        else if (isalpha(original_char) && isupper(original_char))
        {
            new_char = random_upper_letters(original_char);
            greek += new_char;
        }
        else if (isalpha(original_char) && islower(original_char))
        {
            new_char = random_lower_letters(original_char);
            greek += new_char;
        }
        else greek += original_char;
    }
    fin.close();
    return greek;
}