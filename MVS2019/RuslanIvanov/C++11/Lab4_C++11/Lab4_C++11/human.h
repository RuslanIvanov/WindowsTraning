#pragma once
class human 
{
	bool m_bLive;
	size_t count_childs;
	std::string m_name;
	std::pair<shared_ptr<human>, shared_ptr<human>> parent;
	std::vector<weak_ptr<human>> childs;
public:
	human(std::pair<shared_ptr<human>, shared_ptr<human>> p) 
	{
	}

	human(std::pair<shared_ptr<human>> p)
	{
	}

	human(weak_ptr<human> c)
	{
	}
};