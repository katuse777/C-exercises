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
void open_file(std::string filename);




std::ifstream fin;
std::string filename;
//MAIN FUNCTION
int main()
{

    file_summary();

    return 0;
}


/*void open_file(std::string filename)
  ------------------------------------
  this function opens the file entered by the user, if a function has processed the entire file via a loop
  then the file has to be closed and opened up again if you want to process the file again from the start
*/
void open_file(std::string filename)
{
    fin.open(filename.c_str());
    if (fin.fail())
    {
        std::cout << "ERROR: Could not open file " << filename << std::endl;
        std::cout << "Make sure the file exists and if it does, make sure you closed it before trying to open it." << std::endl;
    }
}


/*void get_file_from_user()
  -------------------------
  this function prints out a prompt to the user, asking them to enter the name of the file hey want to be read
  and attempts to open that file and if the file could not be opened, the user will be prompted again this time
  they'll know that they made a mistake and should try again
*/
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


/*int num_of_lines()
  ------------------
  when this function is called, the input file has already been opened so, it is ready for processing
  and when it's done, it will close the input file.
  this function will get a line from the input file and increment the lines_counted variable until
  the end of the file is reached and the return the value of the number of lines counted
*/
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



/*int num_of_chars()
  ------------------
  this function calls the open_file() function
  then loops through the file reading every char in the file and counting them,
  once the the char that is being read is the EOF character, the function breaks
  out of the loop, closes the file and returns the number of characters counted.
*/
int num_of_chars()
{
    open_file(filename.c_str());
    int ch;
    int chars_counted = 0;
    while (true)
    {
        ch = fin.get();
        if (ch == EOF)    break;
        else  ++chars_counted;
    }
    fin.close();
    return chars_counted;
}


/*int num_of_words()
  ------------------
  this function calls the open_file() function
  loop thorugh the file, counting the number of words.
  This function read the characters in this file one-by-one
  if the char that is read is not a space character, then 
  the words_counted variable is incremented the function ignores
  all other characters until it reads the next whitespace character
  then will start looking for the next non-whitespace character and
  increment the words_counted variable when the end of the file is 
  reached, the file is closed and the function returns the number
*/
int num_of_words()
{
   open_file(filename.c_str());
   int ch;
   int words_counted = 0;
   bool ignore_chars = false;
   while (true)
   {
        ch = fin.get();
        if (ch == EOF) break;
        else if (!isspace(ch) && ignore_chars == false)
        {
            ++words_counted;
            ignore_chars = true;
        }
        else if (isspace(ch) && ignore_chars == true)  ignore_chars = false; 
   }
   fin.close();
   return words_counted;
}


/*void file_summary()
  -------------------
  this function calls the functions defined above, and uses those with a return value
  to print out the return value next to a string the describes what that return value
  represents, e.g
  std::cout << "Number of lines counted: " << lines_counted << std::endl;
*/
void file_summary()
{
    get_file_from_user();
    std::cout << std::dec;
    std::cout << "There are: " << num_of_lines() << " lines in this file\n";
    std::cout << "There are: " << num_of_words() << " words in this file\n";
    std::cout << "There are: " << num_of_chars() << " characters in this file\n";
    fin.close();
}