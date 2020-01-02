#include <iostream>
using namespace std;

#include "Calc.h"
#include "Adder.h"

void Calculator :: run(){

    cout << "두 수 입력 : ";
    int a,b;
    cin >> a >> b;
    Adder adder(a,b);
    cout << adder.process();
}
