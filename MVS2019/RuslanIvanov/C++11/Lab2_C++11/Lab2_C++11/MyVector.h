#pragma once
#include <vector>
#include <algorithm>
#include <string.h>
#include <iterator>
#include <utility>
#include <initializer_list>

template<typename T>
class MyVector
{
	std::vector<T> m_v;
	T up = T();
	T down = T();
	public:
		MyVector(T up, T down, std::initializer_list<T>);
		MyVector() = default;// сгененрирцй сам
		void applyList(T up, T down, std::initializer_list<T>);
		bool deleteList(T up, T down, std::initializer_list<T> list ) ;
		void printVect();
		void sort(bool);
};

//template<typename T>
//MyVector<T>::MyVector()
//{
//} т.к = default

template<typename T>
MyVector<T>::MyVector(T up, T down, std::initializer_list<T> list)
{// если значени€ такие в векторе есть, то не всавл€ть
	//prev,next

	if (down < up) 
	{
		T tmp = down;
		down = up;
		up = tmp;
	}
		
	m_v.reserve(list.size());

	/*std::vector<T>::iterator it = m_v.begin()+down;
	std::vector<T>::iterator ite = m_v.end();*/
	for (auto& element : list)
	{
		if (m_v.empty())
		{
			m_v.push_back(element);
		}
		else
		{
			if ((up <= element && down >= element) && (std::find(m_v.begin(), m_v.end(), element) == m_v.end()))
			{
				m_v.push_back(element);
			}
		}
	}
}

template<typename T>
void MyVector<T>::applyList(T up, T down, std::initializer_list<T> list)
{// если такие значени€ есть в векторе, то не вставл€ть, еслитакие значени€ повтор€бтс€ в списке иниици- то же не вставл€ть
//prev,next

	if (down < up)
	{
		T tmp = down;
		down = up;
		up = tmp;
	}

	for (auto& element : list)
	{
		if (m_v.empty())
		{
			m_v.push_back(element);
		}
		else
		{
			if ((up <= element && down >= element) && (std::find(m_v.begin(), m_v.end(), element) == m_v.end()))
			{
				m_v.push_back(element);
			}
		}
	}
}


template<typename T>
bool MyVector<T>::deleteList(T up, T down, std::initializer_list<T> list)
{
	//сдвинуть итераторы на значени€ up и down
	//iterator erase(iterator first, iterator last);
	if (m_v.empty())
	{
		return false;
	}

	if (down < up)
	{
		T tmp = down;
		down = up;
		up = tmp;
	}

	//typename T::iterator 
	typename  std::vector<T>::iterator itb = m_v.begin();
	typename  std::vector<T>::iterator ite = m_v.end();

	for (auto& element : list)
	{
		if ((up <= element && down >= element))
		{
			auto it = std::find(itb, ite, element);
			if (it == m_v.end()) break;

			it = m_v.erase(it);
			if(it!=m_v.end())
			{//удалил
				itb = m_v.begin() ;
				ite = m_v.end();
			}
		}
	}

	return true;
}

template<typename T>
void  MyVector<T>::printVect()
{
	std::cout <<"\nMyVector is:";

	if (m_v.empty())
	{
		std::cout << " EMPTY! "; return;
	}

	/*for (size_t i = 0; i<m_v.size(); ++i)
	{
		std::cout <<m_v[i] << " ";
	}*/

	for (auto& el : m_v) 
	{
		std::cout <<el << " ";
	}
}

template<typename T>
void MyVector<T>::sort(bool b)
{		
	std::sort(m_v.begin(), m_v.end(), [b](auto a, auto b)->bool { return ((b == true) ? a >= b : a < b); });
}
