#ifndef __RECT_H__
#define __RECT_H__
#include <iostream>
using namespace std;
#include "shape.h"
class rect : public shape{
    protected:
        void draw(){ cout << "DRAW rect "<< endl; }
};
#endif
