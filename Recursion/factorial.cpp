#include <iostream>
using namespace std;

// Factorial(!) means Product of a number to 1
// For example if a number is 5 then 5! is equal to 5x4x3x2x1 = 120

int fact(int k)
{
    if (k < 2)
    {
        return k;
    }
    if (k == 0)
    {
        return 1;
    }
    return k * fact(k - 1);
}

int main()
{
    int num;
    cout << "Enter a number to find Factorial: ";
    cin >> num;
    cout << fact(num);
}