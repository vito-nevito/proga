#ifndef OCHERED_H
#define OCHERED_H

#include<vector>

class Ochered
{
private:
    std::vector<int> m_data;
public:
    Ochered(): m_data({})
    {};

    Ochered(std::initializer_list<int> a):m_data(a)
    {};

    void push(int a);

    int pop();

    ~Ochered() {};
};

#endif

