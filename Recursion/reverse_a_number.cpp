#include <iostream>
using namespace std;

int sum = 0;
int reverse1(int k)
{
    if (k == 0)
    {
        return sum;
    }
    int rem = k % 10;
    sum = sum * 10 + rem;
    reverse1(k / 10);
    return sum;
}

int main()
{
    cout << reverse1(546903);
}