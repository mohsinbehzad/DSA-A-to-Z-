#include <iostream>
#include <stack>
#include <string>

using namespace std;
struct CLLasQueue
{
public:
    int value;
    CLLasQueue *next;
    CLLasQueue(int value)
    {
        this->value = value;
    }
    CLLasQueue(int value, CLLasQueue *next)
    {
        this->value = value;
        this->next = next;
    }
};
CLLasQueue *tail = NULL;

void insert(int val)
{
    CLLasQueue *n = new CLLasQueue(val);
    if (tail == NULL)
    {
        tail = n;
    }
    n->next = tail->next;
    tail->next = n;
    tail = n;
    // size++;
}

void push(int i)
{
    insert(i);
}
int pop()
{
    int temp = tail->next->value;
    CLLasQueue *t = tail->next;
    tail->next = tail->next->next;
    delete t;
    return temp;
}

void display()
{
    CLLasQueue *temp = tail->next;
    do
    {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << "END" << endl;
}

int main(int argc, char const *argv[])
{
    push(23);
    push(24);
    push(25);
    push(26);
    push(27);
    display();
    pop();
    pop();
    display();
    return 0;
}
