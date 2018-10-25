/**
 * Title: hw4_3.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program can drop a number by value from the queue and remove the number in the back of the queue
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
    bool drop(int value);
    void removeBack();

private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Remove a specific item from the queue.

/*
            --- Sudo code ---
1. bool set to false; if bool = true we found the value
2. int index to hold index of the value in the queue
3. itterate through the queue with a forloop (the same loop as is used in the display method)
4. if myArray[position] == inputValue set controller to true and index = position
5. after the loop is done, check if controller == true
6. if controller == true, run a new for loop to itterate from the position we found towards the right
   myArray[position] = myArray[position + 1]
7. when loop is done reduse the size of myBack by 1
8. then return true
9. else if the controller was false, return false.
        
*/
bool Queue::drop(int value)
{
    bool controller = false;
    int index;
    int size = myBack - myFront;
    
     for (int i = myFront; i != myBack; i = (i + 1)%QUEUE_CAPACITY) 
     {
        if (myArray[i] == value)
        {
         controller = true;
         index = i;
        }
     }
     
     //test om controller er true her...
     if(controller == true)
     {
         for(int x = index; x < size; x++)
         {
             myArray[x] = myArray[x + 1];
         }
         myBack--;
         return true;
     } 
     
     else 
     {
        return false;
     }
}

void Queue::removeBack(){
    if(myFront == myBack)
    {
        cerr << "Queue is empty, cant remove item" << endl;
    }
    else
    {
        myBack--;
    }
}


bool Queue::isSorted()
{
    bool acending = false;
    
    if(myArray[myFront] >= myArray[myFront+1])
    {
        acending = false;

    }
            
    else if(myArray[myFront] <= myArray[myFront+1])
    {
        acending = true;
    }
    
    if(acending == true)
    {
        for (int i = myFront; i != myBack - 1; i = (i + 1)%QUEUE_CAPACITY) 
        {
            if(myArray[i] > myArray[i+1])
            {
               return false;
            }
        }
    }
    else if(acending == false){
        for (int i = myFront; i != myBack - 1; i = (i + 1)%QUEUE_CAPACITY) 
        {
            if(myArray[i] < myArray[i+1])
            {
               return false;
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
   q1.enqueue(400);
   q1.removeBack();  
   q1.display();    // Queue has 100 200 300

   q1.drop(200);
   q1.display();    // Queue has 100 300

   return 0;


}



