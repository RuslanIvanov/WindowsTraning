#pragma once

template <typename TT>
 auto& VALIDATE(TT& tt) 
{
	if constexpr (std::is_pointer<TT>::value)
	{
		std::cout << "\nis_pointer";
		return *tt;
	}
	else
	{
		std::cout << "\nno pointer";
		return tt;
	}
}

template <typename T>
void PRINTF(const T& t) 
{
	std::cout << "\nPRINTF:\n";
	for (auto it = std::begin(t); it != std::end(t); ++it)
	{
		std::cout << "," << VALIDATE(*it) << " ";
	}
	
}

template <typename T>
void PRINTF2(const T& t)
{
	std::cout << "\nPRINTF2:\n";

	for (auto it = std::begin(t); it != std::end(t); ++it)
	{

		if constexpr (std::is_pointer<decltype(it)>::value)
		{
			std::cout << "point1 " << *it << " ";
		}
		else
		{
			if  (std::is_pointer<decltype(*it)>::value)
				std::cout << "point2 " << *it << " ";
			else
				std::cout << "no point " << (*it) << " ";//???
		}//*/
	}

}