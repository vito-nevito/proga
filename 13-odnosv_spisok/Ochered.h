#ifndef OCHERED_H
#define OCHERED_H

#include "My_data.h"
#include "Elem.h"

class Ochered : My_data
{
protected:
    Elem* m_BegQ;
    Elem* m_EndQ;

public:
    Ochered(): m_BegQ(NULL), m_EndQ(NULL){};

    virtual void push(int a);

    virtual int pop();

    ~Ochered() {};
};

#endif
