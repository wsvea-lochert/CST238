/***********************************************************************
 * Original code: https://cs.calvin.edu/activities/books/c++/ds/2e/SourcePrograms/Chap07/Figures7.4-5/
 * Updated by Dr. Byun for CST238
 * Basic operations:
 *   constructor:  Constructs an empty stack
 *   empty:        Checks if a stack is empty
 *   push:         Modifies a stack by adding a value at the top
 *   top:          Retrieves the top stack value; leaves stack unchanged
 *   pop:          Modifies stack by removing the value at the top
 *   display:      Displays all the stack elements
 ************************************************************************/

#include <iostream>
using namespace std;

const int STACK_CAPACITY = 30;
typedef char StackElement;

class Stack
{
public:
    Stack();
    bool empty() const;
    void push(StackElement value);
    void display() const;
    StackElement top() const;
    void pop();

private:
    StackElement myArray[STACK_CAPACITY];
    int myTop;
}; // end of class declaration


//--- Definition of Stack constructor
Stack::Stack()
: myTop(-1)
{}


//--- Definition of empty()
bool Stack::empty() const
{ 
    return (myTop == -1); 
}


//--- Definition of push()
void Stack::push(StackElement value)
{
    if (myTop < STACK_CAPACITY - 1) //Preserve stack invariant
    { 
        ++myTop;
        myArray[myTop] = value;
    }
    else
    {
        cerr << "*** Stack full -- can't add new value ***\n"
            "Must increase value of STACK_CAPACITY.\n";
        return;
    }
}


//--- Definition of display()
void Stack::display() const
{
    for (int i = myTop; i >= 0; i--) 
    {
        cout << myArray[i] << " ";
    }
}


//--- Definition of top()
StackElement Stack::top() const
{
    if ( !empty() ) 
    {
        return (myArray[myTop]);
    }
    else
    {
        cerr << "*** Stack is empty -- returning garbage value ***\n";
        StackElement garbage;
        return garbage;
    }
}


//--- Definition of pop()
void Stack::pop()
{
    if ( !empty() )
    {
        myTop--;
    }
    else
    {
        cerr << "*** Stack is empty -- can't remove a value ***\n";
    }
}


int main()
{
    Stack s;
    
    char charValue;
    
    cin >> charValue;
    
    s.push(charValue);
    s.display();

    

    //s.push(doubleValue[0]);
    
    s.display();
    cout << endl;


/*
    
    cout << "Stack created.  Empty? " << boolalpha << s.empty() << endl;

    cout << "How many elements to add to the stack? ";
    int numItems;
    cin >> numItems;
    for (double i = 1.0; i <= numItems; i++)
        s.push(i);

    cout << "Stack contents:\n";
    s.display();
    cout << "Stack empty? " << s.empty() << endl;

    cout << "Top value: " << s.top() << endl;

    while (!s.empty())
    {
        cout << "Popping " << s.top() << endl;
        s.pop();
    }
    cout << "Stack empty? " << s.empty() << endl;
    cout << "Top value: " << s.top() << endl;
    cout << "Trying to pop: " << endl;
    s.pop();*/
}
