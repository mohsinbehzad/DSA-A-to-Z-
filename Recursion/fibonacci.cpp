#include <iostream>
using namespace std;

int fibo(int k)
{
    if (k < 2)
    {
        return k;
    }
    return fibo(k - 1) + fibo(k - 2);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << fibo(num);
}