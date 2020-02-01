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


template <typename T> class MyStack
{	
	static const size_t m_n=10;
	T m_p[m_n];

	size_t m_index;// кол объектов в екторе до m_n

public:

	MyStack()
	{
		m_index = 0;

		for (size_t  i=0; i < m_n; i++)
		{
			m_p[i] = T();
		}

	}

	~MyStack()
	{	
		for (size_t i = 0; i < m_n; i++)
			m_p[i].~T();
	}

	T& operator[](size_t i) //для стека
	{
		if (i < m_n)
		{
			return m_p[i];
		}
		else throw ErrorStack(i, m_n);// throw std::out_of_range;
		
	}

	void push(const T& p) // вставялть
	{		
		if (m_index < m_n)
		{
			m_p[m_index] = p;
			m_index++;
		}
		else 
		{
			m_index = m_n;
			throw "\nError push";
		}
	}

	T pop() // выталкивать
	{
		
		if (m_index > 0 && m_index <= m_n)
		{
			//T tmp = m_p[m_index];
			m_index--;
			return  m_p[m_index];
		}
		else
		{
			throw "\nError pop";
		}

	}

	bool empty() { return (m_index == 0);  }
	size_t size() { return m_n; }
};
