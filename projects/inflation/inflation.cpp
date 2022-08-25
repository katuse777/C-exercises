/*It is difficult to make a budget that spans several years, because prices are
  not stable. If your company needs 200 pencils per year, you cannot simply
  use this year’s price as the cost of pencils 2 years from now. Because of
  inflation the cost is likely to be higher than it is today. Write a program
  to gauge the expected cost of an item in a specified number of years. The
  program asks for the cost of the item, the number of years from now that
  the item will be purchased, and the rate of inflation. The program then
  outputs the estimated cost of the item after the specified period. Have the
  user enter the inflation rate as a percentage, like 5.6 (percent). Your program
  should then convert the percent to a fraction, like 0.056, and should use a
  loop to estimate the price adjusted for inflation. (Hint: This is similar to computing
  interest on a charge card account, which was discussed in this chapter.)
*/

//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
double price_after_inflation(double current_price, double years_of_inflation, double rate_of_inflation);


//GLOBAL VARIABLE DECLERATIONS


//MAIN FUNCTION
int main()
{
    double current_price, years_of_inflation, rate_of_inflation, inflated_price;
    std::cout << "This program will allow you to calculate the expected price"
    " of a item after a given numberof years due to inflation.\n";
    std::cout << "Enter the current price of the item: $";
    std::cin >> current_price;
    std::cout << "Enter the rate of inflation(%): ";
    std::cin >> rate_of_inflation;
    std::cout << "In How many years do you want to purchase this item again ? ";
    std::cin >> years_of_inflation;

    inflated_price = price_after_inflation( current_price, years_of_inflation, rate_of_inflation);
    std::cout << "The item will cost $" << inflated_price << " in " << years_of_inflation << " years.\n";

    return 0;
}

double price_after_inflation(double current_price, double years_of_inflation, double rate_of_inflation)
{
    double now_price = current_price;
    double inflated_price = 0.0;
    rate_of_inflation = rate_of_inflation/100;
    for (int i = 0; i < years_of_inflation; i++)
    {
        inflated_price += (current_price * rate_of_inflation);
        current_price = inflated_price;
    }
    inflated_price += now_price;

    return inflated_price;
}

