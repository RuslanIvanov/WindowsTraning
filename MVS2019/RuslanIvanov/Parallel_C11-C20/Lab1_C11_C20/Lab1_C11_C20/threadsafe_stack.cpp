
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

void threadsafe_stack::push(int)
{
	m_mut.lock();

	m_mut.unlock();
}

void threadsafe_stack::top(int& r) const
{
	m_mut.lock_shared();

	m_mut.unlock_shared();
}

void threadsafe_stack::pop(int& r) const
{
	m_mut.lock_shared();

	m_mut.unlock_shared();
}
bool threadsafe_stack::empty() {}
size_t threadsafe_stack::size() {}