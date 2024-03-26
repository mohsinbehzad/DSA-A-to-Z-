#include <iostream>
using namespace std;

class Sta
{
public:
    int *s;
    int top, size;

    Sta()
    {
        top = -1;
        size = 10;
        s = new int[size];
    }

    Sta(int size)
    {
        top = -1;
        this->size = size;
        s = new int[size];
    }

    void push(int ele)
    {
        if (is_full())
        {
            cout << "Stacks is full";
        }
        else
            s[++top] = ele;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack is empty";
            return -1;
        }
        else
            return s[top--];
    }

    bool is_full()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
            return false;
    }

    bool is_empty()
    {
        if (top == -1)
        {
            return true;
        }
        else
            return false;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << s[i];
        }
    }
};

int main()
{
    Sta s, s2(7);
    s2.push(5);
    s2.push(6);
    s2.push(8);
    s2.push(10);
    s2.display();
    cout << endl;
    s2.pop();
    s2.pop();
    s2.display();

    // int num;
    // do
    // {
    //     cout<<"Enter 1 to Push: \nEnter 2 to Pop: \nEnter 0 to Exit: ";
    //     cin >> num;
    //     if (num == 1) {

    //     }

    // } while (num != 0);
}