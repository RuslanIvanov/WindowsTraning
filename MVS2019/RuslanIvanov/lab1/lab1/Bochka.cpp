#include "Bochka.h"
#include <iostream>

Bochka::Bochka(float water, float spirt)
{//
	m_V = water + spirt;//100.0% -  полный V
	m_spirt = spirt / m_V; // 0.96 или если бочка  с водой то 0
	m_Vcup=1.;
}

Bochka::~Bochka()
{}

void Bochka::Pereliv(Bochka& b) 
{
	m_spirt = ((m_spirt * m_V) + (m_Vcup * b.getSpirt())) / (m_V + m_Vcup);
	m_V += m_Vcup;
	b.setV(b.getV() - m_Vcup);
}

float Bochka::getSpirt() 
{ 
	return m_spirt; 
}

void Bochka::setV( float v ) 
{ 
	m_V = v; 
}

float Bochka::getV() 
{ 
	return m_V; 
}

float Bochka::getPercent()
{
	return  m_spirt * 100;
}

void Bochka::printV() 
{
	std::cout << "\nspirt = " << m_spirt*100 << "%, water = " << m_V - (m_spirt*100) << "%";
}
