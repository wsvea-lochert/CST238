#include <iostream>
using namespace std;


void readScore(double nums[], int size);
double getAverage(double nums[], int size);


int main () {
   const int MAX_NUM = 5;
   double score[MAX_NUM], average;
   int i;

   readScore(score, MAX_NUM);
   average = getAverage(score, MAX_NUM);
   cout << "Average: " << average << endl;
   return 0;
}

void readScore(double nums[], MAX_NUM){
    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }
    
}


double getAverage(a[], MAX_NUM){
    double sum = 0;
    int k;

    for(k=0; k < size; k++) {
        sum += nums[k];
    }

    return (sum/size);

}

double maxScore(double nums[], int size){
   
    double largest = nums[0];
    
    for(int i = 1; i < size; i++){
        if(nums[i] > largest){
            largest = nums[i];
        }
        
        return largest;
    }
}