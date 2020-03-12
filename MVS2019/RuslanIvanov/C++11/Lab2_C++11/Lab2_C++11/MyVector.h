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
		MyVector() = default;
		void applyList(T up, T down, std::initializer_list<T>);
		void deleteList(T up, T down) ;
		void printVect();
};

//template<typename T>
//MyVector<T>::MyVector()
//{
//}

template<typename T>
MyVector<T>::MyVector(T up, T down, std::initializer_list<T> list)
{// если значения такие в векторе есть, то не всавлять
	//prev,next

	if (down > up) 
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
		if((up>= element && down <= element ) && std::find(m_v.begin(), m_v.end(), list) != m_v.end())
		{
			m_v.push_back( element );
		}
	}
}

template<typename T>
void MyVector<T>::applyList(T up, T down, std::initializer_list<T> list)
{// если такие значения есть в векторе, то не вставлять, еслитакие значения повторябтся в списке иниици- то же не вставлять
//prev,next
	m_v.insert(m_v.end(), list);
}


template<typename T>
void MyVector<T>::deleteList(T up, T down )
{
	//сдвинуть итераторы на значения up и down
	//iterator erase(iterator first, iterator last);
}

template<typename T>
void  MyVector<T>::printVect()
{
	std::cout <<"\nMyVector is:";

	if (m_v.empty())
	{
		std::cout << " EMPTY! "; return;
	}

	for (std::vector<T>::iterator /*auto*/ i = m_v.begin(); i != m_v.end(); ++i)
	{
		std::cout << *i << " ";
	}
}
