#ifndef STACK_H
#define STACK_H

#include<vector>

class Stack
{
private:
    std::vector<int> m_data;
public:
    Stack();

    void push(int a);

    int pop();

    ~Stack() {};
};

#endif

