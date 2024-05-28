#include <iostream>
#include <stack>
#include <string>

using namespace std;
class Queue
{
public:
    int *arr;
    int front;
    int end;
    int size;
    int lengthOfArray;

    Queue(int s)
    {
        lengthOfArray = s;
        arr = new int[lengthOfArray]; // Dynamically allocate memory for the array
        size = front = end = 0;
    }
    Queue()
    {
        Queue(0);
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
        // end++;
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

    int length()
    {
        return size;
    }

    void splitCircularQueueInTwo(Queue q)
    {
        Queue first(q.length());
        Queue second(q.length());
        while (!q.empty())
        {
            first.push(q.pop());
            if (!q.empty())
            {
                second.push(q.pop());
            }
        }
        first.display();
        second.display();
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

int main(int argc, char const *argv[])
{
    Queue q(10); // Creating a queue with size 5
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // q.pop();
    q.push(5);
    q.push(6); // This will print "Queue is full" because the queue is full
    // q.pop();
    q.push(7);
    q.push(8);
    q.push(9);
    q.display();
    cout << "After splitting queue in two" << endl;
    q.splitCircularQueueInTwo(q);

    return 0;
}
