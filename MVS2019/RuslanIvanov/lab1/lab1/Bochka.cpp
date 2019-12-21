#include "Bochka.h"
#include <iostream>

Bochka::Bochka()
{
	 m_V = 10;
	 m_percent = 96;
	 m_cup=1;
}

Bochka::~Bochka()
{}

void Bochka::Pereliv(Bochka& b) 
{
	b.m_V = b.m_V - m_cup;
	m_V = m_V + m_cup;
}

int Bochka::getPercent()
{
	return m_percent;
}

void Bochka::printV() 
{
	std::cout << "\nV = " << m_V << ", " << m_percent << "%";
}
