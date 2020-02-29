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
	size_t m_index;// кол объектов в екторе до m_n

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
	{	//сколько сконструировал пользователь и по T(), столько и удал€ю => m_n
		for (size_t i = 0; i < m_n; i++)
			m_p[i].~T();
	}

	T operator[](size_t i) const//дл€ стека только читаtь
	{
		if (i < m_index) // только сколько внесено
		{

			return m_p[i];
		}
		else throw ErrorStack(i, m_n);// throw std::out_of_range;
	}

	T & operator[](size_t i) //дл€ стека -> внести только те которые уже были внесены ренее пользователем
	{
		if (i < m_n && i < m_index)
		{
			return m_p[i];
		}
		else throw ErrorStack(i, m_n);// throw std::out_of_range;
		
	}

	//T& operator[](size_t i) //дл€ стека _ вставл€ть по индексу, но будут дыры, но если будут, то дыры будут проиниц. по дефолту
	//{
	//	if (i < m_n)
	//	{
	//		if (i >= m_index)
	//		{
	//			m_index++;
	//			if (m_index > m_countElem)
	//				m_countElem = m_index;// внес больше, чем было до этого, если i  шагнул на 2 и более от m_index, 
	//										//то в промежутках будут дефолтовые значени€
	//		}
	//		return m_p[i];
	//	}
	//	else throw ErrorStack(i, m_n);// throw std::out_of_range;
	//	
	//}

	void push(const T& p) // встав€лть
	{		
		if (m_index < m_n)
		{
			m_p[m_index] = p;
			 
			m_index++;

			//if(m_index > m_countElem)
			//	m_countElem = m_index;//что бы удалит все элемены, если меньше вставили Ёлемнтов в тек стек
		}
		else 
		{
			m_index = m_n;
		//	m_countElem = m_n;
			throw "\nError push";
		}
	}

	T pop() // выталкивать
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
	size_t size() { return m_index; }// количество элементов в контейнере
};
