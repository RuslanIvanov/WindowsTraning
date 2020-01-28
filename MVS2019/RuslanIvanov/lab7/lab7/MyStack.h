#pragma once
template <typename T> class MyStack
{
	T* m_p;
	size_t m_n;
	size_t m_cap;
	size_t m_index;
	size_t m_size;

public:

	MyStack() 
	{
		m_p = nullptr;
		m_n = 0;
		m_cap = 0;
		m_index = 0;
		m_size=0;
	}

	MyStack(size_t n)
	{
		m_n = n;
		m_cap = n + 10;
		m_index = 0;
		m_size=0;

		m_p = new T[n + m_cap]; //malloc

		for (size_t  i=0; i < n; i++)
		{
			m_p[i] = T();
		}

	}

	~MyStack()
	{		
		delete [] m_p;
	}

	void pop(const T& p) 
	{
		if (m_index < m_n) 
		{
			m_p[m_index] = p;
			m_index++;
		}
	}

	bool push(T& t) 
	{
		if (m_index > m_n)
		{
			t = m_p[m_index];
			m_index--;
			return true;
		}
		else return false;

	}
};
