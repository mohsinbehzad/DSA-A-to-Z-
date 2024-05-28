#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool SingleTypeBalancedBraces(string s)
{
    stack<char> c;
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == '(')
        {
            c.push(s[i]);
        }
        else if (s[i] == ')' && c.top() == '(')
        {
            c.pop();
        }
        else
        {
            return false;
        }
    }
    return c.empty();
}

int main(int argc, char const *argv[])
{
    string s = "((()))";
    cout << SingleTypeBalancedBraces(s);
    return 0;
}
