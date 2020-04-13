#pragma once

template <typename TT>
 auto& VALIDATE(TT& tt) 
{
	if constexpr (std::is_pointer<TT>::value)
	{
		std::cout << "\nis_pointer ";
		return *tt;
	}
	else
	{
		std::cout << "\nno pointer ";
		return tt;
	}
}

template <typename T>
void PRINTF(const T& t) 
{
	std::cout << "\nPRINTF:\n";
	for (auto it = std::begin(t); it != std::end(t); ++it)
	{
		std::cout << "," << VALIDATE(*it) << " ";//OK
	}
	
}

template <typename T>
auto isPointer(const T& t) 
{
	if constexpr (std::is_pointer<T>::value)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
void PRINTF2(const T& t)
{
	std::cout << "\nPRINTF2:\n";

	for (auto it = std::begin(t); it != std::end(t); ++it)
	{

		if constexpr (std::is_pointer<decltype(*it)/*T*/>::value)//??
		//if constexpr (std::is_member_pointer<decltype(*it)>::value)
		//if(isPointer(*it))
		//if constexpr (std::is_pointer<typename T::value_type>::value)
		{
			std::cout << "\npoint2 " << **it << " ";
		}
		else
		{		
			std::cout << "\nno point2 " << (*it) << " ";//???
		}//*/
	}

}

template <typename T,typename TT>
void sumV( T& t,TT tt ) 
{
	if constexpr (std::is_same<T, std::vector<TT>>::value)
	{
		std::cout << "\nsum elements vect on: " << tt;
		for (auto it = std::begin(t);it != std::end(t); ++it) 
		{
			*it += tt;
		}
	}
	else
	{
		std::cout << "\nsum on: " << tt;
		t += tt;
	}
}

template <typename T>
//void PRINT_ADAPT(const T& t) 
void PRINT_ADAPT(T t)
{

	if constexpr (std::is_same<T, std::queue<typename T::value_type>>::value)
	{
		std::cout << "\ncontainer_adapter queue ";
		if constexpr (std::is_pointer<typename T::value_type>::value)
		{
			std::cout << "(pointers): ";
			while (!t.empty())
			{
				std::cout << "," << *t.front()<<" ";
				t.pop();
			}
		}
		else
		{
			std::cout << ":";
		
			while (!t.empty())
			{
				std::cout << "." << t.front() << " ";
				t.pop();
			}
		}
	}

	if constexpr (std::is_same<T, std::priority_queue<typename T::value_type>>::value)
	{
		std::cout << "\ncontainer_adapter priority_queue ";

		if constexpr (std::is_pointer<typename T::value_type>::value)
		{
			std::cout << "(pointer) :";
			while (!t.empty())
			{
				std::cout << "," << *t.top() << " ";
				t.pop();
			}
		}
		else 
		{
			std::cout << ":";
			while (!t.empty())
			{
				std::cout << "." << t.top()<<" ";
				t.pop();
			}
		}
	}

	if constexpr (std::is_same<T, std::stack<typename T::value_type>>::value)
	{
		std::cout << "\ncontainer_adapter stack ";
		if constexpr (std::is_pointer<typename T::value_type>::value)
		{
			std::cout << "(pointer) :";
			while (!t.empty())
			{
				std::cout << "," << *t.top() << " ";
				t.pop();
			}
		}
		else 
		{
			std::cout << ":";
			while (!t.empty())
			{
				std::cout << "," << t.top() << " ";
				t.pop();
			}
		}
	}

	std::cout << "  end\n";
}

class SORT_SET
{
public:
	SORT_SET() {}

	bool operator()(const  std::shared_ptr<string>&  l, const  std::shared_ptr<string>& r) const
	{
		return (*l->begin() < *r->begin());
	}

};

bool cmp(const  std::shared_ptr<string>& l, const  std::shared_ptr<string>& r)
{
	return (*l->begin() < *r->begin());
}

template<typename T,typename U>
struct S { T m_t; U m_u; };

//My deduction guid
template<typename T, typename U> 
S(const T& t, const U& u)->S<T, U>;

template<typename T>
S(const T& t, size_t size)->S<T, size_t>;

template<typename T, size_t size> 
class MyArray
{
	T ar[size] = {T()}; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
	MyArray() = delete;
};