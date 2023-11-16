#ifndef MYDATA_H
#define MYDATA_H

#include<vector>

class My_data
{
protected:
    std::vector<int> m_data;
public:
    My_data(): m_data({})
    {};

    virtual void push(int a) = 0;

    virtual int pop() = 0;

    ~My_data() {};
};

#endif


