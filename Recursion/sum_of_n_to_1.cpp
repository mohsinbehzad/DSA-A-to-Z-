#include <iostream>
using namespace std;

int sum(int k)
{
    if (k < 2)
    {
        return k;
    }
    return k + sum(k - 1);
}

int main()
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << sum(num);
}