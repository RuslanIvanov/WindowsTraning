#include "Oct.h"
#include <iostream>
//Oct::Oct() {}

void Oct::Show() 
{
	std::cout << "\nin Oct: ";
	std::cout<< static_cast<int>(m_oct1) << static_cast<int>(m_oct0);

	//std::cout << "\n";
	//printf("%d,%d", m_oct1, m_oct0);
}

void Oct::ShowPos(int pos)
{//switch
	if (pos == 0) { std::cout << "\nOct 1->" << static_cast<int>(m_oct0); }
	else if (pos == 1) { std::cout << "\nOct 2->" << static_cast<int>(m_oct1); }
	else { std::cout << "\nerror Oct pos: " << pos; }
}

void Oct::Edit(int pos, int val)
{
	if (pos == 0) { m_oct0 = val; }
	else if (pos == 1) { m_oct1 = val; }
	else { std::cout << "\nerror Oct pos: " << pos; }
}
