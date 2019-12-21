
#pragma once

class Bochka 
{
	int m_V;
	int m_percent;
	int m_cup;
public:
	Bochka();
	~Bochka();
	void Pereliv(Bochka&);
	int getPercent();
	void printV();
};
