#include <iostream>
#include <stack>

using namespace std;

void noYellow(stack<string> &sta)
{
    if (sta.empty())
        return;
    string temp = sta.top();
    sta.pop();
    noYellow(sta);
    if (temp != "yellow")
    {
        sta.push(temp);
    }
}

void printStack(stack<string> q)
{
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    stack<string> sta;
    sta.push("red");
    sta.push("pink");
    sta.push("yellow");
    sta.push("black");
    sta.push("white");
    printStack(sta);
    noYellow(sta);
    printStack(sta);

    return 0;
}
