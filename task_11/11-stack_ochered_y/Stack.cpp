#include <assert.h>
#include<iostream>
#include "Stack.h"

void Stack::push(int a)
{
    if(m_Top == NULL)
    {
        Elem* p = (Elem *) malloc(sizeof(Elem));
        p->inf = a;
        p->link = NULL;
        m_Top = p;
    }
    else
    {
        Elem* p = (Elem *) malloc(sizeof(Elem));
        p->inf = a;
        p->link = m_Top;
        m_Top = p;
    }
};

int Stack::pop()
{
    if(m_Top == NULL)
    {
        std::cout << "NOOOOOO" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int val;
    val = m_Top->inf;
    Elem* p = m_Top;
    m_Top = p->link;
    free(p);
    return val;
};
