#include <iostream>
using namespace std;

// int multiplication(int a, int b) {
//     if (b == 1) {
//         return a;
//     }
//     return a + multiplication(a, b - 1);
// }

int recursive_multiplication(int a, int b)
{
    int result = 0;
    for (int i = 0; i < b; i++)
    {
        result += a;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    cout << recursive_multiplication(2, 6);
    return 0;
}
