#pragma once

template <typename T,size_t> class MyStack2;
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyStack2<T>& );

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
          /* if (m_next)//m_head     
          {
               m_next->m_next = this->m_next;
           }*/
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

    MyStack2(): m_head(nullptr) 
    {
        m_index = 0;
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

    T& operator[](size_t i) 
    {

        if (i < m_index) // ������ ������� �������
        {
            size_t ii = 1;
            Node* p = m_head;
            while (m_head)
            { 
                if (ii == m_index)
                {
                    return p->m_t;
                }
                else p = p->m_next;
                ii++;
            }
            throw "\nError.  Stack is empty!";
        }
        else throw ErrorStack2(i, m_index);// throw std::out_of_range;
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
           catch (std::bad_alloc) { /*throw std::bad_alloc;*/ } //"\nError push. Bad alloc new!";

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

   /* T& pop() // �����������
    {
        if (m_index > 0 && m_index <= m_n)
        {
            if (m_head)// ������� � ������, ����� ������������� ����� ������
            {
                m_index--;
                Node* p = m_head;
                size_t ii = 0;
                while(m_head)
                {
                    p = m_head->m_next;
                    ii++
                }
              //  Node* p = m_head->m_next;
              //  T t = m_head->m_t;
              //  delete m_head;
              //  m_head = p;
              //  return t;
                return p->m_t;
            }
            throw "\nError pop. Stack is empty!";
           
        }
        else
        {
            throw "\nError pop. Exit  of size stack!";
        }

    }*/

  private:
  friend  std::ostream& operator<< <>(std::ostream& os, const MyStack2& s); //<T>
};

template <typename T,size_t>
std::ostream& operator<<(std::ostream& os, const MyStack2<T>& s)
{

    return os;
}