/*Code by Dr.Byun, modified by William Svea-Lochert
* =====================
* ||    Main file    ||
* =====================
*/
#include <iostream>
#include <cstdlib> //for exit
#include "dayOfYear.h"
using namespace std;

int main( )
{
    DayOfYear date1(2, 21), date2(5), date3;
    cout << "Initialized dates:\n";
    date1.output( ); cout << endl;
    date2.output( ); cout << endl;
    date3.output( ); cout << endl;

    date1 = DayOfYear(10, 31);
    cout << "date1 reset to the following:\n";
    date1.output( ); cout << endl;
    return 0;
}