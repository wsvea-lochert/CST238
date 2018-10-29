/*Code by Dr.Byun, modified by William Svea-Lochert
* ====================
* || Interface file ||
* ====================
*/
#include <iostream>
#include <cstdlib> //for exit

using namespace std;

class DayOfYear
{
public:
    DayOfYear(int monthValue, int dayValue);
    //Initializes the month and day to arguments.
   
    DayOfYear(int monthValue);
    //Initializes the date to the first of the given month.
   
    DayOfYear( );
    //Initializes the date to January 1.
   
    void input( );
    void output( );
    int getMonthNumber( );
    //Returns 1 for January, 2 for February, etc.

    int getDay( );
private:
    int month;
    int day;
    void testDate( );
};