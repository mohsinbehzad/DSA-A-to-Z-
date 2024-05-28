#include <iostream>
#include <queue>

using namespace std;
void reverseQueue(queue<int> &q)
{
    if (q.empty())
        return;
    int temp = q.front();
    q.pop();
    reverseQueue(q);
    q.push(temp);
}

void printQueue(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "Original queue: ";
    printQueue(q);

    reverseQueue(q);

    cout << "Reversed queue: ";
    printQueue(q);

    return 0;
}
