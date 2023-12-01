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
}

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
}

Spisok::Spisok(std::initializer_list<int> a):m_Top(NULL)
{
    for(int i : a)
        (*this).push(i);
}

void Spisok::print()
{
    Elem* p = m_Top;
    while(p != NULL)
    {
        std::cout << p -> inf << " ";
        p = p->link;
    }
    std::cout << std::endl;
}

bool Spisok::isEmpty()
{
    if(m_Top == NULL)
        return 1;
    return 0;
}

std::vector<int> Spisok::data()
{
    std::vector<int> res{};
    Elem* p = m_Top;
    while(p != NULL)
    {
        res.push_back( p -> inf);
        p = p->link;
    }
    return res;
}
