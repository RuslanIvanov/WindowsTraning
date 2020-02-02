#pragma once

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
           /* if (pNext)
            {
                pNext->pPrev = this->pPrev;
            }*/

        }
        // �������� ����
        T m_t;
        // ��������� �� ��������� ����
        Node* m_next;
    };


    // ������ ������������ ������
    Node* m_head;

    size_t m_index;// ��� �������� � ������ �� m_n

public:

    MyStack2(): m_head(nullptr) { }
    {
        m_index = 0;
    }

    ~MyStack2()
    {
        while (m_head)
        {
                Node* newHead = m_head->m_next;
                delete m_head;
                m_head = newHead;
                m_index--;
        }
    }

    void push(const T& p) // ���������
    {
        if (m_index < m_n)
        {
            if (Node* node = new Node(p))
            {
                node->m_next = m_head;
                m_head = node;
            }
            m_index++;
        }
        else
        {
            throw "\nError push. Exit  of size stack!";
        }
    }

    T& pop() // �����������
    {
        if (m_index > 0 && m_index <= m_n)
        {
            m_index--;

            if (m_head)
            {
           
                Node* newHead = m_head->m_next;
                delete m_head;
                m_head = newHead;
            }
            return  m_p[m_index]; return m_node->m_t;
        }
        else
        {
            throw "\nError pop. Exit  of size stack!";
        }

    }

    bool empty() { return (m_index == 0); }
    size_t size() { return m_index; }
};
