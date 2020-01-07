#ifndef __QUEUE_H__
#define __QUEUE_H__
class MyQueue{
    private:
        int top = 0;
        int front = -1;
        int *arr;
        int n;
    public:
        MyQueue();
        MyQueue(int n);
        void enqueue(int item);
        int dequeue();
        void print();
        ~MyQueue();
};
#endif
