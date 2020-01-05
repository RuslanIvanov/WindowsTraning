#pragma once
class B
{
	int m_size_i;
	int m_size_j;
	double m_b[256][256];
	public:
		B(double b = 0.0,int i = 10, int j = 10);
		//double& operator[](int);
		double* operator[](int);

};

