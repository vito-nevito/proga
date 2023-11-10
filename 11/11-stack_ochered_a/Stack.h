#ifndef STACK_H
#define STACK_H

#include "My_data.h"

class Stack : My_data
{
public:
    virtual void push(int a);

    virtual int pop();
};


#endif

