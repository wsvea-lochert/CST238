// A sample Money class to keep a money amount in dollars and cents.

#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Money
{
public:
    Money( );
    Money(double amount);
    Money(int theDollars, int theCents);
    Money(int theDollars);
    double getAmount( ) const;
    int getDollars( ) const;
    int getCents( ) const;
    void input( );
    void output( ) const;
private:
    int dollars; 
    int cents; 

    int dollarsPart(double amount) const;
    int centsPart(double amount) const;
    int round(double number) const;
};


int main( )
{
    Money yourAmount, myAmount(10, 9);
    cout << "Enter your money amount: ";
    yourAmount.input( );

    cout << "Your amount is "; 
    yourAmount.output( ); 
    cout << endl;
    cout << "You have " << yourAmount.getDollars() << " dollars and ";
    cout << yourAmount.getCents() << " cents.\n\n";
    
    cout << "My amount is "; 
    myAmount.output( ); 
    cout << endl;

    return 0;
}


Money::Money( )
: dollars(0), cents(0)
{/*Body intentionally empty.*/}


Money::Money(double amount)
: dollars(dollarsPart(amount)), cents(centsPart(amount))
{/*Body intentionally empty*/}


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


double Money::getAmount( ) const
{
    return (dollars + cents*0.01);
}


int Money::getDollars( ) const
{
    return dollars;
}


int Money::getCents( ) const
{
    return cents;
}


void Money::output( ) const
{
    int absDollars = abs(dollars);
    int absCents = abs(cents);
    if (dollars < 0 || cents < 0)//accounts for dollars == 0 or cents == 0
        cout << "$-";
    else
        cout << '$';
    cout << absDollars;

    if (absCents >= 10)
        cout << '.' << absCents;
    else
        cout << '.' << '0' << absCents;
}


// This function reads the dollar sign and then the amount number.
// For example, type like $75.25
// Don't forget $ symbol.
void Money::input( )
{
    char dollarSign;
    cin >> dollarSign;
    if (dollarSign != '$')
    {
        cout << "No dollar sign in Money input.\n";
        exit(1);
    }

    double amountAsDouble;
    cin >> amountAsDouble;
    dollars = dollarsPart(amountAsDouble);
    cents = centsPart(amountAsDouble);
}


int Money::dollarsPart(double amount) const
{
    return static_cast<int>(amount);
}


int Money::centsPart(double amount) const
{
    double doubleCents = amount*100;
    int intCents = (round(fabs(doubleCents)))%100;
    if (amount < 0)
        intCents = -intCents;
    return intCents;
}


int Money::round(double number) const
{
    return static_cast<int>(floor(number + 0.5));
}