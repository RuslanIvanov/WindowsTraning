template <typename T, size_t m_n = 10>::
MyStack()
{
	m_index = 0;
	for (size_t i = 0; i < m_n; i++)
	{
		m_p[i] = T();
	}

}