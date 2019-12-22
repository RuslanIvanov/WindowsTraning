
#pragma once

class Bochka 
{
	float m_V;// â %
	float m_Vcup;
	float m_spirt; // â %
public:
	
	Bochka(float,float);
	~Bochka();
	void Pereliv(Bochka&);
	int getPercent();
	void printV();
};
