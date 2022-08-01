/*Write a program that reads a file and reports how many lines, words, and
  characters appear in it. For the purposes of this program, a word consists of a
  consecutive sequence of any characters except whitespace characters
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <sstream>


//FUNCTION PROTOTYPES
void get_file_from_user();
int num_of_lines();
int num_of_chars();
void file_summary();


std::ifstream fin;
std::string filename;
//MAIN FUNCTION
int main()
{

    file_summary();

    return 0;
}

void get_file_from_user()
{
    do
    {
        std::cout << "Enter the name of a file, along with the file extension, e.g myFile.txt: ";
        getline(std::cin, filename);
        fin.open(filename.c_str());
        std::cout << "Input file: " << filename << '\n';
    } while (fin.fail());
}

int num_of_lines()
{
    std::string line_from_file;
    int lines_counted = 0;
    do
    {
        getline(fin, line_from_file);
        if (!fin.fail())    ++lines_counted;
    } while (!fin.fail() && !fin.eof());
    fin.close();
    return lines_counted;
}

int num_of_chars()
{
    fin.open(filename.c_str());
    int ch;
    int chars_counted = 0;
    while (true)
    {
        ch = fin.get();
        if (ch == EOF)    break;
        else if (ch == '\n') continue;
        else  ++chars_counted;
    }
    fin.close();
    return chars_counted;
}

int num_of_words()
{
    fin.open(filename.c_str());
   int ch;
   int words_counted = 0;
   bool ignore_chars = false;
   while (true)
   {
        ch = fin.get();
        if (ch == EOF) break;
        else if (ch == '\n')  continue;
        else if (isalnum(ch) && ignore_chars == false)
        {
            ++words_counted;
            ignore_chars = true;
        }
        else ignore_chars = false; 
   }
   fin.close();
   return words_counted;
}

void file_summary()
{
    get_file_from_user();
    std::cout << std::dec;
    std::cout << "There are: " << num_of_lines() << " lines in this file\n";
    std::cout << "There are: " << num_of_words() << " words in this file\n";
    std::cout << "There are: " << num_of_chars() << " characters in this file\n";
    fin.close();
}