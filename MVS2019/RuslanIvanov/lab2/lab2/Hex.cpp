#include "Hex.h"
#include <iostream>
//Hex::Hex() {}
void Hex::Show()
{
	std::cout << "\nin Hex: ";
	std::cout << std::hex; // ������������� ������ cout �� ��v�� � hex
	//std::cout << m_hex1 << m_hex0;// ���� ��������� � int
	std::cout << static_cast<int>(m_hex1) << static_cast<int>(m_hex0);
	std::cout << std::dec;// ������������� ������ cout �� ��d�� � dec

	//std::cout << "\n";
	//printf("%d,%d", m_hex1, m_hex0);
}
void Hex::ShowPos(int pos)
{
	if (pos == 0) 
	{ 
		std::cout << "\nHex 1->"<< static_cast<int>(m_hex0);
	}
	else if (pos == 1) { std::cout<< "\nHex 2->"<< static_cast<int>(m_hex1); }
		else { std::cout << "\nerror Hex pos: " << pos; }
}

void Hex::Edit(int pos, int val)
{
	if (pos == 0) { m_hex0 = val; }
	else if (pos == 1) { m_hex1 = val; }
		else { std::cout << "\nerror Hex  pos: " << pos; }
}
