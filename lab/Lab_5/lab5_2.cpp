/*
 * Title: lab1_2.cpp
 * Abstract: Determine the minimum and maximum numbers from input data in a file.
 *           To compile this code, you should provide "-std=c++11" option.
 * Author: Alice Otter
 * ID: XXXX
 * Date: 08/31/18
 */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    cout << "Enter input file name: ";
    string file_name;
    string file_name_Two;
    int x, y;
    
    cin >> file_name;

    cout << "enter input for file two: ";
    cin >> file_name_Two;
    
    // Open the input file.
    ifstream input_file(file_name);
    
    //Open file nr 2
    ifstream input_fileTwo(file_name_Two);
    
    if (input_file.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
    if(input_fileTwo.fail())
    {
        cout << "Error: Input file open failed. \n";
        return 0;
    }
    
    input_file >> x;
    input_fileTwo >> y;
    bool ender = false;
    
    while(!ender)
    {
        if(x == -1 && y != -1)
        {
            while(!ender)
            {
                cerr << y;
                input_fileTwo >> y;
                
                if(y == -1)
                {
                    ender = true;
                }
            }
        }
        
        if(y == -1 && x != -1)
        {
            while(!ender)
            {
               // cerr << "tiss";
                cerr << x;
                input_file >> x;
                if(x == -1)
                {
                    ender = true;
                }
            }
        }
        
        if(y == -1 && x == -1)
        {
            ender = true;
        }
        
        else if(x > y)
        {
            cerr << y << " ";
            input_fileTwo >> y;
        }
        else if(y > x)
        {
            cerr << x << " ";
            input_file >> x;
        }
        else if(x == y || y == x)
        {
            cerr << x << " ";
            input_file >> x;
        }
    }
    cout << endl;
    input_file.close();
    input_fileTwo.close();
    return 0;
}


