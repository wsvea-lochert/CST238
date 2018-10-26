/*
 * Title: lab8_1.cpp
 * Abstract: This program implements the big tree
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/26/2018
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
    ~List( );
private:
   int mySize;     // current size of list
   int myCapacity; // capacity of array
   int * myArray;  // pointer to dynamic array
}; 

List::List(const List& org)
  :myCapacity(org.getMyCapacity( )), mySize(org.getMySize( ))
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
    myArray = new int[myCapacity];
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
   /* // Test the class constructor
    int maxListSize;
    cout << "Enter the list size: ";
    cin >> maxListSize;
    List intList (maxListSize);
    cout << "Constructing intList\n";

    // Test insert()
    for (int i = 0; i < 9; i++)
    {
        cout << "Inserting " << i << " at position " << i/2 << endl;
        intList.insert(i, i/2); //  -- Insert i at position i/2
        //Test output
        intList.display();
    }
    cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;

    return 0;*/
    
    List orgList;
    
    for (int i = 0; i < 9; i++)
    {
        orgList.insert(i, i);
    }

    List copyList(orgList);  // Copy constructor
    copyList.insert(400, 0);
    copyList.insert(500, 1);
    
    cout << "========== orgList1 ==========\n";
    orgList.display();
    
    cout << "========== copyList1 ==========\n";
    copyList.display(); 
    
    // Assignment operation
    copyList = orgList;
    orgList.insert(77, 2);
    orgList.insert(88, 5);
    
    cout << endl << endl;
    cout << "========== orgList2 ==========\n";
    orgList.display();
    
    cout << "========== copyList2 ==========\n";
    copyList.display(); 
    
    return 0;

}