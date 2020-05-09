
using namespace std;
//#include "Header.h"
#include "threadsafe_stack.h"
mutex mut_sinx_out;
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
{//Вставляет элемент на верх.
	m_mut.lock();
	std::cout << "\npush = "<<val;
	m_v.push_back(val);
	m_mut.unlock();
}

int threadsafe_stack::top() const
{//Доступ к верхнему элементу (вычитать может кто угодно )
	int r=int();
	
	m_mut.lock_shared();// будет освобожден когда последний вляделец скажет unlock  в коллективном режиме,  а доступ в эксклюзивном режиме до unlock запрещен
	
	if (m_v.size())
	{
		//std::cout << "\n top";
		r = m_v[0];
	}
	else
	{
		m_mut.unlock_shared();
		throw "exception  top: stack is empty";
	}
	m_mut.unlock_shared();

	return r;
}

void threadsafe_stack::pop(int &r) 
{//Удаляет верхний элемент.
	m_mut.lock_shared();

	if (m_v.size())
	{
		r = m_v[0];

		m_v.erase(m_v.begin());
	}
	else
	{
		//m_mut.unlock();
		m_mut.unlock_shared();
		throw "exception pop: stack is empty";
	}
	m_mut.unlock_shared();
	//m_mut.unlock();
}
bool threadsafe_stack::empty() 
{
	m_mut.lock_shared();
	size_t size = m_v.size();
	m_mut.unlock_shared();
	//в этот момент может поменяться m_v.size(); в другом потоке
	return (size == 0) ? true : false;
}

size_t threadsafe_stack::size()
{
	m_mut.lock_shared();
	size_t size = m_v.size();
	m_mut.unlock_shared();

	return size;
}

void fReaders(threadsafe_stack& s)
{
	if (s.empty()) { std::cout << "\nstack is empty!";  return;  }

	while (s.empty() == false)
	{
		try
		{
			auto resTop = s.top();

			lock_guard<mutex> m(mut_sinx_out);
			std::cout << "\nth[" << this_thread::get_id() << "]" << " resTop = " << resTop;
		}
		catch (const char* e) 
		{
			std::cout << "\n"<<e;
			return;
		}	

		int resPop = 0;

		try
		{
			s.pop(resPop);
			//lock_guard<mutex> m(mut_sinx_out);
			//std::cout << "\nth[" << this_thread::get_id()<<"]" << " resPop = " << resPop;
		}
		catch (const char* e) { std::cout  << "\n"<< e; }
		
	
	}

}

void fWriters(threadsafe_stack& s,int el)
{
		s.push(el);
}