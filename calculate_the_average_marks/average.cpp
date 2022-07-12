/*Write a program to compute the area of the quarter circle by dividing it into
  10,000 rectangles
*/

//INCLUDE DIRECTIVES
#include <iostream>
#include <cmath>

//FUNCTION PROTOTYPES
void calculating_width();
void calculating_sum_of_area();

//GLOBAL VARIABLE FUNCTIONS
const int RADIUS = 2;
double width;   //this variable will store the width of the rectangles
int number_of_rectangles = 10000;
double heigth; //this variable will store the heigth of the rectangles
double sum_of_areas = 0;


//MAIN FUNCTION 
int main()
{
    std::cout << "I can find the area of a circle with a radius of 2 inches by dividing it into rectangles, the more rectangles I use the more accurate my answer will be.\n"
        "Enter the number of rectangles you want: ";
    std::cin >> number_of_rectangles;
    calculating_sum_of_area();
    std::cout << "Total area: " << sum_of_areas;


    system("pause>0");
    return 0;
}

//FUNCTION DEFINITIONS
void calculating_width()
{
    width = RADIUS / number_of_rectangles;
}

void calculating_sum_of_area()
{
    calculating_width();
    double midpoint = 0;
    for (int i = 1; i < number_of_rectangles; i++)
    {
        midpoint += i * (midpoint / 2);
        heigth = sqrt((RADIUS * RADIUS) - (midpoint * midpoint));
        sum_of_areas += heigth * width;
    }
}