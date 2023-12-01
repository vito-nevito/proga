#ifndef STACK_H
#define STACK_H

#include<vector>

class Stack
{
protected:
    std::vector<int> m_data;
public:
    Stack();

    Stack(std::initializer_list<int> a):m_data(a) {};

    virtual void push(int a);

    virtual int pop();

    ~Stack() {};
};

#endif

