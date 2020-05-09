
using namespace std;
//#include "Header.h"
#include "threadsafe_stack.h"
mutex mut_sinx_out;

threadsafe_stack::threadsafe_stack(const threadsafe_stack& r)
{
	//mut
	r.sh_lock();
	for (size_t i = 0; i < r.m_v.size(); i++)
	{		
		m_v.push_back(r.m_v[i]);		
	}
	r.sh_unlock();
}

threadsafe_stack::threadsafe_stack(threadsafe_stack&& r)
{
	r.lock();
	std::copy(std::make_move_iterator(r.m_v.begin()), std::make_move_iterator(r.m_v.end()), std::back_inserter(m_v));
	r.m_v.clear();
	r.unlock();
}

threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack&& r)
{
	if (this == &r) { return *this; }

	std::lock(m_mut, r.m_mut);

	m_v.clear();

	std::copy(std::make_move_iterator(r.m_v.begin()), std::make_move_iterator(r.m_v.end()), std::back_inserter(m_v));
	r.m_v.clear();

	r.m_mut.unlock();
	m_mut.unlock();

	return *this;
}

threadsafe_stack& threadsafe_stack::operator=(threadsafe_stack& r)
{
	if (this == &r) { return *this; }

	std::lock(m_mut, r.m_mut);//для борьбы с deadlock

	m_v.clear();

	std::copy(r.m_v.begin(), r.m_v.end(), std::back_inserter(m_v));
	
	r.m_mut.unlock();
	m_mut.unlock();

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
	//читать можно всем, если нет модификации
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
	//m_mut.lock_shared(); 
	m_mut.lock();// так как удалять будем => эксклюзивно
	if (m_v.size())
	{
		r = m_v[0];

		m_v.erase(m_v.begin());
	}
	else
	{
		m_mut.unlock();
		//m_mut.unlock_shared();
		throw "exception pop: stack is empty";
	}
//	m_mut.unlock_shared();
	m_mut.unlock();
}
bool threadsafe_stack::empty() const
{
	m_mut.lock_shared();
	size_t size = m_v.size();
	m_mut.unlock_shared();
	//в этот момент может поменяться m_v.size(); в другом потоке
	return (size == 0) ? true : false;
}

size_t threadsafe_stack::size() const
{
	//m_mut.lock_shared();
	//size_t size = m_v.size();
	//m_mut.unlock_shared();

	//return size;
	// альтернатива:
	std::shared_lock lock(m_mut);
	return m_v.size();
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