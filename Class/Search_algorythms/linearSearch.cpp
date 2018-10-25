// A sample program to conduct the linear search.
#include <iostream>
using namespace std;

// Function prototype
int linearSearch(int data[], int size, int value);

int main()
{
   const int SIZE = 5;
   int numbers[SIZE] = { 87, 75, 98, 100, 82 };
   int inputNum;
   int result;

   cout << "Enter a number to search: ";
   cin >> inputNum;
   
   // Search the array to find the location of the input number.
   result = linearSearch(numbers, SIZE, inputNum);

   if (result == -1)
   {
      cout << inputNum << " doesn't exist." << endl;
   }
   else
   {
      cout << inputNum << " is at the index " << result << endl;
   }
   return 0;
}


//*****************************************************************
// The linearSearch function performs a linear search on an       *
// integer array. The array data, which has a maximum of size      *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************

int linearSearch(int data[], int size, int value)
{
   for(int i = 0; i < size; i++)
   {
       if(data[i] == value)
       {
           return i;
       }
   }
    return -1;
}
