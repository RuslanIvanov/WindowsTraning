#include "ClassA.h"

size_t ClassA::m_count;
thread_local size_t ClassA::m_countInTh = 0;
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
	//m_count--;
}

size_t funcMakeA(const std::string nameTh, unsigned int id)
{
	
	ClassA::setZero();// желательно нулить thread_local при быстрых исп_ии ф_ий потока
	
	size_t idTh = id;
	//size_t nObj_old = ClassA::getCountInTh();
	ClassA a1;
	ClassA* pA = new ClassA();
	thread_local ClassA a2; // 
	static ClassA a3;// единожды
	
	ClassA::lock();
	std::cout << "\nbegin ttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt";
	std::cout << "\n start thread '" << nameTh << "' id = " << id;
	std::cout << "\n objects in threads: " << ClassA::getCount();
	std::cout << "\n thread id = " << id << " objs in this thread  = " <<  ClassA::getCountInTh() /*- nObj_old*/;
	std::cout << "\nttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttttt end";
	ClassA::unlock();

	delete pA;

	return idTh;
}