#ifndef MYDATA_H
#define MYDATA_H

#include<vector>
#include "I.h"

class My_data : I
{
protected:
	std::vector<int> m_data;
public:
    void push(int a);
};

#endif
