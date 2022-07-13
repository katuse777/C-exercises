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

//FUNCTION PROTOTYPES
void get_wind_speed_and_temp(); 
double calculate_wind_chill(double & wind_s, double & temperature); 
void print_wind_chill(double wind_chill);
void wind_to_the_Nth_pow(double & wind);

//GLOBAL VARIABLE DECLERATIONS


//MAIN FUNCTION
int main()
{
    get_wind_speed_and_temp();


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
void get_wind_speed_and_temp()
{
    double wind_speed, temp;
    std::cout << "Enter the temperature: ";
    std::cin >> temp;
    std::cout << "Enter the wind speed: ";
    std::cin >> wind_speed;

    double wind_chill = calculate_wind_chill(wind_speed, temp);
    print_wind_chill(wind_chill);
}

double calculate_wind_chill(double & wind_s, double & temperature)
{
    wind_to_the_Nth_pow(wind_s);
    return 35.74 + (0.6215 * temperature) - (35.75 * wind_s) + (0.4275 * temperature * wind_s);
}

void wind_to_the_Nth_pow(double & wind)
{
    wind = pow(wind, 0.16);
}

void print_wind_chill(double wind_chill)
{
    std::cout << "Wind Chill: " << wind_chill;
}