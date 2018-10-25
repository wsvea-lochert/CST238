/**
 * Title: hw1_1
 * Auther: William Svea-Lochert
 * Abstract: this program first reads how many inputs of integers a user want (max 30) and then prompts user to write x amount of integers.
 *           then count the occurences of distinct numbers.
 * ID: 1112
 * Date: 09.04.2018
 * */
 
 //compile: $ g++ -std=c++11 -o hw1_1  hw1_1.cpp

#include <iostream> // for cin and cout
#include <cstdlib>  // for exit
#include <climits>
#include <map>
#include <vector>
using namespace std;

int maxScore(int nums[], int size);

int main ()
{
    int inputValue;
    int numbers [inputValue];
    map<int,int> tellerMap;
    
    //promts user to write how many values they want.
    cout << ("How many input values [max 30]?") << endl;
    
    //reads input
    cin >> inputValue;
    
    
    if(inputValue <= 30)
    {
        // tells user how many input values the user can enter
        cout << ("Enter " ) << inputValue << (" numbers:") << endl;
        
        //fills arrays numbers with user inputs 
        for(int i = 0; i < inputValue; i++)
        {
            cin >> numbers[i];
        }
        
        for(int x = 0; x < inputValue; x++)
        {
            tellerMap[numbers[x]]++;
        }
        
        //gives user the highest number entered
        maxScore(numbers, inputValue);
        
        
        vector<uint32_t> keys;
        
        cout << ("Number 	Count") << endl;
        
        for (auto & valueKey : tellerMap) 
        {
            keys.emplace_back(valueKey.first);
            cout << "  " << valueKey.first << "       " << valueKey.second << endl;
        }
        
    }
    else
    {
        cout << ("To many input values") << endl;
        exit(1);
    }
    return 0;
}


//metode for aa finne det hoyeste tallet//
int maxScore(int nums[], int size)
{
   
    int largest = nums[0];
    
    for(int i = 1; i < size; i++)
    {
        if(nums[i] > largest)
        {
            largest = nums[i];
        }
    }
    cout << ("Biggest Number: ") << largest << endl;
}

