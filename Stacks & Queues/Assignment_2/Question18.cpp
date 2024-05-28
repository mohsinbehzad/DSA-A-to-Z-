#include <iostream>
#include <stack>
#include <string>

using namespace std;
int *arr = new int[100];
int size;
class forwardQueue
{
public:
    int front;
    int end;
    int lengthOfArray;

    forwardQueue(int s)
    {
        lengthOfArray = s;
        size = front = end = 0;
    }
    forwardQueue()
    {
        forwardQueue(0);
    }
    bool full() { return size == lengthOfArray; }
    bool empty() { return size == 0; }
    void push(int i)
    {
        if (full())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[end++] = i;
        end = end % lengthOfArray;
        size++;
    }

    int pop()
    {
        if (empty())
            return -1;
        int removed = arr[front++];
        front = front % lengthOfArray;
        size--;
        return removed;
    }

    void display()
    {
        int i = front;
        do
        {
            cout << arr[i++] << " ";
            i = i % lengthOfArray;
        } while (i != end);
        cout << endl;
    }
};

class backwardQueue
{
public:
    int front;
    int end;
    int lengthOfArray;

    backwardQueue(int s)
    {
        lengthOfArray = s;
        size = 0;
        front = end = 100;
    }
    backwardQueue()
    {
        backwardQueue(0);
    }
    bool full() { return size == lengthOfArray; }
    bool empty() { return size == 0; }
    void push(int i)
    {
        if (full())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[--end] = i;
        if (100 - end == lengthOfArray)
            end = 100;
        size++;
    }

    int pop()
    {
        if (empty())
            return -1;
        int removed = arr[--front];
        if (100 - front == lengthOfArray)
            front = 100;
        size--;
        return removed;
    }

    void display()
    {
        int i = front;
        do
        {
            cout << arr[--i] << " ";
            if (100 - i == lengthOfArray)
                i = 100;
        } while (i != end);
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    forwardQueue q(5); // Creating a queue with size 5
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    q.display();

    backwardQueue q2(5); // Creating a queue with size 5
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);
    q2.pop();
    q2.push(5);
    q2.push(6);
    q2.push(6);

    q2.display();
    return 0;
}
