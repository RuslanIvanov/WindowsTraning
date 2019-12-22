#include "Bochka2.h"
#include <iostream>

Bochka::Bochka(int water, int spirt)
{//
	m_V = water + spirt;//100.0%
	m_spirt = spirt; 
	m_water = water;
	m_Vcup=1;
}

Bochka::~Bochka()
{}

void Bochka::Pereliv(Bochka& b) 
{
	m_spirt = m_V - m_water;
	m_water += m_Vcup;
	b.m_water-= m_Vcup;
	m_spirt -= m_Vcup;
	b.m_spirt += m_Vcup;
}

int Bochka::getPercent()
{
	return  m_spirt;
}

void Bochka::printV() 
{
	std::cout << "\nspirt = " << m_spirt << "%, water = " << m_water << "%";
}
