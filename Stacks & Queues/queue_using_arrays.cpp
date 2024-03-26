#include<iostream>
using namespace std;

class Que {
    public:
    int *q;
    int size;
    int front;
    int rear;

    Que () {
        size = 10;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    Que (int size) {
        this->size = size;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x) {
        if(is_full()) {
            cout<<"No Space";
        }
        else{
            if(front == -1){
                front = rear = 0;
            }
            else{
                rear++;
            }
            q[rear]=x;
        }
    }

    int dequeue() {
        if(is_empty()) {
            cout<<"Queue is empty";
            return -1;
        }
        else {
            return q[front++];
        }
    }

    bool is_full() {
        if(rear == size-1) {
            return true;
        }
        else 
            return false;
    }

    bool is_empty() {
        if(rear == -1) {
            return true;
        }
        else    
            return false;
    }

    void display(){
        for(int i = front; i<=rear; i++){
            cout<<q[i]<<"->";
        }
        cout<<"end"<<endl;
    }
};

int main() {
    Que q, q2(5);
    q2.enqueue(8);
    q2.enqueue(5);
    q2.enqueue(4);
    q2.enqueue(23);
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.display();

}