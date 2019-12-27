#pragma once
class Oct
{
	unsigned char m_oct0 : 3;// разбиваем число на группы по три
	unsigned char m_oct1 : 3;// 23 -> 010 011
	public:
		//Oct();

		void Set(unsigned char b)
		{
			m_oct0 = b;
			m_oct1 = b;
		}

		void Show();
		void ShowPos(int pos);
		void Edit(int pos, int val);
};

