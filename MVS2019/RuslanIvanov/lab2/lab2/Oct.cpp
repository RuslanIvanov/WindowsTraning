#include "Oct.h"
#include <iostream>
//Oct::Oct() {}

void Oct::Show() 
{
	std::cout << "\nin Oct: ";
	std::cout<< m_oct1 << m_oct0;
	//std::cout << "\n";
	//printf("%d,%d", m_oct1, m_oct0);
}

void Oct::ShowPos(int pos)
{
	if (pos == 1) { std::cout << "\nOct 1->" << m_oct0; }
	else if (pos == 2) { std::cout << "\nOct 2->" << m_oct1; }
	else { std::cout << "\nerror Oct pos: " << pos; }
}

void Oct::Edit(int pos, int val)
{
	if (pos == 1) { m_oct0 = val; }
	else if (pos == 2) { m_oct1 = val; }
	else { std::cout << "\nerror Oct pos: " << pos; }
}
