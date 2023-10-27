#ifndef PRAMOUG_H
#define PRAMOUG_H

class Pramoug
{
private:
    double m_x1, m_y1, m_x2, m_y2;
public:

    Pramoug(double x1, double y1, double x2, double y2);

    bool compare(Pramoug& p);

    ~Pramoug(){};
};

#endif

