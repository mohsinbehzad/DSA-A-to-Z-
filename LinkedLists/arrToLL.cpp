#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;

public:
    Node(int data)
    {
        id = data;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printInReverseReccursive() {
    
}

int main()
{
    vector<int> arr = {3, 2, 5, 7};
    Node *head = convertArr2LL(arr);
    // cout<<head->id;
    Node *temp = head;
    while (temp)
    {
        cout << temp->id << "->";
        temp = temp->next;
    }
}