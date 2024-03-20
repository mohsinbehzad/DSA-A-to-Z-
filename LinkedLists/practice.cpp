#include<iostream>
using namespace std;

struct Node {
    int id;
    Node *next = NULL;
};
Node *first = NULL;
Node *last = NULL;

void insertEnd () {
    // Node *curr;
    // curr = new Node;
    Node *curr = new Node;
    cout<<"Enter Id: ";
    cin>>curr->id;
    if (first == NULL){
        first = last = curr;
    }
    else {
        last->next = curr;
        last = curr;
    }
}

void insertStart() {
    Node * curr = new Node;
    cout<<"Enter ID";
    cin>>curr->id;
    if (first == NULL) {
        first = last = curr;
    }
    else {
    curr->next = first;
    first = curr;
    }   
}

void display() {
    if(first != NULL){
    Node *temp = first;
    while (temp != NULL) {
        cout<<temp->id<<"->";
        temp = temp->next;
    }
    }
    else {
        cout<<"Linked List is Empty";
    }
}

void delFirst() {
    if(first == NULL ) {
        cout<<"Linked List is empty";
    }
    else{
    Node *ptr= first;
    first = first->next;
    delete ptr;
    }
}

void delLast(){
    if(last == NULL) {
        cout<<"nothing found";
    }
    else {
        Node *ptr = first;
        if(ptr==last){
            delete ptr;
        }
        else{
        while(ptr->next!=last){
        ptr = ptr->next;
        }
        last = ptr;
        ptr = ptr->next;
        delete ptr;
        }
    }
}

void search(int key){
    Node *ptr = first;
    while (ptr->id != key && ptr != NULL){
            ptr = ptr->next;
    }
    if(ptr == NULL) {
        cout<<"not found";
    }
    else {
        cout<<"found";
    }
}

Node* searchR(int key) {
    Node *ptr = first;
    while(ptr!=NULL && ptr->id != key) {
        ptr = ptr-> next;
    }
    return ptr;
}

void insertAfter(int key) {
    Node *ptr = searchR(key);
    if(ptr == NULL) {
        cout<<"value does not exist";
    }
    else{
        Node *curr = new Node;
        cout<<"Enter ID: ";
        cin>>curr->id;
        if(ptr==last){
            ptr->next = curr;
            last = curr;
        }
        else{
            curr->next = ptr->next;
            ptr->next = curr;
        }
    }
}

// void insertBefore(int key){
//     Node *ptr = searchR(key);
//     if(ptr!=) 
// }




void delSpecific(int key) {

}

void delAfter(int key) {

}

void delBefore(int key) {

}

void reverse() {

}

Node *removeTail(Node *head) {
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    last = temp;
    return head;
}

Node *removeK(Node *head,int k) {
    if (head == NULL) {
        return head;
    }
    if (k == 1) {
        Node *temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    cnt++;
    while(temp != NULL) {
        if(k==cnt){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }    
    return head;
}

Node *removeEl (Node *head, int el) {
    if(head == NULL) {
        return head;
    }
    if (head->id == el) {
        Node *temp = head;
        head = temp->next;
        delete temp;
    }
    Node *temp = head;
    Node *prev = NULL;
    while(temp->id != NULL) {
        if(temp->id == el) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {

}