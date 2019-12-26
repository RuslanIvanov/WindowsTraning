#pragma once
#include <iostream>
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"

union MyBytes
{
	//спецификатор доступа- public, так как встроеный член Bin не имеет контср
	Bin m_bin;
	Hex m_hex;
	Oct m_oct;
private:
	unsigned char m_dec;
public :
	
	MyBytes(unsigned char byte) { m_dec = byte; } //конструктор // m_dec и m_bin..m_hex - занимают одноместо в пам€ти

	void ShowBin() { m_bin.Show(); }
	//..
	void ShowHex() { m_hex.Show(); }
	void ShowDec() { std::cout<<"DEC: "<<m_dec; }
	void ShowChar()
	{
		if ((m_dec >= 'A' && m_dec <= 'Z') || (m_dec >= 'a' && m_dec <= 'z'))
		{
			std::cout << "\nchar is: " << static_cast<char>(m_dec);
		}
	}
	void ShowOct() { m_oct.Show(); }

	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	void ShowHexPos(int pos) { m_hex.ShowPos(pos); }
	void ShowOctPos(int pos) { m_oct.ShowPos(pos); }
	//Е
	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	//Е
};