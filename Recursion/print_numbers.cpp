#include <iostream>
using namespace std;

void print_recursive(int k)
{
    if(k==0){
        return;
    }
    print_recursive(k-1);
    cout<<k<<endl;
}

void print_reverse(int k) {
    if (k ==0){
        return;
    }
    cout<<k<<endl;
    print_reverse(k-1);
}

int main() 
{
    int num,num2;
    cout<<"Enter an integer to which the numbers will be printed: ";
    cin>>num;
    print_recursive(num);
    cout<<"Enter an integer to print in reverse: ";
    cin>>num2;
    print_reverse(num2);
}