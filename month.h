#ifndef _month_h
#define _month_h

enum MONTH 
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};


/*bool leap_year(int year)
  -----------------------
  this function returns true if the year passed into it is indeed a leap year and false otherwise
*/
bool leap_year(int year);



/*int days_in_month(int year, MONTH month)
  --------------------------------------
  takes in a year and a month, if the year passed in is a leap year and returns the number of days
  that month should have
*/
int days_in_month(int year, MONTH month);

#endif