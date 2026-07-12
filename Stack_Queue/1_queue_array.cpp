#include<bits/stdc++.h>
using namespace std;

class queues{
    int *arr;
    int front;
    int rear;
    int size;
    public:

    queues(int size){       // constructor
        front = -1;
        rear = -1;
        this->size = size;
        arr = new int[size];
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == size-1;            // return  rear == (front + size - 1) % size;  // for circular queue
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(front == -1){
            front = 0;
        }
        rear++;                 // rear = (rear + 1) % size;   // for circular queue
        arr[rear] = data;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;            // front = (front + 1) % size;   // for circular queue
        if(front > rear){       // Queue has become empty after dequeue
            front = rear = -1;       // reset the queue
        }
    }

    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<arr[front]<<endl;
    }


};

int main(){
    int n;
    cin>>n;
    queues q(n);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peek();
    q.dequeue();
    q.peek();
    return 0;
}