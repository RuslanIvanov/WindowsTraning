#include "Bin.h"
#include <iostream>
///Bin::Bin()  {}
void Bin::Show() 
{
	std::cout << "\nin Bin: ";
	//std::cout<< m_bin7 << m_bin6 << m_bin5 << m_bin4 << m_bin3 << m_bin2 << m_bin1 << m_bin0;//??? а при обявлении поля unsigned char - вывод не чила???
	// надо приводить к int т.к. иначе вывод 0 - как пробела, 1 как символ рожи
	std::cout << static_cast<int> (m_bin7) << static_cast<int>(m_bin6) << static_cast<int>(m_bin5) << static_cast<int>(m_bin4) << static_cast<int>(m_bin3) << static_cast<int>(m_bin2) << static_cast<int>(m_bin1) << static_cast<int>(m_bin0);
	//std::cout << "\n";
	//printf("%d,%d,%d,%d,%d,%d,%d,%d", m_bin7, m_bin6, m_bin5, m_bin4, m_bin3, m_bin2, m_bin1, m_bin0);
}
void Bin::ShowPos(int pos)
{// изменить позици. 0,1,2,...
	switch (pos)
	{
		case 0:
			std::cout << "\nBin 0->" << static_cast<int>(m_bin0);
		break;
		case 1:
			std::cout << "\nBin 1->" << static_cast<int>(m_bin1);
		break;
		case 2:
			std::cout << "\nBin 2->" << static_cast<int>(m_bin2);
			break;
		case 3:
			std::cout << "\nBin 3->" << static_cast<int>(m_bin3);
			break;
		case 4:
			std::cout << "\nBin 4->" << static_cast<int>(m_bin4);
			break;
		case 5:
			std::cout << "\nBin 5->" << static_cast<int>(m_bin5);
			break;
		case 6:
			std::cout << "\nBin 6->" << static_cast<int>(m_bin6);
			break;
		case 7:
			std::cout << "\nBin 7->" << static_cast<int>(m_bin7);
			break;
		default:
			std::cout << "\nerror Bin pos: " << pos;
			break;
	}
}

void Bin::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0: m_bin0 = val;  
		break;
	case 1: m_bin1 = val;  
		break;
	case 2: m_bin2 = val;  
		break;
	case 3: m_bin3 = val;  
		break;
	case 4: m_bin4 = val;  
		break;
	case 5: m_bin5 = val;  
		break;
	case 6: m_bin6 = val;  
		break;
	case 7: m_bin7 = val;  
		break; 
	default: std::cout << "\nerror Bin pos: " << pos;  
		break;
	}
}
