#include "circle.h"
#include "rect.h"
#include "line.h"

int main(){
    shape p;

    p.paint(new circle());
    p.paint(new rect());
    p.paint(new line());
}
