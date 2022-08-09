/*In statistics, a collection of data values is often referred to as a distribution.
  One of the primary goals of statistical analysis is to find ways to compress the
  complete set of data into summary statistics that express properties of the
  distribution as a whole. The most common statistical measure is the mean,
  which is simply the traditional average. For the distribution x1, x2, x3, . . . , xn,
  the mean is usually represented by the symbol .
  Write a function
    double mean(Vector<double> & data);
  that returns the mean of the data in the vector
*/

#include <iostream>
#include <vector>


//FUNCTION PROTOTYPES
double mean(std::vector<double> data);
void add_values_to_vector(std::vector<double> & data);



//GLOBAL VARIABLE DECLERATIONS
std::vector<double> data;


//MAIN FUNCTION
int main()
{
    add_values_to_vector(data);
    std::cout << mean(data);


    return 0;
}

double mean(std::vector<double> data)
{
    double average = 0.0;
    for (int i = 0; i < data.size(); i++)
    {
        average += data[i];
    }
    average /= data.size();
    return average;
}

void add_values_to_vector(std::vector<double> & data)
{
    for (int i = 0; i < 150; i+= 7)
    {
        data.push_back(i);
    }
}