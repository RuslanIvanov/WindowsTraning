
using namespace std;
//#include "Header.h"
#include "threadsafe_stack.h"
unsigned short threadsafe_stack::countReads;
threadsafe_stack::threadsafe_stack(const threadsafe_stack& r)
{

}

threadsafe_stack::threadsafe_stack(threadsafe_stack&&)
{
}

threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack&& st)
{
	if (this == &st) { return *this; }
	return *this;
}

threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack& st)
{
	if (this == &st) { return *this; }
	return *this;
}

void threadsafe_stack::push(int val)
{//��������� ������� �� ����.
	m_mut.lock();
	std::cout << "\n push";
	m_v.push_back(val);
	m_mut.unlock();
}

int threadsafe_stack::top() const
{//������ � �������� �������� (�������� ����� ��� ������ )
	int r=int();
	
	m_mut.lock_shared();
	std::cout << "\n top";
	if (m_v.size())
	{
		r = m_v[0];

		countReads++;
		std::cout << "\n top["<<countReads<<"] = "<< r ;
	}
	else
	{
		m_mut.unlock_shared();
		throw "top: stack is empty";
	}
	m_mut.unlock_shared();

	return r;
}

void threadsafe_stack::pop(int &r) 
{//������� ������� �������. (� ������� ���-�� ����, - ���� �� ���������(���������)= �������� ������� ���������)
	m_mut.lock_shared();
	//m_mut.lock();
	std::cout << "\n pop";
	if (m_v.size())
	{
		r = m_v[0];
		if (countReads == 1)
		{
			m_v.erase(m_v.begin());
			countReads = 0;
			std::cout << "\n pop erase ";
		}

		if (countReads > 0)
		{
			std::cout << "\n pop wait.."<< countReads;
			countReads--;
		}
	}
	else
	{
		//m_mut.unlock();
		m_mut.unlock_shared();
		throw "pop: stack is empty";
	}
	m_mut.unlock_shared();
	//m_mut.unlock();
}
bool threadsafe_stack::empty() 
{
	m_mut.lock_shared();
	size_t size = m_v.size();
	m_mut.unlock_shared();
	//� ���� ������ ����� ���������� m_v.size(); � ������ ������
	return (size == 0) ? true : false;
}

size_t threadsafe_stack::size()
{
	m_mut.lock_shared();
	size_t size = m_v.size();
	m_mut.unlock_shared();

	return size;
}

void funThread(threadsafe_stack& s)
{
	if (!s.empty())
	{
		auto res = s.top();
		auto res2 = res;
		s.pop(res2);
		std::cout <<"\nidTh = "<<this_thread::get_id() <<" res = " <<res;
	}

}