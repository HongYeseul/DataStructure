#ifndef __STACK_H__
#define __STACK_H__
class MyStack{
    private:
        int top = -1;
        int *arr;
    public:
        MyStack();
        MyStack(int n);
        void push(int item);
        int pop();
        void print();
        ~MyStack();
};
#endif
