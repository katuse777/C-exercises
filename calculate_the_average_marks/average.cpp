/*write a program AverageList that reads in a list of integers representing exam scores
  and then prints out the average. Because some unprepared student might
  actually get a score of 0, your program should use −1 as the sentinel to mark the
  end of the input.
*/

//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
void finding_the_average();  //this function will take user input and call another function to process the input
void calculating_sum_and_number_of_scores(unsigned);  //this function will take the numbers entered by the user and find average

//GLOBAL VARIABLE DECLERATIONS
unsigned sum = 0;
unsigned number_of_scores = 0;
unsigned average;
const int SENTINEL = -1;

//MAIN FUNCTION 
int main()
{
    std::cout << "Enter the exam scores of all your students and I'll give you their average: \n";
    std::cout << "Enter a -1 to terminate the program and get your results:\n";
    finding_the_average();
    std::cout << "The average of all students is: " << average << "\n";


    system("pause>0");
    return 0;
}

//FUNCTION DECLERATIONS
void finding_the_average()
{
    unsigned user_num;

    do
    {
        std::cin >> user_num;
        if (user_num == SENTINEL)
            break;
        calculating_sum_and_number_of_scores(user_num);

    } while (true);
    
    if (number_of_scores > 0)
        average = sum / number_of_scores;
    else 
        std::cout << "Try actually entering number's next time\n";    
}

void calculating_sum_and_number_of_scores(unsigned user_num)
{
    sum += user_num;
    ++number_of_scores;
}
