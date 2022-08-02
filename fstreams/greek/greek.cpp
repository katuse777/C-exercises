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
    char ch = 65;
    for (int i = 0; i < 100; i++)
    {
        std::cout << random_num_in_range(65, 90) << std::endl;
        ch++;
    }

    return 0;
}

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

int random_num_in_range(int min, int max)
{
    int random_num;
    random_num = (rand() % max) + min;
    if (random_num > max)   random_num -= min;
    return random_num;
}

char random_upper_letters(char ch)
{
    ch = random_num_in_range(65, 90);
    return ch;
}

char random_lower_letters(char ch)
{
    ch = random_num_in_range(97, 122);
    return ch;
}

char get_chars_from_file()
{
    char ch;
    ch = fin.get();
    return ch;
}

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