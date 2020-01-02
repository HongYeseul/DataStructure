#include <iostream>
using namespace std;

class Circle{
    string name;

    public :
    Circle(string n);
    ~Circle();
};

Circle :: Circle(string n){
    cout << "Make "<< n << endl;
    name = n;
}

Circle :: ~Circle(){
    cout << name << "소멸 !" << endl;
}

Circle globalDonut("전역 변수 1번");
Circle globalPizza("전역 변수 2번");

void f(){
    Circle fDonut("f함수 지역변수 1번");
    Circle fPizza("f함수 지역변수 2번");
}

int main(){
    Circle mainDonut("메인 함수 1번");
    Circle mainPizza("메인 함수 2번");
    f();
    return 0;
}
