#include "A.h"
#include <iostream>
A::A(double a,int size)
{
	if (size <= 256)
	{
		m_size = size;
	}
	else m_size = 256;

	for (int i = 0; i < m_size; i++)
	{
		m_a[i] = 0;
	}
}

double& A::operator[](int i)
{
	if(i >= 0 && i < m_size ) 
	{
		return m_a[i];
	}
	else 
	{ 		
		_ASSERT_EXPR(false, L"error array index");
	}
};