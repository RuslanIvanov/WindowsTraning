#pragma once

template<typename T>
class c_range 
{
	T m_max;
	T m_min;
	T m_value;

	public:

		c_range() { m_max = T(); m_min = T(); m_value = m_min; }
		constexpr c_range(const T min, const T max, const T val=T()):m_max(max), m_min(min), m_value(val) {  }
		constexpr T/*&*/ getValue() const
		{
			return m_value;
		}

		constexpr T getMax () const
		{
			return m_max;
		}

		constexpr T getMin() const
		{
			return m_min;
		}

		constexpr T& setValue(const T& t)
		{
			(t >= m_min && m_max >= t) ? m_value = t : ((t<m_min)? m_value = m_min : m_value = m_max);
			return m_value;
		}

		void setRane(const T& min, const T& max) 
		{
			if (min < max)
			{
				m_min = min; m_max  = max;
			}
			else throw "Error, must be 'min < max'!";
		}

		bool operator==(const T& t) const
		{
			return ((t >= m_min && m_max >= t) ?  true :  false);
		}

		friend  std::ostream& operator<< (std::ostream& os, const c_range& r)
		{
			os << "[" << r.m_min << "," << r.m_max << "] = " << r.m_value;
			return os;
		}
};
