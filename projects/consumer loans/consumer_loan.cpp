/*Negotiating a consumer loan is not always straightforward. One form of
  loan is the discount installment loan, which works as follows. Suppose a
  loan has a face value of $1,000, the interest rate is 15%, and the duration
  is 18 months. The interest is computed by multiplying the face value of
  $1,000 by 0.15, to yield $150. That figure is then multiplied by the loan
  period of 1.5 years to yield $225 as the total interest owed. That amount is
  immediately deducted from the face value, leaving the consumer with only
  $775. Repayment is made in equal monthly installments based on the face
  value. So the monthly loan payment will be $1,000 divided by 18, which
  is $55.56. This method of calculation may not be too bad if the consumer
  needs $775 dollars, but the calculation is a bit more complicated if the
  consumer needs $1,000. Write a program that will take three inputs: the
  amount the consumer needs to receive, the interest rate, and the duration
  of the loan in months. The program should then calculate the face value
  required in order for the consumer to receive the amount needed. It should
  also calculate the monthly payment. Your program should allow the calculations
  to be repeated as often as the user wishes
*/

//INCLUDE DIRECTIVES
#include <iostream>


//FUNCTION PROTOTYPES
double calculate_loan_term(int months_to_pay);
double calculate_face_value_of_loan(double amount_needed, double interest_rate, double loan_term);
double calculate_monthly_payments(double face_value, int months_to_pay);

//GLOBAL VARIABLE DECLERATIONS



//MAIN FUNCTION
int main()
{
    double amount_needed;
    double months_to_pay;
    double interest_rate;
    char continue_char = 'y';
    do
    {
        std::cout << "If your trying to get a consumer loan, this program can help "
        "you find out the face value of the loan.\n";
        std::cout << "Enter the amount of money you want to get from the loan: ";
        std::cin >> amount_needed;
        std::cout << "Enter the interest rate of the loan in (%): ";
        std::cin >> interest_rate;
        std::cout << "Enter the number of months it will take to pay out the loan: ";
        std::cin >> months_to_pay;

        double loan_term = calculate_loan_term(months_to_pay);
        double face_value = calculate_face_value_of_loan(amount_needed, interest_rate, loan_term);
        double monthly_payments = calculate_monthly_payments(face_value, months_to_pay);
        std::cout << "If you want $" << amount_needed << ", at a interest rate of " << interest_rate
        << "% paid over " << months_to_pay << " months, then you should take out a loan of $"
        << face_value << " which will require monthly repayments of $" << monthly_payments << std::endl;
        std::cout << "Do you want to make another calculation(y/n) ?\n";
        std::cin >> continue_char;
        if (continue_char == 'n' || continue_char == 'N') break;
    } while (true);
     

    return 0;
}


double calculate_loan_term(int months_to_pay)
{
    return months_to_pay/12;
}

double calculate_face_value_of_loan(double amount_needed, double interest_rate, double loan_term)
{
    interest_rate = interest_rate/100;

    return amount_needed/(1 - (interest_rate * loan_term));
}

double calculate_monthly_payments(double face_value, int months_to_pay)
{
    return face_value/months_to_pay;
}