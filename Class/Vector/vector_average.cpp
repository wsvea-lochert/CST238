// A demo program to determine the average of a vector using size().
// Written by Dr. Byun for CST238.
#include <iostream>
#include <vector>
using namespace std;

// Function prototype
double getAverage (vector<double> vect);
double getMax(vector<double> vect);
double getMin(vector<double> vect);

int main()
{
   double number;
   vector<double> scores;

    cout << "Enter a list of positive numbers.\n"
         << "Place a negative number at the end.\n";
    cin >> number;
    while (number > 0)
    {
        scores.push_back(number);
        cin >> number;
    }
   
   // Display the average of scores.
   cout << "Average: " << getAverage (scores) << endl;
   cout << "Max score: " << getMax (scores) << endl;
   cout << "Min score: " << getMin (scores) << endl;
   
   return 0;
}


// This function determines the average of a vector.
// Note that it doesn't need the vector size as an argument.
double getAverage (vector<double> vect)
{
   if (vect.size() == 0)
   {
       return 0;    // No score in the vector.
   }
   else
   {
      double sum = 0;
      
      for (unsigned int count = 0; count < vect.size(); count++)
      {
         sum += vect[count];
      }
      
      return sum/vect.size();
   }

}

//max score in a vector
double getMax(vector<double> vect)
{
    if (vect.size() == 0)
    {
        return 0;
    }
    else
    {
        double maxValue = vect[0];
        
        for (unsigned int count = 0; count < vect.size(); count++)
        {
            if(vect[count] > maxValue)
            {
                maxValue = vect[count];
            }
        }
        return maxValue;
    }
}
//min score in vector
double getMin(vector<double> vect)
{
    if (vect.size() == 0)
    {
        return 0;
    }
    else
    {
        double minValue = vect[0];
        
        for (unsigned int count = 0; count < vect.size(); count++)
        {
            if(vect[count] < minValue)
            {
                minValue = vect[count];
            }
        }
        return minValue;
    }
}