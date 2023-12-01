#ifndef MYDATA_H
#define MYDATA_H

#include<vector>
#include "I.h"

class My_data : I
{
protected:
	std::vector<int> m_data;
public:

    My_data():m_data({}) {};

    My_data(std::initializer_list<int> a):m_data(a) {};

    void push(int a);
};

#endif
