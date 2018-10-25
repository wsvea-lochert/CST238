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

const Money operator +(const Money& amount1, const Money& amount2);
bool operator ==(const Money& amount1, const Money& amount2);


int main( )
{
    Money m1 (10, 75), m2 (7, 50);
    Money totalAmount;
    
    testAmount = m1 == m2;
    
   /* totalAmount = m1 + m2;
    cout << "m1 is "; 
    m1.output( ); 
    cout << endl;
    cout << "m2 is "; 
    m2.output( ); 
    cout << endl;
    cout << "Total amount is "; 
    totalAmount.output( ); 
    cout << endl;*/

    return 0;
}

bool operator ==(const Money& amount1, const Money& amount2){
    
    int allCents1 = amount1.getCents( ) + amount1.getDollars( )*100;
    int allCents2 = amount2.getCents( ) + amount2.getDollars( )*100;
    

    if (allCents1 == allCents2){
        return true;
    }
    else{
        return false;
    }
}


const Money operator +(const Money& amount1, const Money& amount2)
{
    int allCents1 = amount1.getCents( ) + amount1.getDollars( )*100;
    int allCents2 = amount2.getCents( ) + amount2.getDollars( )*100;
    int sumAllCents = allCents1 + allCents2;
    int absAllCents = abs(sumAllCents); //Money can be negative.
    int finalDollars = absAllCents/100;
    int finalCents = absAllCents%100;

    if (sumAllCents < 0)
    {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }

    return Money(finalDollars, finalCents);
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