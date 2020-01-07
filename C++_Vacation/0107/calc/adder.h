#include "calc.h"
class Adder : public calc{
    protected:
        virtual int CALC(int a, int b){
            return a+b;
        }
};

class subtractor : public calc{
    protected:
        virtual int CALC(int a, int b){
            return a-b;
        }
};
