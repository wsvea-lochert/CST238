/*
 * Title: lab3_2.cpp
 * Abstract: This program has basic operations listed below in the source, i have added the function to
             search for a numbers indexs in the array.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 09/16/2018
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
    int find(int value);

private:
    int mySize;  // Current size of elements stored in the list
    int myArray[CAPACITY];  
}; 


//--- Definition of class constructor
List::List()     
: mySize(0)
{}

int List::find(int value){
    for (int i = 0; i < mySize; i++){
        if (value == myArray[i]){
            //adding ++ before i here becouse c++ starts counting at 0, where as we humans count from 1
            cout << ++i << " is the position of " << value << endl;
            return i;
            break;
        }
    }
    return -1;
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
    // Test the class constructor
    List intList;
    cout << "Constructing intList\n";

    // Test empty() and output of empty list
    if (intList.empty())
    {
        cout << "Empty List: \n";
        intList.display();
        cout<< endl;
    }

    // Test insert()
    for (int i = 0; i < 9; i++)
    {
        cout << "Inserting " << i << " at position " << i/2 << endl;
        intList.insert(i, i/2);       //  -- Insert i at position i/2
        //Test output
        intList.display();
    }
    cout << "List empty? " << (intList.empty() ? "Yes" : "No") << endl;

    cout << "\nTry to insert at position -1" << endl;
    intList.insert(0, -1);
    cout << "\nTry to insert at position 10" << endl;
    intList.insert(0, 10);

    intList.find(3);

    /* Test erase()
    int index;
    cout << "\nGive an index of a list element to remove: ";
    cin >> index;
    intList.erase(index);
    intList.display();*/

   

    return 0;
}