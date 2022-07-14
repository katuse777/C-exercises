/*Write a function windChill that takes the values of t and v and returns the
  wind chill.
  formula for wind chill is
  35.74 + 0.6215 t – 35.75 v^0.16 + 0.4275 t v^0.16
  where t is the Fahrenheit temperature and v is the wind speed in miles per hour.
*/

#include <iostream>
#include <iomanip>   //conatins setw() function
#include <cmath>    //contins pow(base, exponent) function

//Function prototypes
void top_row_of_wind_chill_table();
double wind_speed_to_the_Nth_pow(double windSpeed);
int calulating_wind_chill(double wind_speed, double temperature);
void print_wind_chill_table();


//MAIN FUNCTION
int main()
{
	std::cout << std::setw(50) << "Temperature(F)\n";
	std::cout << "calm" << std::setw(6);
	top_row_of_wind_chill_table();
	print_wind_chill_table();
	system("pause>0");
	return 0;
}

/*top_row_of_wind_chill_table()
* -----------------------------
* this function's job is to display the scale of the y-axis, all the values on the top row will be used as the temperature
* values when calculating the wind chill
*/
void top_row_of_wind_chill_table()
{
	int i = 40;
	while (i >= -45)
	{
		std::cout << i << std::setw(6);
		i -= 5;
	}
	std::cout << '\n';
}

/*wind_speed_to_the_Nth_pow(double windSpeed)
* ----------------------------------------
* the formula for calculating wind chill requires us to multiply the wind speed by it'self
* 0.16 times and this function will take in the wind_speed as an argument and use the pow function
* to raise the wind speed the 0.16th power and return that value to be used in the full calculation of the wind chill
* by the calculating_wind_chill() function
*/
double wind_speed_to_the_Nth_pow(double windSpeed)
{
	windSpeed = pow(windSpeed, 0.16);
	return windSpeed;
}

/*calulating_wind_chill(double wind_speed, double temperature)
* ------------------------------------------------------
* formula fo wind chill: 35.74 + 0.6215 t – 35.75 v^0.16 + 0.4275 t v^0.16
* this function will calulate the wind chill using the the wind speed and temperature it receives as arguments
* it will call the wind_speed_to_the_Nth_pow() function to simplify raising the wind speed to the 0.16th power
* and it will return the wind chill for that combination of wind speed and temperature
*/

int calulating_wind_chill(double wind_speed, double temperature)
{
	double wind_s = wind_speed_to_the_Nth_pow(wind_speed);
	return 35.74 + (0.6215 * temperature) - (35.75 * wind_s) + (0.4275 * temperature * wind_s);
}

/*
* void print_wind_chill_table()
* -----------------------------
* this function is responsibly for supplying the temperature and wind speed to the calculating_wind_chill() function
* by using loops, it will provide the same temperture values for each of the wind_speed values in the table
*/
void print_wind_chill_table()
{
	for (int wind_speed = 5; wind_speed <= 60; wind_speed += 5)
	{
		if (wind_speed == 5) std::cout << wind_speed << std::setw(9);
		else
			std::cout << wind_speed << std::setw(8);
		for (int temp = 40; temp >= -45; temp -= 5)
		{
			std::cout << calulating_wind_chill(wind_speed, temp);
			if (temp == -45)
				std::cout << '\n';
			else
				std::cout << std::setw(6);
		}
	}
}