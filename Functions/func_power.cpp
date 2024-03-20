#include<iostream>
using namespace std;

int power (int a, int b) {
    // int a , b;
    cout<< "numbers :"<< endl;
    cin>> a >> b;
    int ans = 1;
    for(int i = 0; i < b; i++) {
        ans = ans * a;
    }
    cout<<ans;
    return ans;
}

int main() {
    // pow (a,b)
    int a , b;
    // cin>> a >> b;
    power(a,b); 

    int c,d;
    power (c,d);

}