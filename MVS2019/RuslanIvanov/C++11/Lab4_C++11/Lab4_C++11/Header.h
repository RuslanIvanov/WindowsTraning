#pragma once

template <typename TT>
TT VALIDATE(TT tt)
{
	if constexpr (std::is_pointer<TT>::value)
		return *tt;
	else return tt;
}

template <typename T>
void PRINTF(const T& t) 
{
	std::cout << "\nPRINTF:\n";
	for (auto it = std::begin(t); it != std::end(t); ++it)
	{
		std::cout << "," << VALIDATE(*it) << " ";
	/*	if constexpr (std::is_pointer<T&>::value)
		{
			std::cout << "." << **it << " ";
		}
		else 
		{
		std::cout << "," << *it << " ";
		}*/
	}

	

}