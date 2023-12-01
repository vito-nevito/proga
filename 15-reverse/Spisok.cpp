#include <assert.h>
#include<iostream>
#include "Spisok.h"

void Spisok::push(int a)
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

int Spisok::pop()
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

Spisok::Spisok(std::initializer_list<int> a):m_Top(NULL)
{
    for(int i : a)
        (*this).push(i);
};
