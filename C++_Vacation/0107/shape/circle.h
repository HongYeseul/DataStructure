#ifndef __CIRCLE_H__
#define __CIRCLE_H__
#include <iostream>
using namespace std;
#include "shape.h"
class circle : public shape{
    protected:
        void draw() { cout << "DRAW circle" << endl;}
};
#endif
