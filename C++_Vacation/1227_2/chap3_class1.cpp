#include <iostream>
using namespace std;

class Circle{
public :
    int radius;
    double getArea();
};

class Rectangle{
public :
    int width;
    int height;
    int getArea();
};

double Circle :: getArea(){
    return 3.14 * radius * radius;
}

int Rectangle :: getArea(){
    return width*height;
}

int main(){
    Circle donut;
    donut.radius = 1;
    double area = donut.getArea();
    cout << "donut " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza " << area << endl;

    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "Rectengle " << rect.getArea() << endl;
}
