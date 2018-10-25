/**
 * Title: hw2_1.cpp
 * Auther: William Svea-Lochert
 * Abstract: This program is made to do three operations to an array. the program displays 3 options to the user.
 *           1 delete max, 2 append a number and 3 reverse array. when the program has finished the first opperation
 *           it will ask the user if it wants to do another operation.
 * ID: 1112
 * Date: 09.10.2018
 * */


#include <iostream>
using namespace std;

int main ()
{
    int rightOrleft;
    int arr[10] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int tempArr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char fortsett = 'Y';
    int size = 9;
    
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

        //delete max
        if(rightOrleft == 1)
        {
            int max = arr[0];
            int tempIndex;
            for(int x = 1; x < 10; x++)
            {
                if(arr[x] > max)
                {
                    max = arr[x];
                    tempIndex = x;
                }
            }
            arr[tempIndex] = 0;
            size--;
        }
        
        //append a number
        if(rightOrleft == 2)
        {
            if(size == 9)
            {
                cout << "Array is full and can’t append anymore." << endl;
            }
            else
            {
                int appendInt;
                cout << "Enter the number to Append: ";
                cin >> appendInt;
                for(int y = 0; y <= 9; y++)
                {
                    if(arr[y] == 0)
                    {
                        arr[y] = appendInt;
                        y=10;
                        size++;
                    }
                }
            }
            
        }
        //--------------//
        //reverse array
        if(rightOrleft == 3)
        {
         int start = 0;
         int end = size;
        
            while (start < end)
            {
                int temp = arr[start]; 
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;
            } 
        }
        
        for(int p = 0; p < 10; p++)
        {
            cout << arr[p] << (" ");
        }
        
        cout << endl;
        cout << ("Continue?  (Y/N): ");
        cin >> fortsett;
        cout << endl;
        
        if(fortsett == 'N')
        {
            return 0;
        }
    }
}
