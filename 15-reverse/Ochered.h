#ifndef OCHERED_H
#define OCHERED_H

#include "I.h"

class Ochered : I
{
protected:
    std::vector<int> m_data;

public:
    Ochered(): m_data({})
    {};

    Ochered(std::initializer_list<int> a):m_data(a)
    {};

    virtual void push(int a);

    virtual int pop();

    virtual std::vector<int> data();

    virtual bool isEmpty();

    virtual void print();

    ~Ochered(){};
};

#endif
