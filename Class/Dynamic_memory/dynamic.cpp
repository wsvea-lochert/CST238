/*
* =======================================================================================================
*  This program uses only pointers and dynamic memory, when it is finishing we free the memory to the OS
* =======================================================================================================
*/

#include <iostream>
using namespace std;

int main()
{
    cerr << " === This program uses pointers, no normal variables ===\n" << endl ;
    
    //Pointers using dynamic memory//
    int * ptrId = new int;
    double * ptrScore1 = new double;
    double * ptrScore2 = new double;
    
    //Enter id an two scores
    cerr << "Enter a ID: ";
    cin >> *ptrId;
    
    cerr << "Enter a score: ";
    cin >> *ptrScore1;
    
    cerr << "Enter a score: ";
    cin >> *ptrScore1;
    cerr << endl;
    
    //Printing result of the two scores so we get an Avg and ID//
    cerr << "========= Result =========" << endl;
    cerr << "Avg: " << (*ptrScore1 + *ptrScore2) / 2 << " ID: " << *ptrId << endl;
    cerr << "==========================" << endl;
    
    //returns memory to OS//
    delete ptrId;
    delete ptrScore1;
    delete ptrScore2;
    
    //overwrite pointer addres to NULL//
    ptrId = nullptr;
    ptrScore1 = nullptr;
    ptrScore2 = nullptr;
    
    cerr << "Thank you, for trying!" << endl;
}