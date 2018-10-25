/**
 * Title: hw1_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: The program takes user input for a .txt file with 5 numbers. from that file it draws a horizontal histogram.
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

    cout << ("Enter input file name: ");
    cin >> fileName;
    cout << fileName << endl;
    
    in_file.open(fileName.c_str());
    
    if (in_file.fail()) 
    {
        cout << "Error: input file open failed.\n";
        exit (1);
    }
    
    cout << ("===== Horizontal Histogram =====") << endl;
    
    while (in_file >> x) 
    {
        cout << x << (": "); 
      for(int i = 0; i < x; i++)
      {
         cout << ("*");
      }
      cout<< (" ") << endl;
    }
    
    in_file.close();

    return 0;
    //int numbers[i]


    
    
    

}