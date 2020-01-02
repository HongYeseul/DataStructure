#include <iostream>
#include "Queue.h"
using namespace std;

MyQueue :: MyQueue(){
    cout << "사이즈 없음" << endl;
}

MyQueue :: MyQueue(int n){
    arr = new int [n];
    cout << "Size " << n << " Queue" << endl;
}

void MyQueue :: enqueue(int item){
    
}
