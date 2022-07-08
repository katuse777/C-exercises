/*
* Write a program that converts a distance in meters to the corresponding English
  distance in feet and inches. The conversion factors you need are
  1 inch = 0.0254 meters
  1 foot = 12 inches
*/

//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
double meters_to_inches();  //this function will take in a measurment in meters and convert it to inches
double inches_to_feet(double); //this function will convert inches to feet

//GLOBAL VARIABLE DECLERATIONS


//INT MAIN FUNCTION
int main()
{
	double for_inches_to_feet = meters_to_inches();
	inches_to_feet(for_inches_to_feet);

	system("pause>0");
	return 0;
}

double meters_to_inches()
{
	double inches;
	double meters;
	std::cout << "Enter a measurment in meters and I'll convert it to inches: ";
	std::cin >> meters;
	std::cout << " meters is equal to: ";
	inches =  meters/0.0254;
	std::cout << inches << "\n";

	return inches;
}

double inches_to_feet(double inches)
{
	double feet = inches/12.0;
	std::cout << inches << " inches is equal to: " << feet << " feet.";

	return feet;
}