#pragma once
class Counter
{
	char* m_pStr;
	int m_nOwners;
	Counter* pNextCounter;

	static Counter* Head;
	static unsigned int m_curCounters;


};

