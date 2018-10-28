/*
 * Title: lab7_2.cpp
 * Abstract: This program implements the big tree and has functions to add values to the list, 
             get the capasity and the amount of elements in the list. it also can reset an list and
             find the last index a number accures in the list.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/28/2018
 */


/* -----------------------------------------------------------------
  A sample list with a dynamic array
  Original source: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap06/Figure6.1/
  Updated by Dr. Byun for CST238.

  Basic operations are:
    Constructor
    empty:    Check if list is empty
    insert:   Insert a value into the list at a given position.
    erase:    Remove a value from the list at a given position.
    display:  Output the list
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

class List
{
public:
    List();    // Constructor. Default 50
    List(int capacityValue);
    List(const List& org); // Copy constructor
     List& operator =(const List& rightSide);  // Assignment operator
    int getMyCapacity() const {return myCapacity;};
    int getMySize() const {return mySize;};
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    void reset(); 
    bool addItem(int item);
    int findLast(int item);
    void sort(int array[], int Size);
    ~List( );
private:
   int mySize;     // current size of list
   int myCapacity; // capacity of array
   int * myArray;  // pointer to dynamic array
}; 



List::List(const List& org)
  :myCapacity(org.getMyCapacity()), mySize(org.getMySize( ))
{
    myArray = new int[myCapacity];
    
    for (int i =0; i < mySize; i++)
    {
        myArray[i] = org.myArray[i];
    }
}

List::~List()
{
    delete [] myArray;
}

List& List::operator =(const List& rightSide)
{
    if(this != &rightSide){
        if(myCapacity != rightSide.myCapacity)
        {
            delete [] myArray;
            myArray = new int[rightSide.myCapacity];
        }
        
        myCapacity = rightSide.myCapacity;
        mySize = rightSide.mySize;
        
        for(int i = 0; i < mySize; i++)
        {
            myArray[i] = rightSide.myArray[i];
        }
    }
    return *this;
}


//--- Definition of class constructor
List::List()     
: mySize(0), myCapacity(50)
{
    myArray = new int[myCapacity];
}


List::List(int capacityValue)     
: mySize(0), myCapacity(capacityValue)
{
    if(capacityValue < 1)
    {
        cerr << "\n============ error, cant set a capasity less than 1 ============" << endl;
        cerr << "               - Setting capasity to default(50) -" << endl;
        cerr << "================================================================" << endl;
        myCapacity = 50;
    }
    
    myArray = new int[myCapacity];
}

int List::findLast(int item)
{
    for(int i = mySize; i >= 0; i--)
    {
        if(myArray[i] == item)
        {
            return i;
        }
    }
    return -1;
}

void List::sort(int array[], int Size)
{
    for(int i = 0; i < Size-1; i++)
    {
        for(int j = 0; j < Size-i-1; j++)
        {
            if(*(array + j) > *(array + j+1))
            {
                int temp = *(array + j);
                *(array + j) = *(array + j+1);
                *(array + j+1) = temp;
            }
        }
    }
}

void List::reset()
{
    cout << endl;
    delete [] myArray;
    
    cout << "enter a new capasity: ";
    cin >> myCapacity;
    
    if(myCapacity < 1)
    {
        cerr << "\n============ error, cant set a capasity less than 1 ============" << endl;
        cerr << "               - Setting capasity to default(50) -" << endl;
        cerr << "================================================================" << endl;
        myCapacity = 50;
    }
    mySize = 0;
    
    myArray = new int[myCapacity];
}

bool List::addItem(int item){
    for(int i = 0; i < mySize-1; i++)
    {
        if(myArray[i] > myArray[i+1])
        {
            return false;
        }
    }
    
    if (mySize == myCapacity)
    {
       // int doubleCapasity = myCapacity * 2;
        myCapacity = myCapacity * 2;
        int * tempArr = new int[myCapacity];
        
        tempArr = myArray;
        myArray = tempArr;
    }
    insert(item, mySize);
    sort(myArray, mySize);
    
    return true;
    
}

//--- Definition of empty()
bool List::empty() const
{
    return mySize == 0;
}


//--- Definition of display()
void List::display() const
{
    for (int i = 0; i < mySize; i++)
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of insert()
void List::insert(int item, int pos)
{
    if (mySize == myCapacity)
    {
        cerr << "*** No more space for a list element -- increase capacity ***\n";
        return;
    }
    if (pos < 0 || pos > mySize)
    {
        cerr << "*** Illegal location to insert -- " << pos 
            << ".  List unchanged. ***\n";
        return;
    }

    // First shift array elements right to make room for item
    for(int i = mySize; i > pos; i--)
    {
        myArray[i] = myArray[i - 1];
    }

    // Now insert item at position pos and increase list size  
    myArray[pos] = item;
    mySize++;
}


//--- Definition of erase()
void List::erase(int pos)
{
    if (mySize == 0)
    {
        cerr << "*** List is empty ***\n";
        return;
    }
    if (pos < 0 || pos >= mySize)
    {
        cerr << "Illegal location to delete -- " << pos
            << ".  List unchanged. ***\n";
        return;
    }

    // Shift array elements left to close the gap
    for(int i = pos; i < mySize; i++)
    {
        myArray[i] = myArray[i + 1];
    }

    // Decrease list size
    mySize--;
}





//--- Client program to test List class.
int main()
{
List intList (10);
   
   intList.addItem(10);
   intList.addItem(20);
   cout << "=== Solution: 10 2 ===\n";
   cout << intList.getMyCapacity() << " " << intList.getMySize();

   cout << "\n=== Test reset() ===\n";
   intList.reset();

   intList.addItem(30);
   cout << "\n=== Solution: 5 1 ===\n";
   cout << intList.getMyCapacity() << " " << intList.getMySize();

   return 0;

}