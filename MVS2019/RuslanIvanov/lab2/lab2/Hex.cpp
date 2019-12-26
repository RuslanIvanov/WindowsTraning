#include "Hex.h"
#include <iostream>
//Hex::Hex() {}
void Hex::Show()
{
	std::cout << "\nin Hex: ";
	std::cout<< m_hex1 << m_hex0;//???
	//std::cout << "\n";
	//printf("%d,%d", m_hex1, m_hex0);
}
void Hex::ShowPos(int pos)
{
	if (pos == 2) { std::cout << "\n1->" << m_hex0; }
	else if (pos == 1) { std::cout << "\n2->" << m_hex1; }
		else { std::cout << "\nerror Hex pos: " << pos; }
}

void Hex::Edit(int pos, int val)
{
	if (pos == 1) { m_hex0 = val; }
	else if (pos == 2) { m_hex1 = val; }
		else { std::cout << "\nerror Hex  pos: " << pos; }
}
