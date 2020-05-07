
using namespace std;
//#include "Header.h"
#include "threadsafe_stack.h"

threadsafe_stack::threadsafe_stack(const threadsafe_stack& r)
{

}

threadsafe_stack::threadsafe_stack(threadsafe_stack&&)
{
}

threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack&& st)
{
}
threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack& st)
{
}

void threadsafe_stack::push(int val)
{//Вставляет элемент на верх.
	m_mut.lock();
	m_v.push_back(val);
	m_mut.unlock();
}

void threadsafe_stack::top(int& r) const
{//Доступ к верхнему элементу 
	m_mut.lock_shared();

	m_mut.unlock_shared();
}

void threadsafe_stack::pop(int& r) const
{//Удаляет верхний элемент. 
	m_mut.lock_shared();
	if (m_v.size())
	{
		val = data_[0];
		data_.erase(data_.begin() + 0);
		return true;
	}
	return false;
	m_mut.unlock_shared();
}
bool threadsafe_stack::empty() {}
size_t threadsafe_stack::size() {}