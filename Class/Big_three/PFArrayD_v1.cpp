/*
* This program has a deconstructor so the program does not crash.
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
    ~PFArrayD( );
    void addElement(double element);

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


// A test function to create an object with a dynamic array.
void testPFArrayD( )
{
    PFArrayD temp(1000000); // Create an object with a dynamic array. 
    
    temp.addElement(100); // Assign 100 to the first element.
    temp.addElement(200); // Assign 200 to the second element.
}

// Destructor
PFArrayD::~PFArrayD( )
{
    delete [] a;
}





int main( )
{
    cout << "This program shows the need of a destructor in a class.\n";
    
    for (int i=0; i < 500000; i++)
    {
        cout << "Object " << i+1 << endl;
        testPFArrayD( );
    }

    return 0;
}