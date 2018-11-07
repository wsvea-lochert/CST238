// A sample recursive factorial function.

#include <iostream>
using namespace std;

// Factorial function prototype
int f(int n);
int sum(int n);

int main()
{
    int num;
    
    cout << "Enter a non-negative number: ";
    cin >> num;
    cout << "=" << sum(num) << endl;
    
    return 0;
}

/*
// Factorial function definition
int f(int n) 
{
    if (n == 0)             // Base case
        return 1
    else 
        return n * f(n-1);  // Recursive case, fuction calling itself.
}*/

int sum(int n)
{
    if(n == 1){
        cout << n;
        return 1;
    }
    else{
        cout<< n <<"+";
        return n + sum(n-1);
    }

    
}