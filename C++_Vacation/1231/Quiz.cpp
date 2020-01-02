#include <iostream>
#include "MyStack.h"
using namespace std;
void PrintMenu(){
    cout <<"1. s.push" << endl;
    cout <<"2. s.pop" << endl;
    cout <<"3. s.print" << endl;
    cout <<"4. Quit" << endl;
}
int main(){
    MyStack s(10);
    int input = 0, loop = 1, item=0;

    while(loop){
        PrintMenu();
        cin >> input;
        switch(input){
            case 1 : cin >> item;
                   s.push(item); break;
            case 2 : cout << s.pop() << endl; break;
            case 3 : s.print(); break;
            case 4 : loop = 0; break;
            default : printf("Wrong input... \n");
        }
    }
}
