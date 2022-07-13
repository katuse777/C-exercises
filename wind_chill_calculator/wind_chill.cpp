/*Write a function windChill that takes the values of t and v and returns the
  wind chill. In doing so, your function should take account of two special cases:
  • If there is no wind, windChill should return the original temperature t.
  • If the temperature is greater than 40° F, the wind chill is undefined, and
  your function should call error with an appropriate message.

  35.74 + 0.6215 t – 35.75 v^0.16 + 0.4275 t v^0.16
  where t is the Fahrenheit temperature and v is the wind speed in miles per hour
*/

//INCLUDE DIRECTIVES
#include <iostream>
#include <cmath>
#include <cstdlib>

//FUNCTION PROTOTYPES
void get_wind_speed_and_temp();
double calculate_wind_chill(double& wind_s, double& temperature);
void print_wind_chill(int wind_chill);
void wind_to_the_Nth_pow(double& wind);
void error(std::string);

//GLOBAL VARIABLE DECLERATIONS


//MAIN FUNCTION
int main()
{
    get_wind_speed_and_temp();


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS

/*get_wind_speed_and_temp function
  --------------------------------
  this function will ask the user to enter the current temperature and wind speed
  and it will call other functions to which it will pass these valuse into for
  processing and call another function which will use that return value to print
  the wind chill to the user
*/
void get_wind_speed_and_temp()
{
    double wind_speed, temp;
    std::cout << "Enter the temperature(degrees Fahrenheit): ";
    std::cin >> temp;
    std::cout << "Enter the wind speed(miles per hour): ";
    std::cin >> wind_speed;

    int wind_chill = calculate_wind_chill(wind_speed, temp);
    print_wind_chill(wind_chill);
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
    if (temperature > 40.0) error("Undefined");
    if (wind_s == 0.0) return temperature;
    wind_to_the_Nth_pow(wind_s);
    return 35.74 + (0.6215 * temperature) - (35.75 * wind_s) + (0.4275 * temperature * wind_s);
}


void print_wind_chill(int wind_chill)
{
    std::cout << "Wind Chill: " << wind_chill << " degrees Fahrenheit.";
}

void error(std::string msg)
{
    std::cerr << msg << "\n";
    exit(EXIT_FAILURE);
}