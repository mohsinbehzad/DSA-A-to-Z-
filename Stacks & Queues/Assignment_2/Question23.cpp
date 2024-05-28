#include <iostream>
#include <stack>
#include <string>

using namespace std;

string palindromeString(stack<char> st, string &forward, string backward)
{
    if (st.empty())
        return backward;

    forward += st.top();
    backward = st.top() + backward;
    st.pop();

    return palindromeString(st, forward, backward);
}

bool palindrome(stack<char> s)
{
    string a = "";
    string b = "";
    string &c = a;
    string p = palindromeString(s, c, b);
    cout << a << " " << p << endl;
    return a == p;
}

int main(int argc, char const *argv[])
{
    stack<char> st;
    st.push('a');
    st.push('b');
    st.push('b');
    st.push('a');
    cout << palindrome(st) << endl;
    return 0;
}
