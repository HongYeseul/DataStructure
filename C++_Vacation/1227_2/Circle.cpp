#include <iostream>
using namespace std;

class Circle{
    public:
        int radius;
        Circle();
        Circle(int n);
        double getArea();
};

//Circle :: Circle(){
//    radius = 1;
//    cout << "반지름 " << radius << " 원 생성 " << endl;
//}

Circle :: Circle() : Circle(1) {} //위임 생성자 

Circle :: Circle(int n){
    radius = n;
    cout << "Make radius " << radius << endl;
}

double Circle :: getArea(){
    return radius*radius*3.14;
}

int main(void){
    Circle donut;
    double area = donut.getArea();
    cout << "donut " << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza " << area << endl;
}
