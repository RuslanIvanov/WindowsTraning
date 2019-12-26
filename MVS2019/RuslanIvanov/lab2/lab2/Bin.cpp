#include "Bin.h"
#include <iostream>
///Bin::Bin()  {}
void Bin::Show() 
{
	std::cout << "\nin Bin: ";
	std::cout<< m_bin7 << m_bin6 << m_bin5 << m_bin4 << m_bin3 << m_bin2 << m_bin1 << m_bin0;//??? а при обявлении поля unsigned char - вывод не сила???
	std::cout << "\n";
	printf("%d,%d,%d,%d,%d,%d,%d,%d", m_bin7, m_bin6, m_bin5, m_bin4, m_bin3, m_bin2, m_bin1, m_bin0);
}
void Bin::ShowPos(int pos)
{

}

void Bin::Edit(int pos, int val)
{}
