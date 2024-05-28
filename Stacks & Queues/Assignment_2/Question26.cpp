#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check if the given character is an operator
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of the operator
int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix)
{
    string postfix = "";
    stack<char> st;

    for (char &ch : infix)
    {
        if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if (st.empty())
            {
                throw invalid_argument("Invalid expression: Unmatched parentheses");
            }
            st.pop(); // Discard '('
        }
        else if (isOperator(ch))
        {
            while (!st.empty() && st.top() != '(' && getPrecedence(st.top()) >= getPrecedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            postfix += ch; // Operand
        }
        else
        {
            throw invalid_argument("Invalid character in expression: " + string(1, ch));
        }
    }

    // Pop remaining operators from stack
    while (!st.empty())
    {
        if (st.top() == '(')
        {
            throw invalid_argument("Invalid expression: Unmatched parentheses");
        }
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;
    cout << "Enter the infix expression: ";
    cin >> infix;

    try
    {
        string postfix = infixToPostfix(infix);
        cout << "Postfix expression: " << postfix << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
