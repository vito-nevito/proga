#ifndef MYDATA_H
#define MYDATA_H

#include<vector>

class My_data
{
public:
    virtual void push(int a) = 0;

    virtual int pop() = 0;
};

#endif
