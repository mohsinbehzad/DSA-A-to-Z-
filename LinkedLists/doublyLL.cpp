#include <iostream>
using namespace std;

struct stu
{
    int id;
    stu *next = NULL; // forward move
    stu *prev = NULL; // backward move
};
stu *first = NULL;
stu *last = NULL;

void insert(int x)
{
    // 1. create new node. 2.input data 3.check empty 4.if not empty
    stu *curr = new stu;
    curr->id = x;
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr;
        curr->prev = last;
        last = curr;
    }
}

void insert_start(int x)
{
    stu *curr = new stu;
    curr->id = x;
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        curr->next = first;
        first->prev = curr;
        first = curr;
    }
}

stu *search(int key)
{
    stu *p = first;
    while (p->id != key && p != NULL)
    {
        p = p->next;
    }
    return p;
}

void insert_after(int x)
{
    // 1.check whether x exists ot not
    stu *p = search(x);
    if (p == NULL)
    {
        cout << "Element does not exists";
    }
    else
    {
        stu *curr = new stu;
        if (p == last)
        {
            last->next = curr;
            curr->prev = last;
            last = curr;
        }
        else
        {
            curr->next = p->next;
            p->next = curr;
            curr->prev = p;
            curr->next->prev = curr;
        }
    }
}

void insert_before(int x)
{
    // 1.check whether x exists ot not
    stu *p = search(x);
    if (p == NULL)
    {
        cout << "Element does not exists";
    }
    else
    {
        stu *curr = new stu;
        if (p == first)
        {
            first->prev = curr;
            curr->next = first;
            first = curr;
        }
        else
        {
            p = p->prev;
            curr->next = p->next;
            p->next = curr;
            curr->prev = p;
            curr->next->prev = curr;
        }
    }
}

void del_start()
{
    stu *p = first;
    if (first == NULL)
    {
        cout << "Norhing Found";
    }
    else
    {
        first = p->next;
        first->prev = NULL;
        delete p;
    }
}

void del_last()
{
    stu *p = last;
    if (last == NULL)
    {
    }
}

void del_specific(int key)
{
    stu *p = search(key);
    if (p == NULL)
    {
        cout << "Norhing Found";
    }
    else if (p == first)
    {
        del_start();
    }
    else if (p == last)
    {
        del_last();
    }
    else
    {
        stu *k = p->prev;
        k->next = p->next;
        p->next->prev = k;
        delete p;
    }
}

void reverse_display()
{
    stu *p = last;
    while (p != NULL)
    {
        cout << p->id;
        p = p->prev;
    }
}

void display() {
    stu *p = first;
    while (p != NULL) {
        cout << p->id << " -> ";
        p = p->next;
    }
    cout << endl;
}

void reverseReccurively(stu *node) {
    if (node->next == NULL) {
        cout << node->id << "->";
        return;
    }

    reverseReccurively(node->next);
    cout << node->id << "->";
}

int main()
{
    bool shouldRun = true;
    while (shouldRun) {
        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Exit" << endl;

        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            int id;
            cout << "ID"<< endl;
            cin >> id;
            insert(id);
            
            break;

        case 2:
            reverseReccurively(first);
            break;

        case 3:
            shouldRun = false;
            break;
        
        default:
            break;
        }
        
    }
}