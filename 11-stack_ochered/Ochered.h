#ifndef OCHERED_H
#define OCHERED_H

#include<vector>

class Ochered : Stack
{
private:
    std::vector<int> m_data;
public:
    Ochered();

    void push(int a);

    int pop();

    ~Ochered() {};
};

#endif

