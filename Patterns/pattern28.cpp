#include <iostream>
using namespace std;

int main()
{
    cout << "Enter a number";
    int n;
    cin >> n;
    int i = 0;
    while (i < n)
    {
        int j = 1;
        while (j<=n) 
        {
            cout<<"* ";
            j = j+1;
        }
        cout<<endl;
        i++;
    }
}