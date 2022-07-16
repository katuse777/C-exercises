#include "month.h"

bool leap_year(int year) 
{
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

/*int daysInMonth(int year, ::MONTH month)
  ----------------------------------------
  this function takes in a month and a year and returns the number of dasy that month will
  have

*/
int days_in_month(int year, ::MONTH month) 
{
    switch (month)
    {
        case ::April:
        case ::June:
        case ::September:
        case ::November:
        return 30;
        case ::February:
        return (leap_year(year)) ? 29 : 28;
        default:
        return 31;
    }
}