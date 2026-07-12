#include<bits/stdc++.h>
using namespace std;

class stackImpl{
    private:
    int top = -1;
    int stk[10];     // in array size is fixed

    public: 
        stackImpl(){
            top = -1;
        }

    int push(int x){
        if(top >= 10){
            cout<<"Stack is full";
        }
        top++;
        stk[top] = x;
    }

    int size(){
        if(top == -1){
            cout<<"stack is empty";
        }
        else{
            return top+1;
        }
    }

    int topelem(){
        if( top == -1){
            cout<<"stack is empty";
        }else{
            return stk[top];
        }
    }

    void pop(){
        if(top == -1){
            cout<<"stack is already empty";
        }else{
            top--;
        }
    }
    
};

int main(){
        stackImpl stak;   // object creation 

        stak.push(10);
}