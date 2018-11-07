/*
 * A sample linked list using struct.
 * This program is written by Dr. Byun based on Savitch's textbook.
 */
#include <iostream>
using namespace std;

struct ListNode 
{
    int data;
    ListNode *link; 
}; 

typedef ListNode* ListNodePtr;

void headInsert(ListNodePtr& head, int newData);
void display(ListNodePtr head);
bool find(ListNodePtr ptr, int number);


// Function to add a new node at the head of the linked list
void headInsert(ListNodePtr& head, int newData)
{
    ListNodePtr p = new ListNode;
    p->data = newData;
    p->link = head;
    head = p;
}


// Display every node one by one
void display(ListNodePtr ptr)
{
    cout << "===== Content =====" << endl;
    while (ptr != nullptr) 
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

/*----------------------------------------------finde element in linked list------------------------------------------------*/

//find a spesific number in a linked list (node).
bool find(ListNodePtr ptr, int number)
{
    //if there is nothing in the "linked list" return false.
    if(!ptr)
    {
        return false;
    }
    
    //loop trough linked list while ptr != null and increment.
    while(ptr)
    {
        // if the number is found, return true and cout that it was found.
        if (ptr->data == number)
        {
            cout <<"(" << number << ") was found." << endl;
            return true;
        }
        //increment ptr
        ptr = ptr->link;
    }
    
    //if the number was not found, return false and tell the user it was not found.
    cout << "(" << number << ") was not found." << endl;
    return false;
}

/*--------------------------------------------------------------------------------------------------------------------------*/


int main()
{
    ListNodePtr head;
    
    // Initially, the head points nullptr (or NULL).
    head = nullptr;
    
    // Add two nodes.
    headInsert(head, 12);
    find(head, 12);
    find(head, 300);
    headInsert(head, 100);
    headInsert(head, 999);
    headInsert(head, 1112);
    display(head);
    
    return 0;
}