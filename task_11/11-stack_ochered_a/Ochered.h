#ifndef OCHERED_H
#define OCHERED_H

#include "My_data.h"

class Ochered : My_data
{
protected:
    std::vector<int> m_data;

public:
    Ochered(): m_data({})
    {};

    virtual void push(int a);

    virtual int pop();

    ~Ochered(){};
};

#endif
