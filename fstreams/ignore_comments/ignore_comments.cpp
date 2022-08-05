/*Write a function
  void removeComments(istream & is, ostream & os);
  that copies characters from the input stream is to the output stream os, except
  for characters that appear inside C++ comments. Your implementation should
  recognize both comment conventions:
  • Any text beginning with / * and ending with * /, possibly many lines later.
  • Any text beginning with //and extending through the end of the line
*/

#include <iostream>
#include <string>
#include <istream>
#include <ostream>
#include <fstream>

//FUNCTION PROTOTYPES
void remove_comments(std::istream & is, std::ostream & os);
bool is_line_comment(std::string str);
bool is_block_comment(std::string str);


//GLOBAL VARIABLE DECLERATIONS
bool inside_block_comment = false;
std::ifstream fin("input.txt");


//MAIN FUNCTION
int main()
{
  remove_comments(fin, std::cout);


  return 0;
}


void remove_comments(std::istream & is, std::ostream & os)
{
  char ch;
  std::string one_line = "";
  std::string str = "";
  while (true)
  {
    ch = is.get();  
    if (ch == EOF || is.fail()) break;
    one_line += ch;
    if (ch == '\n' && inside_block_comment == false)
    {
      if (is_line_comment(one_line))
      {
        for (int i = 0; i < one_line.length(); i++)
        {
          if (one_line[i] == '/' && one_line[i + 1] == '/')  break;
          str += one_line[i];
        }
      }
      else if (is_block_comment(one_line))
      {
        for (int i = 0; i < one_line.length(); i++)
        {
          if (one_line[i] == '/' && one_line[i + 1] == '*')
          {
            inside_block_comment = true;
            break;
          }
          else  str += one_line[i];
        }
      }
    }
    else if (ch == '\n' && inside_block_comment)
    {
      for (int i = 0; i < one_line.length(); i++)
      {
        if (one_line[i] == '*' && one_line[i + 1] == '/')
          inside_block_comment = false;
      }
    }
    
    
    if (ch == '\n')
      one_line = "";
  }

  for (int i = 0; i < str.length(); i++)
  {
    os.put(str[i]);
  }
}


bool is_line_comment(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '/' && str[i + 1] == '/')
      return true;
  }
  return false;
}

bool is_block_comment(std::string str)
{
  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '/' && str[i + 1] == '*')
      return true;
  }
  return false;
}

