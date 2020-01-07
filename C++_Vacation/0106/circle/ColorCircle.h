#ifndef __COLOR_H__
#define __COLOR_H__
#include <iostream>
#include <string>
#include "circle.h"
using namespace std;

class ColorCircle : public circle {
    string color;
    public:
    void setColor(string color){ this->color = color; }
    void showColorPoint(){ cout << color << ':' << " radius "<< getArea() << endl;};
};
