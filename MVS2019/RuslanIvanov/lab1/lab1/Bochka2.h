
#pragma once

class Bochka 
{
	int m_V;// â %
	int m_Vcup;
	int m_spirt; // â %
	int m_water;

public:
	
	Bochka(int,int);
	~Bochka();
	void Pereliv(Bochka&);
	int getPercent();
	void printV();
};
