#ifndef CRATIONAL_H
#define CRATIONAL_H

class CRational
{
protected:
    int m_num;
    int m_den;
public:
    CRational(int a, int b);

    CRational(float a);

    void print();

    int getN();

    int getD();

    friend const CRational operator +(CRational& c1, CRational& c2);

    friend const CRational operator -(CRational& c1, CRational& c2);

    friend const CRational operator *(CRational& c1, CRational& c2);
};

#endif
