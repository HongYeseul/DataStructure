#ifndef __QUEUE__
#define __QUEUE__

class MyQueue{
    private:
        int top = -1;
        int front = -1;
        int *arr;
    public:
        MyQueue();
        MyQueue(int n);
        void enqueue(int item);
        int dequeue();
        void print();
        ~MyQueue();
};

#endif
