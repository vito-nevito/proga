#include<iostream>
#include<assert.h>
#include<algorithm>
#include "CRational.h"

int CRational::getN()
{
    return m_num;
}

int CRational::getD()
{
    return m_den;
}

CRational::CRational(int a, int b)
{
    if(b == 0)
    {
        std::cout << "you tupoi" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    int c = std::__gcd(a, b);
    m_num = a/c;
    m_den = b/c;
}

CRational::CRational(float a)
{
    float eps = 0.000001;
    int denom = 1.0/eps;
	int num = a*denom;
	int gcd = std::__gcd(num, denom);
	m_num = num/gcd;
    m_den = denom/gcd;
}

CRational const operator +(CRational& c1, CRational& c2)
{
    int num = c1.getN() * c2.getD() + c2.getN() * c1.getD();
    int den = c1.getD() * c2.getD();
    return CRational(num, den);
}

CRational const operator *(CRational& c1, CRational& c2)
{
    int num = c1.getN() * c2.getN();
    int den = c1.getD() * c2.getD();
    return CRational(num, den);
}

CRational const operator -(CRational& c1, CRational& c2)
{
    int num = c1.getN() * c2.getD() - c2.getN() * c1.getD();
    int den = c1.getD() * c2.getD();
    return CRational(num, den);
}

void CRational::print()
{
    if(m_den == 1)
        std::cout << m_num;
    else
        std::cout << m_num << "/" << m_den;
}

