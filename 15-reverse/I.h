#ifndef I_H
#define I_H

#include<vector>

class I
{
public:
    virtual void push(int a) = 0;

    virtual int pop() = 0;

    virtual int* data() = 0;

    virtual bool isEmpty() = 0;

    virtual void print() = 0;
};

#endif
