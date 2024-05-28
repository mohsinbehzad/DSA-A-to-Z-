#include <iostream>
#include <stack>
#include <string>

using namespace std;
bool Multiplebalancedbraces(string str)
{
    stack<char> t;

    for (int i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if (c == '[' || c == '(' || c == '{')
        {
            t.push(c);
        }
        else
        {
            char n = t.top();
            if (c == ')' && n == '(')
            {
                t.pop();
            }
            else if (c == ']' && n == '[')
            {
                t.pop();
            }
            else if (c == '}' && n == '{')
            {
                t.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return t.empty();
}

int main(int argc, char const *argv[])
{
    string s = "[{()}]";
    cout << Multiplebalancedbraces(s);
    return 0;
}
