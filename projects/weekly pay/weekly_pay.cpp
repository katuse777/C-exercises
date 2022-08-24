/*An employee is paid at a rate of $16.78 per hour for the first 40 hours
  worked in a week. Any hours over that are paid at the overtime rate of oneand-
  one-half times that. From the worker’s gross pay, 6% is withheld for
  Social Security tax, 14% is withheld for federal income tax, 5% is withheld
  for state income tax, and $10 per week is withheld for union dues. If the
  worker has three or more dependents, then an additional $35 is withheld
  to cover the extra cost of health insurance beyond what the employer pays.

  Write a program that will read in the number of hours worked in a week
  and the number of dependents as input and will then output the worker’s
  gross pay, each withholding amount, and the net take-home pay for the
  week. For a harder version, write your program so that it allows the calculation
  to be repeated as often as the user wishes.
*/

//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
double social_security_tax(double money_made);
double federal_income_tax(double money_made);
double state_income_tax(double money_made);
double money_took_home();
double actual_money_earned(double s_s_tax, double f_i_tax, double s_i_tax, double money_made, int number_of_dependents);


//GLOBAL VARIABLE DECLERATIONS
const int UNION_DUES = 10;
const int HEALTH_COVER = 35;


//MAIN FUNCTION
int main()
{
    money_took_home();

    return 0;
}


/*double money_earned(int hours_worked, double hourly_rate)
  ---------------------------------------------------------
  this function calculates how much money the person will earn before any deductions
  if the person works for 40 hours or less, the amount of money they earn per hour is normal
  and is calculated so:
    wages = hours_worked * hourly_rate
  But if the person works for more than 40 hours, the amount of money they earn for the first
  40 hours is calculated as usual but any additonal hours warrant and hourly rate that is 1.5 times
  higher than the normal rate:
    wages = (hours_worked - 40) * overtime_hourly_rate
*/
double money_earned(int hours_worked, double hourly_rate)
{
    double overtime_hourly_rate = hourly_rate * 1.5;
    double wages = 0.0;
    if (hours_worked <= 40)
    {
        return hours_worked * hourly_rate;
    }
    else if (hours_worked > 40)
    {
        wages = 40 * hourly_rate;
        wages += (hours_worked - 40) * overtime_hourly_rate;
    }
    return wages;
}

double social_security_tax(double money_made)
{
    return money_made * (0.06);
}

double federal_income_tax(double money_made)
{
    return money_made * (0.14);
}

double state_income_tax(double money_made)
{
    return money_made * (0.05);
}


/*double money_took_home()
  ------------------------
  this function calls all the other function in this program and uses their return values
  to determine how much money the person has after tax,
  The function will print a message to the console, describing what this program does 
  and ask the user to input the values needed to calulate the amount of money the person 
  has after tax  
*/
double money_took_home()
{
    int hours_worked;
    double hourly_rate;
    double actual_amount_earned;
    int number_of_dependents;

    std::cout << "This program will help you calculate how much money you take home after tax.\n"
    << "Enter how much money you earn per hour: $";
    std::cin >> hourly_rate;
    std::cout << "Enter the number of hours worked in this week: ";
    std::cin >> hours_worked;
    std::cout << "Enter the number of people that depend on the money you earn: ";
    std::cin >> number_of_dependents;

    double money_made = money_earned(hours_worked, hourly_rate);
    double s_s_tax = social_security_tax(money_made);
    double f_i_tax = federal_income_tax(money_made);
    double s_i_tax = state_income_tax(money_made);
    actual_amount_earned = actual_money_earned(s_s_tax, f_i_tax, s_i_tax, money_made, number_of_dependents);

    std::cout << "So, you work for " << hours_worked << " hours a week and earn $" << hourly_rate << " per hour.\n"
    << "That means you will earn $" << money_made << " but you only get to take home $" << actual_amount_earned
    << " because you had to pay:\n$" << s_s_tax << " in Social Security Tax.\n" << '$' << f_i_tax 
    << " in federal Income Tax.\n" << '$' << s_i_tax << " in State Income Tax.\n" << '$' << UNION_DUES
    << " in Union dues.\n";
    if ( number_of_dependents > 2)
    {
        std::cout << '$' << HEALTH_COVER << " for to cover the extra cost of Health insurance beyond what"
        " the employer pays.\n";
    }  

    return actual_amount_earned;
}


/*double actual_money_earned(double s_s_tax, double f_i_tax, double s_i_tax, double money_made, int number_of_dependents)
  -----------------------------------------------------------------------------------------------------------------------
  this function calculates how much money the user will get after tax. The calculation will depend on the number of
  dependents the user has
*/
double actual_money_earned(double s_s_tax, double f_i_tax, double s_i_tax, double money_made, int number_of_dependents)
{
    double worker_wage;
    if (number_of_dependents >= 3)    worker_wage = money_made - (s_s_tax + s_i_tax + f_i_tax + UNION_DUES + HEALTH_COVER);
    else    worker_wage = money_made - (s_s_tax + s_i_tax + f_i_tax + UNION_DUES);

    return worker_wage;
}