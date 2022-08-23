#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    return 0;
}