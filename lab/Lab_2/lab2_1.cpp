/**
 * Title: lab2_1.cpp
 * Auther: William Svea-Lochert
 * Abstract: this program shifts an array to the left or to the right depending on the users input, and adds a 0 on the side it moves from.
 * ID: 1112
 * Date: 09.07.2018
 * */

#include <iostream>
using namespace std;

int main ()
{
    int rightOrleft;
    int arr[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    char fortsett = 'Y';
    
    
    cout << ("Array Values: ");
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << (" ");
    }
    cout << endl;
    cout << ("This is the list of options") << endl 
         << ("      1. Delete the max") << endl 
         << ("      2. Append a number") << endl 
         << ("      3. Reverse array") << endl;
    
    while(fortsett = 'Y')
    {
        cout << ("Enter your option: ");
        cin >> rightOrleft;
             
        // right shif
        if(rightOrleft == 1)
        {
            for(int x = 9; x >= 0; x--)
            {
                arr[x] = arr[x-1];
            }
            arr[0] = 0;
        }
        // left shift
        else if(rightOrleft == 2)
        {
            for(int y = 0; y < 9; y++)
            {
                arr[y] = arr[y+1];
            }
            arr[9] = 0;
        }
        
        for(int p = 0; p < 10; p++)
        {
            cout << arr[p] << (" ");
        }
        
        cout << endl;
        cout << ("Continue?  (Y/N): ");
        cin >> fortsett;
        
        if(fortsett == 'N')
        {
            return 0;
        }
    }
   
}
