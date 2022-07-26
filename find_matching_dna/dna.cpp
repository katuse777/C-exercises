/*Write a function
  int findDNAMatch(string s1, string s2, int start = 0);
  that returns the first position at which the DNA strand s1 can attach to the
  strand s2. As in the find method for the string class, the optional start
  parameter indicates the index position at which the search should start. If
  there is no match, findDNAMatch should return –1.
*/

#include <iostream>
#include <string>
#include <cctype>


//FUNCTION PROTOTYPES
char complimentary_bases(char ch);
std::string complimentary_strand(std::string str);
int find_dna_match(std::string str1, std::string str2);
int find_dna_match(std::string str1, std::string str2, int);


std::string bases = "ACGT";
std::string comp_bases = "TGCA";
//MAIN FUNCTION
int main()
{
	std::cout << find_dna_match("ATTCGACTGGAT", "TGACC",3);

	system("pause>0");
	return 0;
}


/*char complimentary_bases(char ch)
* ---------------------------------
* this function takes in a char named ch and if the value of ch is one of the bases A,C,G or T
* the function returns it's complementary base pair, e.g 'A' returns 'T', 'C' returns 'G' and
* vice versa
*/
char complimentary_bases(char ch)
{
	for (int i = 0; i < bases.length(); i++)
	{
		if (ch == bases[i])
			return comp_bases[i];
	}
	return ' ';
}


/*std::string complimentary_strand(std::string str)
* -------------------------------------------------
* this function takes in a string named str and callse the complimentary_bases() function on each
* character in the string and returns the complementary strand to the one passed in,
* e.g complimentary_strand("ATCG) will return "TAGC"
*/
std::string complimentary_strand(std::string str)
{
	std::string comp_strand = "";
	for (int i = 0; i < str.length(); i++)
	{
		comp_strand += complimentary_bases(str[i]);
	}
	return comp_strand;
}


/*int find_dna_match(std::string str1, std::string str2)
* -----------------------------------------------------------------
* this function takes in two strings, str1 and str2, str1 is the template string
* and str2 is a potential substring
* the function works by taking a substring of str1 that has the same length as str2
* starting from the first index. The function then takes this substring of str1 and passes
* into the complimentary_strand() function and compare the comp_of_sub_string with str2
* and if they are identical then the function return the index the loop started at but 
* if they don't match the function takes a substring of the same length as str2 but from
* one index higher than the previous one
*/
int find_dna_match(std::string str1, std::string str2)
{
	std::string comp_of_sub_strand = "";
	int starting_index;
	std::string sub_strand;
	for (int i = 0; i < str1.length(); i++)
	{
		sub_strand = str1.substr(i, str2.length());
		comp_of_sub_strand = complimentary_strand(sub_strand);
		if (comp_of_sub_strand == str2)
			return i;
	}
	
	return -1;
}


/*int find_dna_match(std::string str1, std::string str2, int start)
* -----------------------------------------------------------------
* this function takes in two strings, str1 and str2, str1 is the template string
* and str2 is a potential substring and a integer named start, which specifies where
* the function should start extracting the substring of str1.
* this is a overloaded version of the first find_dna_match() function
*/
int find_dna_match(std::string str1, std::string str2, int start)
{
	std::string comp_of_sub_strand = "";
	int starting_index;
	std::string sub_strand;
	if (start > str2.length())
		return -1;
	else
	{
		for (int i = start; i < str1.length(); i++)
		{
			sub_strand = str1.substr(i, str2.length());
			comp_of_sub_strand = complimentary_strand(sub_strand);
			if (comp_of_sub_strand == str2)
				return i;
		}
	}
	
	return -1;
}