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

//GLOBAL VARIABLE DECLERATIONS
std::ifstream fin("input.txt");


//MAIN FUNCTION
int main()
{
  remove_comments(fin, std::cout);

  return 0;
}


/*void remove_comments(std::istream & is, std::ostream & os)
  ----------------------------------------------------------
  this funtion will get all the characters from the input stream named is and store
  them in the string variable named str, then it will loop through that string
  taking each character one by one, putting it in the output stream 
  and if the current character is a forward slash and the following character is
  also a forward slash then the function will ignore all the characters from the input stream
  until a '\n' character is encountered then the function will carry on putting characters
  after the forward slash
  into the output stream but if the current character is a forward slash and the following character
  is a asterisk then the function will ignore all the characters from the input stream until
  a asterisk follwed by a forward slash is encountered then the function will continue putting 
  the characters after the forward slash into the output stream
*/
void remove_comments(std::istream & is, std::ostream & os)
{
  char ch;
  std::string str = "";
  while (true)
  {
    ch = is.get();
    if (ch == EOF || is.fail())  break;
    str += ch;
  }

  for (int i = 0; i < str.length(); i++)
  {
    if (str[i] == '/' && str[i + 1] == '/')
    {
      while (true)
      {
        int j = i;
        if (str[j] == '\n')  break;
        j++;
        i++;
        continue;
      }
    }
    else if (str[i] == '/' && str[i + 1] == '*')
    {
      int j = i;
      while (true)
      {
        if (str[j] == '/' && str[j - 1] == '*')
        {
          i++;
          break;
        }  
        j++;
        i++;
        continue;
      }
    }

    os.put(str[i]);
  }
  
}
