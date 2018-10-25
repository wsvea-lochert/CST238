// A sample program to show the overloaded << operator.
// Original code is "08-05.cpp" and 
// updated by Dr. Byun for CST238.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Money
{
public:
    Money( );
    Money(int theDollars, int theCents);
    Money(int theDollars);
    friend ostream& operator <<(ostream& outputStream, const Money& amount);
private:
    int dollars; 
    int cents; 
};


int main( )
{
    Money m1(100), m2(25, 75);
    
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m1 << " and " << m2 << endl;

    return 0;
}


ostream& operator <<(ostream& outputStream, const Money& amount)
{
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0)
        outputStream << "$-";
    else
        outputStream << '$';
    outputStream << absDollars;

    if (absCents >= 10)
        outputStream << '.' << absCents;
    else
        outputStream << '.' << '0' << absCents;

    return outputStream;
}


Money::Money( )
: dollars(0), cents(0)
{/*Body intentionally empty.*/}


Money::Money(int theDollars)
: dollars(theDollars), cents(0)
{/*Body intentionally empty*/}


Money::Money(int theDollars, int theCents)
{
    if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
    {
        cout << "Inconsistent money data.\n";
        exit(1);
    }
    dollars = theDollars;
    cents = theCents;
}