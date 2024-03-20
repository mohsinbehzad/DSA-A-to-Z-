#include <iostream>
using namespace std;

struct Node
{
    int id;
    Node *next = NULL;
};
Node *head = NULL;
Node *tail = NULL;

Node* insertNew() {
    Node *curr = new Node();
    cout<<"Enter id: ";
    cin>>curr->id;
    if (head == NULL) {
        head = curr;
        tail = head;
    }
    else {
        tail->next = curr;
        tail = curr;
    }
    return curr;
}

Node *remK (Node *head, int k) {
    if (head == NULL) {
        return head;
    }
    if (k == 1){
        Node *temp = head;
        head = temp->next;
        free(temp);
        return head; 
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;

    while(temp != NULL) {
        cnt ++;
        if(cnt == k) {
            prev->next = prev -> next -> next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *removeId(Node *head, int id) {
    if(head == NULL) {
        return head;
    }
    if(id==head->id) {
        Node *temp = head;
        head = temp->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;

    while(head!=NULL) {
        if(temp->id==id) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

void print (Node* head) {
    while(head!=NULL) {
        cout<<head->id << " ";
        head=head->next;
    }
    cout<<endl;
} 

int main()
{
    insertNew();
    insertNew();
    insertNew();
    print(head);
    remK(head, 2);
    print(head);
    removeId(head,5);
    print(head);
}