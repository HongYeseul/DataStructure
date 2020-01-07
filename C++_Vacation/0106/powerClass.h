#ifndef __POWER_H__
#define __POWER_H__

class Power{
    int kick;
    int punch;
    public:
    Power();
    Power(int k, int p);
    Power operator+(Power op2);
    void print();
};

#endif
