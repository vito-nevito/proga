#ifndef STACK_H
#define STACK_H

#include<vector>

class Stack
{
protected:
    std::vector<int> m_data;
public:
    Stack();

    virtual void push(int a);

    virtual int pop();

    ~Stack() {};
};

#endif

