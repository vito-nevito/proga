#ifndef OCHERED_H
#define OCHERED_H

#include "My_data.h"

class Ochered : public My_data
{
public:

    Ochered():My_data() {};

    Ochered(std::initializer_list<int> a):My_data(a) {};

    int pop();

    ~Ochered(){};
};

#endif
