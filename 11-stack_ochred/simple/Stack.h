#ifndef STACK_H
#define STACK_H

#include<vector>

class Stack
{
private:
    std::vector<int> m_data;
public:
    Stack(): m_data({}) {};

    Stack(std::initializer_list<int> a):m_data(a) {};

    void push(int a);

    int pop();

    ~Stack() {};
};

#endif

