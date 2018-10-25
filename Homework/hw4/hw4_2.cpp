/**
 * Title: hw4_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program checks if the queue is sorted
 * ID: 1112
 * Date: 09.27.2018
 **/

/**********************************************************
 * Queue implementation with a static array.
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap08/Figure8.2/
 * Updated by Dr. Byun for CST238.
 * Basic operations:
 *   Constructor: Constructs an empty queue
 *   empty:       Checks if a queue is empty
 *   enqueue:     Modifies a queue by adding a value at the back
 *   front:       Accesses the front queue value; leaves queue unchanged
 *   dequeue:     Modifies a queue by removing the value at the front
 *   display:     Displays the queue elements from front to back
 *
 **********************************************************/ 
#include <iostream>
using namespace std;

const int QUEUE_CAPACITY = 10;
typedef int QueueElement;

class Queue
{
public:
    Queue();
    bool empty() const;
    void enqueue(QueueElement value);
    void display() const;
    QueueElement front() const;
    void dequeue();
    bool isSorted();

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

bool Queue::isSorted()
{
    bool acending = false;
    int counter = 0;
    int size = myBack-myFront;
    
    for (int i = myFront; i != myBack - 1; i = (i + 1)%QUEUE_CAPACITY){
        if(myArray[i] >= myArray[i+1])
        {
            acending = false;
            if(i == myBack){
                break;
            }
        }
                
        else if(myArray[i] <= myArray[i+1])
        {
            acending = true;
            if(i == myBack){
                break;
            }
        }
    }
    
    if(acending == true)
    {
        for (int i = myFront; i != myBack - 1; i = (i + 1)%QUEUE_CAPACITY) 
        {
            if(myArray[i] == myArray[i + 1]){
                i = (i + 1)%QUEUE_CAPACITY;
            } 
            else if(myArray[i] > myArray[i+1])
            {
                cerr << " bøg ";
               return false;
            }
        }
        
    }
    else if(acending == false){
        for (int i = myFront; i != myBack - 1; i = (i + 1)%QUEUE_CAPACITY) 
        {

            if(myArray[i] == myArray[i + 1]){
                i = (i + 1)%QUEUE_CAPACITY;
            }
            else if(myArray[i] < myArray[i+1])
            {

                return false;
                break;
            }
        }
    }
}


//--- Definition of empty()
bool Queue::empty() const
{ 
    return (myFront == myBack); 
}


//--- Definition of enqueue()
void Queue::enqueue(QueueElement value)
{
    int newBack = (myBack + 1) % QUEUE_CAPACITY;
    if (newBack != myFront)     // queue isn't full
    { 
        myArray[myBack] = value;
        myBack = newBack;
    }
    else
    {
        cerr << "*** Queue full -- can't add new value ***\n"
            "Must increase value of QUEUE_CAPACITY.\n";
    }
}


//--- Definition of display()
void Queue::display() const
{
    for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
    {
        cout << myArray[i] << "  ";
    }
    cout << endl;
}


//--- Definition of front()
QueueElement Queue::front() const
{
    if ( !empty() ) 
    {
        return (myArray[myFront]);
    }
    else
    {
        cerr << "*** Queue is empty -- returning garbage value ***\n";
        QueueElement garbage;
        return garbage;
    }
}


//--- Definition of dequeue()
void Queue::dequeue()
{
    if ( !empty() )
    {
        myFront = (myFront + 1) % QUEUE_CAPACITY;
    }
    else
    {
        cerr << "*** Queue is empty -- "
            "can't remove a value ***\n";
    }
}


int main()
{
    Queue q1;
    
    q1.enqueue(100);
    q1.enqueue(200);
    q1.enqueue(300);
    cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;
    q1.display();
    
    q1.dequeue();
    q1.enqueue(50);

    cout << "isSorted()? " << boolalpha << q1.isSorted() << endl;
    q1.display();
    
    q1.dequeue();
    
    return 0;
}

/*
Acending
Check if front > front +1 && back > back - 1;

Decending
check if Front > front +1 && back < back - 1;

itterate through with a nested for loop: to check if statements are true, if so return true else return false.

––– keep it simple –––
*/