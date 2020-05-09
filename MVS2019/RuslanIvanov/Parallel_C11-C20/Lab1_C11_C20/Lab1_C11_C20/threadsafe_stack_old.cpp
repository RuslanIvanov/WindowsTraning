
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
{//¬ставл€ет элемент на верх.
	m_mut.lock();
	std::cout << "\npush = "<<val;
	m_v.push_back(val);
	m_mut.unlock();
}

int threadsafe_stack::top() const
{//ƒоступ к верхнему элементу (вычитать может кто угодно )
	int r=int();
	
	m_mut.lock_shared();// будет освобожден когда последний вл€делец скажет unlock  в коллективном режиме,  а доступ в эксклюзивном режиме до unlock запрещен
	//std::cout << "\n top";
	if (m_v.size())
	{
		r = m_v[0];

	//	countReads++;
	//	std::cout << "\n top["<<countReads<<"] = "<< r ;
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
{//”дал€ет верхний элемент. (а удалить кто-то один, - один из читателей(последний)= понимать сколько читателей)
	m_mut.lock_shared();

	if (m_v.size())
	{
		r = m_v[0];
	//	if (countReads == 1)
	//	{
			m_v.erase(m_v.begin());
			countReads = 0;
			//std::cout << "\n pop "<<r<<" size after erase  "<< m_v.size();
	//	}

	/*	if (countReads > 0)
		{
			std::cout << "\n pop wait.."<< countReads;
			countReads--;
		}*/
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
	//в этот момент может помен€тьс€ m_v.size(); в другом потоке
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
			std::cout << "\ntop exception: "<<e;
			return;
		}	

		int resPop = 0;

		try
		{
			s.pop(resPop);
			lock_guard<mutex> m(mut_sinx_out);
			std::cout << "\nth[" << this_thread::get_id()<<"]" << " resPop = " << resPop;
		}
		catch (const char* e) { std::cout << e; }
		
	
	}

}

void fWriters(threadsafe_stack& s,int el)
{
		s.push(el);
}