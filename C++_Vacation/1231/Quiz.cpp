#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"
using namespace std;
void PrintMenu(){
    cout <<"1. q.enqueue" << endl;
    cout <<"2. q.dequeue" << endl;
    cout <<"3. q.print" << endl;
    cout <<"4. s.push" << endl;
    cout <<"5. s.pop" << endl;
    cout <<"6. s.print" << endl;
    cout <<"7. Quit" << endl;
}
int main(){
    MyStack s(10);
    MyQueue q(10);
    int input = 0, loop = 1, item=0;

    while(loop){
        PrintMenu();
        cin >> input;
        switch(input){
            case 1 : cin >> item;
                   q.enqueue(item); break;
            case 2 : cout << "DeQueue "<< q.dequeue() << endl; break;
            case 3 : q.print(); break;
            case 4 : cin >> item;
                   s.push(item); break;
            case 5 : cout << "Pop " << s.pop() << endl; break;
            case 6 : s.print(); break;
            case 7 : loop = 0; break;
            default : printf("Wrong input... \n");
        }
    }
}
