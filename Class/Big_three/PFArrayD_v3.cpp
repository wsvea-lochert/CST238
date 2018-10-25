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
    PFArrayD(const PFArrayD& pfaObject); // Copy constructor
    void addElement(double element);
    int getCapacity( ) const { return capacity; }
    int getNumberUsed( ) const { return used; }
    double& operator[](int index);  // [] operator
    ~PFArrayD( );  // Destructor
    PFArrayD& operator=(const PFArrayD& rightSide); //assignment operator

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


// Copy constructor
PFArrayD::PFArrayD(const PFArrayD& pfaObject)
  :capacity(pfaObject.getCapacity( )), used(pfaObject.getNumberUsed( ))
{
    a = new double[capacity];
    for (int i =0; i < used; i++)
        a[i] = pfaObject.a[i];
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


// Destructor without it we get memory leaking
PFArrayD::~PFArrayD( )
{
    delete [] a;
}

/* (1)
* if the capasity of the two arrays are differente, we should delete the old dynamic
* memory and allocate a new dynamic array. 
* 
* (2)
* Then we do a deep copy.
*
*  (3)
* Check selfassignment
*/

PFArrayD& PFArrayD::operator=(const PFArrayD& rightSide) //assignment operator.
{
    // Check for self-assignment
    if(this != &rightSide)
    {
        // if the capasity of the two arrays are differente, we delete the old dynamic
        if(capacity != rightSide.capacity)
        {
            delete [] a;
            a = new double[rightSide.capacity];
        }
        
        //assign new values
        capacity=rightSide.capacity;
        used = rightSide.used;
        
        for(int i = 0; i < used; i++)
        {
            a[i] = rightSide.a[i];
        }
    }
    return *this;
}

int main( )
{
    cout << "This program presents the need of an assignment operator in a class.\n";
    
    PFArrayD cst231(5);
    cst231.addElement(100);
    cst231.addElement(200);
    cst231.addElement(300);
    
    PFArrayD cst238(10);
    cst238.addElement(700);
    cst238.addElement(800);
    
    // Assignment the content of cst231 to cst238.
    // Then, change the first element value of cst238 to 400.
    cst238 = cst231;
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