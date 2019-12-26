#include "Oct.h"
#include <iostream>
//Oct::Oct() {}

void Oct::Show() 
{
	std::cout << "\nin Oct: ";
	std::cout<< m_oct1 << m_oct0;
	std::cout << "\n";
	printf("%d,%d", m_oct1, m_oct0);
}

void Oct::ShowPos(int pos)
{}

void Oct::Edit(int pos, int val)
{}
