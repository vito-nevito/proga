#ifndef OCHERED_H
#define OCHERED_H

#include<vector>
#include"Stack.h"

class Ochered : Stack
{
public:

    Ochered(std::initializer_list<int> a):Stack(a){};

    virtual void push(int a);

    virtual int pop();
};

#endif

