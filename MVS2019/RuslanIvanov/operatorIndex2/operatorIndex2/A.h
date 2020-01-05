#pragma once
class A
{
	double m_a[256];
	int m_size;
public:
	A(double a = 0.0,int size = 10);

	double& operator[](int);
};

