/**
 * Title: hw1_3.cpp
 * Auther: William Svea-Lochert
 * Abstract: The program takes user input for a .txt file with 7 numbers. from that file it draws a vertical histogram.
 * ID: 1112
 * Date: 09.06.2018
 * */

#include <iostream> // for cin and cout
#include <fstream>
#include <cstdlib>  // for exit
#include <climits>
#include <string>
using namespace std;


int main ()
{
    string fileName;
    ifstream in_file;
    int x;
    int numbers[7];
    int maxNumber;
    
    cout << ("Enter input file name: ");
    cin >> fileName;
    cout << fileName << endl;
    
    in_file.open(fileName.c_str());
    
    if (in_file.fail()) 
    {
        cout << "Error: input file open failed.\n";
        exit (1);
    }
    
    cout << ("===== Vertical Histogram =====") << endl;
    
    int counter = 0;
    
    while (in_file >> x) 
    {
        numbers[counter] = x;
        counter++;
    }
    maxNumber = numbers[0];
    
    //check if maxNumber is the highest number
    for(int controll = 0; controll < 7; controll++)
    {
        if(numbers[controll] > maxNumber)
        {
            maxNumber = numbers[controll];
        }
    }
    
    //responsible for printing stars or spaces
    for(int rad = maxNumber; rad>=1; rad--)
    {
        for(int kolonne = 0; kolonne < 7; kolonne++)
        {
            if(numbers[kolonne] >= rad) 
            {
                cout << ("* c");
            }
            else
            {
                cout << ("  ");
            }
        }
        cout << endl;
    }
    cout << ("-------------") << endl;
    
    //printing numbers from file 
    for(int y = 0; y<7; y++){
        cout << numbers[y] << (" ");
    }
    cout << endl;
    in_file.close();
    return 0;
}