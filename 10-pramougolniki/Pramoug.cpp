#include<iostream>
#include "Pramoug.h"

Pramoug::Pramoug(double x1, double y1, double x2, double y2): m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2)
{}

bool Pramoug::Pramoug::compare(Pramoug& p)
{
    if((m_x1 <= p.m_x1 && p.m_x1 <= m_x2) && (m_y1 <= p.m_y1 && p.m_y1 <= m_y2))
        return 1;
    if((m_x1 <= p.m_x2 && p.m_x2 <= m_x2) && (m_y1 <= p.m_y2 && p.m_y2 <= m_y2))
        return 1;
    if((m_x1 <= p.m_x1 && p.m_x1 <= m_x2) && (m_y1 <= p.m_y2 && p.m_y2 <= m_y2))
        return 1;
    if((m_x1 <= p.m_x2 && p.m_x2 <= m_x2) && (m_y1 <= p.m_y1 && p.m_y1 <= m_y2))
        return 1;
    return 0;
}
