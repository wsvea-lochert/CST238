/**
 * Title: lab2_3.cpp
 * Auther: William Svea-Lochert
 * Abstract: this program reads from a file and stores the information from the file into a structure and compares the the average test score from two students and sees who scored the best average
 * ID: 1112
 * Date: 09.09.2018
 * */
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct student
{
        string name;
        double num1;
        double num2;
        double avg;
};
    
int main()
{
    int x;
    string navn, fileName, tall1, tall2, tall3, tall4;
    double number1, number2, number3, number4, avg1, avg2;
    string arr[5];
    student one;
    student two;
    
    cout << ("Enter input file name: ");
    cin >> fileName;
    
    ifstream in_file(fileName);

     if (in_file.fail()) 
    {
        cout << "Error: input file open failed.\n";
        exit(1);
    }
    
    if(in_file.is_open())
    {
        for(int i =0; i < 6; ++i){
            in_file >>arr[i];
        }
    }

   tall1 = arr[1];
   tall2 = arr[2];
   tall3 = arr[4];
   tall4 = arr[5];
   
    number1 = stod(tall1);
    number2 = stod(tall2);
    number3 = stod(tall3);
    number4 = stod(tall4);
   
    one.name = arr[0];
    one.num1 = number1;
    one.num2 = number2;
    avg1 = (number1 + number2) /2;
    one.avg = avg1;
  
    two.name = arr[3];
    two.num1 = number3;
    two.num2 = number4;
    avg2 = (number3 + number4) /2;
    two.avg = avg2;
    
   cout << one.name << "'s average is:  "  << one.avg << endl;
   cout << two.name << "'s average is:  "  << two.avg << endl;
   
   if(avg1 > avg2)
   {
       cout << one.name << " has a better score than " << two.name << endl;
   }
   else
   {
       cout << two.name << " has a better score than " << one.name << endl;
   }
 
}