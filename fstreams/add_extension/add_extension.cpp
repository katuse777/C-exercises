/*Another useful function in filelib.h is
        string defaultExtension(string filename, string ext);
  which adds ext to the end of filename if it doesn’t already have an
  extension. For example,
        defaultExtension("Shakespeare", ".txt")
  would return "Shakespeare.txt". If filename already has an extension,
  that name is returned unchanged, so that
        defaultExtension("library.h", ".cpp")
  would ignore the specified extension and return "library.h" unchanged. If,
  however, ext includes a star before the dot, defaultExtension removes
  any existing extension from filename and adds the new one (minus the star).
  Thus,
        defaultExtension("library.h", "*.cpp")
  would return "library.cpp". Write the code for defaultExtension so
  that it behaves as described in this exercise.
*/
#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
std::string default_extension(std::string filename, std::string ext);
bool has_file_extension(std::string filename);
std::string get_root(std::string filename);



//MAIN FUNCTION
int main()
{
    std::cout << default_extension("myfile.h", "*.ext") << std::endl;

    return 0;
}

/*std::string default_extension(std::string filename, std::string ext)
  --------------------------------------------------------------------
  this function uses the rules specified at the top of this file to determine
  how to append the the extension (ext) to the filename entered
*/
std::string default_extension(std::string filename, std::string ext)
{
    std::string new_filename;
    if (has_file_extension(filename) && ext[0] == '*')
    {
        ext.erase(0, 1);  //removes the star from the file extension
        new_filename = get_root(filename) + ext;
    }
    else if (has_file_extension(filename) && ext[0] != '*')
        return filename;
    else  new_filename = filename + ext;    

    return new_filename;
}


/*bool has_file_extension(std::string filename)
  ---------------------------------------------
  this function determines whether the filename passed in has a file extension
  by looping through the string and if the string contains a period(.) followed
  by atleast one letter, then the function will return true, else it returns false
*/
bool has_file_extension(std::string filename)
{
    for (int i = 0; i < filename.length(); i++)
    {
        if (filename[i] == '.' && !isspace(filename[i + 1]) )
            return true;    
    }
    return false;
}


/*std::string get_root(std::string filename)
  ------------------------------------------
  this function returns a substring a the file name passed in and this substring is
  all the letters that appear before the period
*/
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