/*
 * Title: lab4_3.cpp
 * Abstract: this program checks for the well known balanced parentheses problem. it checks if the userinput of "(" or ")" is balanced like (())
             or other combinations.
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 09/22/2018
 */


//some code inspired by https://gist.github.com/mycodeschool/7207410

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
#include<stack>
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


bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(')
		{
		    S.push(exp[i]);
		}
		else if(exp[i] == ')')
		{
			if(S.empty())
			{
			   	return false;
			}
			else
			{
				S.pop();
			}
		}
	}
	return S.empty() ? true:false;
}

int main()
{
    char cont = 'y';

    while(cont == 'y')
    {
        
    	string expression;
    	cout<<"Enter an expression:  "; // input expression from STDIN/Console
    	cin>>expression;
    	if(AreParanthesesBalanced(expression))
    		cout<<"Balanced" << endl;
    	else
    		cout<<"Not Balanced" << endl;
    		
    		
    	cout << "Do you want to continue? (y/n): ";
    	cin >> cont;
    	cout << endl;
    	
    	
    }
    if(cont == 'n'){
        cout << "Bye!" << endl;
    }
}
