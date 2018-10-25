// A sample program to conduct the binary search.
#include <iostream>
using namespace std;

// Function prototype
int binarySearch(int data[], int size, int value);

// Array size
const int SIZE = 20;

int main()
{
   int numbers[SIZE] = {75, 82, 87, 98, 100, 207, 222,
                       234, 289, 296, 310, 319, 388, 394,
                       417, 429, 447, 521, 536, 600};
   int inputNum;
   int result;

   cout << "Enter a number to search: ";
   cin >> inputNum;
   
   // Search the array to find the location of the input number.
   result = binarySearch(numbers, SIZE, inputNum);
   
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

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. The array named data has a maximum of size    *
// elements and is searched for the number stored in value.     *
// If the number is found, its array subscript is returned.     *
// Otherwise, -1 is returned to indicate the value was not in   *
// the array.                                                   *
//***************************************************************

int binarySearch(int data[], int size, int value)
{
    bool found = false;
    
    int first = 0;
    int last = size-1;
    int middle = last/2;

    while(!found){
        //if item is found
      if(data[middle] == value)
      {
          found = true;
          return middle;
      }
      if(data[middle] > value)
      {
          last = middle - 1;
          middle = (first+last)/2;
      }
      if(data[middle] < value)
      {
          first = middle + 1;
          middle = (first+last)/2;
      }
      //its not in the array
      if(first > last)
      {
          found = true;
          return -1;
      }
  }
}
