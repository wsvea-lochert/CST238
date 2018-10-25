/**
 * Title: hw2_2.cpp
 * Auther: William Svea-Lochert
 * Abstract: Takes input from file that user specifies, splits the information into structures, and then puts the structures into a structured array.
 *           then looking at the 5 quiz scores and taking the average of the 4 highest scores and displays the information to the user.
 * ID: 1112
 * Date: 09.13.2018 and 09.12.2018
 * */

#include <iostream>
#include <fstream>
using namespace std;

double average(double array[], int size);

struct studentQuiz
{
    string name;
    int id;
    double scores[5];
    double average;
};


int main()
{
    string file_name;
    bool controll = false;

    cout << "Enter input file name: ";
    cin >> file_name;

    ifstream input_file(file_name);
    
    if (input_file.fail()) 
    {
        cout << "Error: Input file open failed.\n";
        return 0;
    }
    
    cout << "--------------------------------------------------" << endl
         << "  Course Report: Quiz Average" << endl 
         << "--------------------------------------------------" << endl;
    
    studentQuiz students[30];
    int size = 30;
    int index = 0;
    int teller = 0;
    
    while(!controll)
    {
        studentQuiz student;
        input_file >> student.name;
        input_file >> student.id;
        
        if(student.name == "STOP")
        {
            controll = true;
        }
        else
        {
            teller++;

            for(int i = 0; i < 5; i++)
            {
                input_file >> student.scores[i];
            }
                students[index] = student; 
                cout << students[index].name << " (" << students[index].id << ") : ";
                average(student.scores, 5);
                index++;
        }
        
        if(index == size)
        {
            controll = true;
        }
        index++;
    }
    cout << "--------------------------------------------------" << endl;
    return 0;
}

double average(double array[], int size)
{
   double smallest = array[0] ;
   double sum = array[0];
   
    for ( int i=1;  i < 5;  i++)
    {
        sum += array[i];
        
        if ( array[i] < smallest )
        {
            smallest = array[i];
        }
    }
        sum = sum - smallest;
        double avg = sum/4;
       
        cout << avg << endl;
}         

