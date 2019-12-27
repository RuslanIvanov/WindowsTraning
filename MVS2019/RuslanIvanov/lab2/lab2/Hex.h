#pragma once
class Hex
{
	unsigned char m_hex0 : 4; //// разбиваем число на группы по четыре
	unsigned char m_hex1 : 4; ///23 -> 0010 0011
	
public:
	//Hex();
	void Set(unsigned char b)
	{
		m_hex0 = b;
		m_hex1 = b;
	}
	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);
};

