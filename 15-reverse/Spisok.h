#ifndef SPISOK_H
#define SPISOK_H

#include "I.h"
#include "Elem.h"

class Spisok : I
{
protected:
    Elem* m_Top;

public:
    Spisok():m_Top(NULL){};

    Spisok(std::initializer_list<int> a);

    virtual void push(int a);

    virtual int pop();

    virtual std::vector<int> data();

    virtual bool isEmpty();

    virtual void print();

    ~Spisok() {};
};


#endif
