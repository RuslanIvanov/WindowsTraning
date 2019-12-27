#pragma once
class Bin
{
	unsigned char m_bin0 : 1;//или bool
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;// это все есть представление 1 байт чила
public:
	//Bin();
	void Set(unsigned char b) 
	{ 
		m_bin0 = b;
		m_bin1 = b;
		m_bin2 = b;
		m_bin3 = b;
		m_bin4 = b;
		m_bin5 = b;
		m_bin6 = b;
		m_bin7 = b;
	}
	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);
};

