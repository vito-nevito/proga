#include "My_data.h"

My_data::My_data(): m_data({})
{}

virtual void My_data::push(int a) = 0;

virtual int My_data::pop() = 0;
