
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
	float getPercent();
	float getSpirt();
	void  setV(float);
	float getV();
	void printV();
};
