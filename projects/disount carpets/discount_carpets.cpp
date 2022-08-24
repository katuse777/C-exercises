/*A store sells carpets for $2.75 per meter. If a customer buys more than
  10 m of carpet, they get a discount of 15% on every additional meter of
  carpet they purchase. Write a program that inputs the carpet length that a
  user wishes to buy, stores the value in a double variable, and then calculates
  and outputs the total cost of the carpet.
*/
//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
double length_of_carpet();
double total_discount(int carpet_length);
double cost_of_carpet(double length);
double discounted_price(double cost, double discount);

//GLOBAL VARIABLE DECLERATIONS
const double COST_OF_METRE_OF_CARPET = 2.75;


//MAIN FUNCTION
int main()
{
    double carpet_len = length_of_carpet();
    double discount = total_discount(carpet_len);
    double carpet_cost = cost_of_carpet(carpet_len);
    std::cout << "Cost of carpet: " << discounted_price(carpet_cost, discount) << std::endl;

    return 0;
}

/*double length_of_carpet()
  -------------------------
  This function describes the what this program does and asks the user to enter the length of carpet
  they would like to buy, and return that length
*/
double length_of_carpet()
{
    double length;
    std::cout << "This store sells carpets for $2.75 per meter. If you buy more than 10 m"
    "of carpet, you get a 15% on every additional meter of carpet you purchase.\n"
              << "So, how much carpet do you want: ";
    std::cin >> length;

    return length;          
}


/*double total_discount(int carpet_length)
  -------------------------------------------
  this function calculates the total discount the customer depending on the length of carpet they
  bought, the customer only gets a 15% discount per metre on the price of the the carpet for every
  additional metre after buying ten metres of carpet
*/
double total_discount(int carpet_length)
{
    double discount = 0.0; 
    if (carpet_length > 10)
    {
        while (carpet_length > 10)
        {
            carpet_length--;
            discount += (15/100) * COST_OF_METRE_OF_CARPET;
        }
    }
    return discount;
}

double cost_of_carpet(double length)
{
    double cost = length * COST_OF_METRE_OF_CARPET;

    return cost;
}


double discounted_price(double cost, double discount)
{
    double total_price = cost - discount;

    return total_price;
}