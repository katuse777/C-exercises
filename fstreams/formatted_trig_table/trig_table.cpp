/*The <iomanip> library gives programmers more control over output format,
  which makes it easy, for example, to create formatted tables. Write a program
  that displays a table of trigonometric sines and cosines that looks like this:
  The numeric columns should all be aligned on the right, and the columns
  containing the trigonometric functions (which are listed here for angles in
  degrees at 15-degree intervals) should all have seven digits after the decimal
  point.
            TrigTable
  theta  | sin(theta) | cos(theta) |
  -------+------------+------------+
     -90 | -1.0000000 |  0.0000000 |
     -75 | -0.9659258 |  0.2588190 |
     -60 | -0.8660254 |  0.5000000 |
     -45 | -0.7071068 |  0.7071068 |
     -30 | -0.5000000 |  0.8660254 |
     -15 | -0.2588190 |  0.9659258 |
       0 |  0.0000000 |  1.0000000 |
      15 |  0.2588190 |  0.9659258 |
      30 |  0.5000000 |  0.8660254 |
      45 |  0.7071068 |  0.7071068 |
      60 |  0.8660254 |  0.5000000 |
      75 |  0.9659258 |  0.2588190 |
      90 |  1.0000000 |  0.0000000 |
*/
#include <iostream>
#include <cmath>
#include <iomanip>


//FUNCTION PROTOTYPES
void print_trig_table();


//MAIN FUNCTION
int main()
{
    std::cout << std::setw(10) << "TrigTable\n";
    print_trig_table();
    return 0;
}

void print_trig_table()
{
    std::cout << "thetha  |  sin(theta)  |  cos(theta)  |\n";
    std::cout << std::fixed << std::setprecision(7) << std::right;
    std::cout << "--------+--------------+--------------+\n";
    for (int i = -90; i <= 90; i+= 15)
    {
        std::cout << std::setw(8) << i << '|' << std::setw(14) 
        << std::sin(i) << '|' << std::setw(14) << std::cos(i) << '|' << std::endl;
    }
}