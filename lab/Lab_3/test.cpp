#include <iostream>
#include <string>
using namespace std;

class Money {
    public:
    Money(int dollar, int cent);
    //Initializes the month and day to arguments.
   
    Money( );
    //Initializes the date to January 1.

    int getDollar();
    int getCent();
    int setDollar(int dollarValue);
    int setCent(int centValue);
    
    string output();
    int addAmount(int d, int c);
    
private:
    int dollar;
    int cent;
};


int main()
{
    Money m1, m2;

    cout << "m1 initial amount: " << m1.getDollar() << " and " 
         << m1.getCent() << endl;
         
    cout << "m1 output: " << m1.output() << endl;

    m1.setDollar(20);
    m1.setCent(35);
    m2.setDollar(10);
    m2.setCent(98);
    
   
    cout << "m1 new amount: " << m1.getDollar() << " and " 
    
         << m1.getCent() << endl; 
    cout << "m2 output: " << m2.output() << endl;

    m1.setDollar(50);
    cout << "m1 new amount: " << m1.output() << endl;
    
    m1.addAmount(20, 30);
    cout << "m1 new amount after adding " << m1.output() << endl;

    return 0;
}


Money::Money(int dollarValue, int centValue)
: dollar(dollarValue), cent(centValue){}

Money::Money()
: dollar(0), cent(0){}

int Money::getDollar()
{
    return dollar;
}

int Money::getCent()
{
    return cent;
}

int Money::setDollar(int dollarValue)
{
    dollar = dollarValue;
}

int Money::setCent(int centValue)
{
    cent = centValue;
}

string Money::output()
{
    string sentense = to_string(dollar) + " Dollars and " + to_string(cent) + " Cents";
    return  sentense;
}

int Money::addAmount(int d, int c)
{
    dollar + d;
    cent + c;
    if(cent > 100)
    {
        cent - 100;
        dollar++;
        return dollar + cent;
    }
}

