#include <iostream>
using namespace std;

class Circle{
    int radius;
    int *p;
    public:
    Circle(){ p=NULL ; cout << "Constr.\n"; radius = 10;}
    Circle(int radius){
        p=NULL ; cout << "Constr.\n"; this->radius = radius;
    }
    ~Circle(){
        cout << "Destructor\n";
        if(p!=NULL)
        {
            delete p;
            cout <<"p deleted\n";
        }
    }
    int getRadius() {return radius;}
    void testAlloc(){p = new int(10);}
};
void testFunc(Circle c){ cout << "testFunc1 " << c.getRadius()<< endl;}

int main(){
    Circle c3(30);
    Circle c;
    c3.testAlloc();
    testFunc(c3);
    return 0;
}
