#pragma once
class Counter
{
	char* m_pStr;
	size_t m_nOwners;
	Counter* pNextCounter;

	static Counter* Head;
	static unsigned int m_curCounters;

	Counter(const char*);
	~Counter();
	void AddUser();
	void RemoveUser();
	friend class MyString2;
};

