/*Divide the number of the year for which one wishes to calculate Easter by 19, by 4, and by 7,
  and call the remainders of these divisions a, b, and c, respectively. If the division is even, set
  the remainder to 0; the quotients are not taken into account. Precisely the same is true of the
  following divisions.
  II. Divide the value 19a + 23 by 30 and call the remainder d.
  III. Finally, divide 2b + 4c + 6d + 3, or 2b + 4c + 6d + 4, choosing the former for years between
  1700 and 1799 and the latter for years between 1800 and 1899, by 7 and call the remainder e.
  Then Easter falls on March 22 + d + e, or when d + e is greater than 9, on April d + e – 9.

  Write a procedure
  void findEaster(int year, string & month, int & day);
  that takes a year and returns the Easter date in the reference parameters month
  and day.
*/

#include <iostream>


//FUNCTION PROTOTYPES
void finding_easter(int year);
int calculating_date_of_easter(int year);

int year;

//MAIN FUNCTION
int main()
{
  std::cout << "Enter a year between 1700 and 1899 and I'll tell you, on which day was easter: ";
  std::cin >> year;
  finding_easter(year);  

  system("pause>0");
  return 0;
}

/*calulating_date_of_easter(int year)
  -----------------------------------
  this function takes a year as an argument, performs Gauss’s algorithm for computing the date of Easter
  and retuns the the of (d + e), this value will be used by another function to determine on which day and 
  month easter will fall on
*/
int calculating_date_of_easter(int year)
{
  int a(year % 19), b(year % 4), c(year % 7);
  int d((19*a + 23)/30);
  int e;
  if (year < 1799 && year > 1700)  e = ((2*b) + (4*c) + (6*d) + 3) % 7;
  else if (year < 1899 && year > 1800)  e = ((2*b) + (4*c) + (6*d) + 4) % 7;

  return e + d;    
}

/*finding_easier(int year)
  ------------------------
  this function call the calls the calculating_date_of_easter() function and uses the return value
  to determine the date of eater for that year and prints out the date to the console
*/

void finding_easter(int year)
{
  int d_and_e = calculating_date_of_easter(year);
  if (d_and_e < 9)
    std::cout << "March " << 22 + d_and_e << " " << year;
  else if (d_and_e > 9)
    std::cout << "April " << 22 + d_and_e << " " << year;  
}