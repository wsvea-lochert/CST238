/*
 * Title: lab6_1.cpp
 * Abstract: This program uses the consept of overloading the << operator
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 10/12/2018
 */


/*-----------------------------------------------------------------
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
#include <ostream>
using namespace std;

const int CAPACITY = 16; // Maximum capacity of a list.

class List
{
public:
    List(); // Class constructor
    bool empty() const; 
    void insert(int item, int pos);
    void erase(int pos);  
    void display() const; 
    friend ostream& operator <<(ostream& outputStream, const List& list);

private:
    int mySize;  // Current size of elements stored in the list
    int myArray[CAPACITY];  
}; 


//--- Definition of class constructor
List::List()     
: mySize(0)
{}

ostream& operator <<(ostream& outputStream, const List& list)
{
    for(int i = 0; i < list.mySize; i++)
    {
        outputStream << list.myArray[i] << " ";
        
    }

    return outputStream;
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
    if (mySize == CAPACITY)
    {
        cerr << "*** No space for list element -- terminating "
            "execution ***\n";
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
    List intList;

    for (int i = 0; i < 5; i++)
    {
        cout << "Inserting " << i << " at position " << i/2 << endl;
        intList.insert(i, i/2);
        // Test output. Note that it uses << operator.
        cout << intList << endl;
    }

    cout << "\nRemove the first element (= index 0)." << endl;
    intList.erase(0);
    cout << intList << endl; // Note that it uses << operator.

    return 0;
}
