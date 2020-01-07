#ifndef __LINE_H__
#define __LINE_H__
#include "shape.h"
#include <iostream>
using namespace std;
class line : public shape{
    protected:
        void draw(){ cout << "DRAW line" << endl; }
};
#endif
