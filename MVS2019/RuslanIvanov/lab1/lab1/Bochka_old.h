
#pragma once

class Bochka 
{
	float m_V;// � %
	float m_Vcup;
	float m_spirt; // � %
public:
	
	Bochka(float,float);
	~Bochka();
	void Pereliv(Bochka&);
	int getPercent();
	void printV();
};
