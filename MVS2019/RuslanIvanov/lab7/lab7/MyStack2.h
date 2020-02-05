#pragma once
#define GLOB
#ifdef GLOB
template <typename T, size_t> class MyStack2;
//declaration
template <typename T, size_t m_n>
std::ostream& operator<<(std::ostream& os, const MyStack2<T, m_n>&);
#endif

struct ErrorStack2
{
	size_t m_n;
	size_t m_i;

	ErrorStack2(size_t i, size_t n)
	{
		m_n = n;
		m_i = i;
	}

};


template <typename T, size_t m_n = 10> class MyStack2
{
	struct Node
	{
		Node() : m_next(nullptr) { }
		Node(const T& t) : m_t(t), m_next(nullptr) { }
		~Node()
		{
			m_t.~T();
		}
		// �������� ����
		T m_t;
		// size_t m_numNode;
		// ��������� �� ��������� ����
		Node* m_next;
	};


	// ������ ������������ ������
	Node* m_head;

	size_t m_index;// ��� �������� � ������ �� m_n

public:

	MyStack2() : m_head(nullptr),m_index(0)
	{
		//m_index = 0;
	}

	~MyStack2()
	{
		while (m_head)
		{
			Node* p = m_head->m_next;
			delete m_head;
			m_head = p;
			m_index--;
		}
	}


	MyStack2(const MyStack2& st)
	{
		Node* p = st.m_head;
		size_t i = 0;
		m_index = 0;//?? 
		m_head = nullptr;
		while (p)
		{
			if (i < st.m_index && i<m_n)
			{
				push(p->m_t);// ���� ����� ����
				p = p->m_next;
				i++;
			}
			else break;
		}

	}

	MyStack2& operator=(const MyStack2& st)
	{
		if (this == &st) return *this;

		size_t i = 0;
		Node* psource = st.m_head;
		Node* pcopy = m_head;
		Node* p = (m_index >= st.m_index) ? m_head : st.m_head;
		size_t n = m_index;
		while (p)//���� �� ������� ������
		{
			if ((i < n) && (i < st.m_index))
			{
				pcopy->m_t = psource->m_t;
				i++;
				psource = psource->m_next;
				pcopy = pcopy->m_next;
				//m_index - �������� �������
			}
			else
			{//end copy
				if (i >= n)
				{
					try
					{
						push(psource->m_t);//m_index++
						psource = psource->m_next;
					}
					catch (const char* e)
					{
						//std::cout << e;
						throw e;
					}
				}
				else
				{
					pop();//������� �� ��, ���� ��� � ������ ����� ����
					//pcopy = pcopy->m_next;
				/*	if (pcopy != nullptr)
					{
						MyStack2<T, m_n>::Node* pmem = pcopy->m_next;
						delete pcopy;
						if (pmem != nullptr)
						pcopy = pmem;
					}*/
					
				}
			}
						
			p = p->m_next;
		}	
			
		return *this;

	}
	/*
	MyStack2& operator=(const MyStack2& st)
	{
		if (this == &st) return *this;

		size_t i = 0;
		Node* p = st.m_head;
		Node* pc = m_head;
		// ����� ��� pop ���� � ����������� ����� ������ �� index
		while (p)
		{
			if(i<m_index)
			{
				//����� ����������� ����
				pc->m_t=p->m_t;

			}
			else
			{
				try
				{
					push(p->m_t);
				}
				catch (const char* e)
				{
					//std::cout << e;
					throw e;
				}
			}
			p=p->m_next;
			i++;
		}

		if(i<m_index) {  }

		m_index = i;
		return *this;

	}*/

	MyStack2(MyStack2&& st)
	{
		m_index = st.m_index;

		m_head = st.m_head;
		m_head->m_next = st.m_head->m_next;

		st.m_head = nullptr;
		//st.m_head->m_next = nullptr;
		st.m_index = 0;
		std::cout << "\nrun constr move&& ";

		stop
	}

	MyStack2& operator=(MyStack2&& st)
	{
		if (this == &st)
		{
			return *this;
		}

		//dell all	
		for (int i = 0; i < m_index && i<m_n; i++)
		{
			pop();
		}

		m_index = st.m_index;

		m_head = st.m_head;
		m_head->m_next = st.m_head->m_next;

		st.m_head = nullptr;
		//st.m_head->m_next = nullptr;
		st.m_index = 0;

		std::cout << "\nrun oper move&& ";
		stop
		return *this;
	}
	/*
	MyStack2.h: In member function �T& MyStack2<T, <anonymous> >::operator[](size_t) [with T = int; unsigned int m_n = 4u; size_t = unsigned int]�:
	MyStack2.h:87:5: warning: control reaches end of non-void function [-Wreturn-type]
	*/
	T& operator[](size_t i)
	{

		if (i < m_index) // ������ ������� �������
		{
			size_t ii = 0;
			Node* p = m_head;
			while (p)
			{
				if (ii == i)
				{
					return p->m_t;
				}
				else p = p->m_next;
				ii++;
			}
			if (p == nullptr)
			{
				throw "\nError.  Stack is empty!";
			}
		}
		else { throw ErrorStack2(i, m_index); } // throw std::out_of_range;
	}

	void push(const T& p) // ���������
	{
		if (m_index < m_n)//������ - ��� ��������� ������� ��������
		{
			Node* pNode = nullptr;
			try
			{
				pNode = new Node(p);
			}
			catch (std::bad_alloc& e)
			{ std::cout << e.what(); throw; } //������������� ������ ���������� ���� std :: length_error;

			if (m_head)
			{
				pNode->m_next = m_head;// ������� ����� �������
				m_head = pNode;// ������� ���������� �������
			}
			else { m_head = pNode; }

			m_index++;
		}
		else
		{
			throw "\nError push. Exit  of size stack!";
		}
	}

	void pop() // �����������
	{
		if (m_index > 0 && m_index <= m_n)
		{
			if (m_head)// ������� � ������, ����� ������������� ����� ������
			{
				m_index--;

				Node* p = m_head->m_next;
				delete m_head;
				m_head = p;
			}
		}
		else
		{
			throw "\nError pop. Exit  of size stack!";
		}

	}

	bool empty() { return (m_index == 0); }
	size_t size() { return m_index; }
	Node* getHead() { return m_head; }

	void print_reverse(struct Node* pHead)
	{
		if (pHead == nullptr) return;
		print_reverse(pHead->m_next);
		std::cout << "\n" << pHead->m_t;
	}

#ifdef GLOB
	friend  std::ostream& operator<< <> (std::ostream& os, const MyStack2& s);
#else
	friend  std::ostream& operator<< (std::ostream& os, const MyStack2& s)
	{
		const  MyStack2::Node* p = s.m_head;
		while (p)
		{
			os << "\n" << p->m_t;
			p = p->m_next;
		}
		return os;
	}
#endif
};

//definition
#ifdef GLOB

template <typename T, size_t m_n>
std::ostream& operator<<(std::ostream& os, const MyStack2<T, m_n>& s)
{
	const class /*typename*/ MyStack2<T, m_n>::Node* p = s.m_head;

	while (p)
	{
		os << "\n" << p->m_t;
		p = p->m_next;
	}

	return os;
}
#endif
