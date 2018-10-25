/**
 * Title: lab1_3
 * Auther: William Svea-Lochert
 * Abstract: takes input from user and creates a square and a triangle.
 * ID: 1112
 * Date: 08.31.2018
 * */


#include <iostream> // for cin and cout
using namespace std;

int square(int num1);
int triangle(int num1);

int main(){
    
    cout << "enter a number: " <<endl;
    
    int length;
    cin >> length;
    
    square(length);
    triangle(length);
    
}

int square(int num1){
    for(int i = 0; i < num1; i++){
        for(int l = 0; l < num1; l++){
            cout << "* ";
        }
        cout << "" <<endl;
    }
    cout << "" <<endl;
}

int triangle(int num1){
    
    int save = num1;
    
    int space = 2 * save - 1;
    
    
    //Main loop
    for(int i = 0; i < num1; i++){
        
        for(int l = 0; l < space; l++){
        cout << " ";
        
        }
    
        space = space - 2;
    
        //stjerne utskrift
        for(int x = 0; x <= i; x++){
            cout << "* ";
        }
        
        save--;
        cout << "" <<endl;
    }
}