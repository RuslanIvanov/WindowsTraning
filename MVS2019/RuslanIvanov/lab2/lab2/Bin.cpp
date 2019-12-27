#include "Bin.h"
#include <iostream>
///Bin::Bin()  {}
void Bin::Show() 
{
	std::cout << "\nin Bin: ";
	std::cout<< m_bin7 << m_bin6 << m_bin5 << m_bin4 << m_bin3 << m_bin2 << m_bin1 << m_bin0;//??? а при обявлении поля unsigned char - вывод не сила???
	//std::cout << "\n";
	//printf("%d,%d,%d,%d,%d,%d,%d,%d", m_bin7, m_bin6, m_bin5, m_bin4, m_bin3, m_bin2, m_bin1, m_bin0);
}
void Bin::ShowPos(int pos)
{
	if (pos == 1) { std::cout << "\nBin 1->" << m_bin0; } else
	if (pos == 2) { std::cout << "\nBin 2->" << m_bin1; } else
	if (pos == 3) { std::cout << "\nBin 3->" << m_bin2; } else
	if (pos == 4) { std::cout << "\nBin 4->" << m_bin3; } else
	if (pos == 5) { std::cout << "\nBin 5->" << m_bin4; } else
	if (pos == 6) { std::cout << "\nBin 6->" << m_bin5; } else
	if (pos == 7) { std::cout << "\nBin 7->" << m_bin6; } else
	if (pos == 8) { std::cout << "\nBin 8->" << m_bin7; } 
	else { std::cout << "\nerror Bin pos: " << pos; }
}

void Bin::Edit(int pos, int val)
{
	if (pos == 1) { m_bin0=val; }
	else
		if (pos == 2) { m_bin1 = val; }
		else
			if (pos == 3) {  m_bin2 = val; }
			else
				if (pos == 4) {  m_bin3 = val; }
				else
					if (pos == 5) { m_bin4 = val; }
					else
						if (pos == 6) { m_bin5 = val; }
						else
							if (pos == 7) {  m_bin6 = val; }
							else
								if (pos == 8) { m_bin7 = val; }
								else { std::cout << "\nerror Bin pos: " << pos; }
}
