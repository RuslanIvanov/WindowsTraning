#include "ClassA.h"

size_t ClassA::m_count;
thread_local size_t ClassA::m_countInTh;
std::mutex ClassA::m;
ClassA::ClassA()
{
	m_count++;
	m_countInTh++;
	std::stringstream buf;
	buf << "A_";
	buf << m_count;
	/*char buf[80] = "A";
	sprintf_s(buf, 80, "A_%d", m_count);*/
	m_name.append(buf.str());

}

ClassA::~ClassA()
{
	m_count--;
}

size_t funcMakeA(const std::string nameTh, unsigned int id)
{
	
	thread_local size_t idTh = id;

	ClassA a1;
	ClassA* pA = new ClassA();
	thread_local ClassA a2;
	static ClassA a3;

	ClassA::lock();
	std::cout << "\nstart thread '" << nameTh << "' id = " << id;
	std::cout << "\n objects = " << ClassA::getCount();
	std::cout << "\n objects in thread = " << ClassA::getCountInTh();
	ClassA::unlock();

	return idTh;
}