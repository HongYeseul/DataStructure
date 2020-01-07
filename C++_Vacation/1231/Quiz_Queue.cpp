#include <iostream>
#include "MyQueue.h"
using namespace std;

MyQueue :: MyQueue(){
    cout << "사이즈 없음" << endl;
}

MyQueue :: MyQueue(int n){
    this->n = n;
    arr = new int [n];
    cout << "Size " << n << " Queue" << endl;
}

void MyQueue :: enqueue(int item){
    if(top == front){
        cout << "꽉 참! 넣을 수 없음" << endl;
        return;
    }
    arr[(top++)%n] = item;
}

int MyQueue :: dequeue(){
    if(top == front+1){
        cout << "EMPTY!" << endl;
        return -1;
    }
    return arr[(++front)%n];
}

void MyQueue :: print(){
    for(int i= (front+1)%n; i<top ; i = (i+1)%n )
        cout << arr[i] << ' ';
    cout << endl;
}

MyQueue :: ~MyQueue(){
    cout << "DELETE QUEUE" << endl;
    delete []arr;
}
