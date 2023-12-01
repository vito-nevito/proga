#ifndef STACK_H
#define STACK_H

#include "My_data.h"
#include "Elem.h"

class Stack : My_data
{
protected:
    Elem* m_Top;

public:
    Stack():m_Top(NULL){};

    virtual void push(int a);

    virtual int pop();

    ~Stack() {};
};


#endif
