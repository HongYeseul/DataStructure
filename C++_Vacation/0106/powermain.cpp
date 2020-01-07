#include <iostream>
using namespace std;
#include "powerClass.h"

int main(){
    Power a(1,5);
    Power b(2,3);
    Power c = a+b;
    c.print();
    return 0;
}
