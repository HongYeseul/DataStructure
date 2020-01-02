#include <iostream>
using namespace std;
#include "MyStack.h"
MyStack :: MyStack(){
    cout << "사이즈 없음 " << endl;
}
MyStack :: MyStack(int n){
    cout << "Size " << n << " Stack" << endl;
    arr = new int [n];
}

void MyStack :: push(int item){
    arr[++top] = item;
}

int MyStack :: pop(){
    if(top < 0){
        cout << "내용물 없음" << endl;
        return -1;
    }
    else{
        return arr[top--];
    }
}

void MyStack :: print(){
    for(int i=0; i<= top ; i++){
        cout << arr[i] << ' ' ;
    } cout << endl;
}

MyStack :: ~MyStack(){
    cout << "DELETE" << endl;
    if(top >= 0)
        delete []arr;
}
