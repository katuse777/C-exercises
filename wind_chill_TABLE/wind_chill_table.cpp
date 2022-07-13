/*Write a function windChill that takes the values of t and v and returns the
  wind chill. In doing so, your function should take account of two special cases:
  • If there is no wind, windChill should return the original temperature t.
  • If the temperature is greater than 40° F, the wind chill is undefined, and
  your function should call error with an appropriate message.

  35.74 + 0.6215 t – 35.75 v^0.16 + 0.4275 t v^0.16
  where t is the Fahrenheit temperature and v is the wind speed in miles per hour
  Write a program which will display a wind chill table that starts from 40 degrees Fahrenheit
  and ends at -45 degrees Fahrenheit on the x-axis and on the y-axis should be the wind speed in miles per hour
*/

//INCLUDE DIRECTIVES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

//FUNCTION PROTOTYPES
double calculate_wind_chill(double& wind_s, double& temperature);
void wind_to_the_Nth_pow(double& wind);
void error(std::string);

//GLOBAL VARIABLE DECLERATIONS


//MAIN FUNCTION
int main()
{


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
void table_values()
{

}


/* wind_to_the_Nth_pow function
   ----------------------------
   this funtion will be used to simplify the calculation of the wind chill, specifically, it calculates
   (v^0.16) the wind speed to the power 0.16
*/

void wind_to_the_Nth_pow(double& wind)
{
    wind = pow(wind, 0.16);
}

double calculate_wind_chill(double& wind_s, double& temperature)
{
    wind_to_the_Nth_pow(wind_s);
    return 35.74 + (0.6215 * temperature) - (35.75 * wind_s) + (0.4275 * temperature * wind_s);
}

void error(std::string msg)
{
    std::cerr << msg << "\n";
    exit(EXIT_FAILURE);
}