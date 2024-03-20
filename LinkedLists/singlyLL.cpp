#include <iostream>
using namespace std;

struct stu
{
    int id;
    stu *next = NULL;
};
stu *first = NULL;
stu *last = NULL;

void insert(int id)
{
    stu *curr;
    curr = new stu;
    cout << "Enter id: ";
    cin >> curr->id;
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr;
        last = curr;
    }
}

void insert_start()
{
    stu *curr;
    curr = new stu;
    cout << "Enter id: ";
    cin >> curr->id;
    if (first == NULL)
    {
        first = curr = last;
    }
    else
    {
        curr->next = first;
        first = curr;
    }
}

void display()
{
    stu *p = first;
    while (p != NULL)
    {
        cout << p->id << "->";
        p = p->next;
    }
    cout << endl;
}

void search(int key)
{
    stu *p = first;
    while (p != NULL && p->id != key)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "not found";
    }
    else
    {
        cout << "found";
    }
}

stu *searchR(int key)
{
    stu *p = first;
    while (p != NULL && p->id != key)
    {
        p = p->next;
    }
    return p;
}

void insert_after(int key)
{
    stu *p = searchR(key);
    if (p == NULL)
    {
        cout << "Value not found";
    }
    else
    {
        stu *curr = new stu;
        cout << "Enter id: ";
        cin >> p->id;
        if (p == last)
        {
            last->next = curr;
            last = curr;
        }
        else
        {
            curr->next = p->next;
            p->next = curr;
        }
    }
}

void del_first()
{
    stu *p = first;
    if (first == NULL)
    {
        cout << "Nothing found";
    }
    else
    {
        // p = first;
        first = first->next;
        delete p;
    }
}

void del_last()
{
    stu *p = first;
    if (last == NULL)
    {
        cout << "Nothing Found";
    }
    else
    {
        if (first == last)
        {
            p = first;
            delete p;
            first = last = NULL;
        }
        else
        {
            while (p->next->next != NULL)
            {
                p = p->next;
            }
            p->next = NULL;
            last = p;
        }
    }
}

void del_specific(int key)
{
    stu *p = searchR(key);
}

void reverse_display()
{
    stu *s = first;
    stu *e = last;
    while (e != first)
    {
        while (s->next != e)
        {
            s = s->next;
        }
        cout << e->id;
        e = s;
        s = first;
    }
    cout << e->id;
}

void reverse()
{
    if (first == NULL || first->next == NULL)
    {
        return;
    }
    stu *headTemp = first;
    stu *temp = first;
    stu *prev = nullptr;
    stu *tailTemp = last;
    while (first != tailTemp)
    {
        while (temp != tailTemp)
        {
            prev = temp;
            temp = temp->next;
        }
        temp->next = prev;
        tailTemp = prev;
        prev = first;
        temp = first;
    }
    first = last;
    last = headTemp;
    last->next = NULL;

    stu *p = first;
    while (p != NULL)
    {
        cout << p->id << "->";
        p = p->next;
    }
}

int main()
{
    bool shouldRun = true;
    while (shouldRun)
    {
        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Reverse" << endl;
        cout << "4. Exit" << endl;

        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            int id;
            // cout << "ID"<< endl;
            // cin >> id;
            insert(id);
            break;

        case 2:
            display();
            break;

        case 3:
            reverse();
            break;

        case 4:
            shouldRun = false;
            break;

        default:
            break;
        }
    }
}

// 1.not found
// 2.first one
// 3.last one
// 4.only one value