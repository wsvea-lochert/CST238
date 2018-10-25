/**
 * Title: hw4_1.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program checks if the queue is sorted
 * ID: 1112
 * Date: 09.26.2018
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

const int QUEUE_CAPACITY = 7;
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
    int size();
    int find(int item);
private:
    int myFront;
    int myBack;
    QueueElement myArray[QUEUE_CAPACITY];
}; // end of class declaration


//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}


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

int Queue::size(){
    //max capasity - empty slots????
    if(myFront > myBack){
        int spaceBetween = myBack - myFront;
        return QUEUE_CAPACITY-spaceBetween;
    }else{
        return myBack-myFront;
    }
    
    
}

int Queue::find(int item){
    for(int i = 0; i < QUEUE_CAPACITY; i++){
        if(item == myArray[i]){
            return i+1;
        }
    }
        return -1;
}


int main()
{
    Queue q1;
    cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

    cout << "How many elements to add to the queue? ";
    int numItems;
    cin >> numItems;
    for (int i = 1; i <= numItems; i++) 
        q1.enqueue(100*i);
        


cout << "200 is at position: " << q1.find(200) << endl;
    cout << "Contents of queue:\n";
    
    q1.display(); 
    //cout << "Queue q1 empty? " << q1.empty() << endl;

   // cout << "\nFront value in q1: " << q1.front() << endl << endl;
    
    cout << "size is: " << q1.size() << endl;
    
    
    

    while (!q1.empty())
    {
        cout << "Remove front -- Queue contents: ";
        q1.dequeue();
        q1.display();
    }
    cout << "\nQueue q1 empty? " << q1.empty() << endl;
    cout << "Now try to retrieve front value in q1" << endl;
    cout << "Front value in q1?" << endl << q1.front() << endl;
    cout << "\nNow Try to remove front of q1: " << endl;
    q1.dequeue();
    
    //test size
    //cout << q1.size() << endl;
    
    q1.enqueue(1112);

    
   // cout << "1112 is at: " << q1.find(1112) << endl;
    
    cout << "Whats in the que: " << endl;
    q1.display(); 
    
    cout << "1112 is at: " << q1.find(1112) << endl;
    
    cout << "size is: " << q1.size() << endl;
    
    //cout << QUEUE_CAPACITY;
}