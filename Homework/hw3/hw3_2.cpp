/**
 * Title: hw3_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program has functions to look through arrays with functions to modify and check if the array is 
 *           empty. i have developed a insert function to add elements to the end of the array. another function 
 *           to check if there is duplicate values in the array and another function to remove a element and its 
 *           duplicates.
 * ID: 1112
 * Date: 09.19.2018
 * */


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
    void insert(int item);
    void erase(int pos);  
    void display() const; 
    int find(int value);
    bool isDuplicate();
    bool remove(int value);

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


void List::insert(int item)
{
    myArray[mySize] = item;
    mySize++;
}

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

    for(int i = pos; i < mySize; i++)
    {
        myArray[i] = myArray[i + 1];
    }

    // Decrease list size
    mySize--;
}

bool List::remove(int value)
{
    int index = 0;
    bool controller = false;
    
    if(mySize == 0)
    {
        cout << "****List is empty****" << endl;
        return false;
    }
    
    for (int l = 0; l < mySize; l++)
    {
       for(int i = 0; i < mySize; i++)
       {
            if(myArray[i] == value)
            {
                index = i;
                controller = true;
            }
        }
        
        if(myArray[index] == value) 
        {
            for(int x = index; x < mySize+1; x++)
            {
                myArray[x] = myArray[x + 1];
                
            }
            --mySize;
        } 
    }
    return controller;
        
}

bool List::isDuplicate(){
    for(int i = 0; i < mySize; i++)
    {
        for(int j = i+1; j < mySize; j++)
        {
            if(myArray[i] == myArray[j])
            {
                return true;
            }
        }
    }
    return false;
}

//--- Client program to test List class.
int main()
{
   List intList;
    
    intList.insert(10);
    intList.insert(30);
    intList.insert(20);
    intList.display();
    cout << (intList.isDuplicate() ? "Yes" : "No") << endl;
    
    intList.insert(30);
    intList.display();

    cout << (intList.isDuplicate() ? "Yes" : "No") << endl;
    
    intList.remove(30);
    intList.display();

    return 0;
}