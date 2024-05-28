#include <iostream>
using namespace std;

class sta
{
public:
    int size;
    int *arr;
    int ptr;

    sta()
    {
        this->size = 5;
        this->arr = new int[size];
        this->ptr = -1;
    }

    sta(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->ptr = -1;
    }

    void push(int x)
    {
        if (size - ptr > 1)
        {
            ptr++;
            arr[ptr] = x;
        }
        else
        {
            cout << "Stack is Full" << endl;
        }
    }

    void pop()
    {
        if (ptr == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            ptr--;
        }
    }

    int peek()
    {
        if (ptr >= 0)
        {
            return arr[ptr];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isempty()
    {
        return ptr == -1;
    }

    bool isfull()
    {
        return ptr == size - 1;
    }

    void display()
    {
        for (int i = 0; i <= ptr; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class SS
{
public:
    sta *st;
    int size;
    int top;

    SS()
    {
        this->size = 5;
        this->st = new sta[size];
        this->top = -1;
    }

    SS(int size)
    {
        this->size = size;
        this->st = new sta[size];
        this->top = -1;
    }

    void push(sta s)
    {
        if (size - top > 1)
        {
            top++;
            st[top] = s;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            top--;
        }
    }

    sta peek()
    {
        if (top >= 0)
        {
            return st[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            sta emptystack;
            return emptystack;
        }
    }
};

int main()
{
    sta s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    cout << s.peek() << endl;

    SS st(4);
    st.push(s);
    st.peek().push(6);
    st.peek().pop();
    cout << st.peek().peek() << endl;
    return 0;
}