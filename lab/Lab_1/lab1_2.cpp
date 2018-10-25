/**
 * Title: lab1_2
 * Auther: William Svea-Lochert
 * Abstract: Takes min and max value of integer in .txt file from user 
 * ID: 1112
 * Date: 08.31.2018
 * */

#include <iostream> // for cin and cout
#include <fstream>  // for input file stream object
#include <cstdlib>  // for exit
#include <climits>
using namespace std;

int main (){
    
    // A file stream object for input.
    ifstream in_file;

    int num;
    
    int min = INT_MAX;
    
    int max = INT_MIN;
    
    string fileName;
    
    cout << "enter a name of .txt file" <<endl;
    
    cin>>fileName;
    
    in_file.open(fileName.c_str());

    if (in_file.fail()) {
        cout << "Error: input file open failed.\n";
        exit (1);
    }
    
    
    while (in_file >> num) {
        if(num > max){
            max = num;
        }
        
        if(num < min){
            min = num;
        }
    }
    
    cout << "min value: " << min << endl;
    
    cout << "max value: " << max << endl;

    in_file.close();

    return 0;
}
