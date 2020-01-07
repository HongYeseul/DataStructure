#include "circle.h"

circle :: circle(){
    
}

circle :: circle(int n){
    this->radius = n;
}

void circle :: set(int n){
    this->radius = n;
}
int circle :: getArea(){
    return this->radius;
}
