#include<iostream>
#include <vector>
using namespace std;

struct Node
{
    int id;
    Node* next = NULL;

    public:
    Node(int id) {
        this->id = id;
        Node* next = nullptr;
    }
};

Node* arr2LL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int length(Node* head) {
    int cntr = 0;
    Node* temp = head;
    while(temp){
        // cout<<temp->id;
        temp = temp->next;
        cntr++;
    }

    return cntr;
}

int main() {
    vector<int> arr = {3,1,9,4,20};
    Node* head = arr2LL(arr);
    cout<< length(head);
}