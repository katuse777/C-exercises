/*The filelib.h interface exports several functions that make it easy to work
  with filenames. Two functions that are particularly useful are getRoot and
  getExtension, which divide a function into its root, which is the identifying
  part of the filename, and the extension, which indicates its type. For example,
  given the filename Middlemarch.txt used in the preceding exercise, the
  root is Middlemarch and the extension is .txt (note that filelib.h defines
  the extension to includes the dot). Write the code necessary to implement
  these functions. To find out how to handle special cases, such as filenames
  that don’t include a dot, consult the filelib.h interface in Appendix A.
*/

#include <iostream>
#include <string>

//FUNCTION PROTOTYPES
std::string get_root(std::string filename);
std::string get_extension(std::string filename);



std::string filename;
//MAIN FUNCTION
int main()
{
    std::cout << "Enter a filename and I'll return the root of the file and the file extension: " << filename << std::endl;
    getline(std::cin, filename);
    std::cout << "Root: " << get_root(filename.c_str()) << std::endl;
    std::cout << "Extension: " << get_extension(filename.c_str()) << std::endl;

    return 0;
}


std::string get_root(std::string filename)
{
    std::string root = "";
    int i = 0;
    for (int i = 0; i < filename.length(); i++)
    {
        if (filename[i] != '.')    root += filename[i];
        else    break;    
    }
    return root;
}

std::string get_extension(std::string filename)
{
    std::string extension = ".";
    int i = 0;
    bool looking_for_extension = false;
    for (int i = 0; i < filename.length(); i++)
    {
        if (filename[i] == '.')
            looking_for_extension = true;
        else if (looking_for_extension)
            extension += filename[i];
    }
    return extension;
}