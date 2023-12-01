#ifndef STACK_H
#define STACK_H

#include "I.h"

class Stack : I
{
protected:
    std::vector<int> m_data;

public:
    Stack(): m_data({})
    {};

    Stack(std::initializer_list<int> a):m_data(a) {};

    virtual void push(int a);

    virtual int pop();

    ~Stack(){};
};


#endif
