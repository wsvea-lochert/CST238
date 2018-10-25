#include <iostream>
using namespace std;

int main()
{
    int * ptrSize = new int;
    int * ptrTotal = new int;
    double * ptrScore = new double[ptrSize];
    
    
    
    cin >> * ptrSize;
    
    for(int i = 0; i < *ptrSize; i++){
        cin >> *ptrScore;
        *total += *ptrScore[i];
    }
    
    cerr << total/ *ptrSize
    
    delete ptrSize;
    delete ptrTotal;
    delete ptrScore;
    
    ptrScore = nullptr;
    ptrTotal = nullptr;
    ptrSize = nullptr;
}