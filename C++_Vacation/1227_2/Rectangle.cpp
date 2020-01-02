#include <iostream>
using namespace std;

class Rectangle{
    int width, height;
    
    public:
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int w);
    ~Rectangle();
    
    bool isSquare();
};

Rectangle :: Rectangle() : Rectangle(1,1){}
Rectangle :: Rectangle(int w) : Rectangle(w,w) {}

Rectangle :: Rectangle(int w, int h){
    width = w;
    height = h;
}

Rectangle :: ~Rectangle(){
    cout << width << ", "<< height << " 원 소멸" << endl;
}

bool Rectangle :: isSquare(){
    return width==height;
}

int main(){
    Rectangle rect1;
    Rectangle rect2(3,5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다" << endl;
    if(rect2.isSquare()) cout << "rect2는 정사각형이다" << endl;
    if(rect3.isSquare()) cout << "rect3은 정사각형이다" << endl;
    return 0;
}
