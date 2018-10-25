/*
 * Title: Lab1_1
 * Abstract: This program determine the max value of three inputs
 * Author: William Svea-Lochert
 * ID: 1112
 * Date: 08/31/2018
 */
 
#include <iostream>
using namespace std;

int main(){
    
    int num1, num2, num3, num4;
    
    //output to consol
    cout << "Enter 4 numbers" << endl;
    
    //reads input from user
    cin >> num1>>num2>>num3>>num4;
    
    int store;
    
    if(num1 > num2 && num1 > num3 && num1 > num4){
        store = num1;
    }
    
    else if(num2 > num1 && num2 > num3 && num2 > num4){
        store = num2;
    }
    
    else if(num3 > num1 && num3 > num2 && num3 > num4){
        store = num3;
    }
    
    else{
        store = num4;
    }
    
    cout << "max number is " << store << endl;
    
    return 0;
    
}