#ifndef __SHAPE_H__
#define __SHAPE_H__
#include <iostream>
using namespace std;
class shape{
    protected:
        void draw(){cout <<"DRAW shape" << endl;}
    public:
        void paint(shape *p){ p->draw(); }
};
#endif
