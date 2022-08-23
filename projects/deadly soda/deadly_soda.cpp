/*A government research lab has concluded that an artificial sweetener commonly
  used in diet soda pop will cause death in laboratory mice. A friend
  of yours is desperate to lose mass but cannot give up soda pop. Your
  friend wants to know how much diet soda pop it is possible to drink without
  dying as a result. Write a program to supply the answer. The input to
  the program is the amount of artificial sweetener needed to kill a mouse
  (use 5 grams), the mass of the mouse (use 35 grams), and the mass of
  the dieter (use 45400 grams for a 100 pound person). Assume that the
  lethal dose for a mouse is proportional to the lethal dose for the human.
  A single can of soda pop has a mass of 350 grams. To ensure the safety of
  your friend, be sure the program requests the mass at which the dieter
  will stop dieting, rather than the dieter’s current mass.
  Assume that diet soda contains 1/10th of 1% artificial sweetener.
  Use a variable declaration
  with the modifier const to give a name to this fraction. You may want to
  express the percent as the double value 0.001. Your program should allow
  the calculation to be repeated as often as the user wishes.
*/
//INCLUDE DIRECTIVES
#include <iostream>

//FUNCTION PROTOTYPES
int get_mass();
int mass_in_grams(int mass);
int how_many_grams_to_kill(int mass_of_person);
long number_of_cans_to_kill_person(int grams_needed_in_cans);
void combining_function();

//GLOBAL VARIABLE DECLERATIONS
const double SWEETENER_PER_CAN = 0.001;



//MAIN FUNCTION
int main()
{
    do
    {
        int mass_in_pound = get_mass();
        if (mass_in_pound == -1) break;
        int grams = mass_in_grams(mass_in_pound);
        int grams_to_kill = how_many_grams_to_kill(grams);

        std::cout << "Number of cans you can drink without dying: " << number_of_cans_to_kill_person(grams_to_kill) << std::endl;
    } while (true);

    return 0;
}

/*int get_mass()
  ----------------
  This function describes how this program works and asks the user to enter the mass at which they will stop their diet at
  and returns that number
*/
int get_mass()
{
    int mass;
    std::cout << "This program calculates the number of cans of diet soda that one can drink witout dying as a result\n"
              << "If you wish to exit the program enter -1 and press ENTER\n"
              << "Enter the mass at which you plan to stop your diet, measured in pounds: ";
    std::cin >> mass;   

    return mass;          
}

/*int mass_in_grams(int mass)
  -------------------------------
  converts mass from pounds to grams, it takes the value returned by the get_mass() function and turns that mass from pounds
  to grams
*/
int mass_in_grams(int mass)
{
    int pounds_to_grams = 454 * mass;

    return pounds_to_grams;
}

/*int how_many_grams_to_kill(int mass_of_person)
  ------------------------------------
  takes the mass retuned by the mass_in_grams() function and calculates how many grams of sweetner will be needed to kill the
  person by using the fact that the amount of sweetner needed to kill a mouse in relation to it mass is proportional to the
  amount of sweetner needed to kill a person in relation to their mass

  sweetner needed to kill mouse(in grams)/mass of the mouse(in grams)  == sweetner needed to kill person(in grams)/mass of the person(in grams)
  sweetner needed to kill mouse == 5 grams
  mass of mouse == 35 grams
*/
int how_many_grams_to_kill(int mass_of_person)
{
    int grams_to_kill_person = mass_of_person/7;

    return grams_to_kill_person;
}


/*int number_of_cans_to_kill_person(int grams_needed_in_cans)
  -------------------------------------------------------
  this function takes the return value of of the how_many_grams_to_kill() function and uses it to determinethe number of cans needed to kill
  a person depending on their target weight, to determine the number of cans needed, we know that there is 0.001 grams of sweetner in a can
  of diet soda and that each can of diet soda has a mass of 350 grams

  the answer is going to be a number with a fractional part but because I'm storing the that number in a integer, the number will be rounded 
  down, giving us the highest number of cans the person can drink without dying
*/
long number_of_cans_to_kill_person(int grams_needed_in_cans)
{
    unsigned long num_of_cans = (350 * grams_needed_in_cans)/SWEETENER_PER_CAN;

    return num_of_cans;
}
