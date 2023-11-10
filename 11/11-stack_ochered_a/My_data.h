#ifndef MYDATA_H
#define MYDATA_H

#include<vector>

class My_data
{
protected:
    std::vector<int> m_data;
public:
    My_data();

    virtual void push(int a);

    virtual int pop();

    ~My_data() {};
};

#endif


