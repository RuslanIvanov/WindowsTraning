#pragma once
class human 
{
	bool m_bLive;
	static size_t countChilds;
	string m_name;
	//std::pair<shared_ptr<human>, shared_ptr<human>> parent;// у каждого  human есть свои родители
	shared_ptr<human> mother;
	shared_ptr<human> father;
	vector<weak_ptr<human>> childs;//// у каждого  human есть свои дети
public:

	human() = delete;
	human(const human&) = delete;
	human& operator=(const human&) = delete;

	human(const char* c,  bool live = true)
	{
		m_name.append(c);
		m_bLive =  live;
		
	}

	//human(human&& h) {}

	static  shared_ptr<human> child(human&& c, shared_ptr<human>& m, shared_ptr<human>& f)
	{
		//
		auto ptr = make_shared<human>(move(c));

		m->childs.push_back(ptr);
		f->childs.push_back(ptr);

		ptr->mother = ptr;
		ptr->father = ptr;
	  ptr->countChilds++;
		return ptr;

	}

	static  shared_ptr<human> child(const char* ch,shared_ptr<human>& m, shared_ptr<human>& f)
	{
		shared_ptr<human> ptr = make_shared<human>(new string(ch));

		m->childs.push_back(ptr);
		f->childs.push_back(ptr);

		ptr->mother = ptr;
		ptr->father = ptr;
		ptr->countChilds++;
		return ptr;

	}

	const char* getName() { return m_name.c_str(); }
	void setName(const char* str) { m_name.append(str); }

	void printH(ostream& os, size_t count) 
	{
		if(mother)
			mother->printH(os, count - 1);

		os << string(count, '\t') << m_name << '\n';

		if (father)
			father->printH(os,count-1);
	}

	void print(ostream& os) 
	{
		printH(os, countChilds);
	}
};