/*Write a program that prints out the longest line in a file entered by the user. If
  several lines are all equally long, your program should print out the first such
  line.
*/

#include <iostream>
#include <fstream>

//FUNCTION PROTOTYPES
void get_file_from_user();
void print_longest_line();



std::ifstream input_file;
std::string filename;
//MAIN FUNCTION
int main()
{
  get_file_from_user();
  print_longest_line();
    return 0;
}

void get_file_from_user()
{
  do
  {
    std::cout << "Enter a file: ";
    getline(std::cin, filename);
    input_file.open(filename.c_str());
    if (!input_file.fail()) break;
    std::cout << "Please enter the name again.";
  } while (input_file.fail() == true);
}

void print_longest_line()
{
  std::string second_longest;
  std::string longest_line;
  getline(input_file, longest_line);
  second_longest = longest_line;
  while (!input_file.fail() && !input_file.eof())
  {
    getline(input_file, longest_line);
    if (longest_line.length() > second_longest.length())  second_longest = longest_line;
    else longest_line = second_longest;
  }
  std::cout << "Longest line: " << longest_line << std::endl;
  input_file.close();
}