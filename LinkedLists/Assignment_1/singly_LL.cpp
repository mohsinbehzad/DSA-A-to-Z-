#include <iostream>
using namespace std;

struct stu
{
    int id;
    stu *next = NULL;
};
stu *head = NULL;
stu *tail = NULL;

void insert(int id)
{
    stu *curr;
    curr = new stu;
    cout << "Enter id: ";
    cin >> curr->id;
    if (head == NULL)
    {
        head = tail = curr;
    }
    else
    {
        tail->next = curr;
        tail = curr;
    }
}

void insert_start()
{
    stu *curr;
    curr = new stu;
    cout << "Enter id: ";
    cin >> curr->id;
    if (head == NULL)
    {
        head = curr = tail;
    }
    else
    {
        curr->next = head;
        head = curr;
    }
}

void display()
{
    stu *p = head;
    while (p != NULL)
    {
        cout << p->id << "->";
        p = p->next;
    }
    cout << endl;
}

void search(int key)
{
    stu *p = head;
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
    stu *p = head;
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
        if (p == tail)
        {
            tail->next = curr;
            tail = curr;
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
    stu *p = head;
    if (head == NULL)
    {
        cout << "Nothing found";
    }
    else
    {
        // p = head;
        head = head->next;
        delete p;
    }
}

void del_last()
{
    stu *p = head;
    if (tail == NULL)
    {
        cout << "Nothing Found";
    }
    else
    {
        if (head == tail)
        {
            p = head;
            delete p;
            head = tail = NULL;
        }
        else
        {
            while (p->next->next != NULL)
            {
                p = p->next;
            }
            p->next = NULL;
            tail = p;
        }
    }
}

void del_specific(int key)
{
    stu *p = searchR(key);
}

void reverse_display()
{
    stu *s = head;
    stu *e = tail;
    while (e != head)
    {
        while (s->next != e)
        {
            s = s->next;
        }
        cout << e->id;
        e = s;
        s = head;
    }
    cout << e->id;
}

void reverse()
{
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    stu *headTemp = head;
    stu *temp = head;
    stu *prev = nullptr;
    stu *tailTemp = tail;
    while (head != tailTemp)
    {
        while (temp != tailTemp)
        {
            prev = temp;
            temp = temp->next;
        }
        temp->next = prev;
        tailTemp = prev;
        prev = head;
        temp = head;
    }
    head = tail;
    tail = headTemp;
    tail->next = NULL;

    stu *p = head;
    while (p != NULL)
    {
        cout << p->id << "->";
        p = p->next;
    }
}

void remove_duplicates(stu* head)
{
    stu *p1 = head;
    stu *p2 = NULL;
    while (p1->next != tail)
    {
        p2 = p1;
        while (p2->next != tail)
        {
            if (p2->next->id == p1->id)
            {
                p2->next = p2->next->next;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    return;
}

bool detect_loop(stu *head) {
    stu *fast = head;
    stu *slow = head;
    while (fast != nullptr || fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

int main()
{
    bool shouldRun = true;
    while (shouldRun)
    {
        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Display" << endl;
        cout << "3. Reverse Display" << endl;
        cout << "4. Reverse List" << endl;
        cout << "5. Exit" << endl;

        int input;
        cin >> input;

        switch (input)
        {
        case 1:
            int id;
            cout << "Enter id: ";
            cin >> id;
            insert(id);
            break;

        case 2:
            display();
            break;

        case 3:
            reverse_display();
            cout << "NULL" << endl;
            break;

        case 4:
            reverse();
            break;

        case 5:
            shouldRun = false;
            break;

        default:
            break;
        }
    }
}