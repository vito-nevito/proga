#include <assert.h>
#include<iostream>
#include "Ochered.h"

void Ochered::push(int a)
{
    if(m_BegQ == NULL)
    {
        Elem* p = (Elem *) malloc(sizeof(Elem));
        p->inf = a;
        p->link = NULL;
        m_BegQ = p;
        m_EndQ = p;
    }
    else
    {
        Elem* p = (Elem *) malloc(sizeof(Elem));
        p->inf = a;
        m_EndQ->link = p;
        p->link = NULL;
        m_EndQ = p;
    }
};

int Ochered::pop()
{
    if(m_BegQ == NULL)
    {
        std::cout << "NOOOOOO" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int val;
    val = m_BegQ->inf;
    Elem* p = m_BegQ;
    m_BegQ = p->link;
    free(p);
    return val;
};

