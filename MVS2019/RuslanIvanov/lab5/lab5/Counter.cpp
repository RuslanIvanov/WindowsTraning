#include <string.h>
#include "Counter.h"
Counter::Counter(const char* str) :m_nOwners(1)
{
	size_t n = strlen(str) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr,str);
}

Counter::~Counter() { delete[] m_pStr; }

void Counter::AddUser()
{
	m_nOwners++;
}

void Counter::RemoveUser()
{
	m_nOwners--;
	if (m_nOwners == 0)
	{
		delete this;
	}
}