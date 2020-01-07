#include <iostream>
using namespace std;

class calc{
    void input(){
        cout << "enter num * 2 >> " << endl;
        cin >> a >> b;
    }
    protected :
        int a,b;
        virtual int CALC(int a, int b) = 0;
    public:
        void run(){
            input();
            cout << "VALUE : " << CALC(a,b)<< endl;
        }
};
