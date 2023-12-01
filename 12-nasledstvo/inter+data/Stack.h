#ifndef STACK_H
#define STACK_H

#include "My_data.h"

class Stack : public My_data
{
public:
    Stack():My_data() {};

    Stack(std::initializer_list<int> a):My_data(a) {};

    int pop();

    ~Stack(){};
};


#endif
