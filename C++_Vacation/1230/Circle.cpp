#include <iostream>
using namespace std;

#include "Circle.h"

Circle :: Circle(){
    radius = 10;
    cout << "radius "<< radius;
    cout << " 생성자 실행 " << endl;
}

Circle :: ~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}

Circle :: Circle(int r){
    radius = r;
    cout << "radius" << radius;
    cout << " 생성자 실행 "<< endl;
}

Circle :: Circle(Circle& c){
    this->radius = c.radius;
    cout << "복사 " << this->radius << endl;
}

double Circle :: getArea(){
    return 3.14*radius*radius;
}
