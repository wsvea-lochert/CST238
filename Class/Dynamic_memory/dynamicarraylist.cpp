#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    double *arrPtr = new double[n];
    
    int count = 1;
    
    double *scorePtr = new double;
    double *sumPtr = new double;
    
    while(count <= n)
    {
        cout << "Enter student " << count << ":";
        cin >> *scorePtr;
        *sumPtr += *scorePtr;
        arrPtr[count-1] = *scorePtr;
        count++;
    }
    
    cout << "Average: " << *sumPtr / n << endl;
    
    delete arrPtr;
    arrPtr = nullptr;
    
    delete scorePtr;
    scorePtr = nullptr;
    
    delete sumPtr;
    sumPtr = nullptr;
    
    return 0;
}