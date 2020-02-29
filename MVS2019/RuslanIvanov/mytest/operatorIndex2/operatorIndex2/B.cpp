#include "B.h"
#include <iostream>
B::B(double b,int i,int j )
{	
	if (i <= 256) { m_size_i = i; }
	else { m_size_i = 256; }

	if (j <= 256) { m_size_j = j; }
	else { m_size_j = 256;  }

	for (int i = 0; i < m_size_i; i++)
		for (int j = 0; j < m_size_j; j++)
			m_b[i][j] = j;
}

//double& B::operator[](int i)
//{
//	if (i >= 0 && i < m_size_i)
//	{
//		return m_b[i][0];
//	}
//	else
//	{
//		_ASSERT_EXPR(false, L"error index for array ");
//	}
//};

double* B:: operator[](int i) 
{
	
	if (i >= 0 && i < m_size_i)
	{
		return  m_b[i];//  адресс строки
	}
	else
	{
		_ASSERT_EXPR(false, L"error index for const array ");
	}
}

