#pragma once
#include <iostream>
#include "Bin.h"
#include "Oct.h"
#include "Hex.h"

union MyBytes
{
	//������������ �������- public, ��� ��� ��������� ���� Bin �� ����� ������
	Bin m_bin;
	Hex m_hex;
	Oct m_oct;
private:
	unsigned char m_dec;
public :
	
	MyBytes(unsigned char byte) { m_dec = byte; } //����������� // m_dec � m_bin..m_hex - �������� ��������� � ������

	void ShowBin() { m_bin.Show(); }
	//..
	void ShowHex() { m_hex.Show(); }
	void ShowDec() { std::cout<<"DEC: "<<m_dec; }
	void ShowChar() { /*? ? ?*/ }
	void ShowOct() { m_oct.Show(); }

	void ShowBinPos(int pos) { /*m_bin.ShowPos(pos);*/ }
	//�
	void EditBin(int pos, int val) { /*m_bin.Edit(pos, val);*/ }
	//�
};