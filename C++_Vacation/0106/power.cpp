#include "powerClass.h"
#include <iostream>
using namespace std;

Power::Power(){
cout << "ERROR" << endl;
} 

Power :: Power(int k, int p){
this->kick = k;
this->punch = p;
}

Power Power :: operator+(Power op2){
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

void Power :: print(){
    cout << this->kick << " " << this->punch << endl;
}
