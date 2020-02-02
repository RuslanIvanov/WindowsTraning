#pragma once

struct ErrorStack
{
	size_t m_n;
	size_t m_i;

	ErrorStack(size_t i, size_t n) 
	{
		m_n = n;
		m_i = i;
	}

};


template <typename T, size_t m_n = 0> class MyStack
{	
	//static const size_t m_n=10;
	T m_p[m_n];

	//size_t m_countElem;
	size_t m_index;// ��� �������� � ������ �� m_n

public:

	MyStack()
	{
		m_index = 0;
		//m_countElem = 0;
		for (size_t  i=0; i < m_n; i++)
		{
			m_p[i] = T();
		}

	}

	~MyStack()
	{	//������� �������������� ������������ � �� T(), ������� � ������ => m_n
		for (size_t i = 0; i < m_n; i++)
			m_p[i].~T();
	}

	T operator[](size_t i) const//��� ����� ������ ����t�
	{
		if (i < m_index) // ������ ������� �������
		{

			return m_p[i];
		}
		else throw ErrorStack(i, m_n);// throw std::out_of_range;
	}

	T & operator[](size_t i) //��� ����� -> ������ ������ �� ������� ��� ���� ������� ����� �������������
	{
		if (i < m_n && i < m_index)
		{
			return m_p[i];
		}
		else throw ErrorStack(i, m_n);// throw std::out_of_range;
		
	}

	//T& operator[](size_t i) //��� ����� _ ��������� �� �������, �� ����� ����, �� ���� �����, �� ���� ����� �������. �� �������
	//{
	//	if (i < m_n)
	//	{
	//		if (i >= m_index)
	//		{
	//			m_index++;
	//			if (m_index > m_countElem)
	//				m_countElem = m_index;// ���� ������, ��� ���� �� �����, ���� i  ������ �� 2 � ����� �� m_index, 
	//										//�� � ����������� ����� ���������� ��������
	//		}
	//		return m_p[i];
	//	}
	//	else throw ErrorStack(i, m_n);// throw std::out_of_range;
	//	
	//}

	void push(const T& p) // ���������
	{		
		if (m_index < m_n)
		{
			m_p[m_index] = p;
			 
			m_index++;

			//if(m_index > m_countElem)
			//	m_countElem = m_index;//��� �� ������ ��� �������, ���� ������ �������� �������� � ��� ����
		}
		else 
		{
			m_index = m_n;
		//	m_countElem = m_n;
			throw "\nError push";
		}
	}

	T pop() // �����������
	{
		
		if (m_index > 0 && m_index <= m_n)
		{
			m_index--;
			return  m_p[m_index];
		}
		else
		{
			throw "\nError pop";
		}

	}

	bool empty() { return (m_index == 0);  }
	size_t size() { return m_index; }// ���������� ��������� � ����������
};
