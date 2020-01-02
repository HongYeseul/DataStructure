#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char password[3] = "hi";
    while(true){
        cout << "enter >> ";
        char enter[10];
        cin >> enter;
        if(strcmp(enter, password) == 0)
        {
            cout << "SAME";
            break;
        }
    }
    
}
