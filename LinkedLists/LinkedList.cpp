#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;    
    }
};

void insertAtHead (Node* &head, int d) {
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail (Node* &tail, int d) {
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;    // or tail = temp;
}

void insertAtPosition (Node* &tail, Node* &head, int position, int d) {

    if(position == 1) {
        insertAtHead (head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position-1) {
        temp = temp -> next;
        cnt++;
    }

    if (temp -> next == NULL ) {
        insertAtTail (tail, d);
        return;
    }

    Node* nodeToInsert = new Node (d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void print (Node* &head) {
    Node* temp = head;

    while (temp != NULL) {
        std::cout<<temp -> data << " ";
        temp = temp -> next;
    }
    std::cout<<endl;
}

int main () {
    Node* node1 = new Node(10);
    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    Node* head = node1;
    Node* tail = node1;

    print (head);

    insertAtTail(tail, 12);
    print (head) ;

    insertAtTail(tail, 15);
    print (head);

    insertAtPosition(tail, head, 4 , 22);
    print (head);

    std::cout << "head " << head -> data <<endl;
    std::cout << "tail " << tail -> data <<endl;
    return 0;
}
