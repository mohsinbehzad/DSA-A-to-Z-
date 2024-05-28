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
        this->ptr = 0;
    }

    sta(int size)
    {
        this->size = size;
        this->arr = new int[size];
        this->ptr = 0;
    }
    bool isEmpty() { return ptr == 0; }

    bool isFull() { return ptr == size; }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        arr[ptr++] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[--ptr];
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[ptr - 1];
    }

    void display()
    {
        for (int i = ptr - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class SS
{
public:
    sta *stack;
    int size;
    int ptr;
    SS(int size)
    {
        stack = new sta[size];
        this->size = size;
        ptr = 0;
    }
    
    SS()
    {
        SS(0);
    }

    bool isEmpty() { return ptr == 0; }

    bool isFull() { return ptr == size; }

    void push(sta *x)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        stack[ptr++] = *x;
    }

    sta *pop()
    {
        return &stack[--ptr];
    }

    sta *peek()
    {
        return &stack[ptr - 1];
    }

    void display()
    {
        for (int i = ptr - 1; i >= 0; i--)
        {
            stack[i].display();
        }
    }
};

int main(int argc, char const *argv[])
{
    sta s(10);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    // s->display();

    sta s2(10);
    s2.push(25);
    s2.push(62);
    s2.push(27);
    s2.push(82);
    s2.push(92);
    // s2->display();

    sta s3(10);
    s3.push(15);
    s3.push(61);
    s3.push(17);
    s3.push(81);
    s3.push(19);
    // s3->display();

    SS ss(3);
    ss.push(&s);
    ss.push(&s2);
    ss.push(&s3);
    ss.display();
    // sta* temp = ss.peek();
    // temp->push(213);
    // temp->display();
    // ss.peek()->pop();
    // ss.display();

    // ss.peek().push(10);
    // cout<<ss.peek().peek();
    return 0;
}
