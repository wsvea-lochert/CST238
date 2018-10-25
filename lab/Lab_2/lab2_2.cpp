/**
 * Title: lab2_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: this program shifts an array to the left or to the right depending on the users input.
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
    int store;
    
    
    cout << ("Array Values: ");
    for(int i = 0; i < 10; i++)
    {
        cout << arr[i] << (" ");
    }
    cout << endl;
    cout << ("This is the list of options") << endl << ("      1. Right rotate") << endl << ("      2. Left rotate") << endl << endl;
    
    while(fortsett = 'Y')
    {
        cout << ("Enter your option: ");
        cin >> rightOrleft;
         
        // right shif
        if(rightOrleft == 1)
        {
            store =arr[9];
            for(int x = 9; x >= 0; x--)
            {
                arr[x] = arr[x-1];
            }
            arr[0] = store;
        }
        // left shift
        else if(rightOrleft == 2)
        {
            store = arr[0];
            for(int y = 0; y < 9; y++)
            {
                arr[y] = arr[y+1];
            }
            arr[9] = store;
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
        if(fortsett == 'n')
        {
            return 0;
        }
        if(fortsett == 'y')
        {
        fortsett = 'Y';
        }
   
    }
}
