/*
* this program demonstrates what a copy constructor does.
*
*
*/

// A sample program to demonstrate the need of big three functions.
#include <iostream>
#include <cstdlib>  // for exit()
using namespace std;

// A class to define partially filled array of doubles.
class PFArrayD
{
public:
    PFArrayD();
    PFArrayD(int capacityValue); 
    void addElement(double element);
    int getCapacity( ) const { return capacity; }
    int getNumberUsed( ) const { return used; }
    double& operator[](int index);  // [] operator
    ~PFArrayD( );  // Destructor
    PFArrayD(const PFArrayD& pfaObject); // Copy constructor

private:
    double *a;    // A pointer to keep a dynamic array. 
    int capacity; // Max capacity of the dynamic array.
    int used;     // Number of array elements used.
};


// Constructor. Default capacity is 50.
PFArrayD::PFArrayD( ) 
  :capacity(50), used(0)
{
    a = new double[capacity];
}


// Constructor with a max capacity size
PFArrayD::PFArrayD(int size)
  :capacity(size), used(0)
{
    a = new double[capacity];
}


void PFArrayD::addElement(double element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PFArrayD.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}


double& PFArrayD::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PFArrayD.\n";
        exit(0);
    }

    return a[index];
}


// Destructor
PFArrayD::~PFArrayD( )
{
    delete [] a;
}

// Copy constructor with this we can make deepcopys
PFArrayD::PFArrayD(const PFArrayD& pfaObject)
:capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new double[capacity];
    for (int i =0; i < used; i++)
    {
        a[i] = pfaObject.a[i];
    }
}


int main( )
{
    cout << "This program shows the need of a copy constructor in a class.\n";
    
    PFArrayD cst231(5);
    cst231.addElement(100);
    cst231.addElement(200);
    cst231.addElement(300);
    
    // Copy the content of cst231 to cst238.
    // Then, change the first element value of cst238 to 400.
    PFArrayD cst238(cst231);
    cst238[0] = 400;

    cout << "cst231 Content: ";
    int count = cst231.getNumberUsed( );
    for (int index = 0; index < count; index++)
        cout << cst231[index] << " ";
    cout << endl;
    
    cout << "cst238 Content: ";
    count = cst238.getNumberUsed( );
    for (int index = 0; index < count; index++)
        cout << cst238[index] << " ";
    cout << endl;

    return 0;
}