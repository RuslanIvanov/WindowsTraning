#include "spinlock.h"
size_t spinlock::count;
void spinlock::lock() 
{
    //���. ������ �����������
	while (f.test_and_set(std::memory_order_relaxed))////�������� ������������� ���� true � �������� ��� ���������� �������� 
	{ 
       // std::cout<<"\nlock...";  
        m_write_entered = 1;
    }
   
    //std::cout << "\nlock once";
}

void spinlock::unlock() 
{
	f.clear(); //�������� ������������� ���� false
	//std::cout << "\n...unlock";
    m_write_entered = 0;
}

bool spinlock::try_lock()
{
	return !f.test_and_set();
}

void spinlock::lock_shared() 
{
   /* if (try_lock()==true)
    {
        numLock.fetch_add(1);
    }
   
    a.fetch_add(1);*/
    do_lock_shared();

}
void spinlock::unlock_shared() 
{
  // std::shared_lock<spinlock> sh()
 
   /* if (a == numLock)
    {
        unlock();
    }

    a.fetch_sub(1);*/

     do_unlock_shared();
}

unsigned long spinlock::number_of_readers() const
{
    return m_state;//m_num_readers;
}

bool spinlock::maximal_number_of_readers_reached() const
{
    return number_of_readers() == m_max_readers;
}


bool spinlock::someone_has_exclusive_lock() const 
{
    return  (m_write_entered != 0);//1!=0 - true
}

void spinlock::increment_readers() 
{
    if (m_num_readers < 32u)
    {     
        m_state |= (1 << m_num_readers);
        m_num_readers++;
    }
}

void spinlock::decrement_readers() 
{
    if (m_num_readers > 0)
    {
        m_num_readers--;
        m_state &= ~(1 << (m_num_readers));
  
    }
}

void spinlock::do_lock_shared() 
{//����� ���������� �����, �������� ��������� ���� �� �������� � �.�. ���� �� ������������ ����������
    while (someone_has_exclusive_lock() || maximal_number_of_readers_reached()) 
    {//��� ������ ������ lock_shared() ����� ������������� ����� ���������������� � ������ ����������� ���.
     //���� ������� ������, ��� ������ ulong, �� ��������� ������ ��� ������ lock_shared() ����� �������� ������������ ���������� ��������.
       // lock();//wait
       bool b = f.test_and_set(std::memory_order_relaxed);//??
       //std::condition_variable_any
    }

    increment_readers();//����� �������� �� ������ ���� �����, ��� ����� ��� ������ ������ ���������� � �����
    //shared-����������� � ������ ������ �����
}

void spinlock::do_unlock_shared()
{
    decrement_readers();
   
    if (someone_has_exclusive_lock())// ���� ���� �����. ���������� � ��� ���������
    {
        if (number_of_readers() == 0) 
        {           
            unlock();//notify_one
        }
    }
    else 
    {//last
        
        if (number_of_readers() == 0)//����� ��������� ��������
            unlock();//notify_one
    }
}


/*
std::memory_order
C++ ���������� ��������� ��������
�������� � ������������ ����� <atomic>
enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
};
(������� � C++11)
std::memory_order(������������ ������� � ������) ����������, ��� �������, ����������� ������ � ������, ��������������� ������ 
��������� ��������.��� ���������� ����� - ���� �����������, �� ������������ ��������, ����� ��������� ������� ������������ ������
� ����� � ��������� ����������, ���� ����� ����� ��������� ��������� �������� ���������� � �������, ������������ �� ����, � �������
������ ����� ���������� ��.�� ����� ����, ������� ������� ��������� ����� ���������� ���� ����� ���������� �������� �������.

��� ��������� �������� �� ��������� ����������� ��������������� ��������������� ������������� ������������(sequentially consistent 
ordering) (�� ���������� ����).����� ��������� ����� ��������� ��������������, �� ��������� ��������� ���������� ����� ���� ������� 
�������������� std::memory_order ��������, ����� ������� ������ �����������, ������ �����������, ������� ���������� � ��������� ������ 
���������� ��� ���� ��������.

���������
������������ ���� <atomic>
��������	����������
memory_order_relaxed	�����������(Relaxed) ������������: ����������� ����������� ������������� � ������������, ��� ������ �������� 
��������� ������ �����������.
memory_order_consume	�������� �������� � ���� ������������� ������ ��������� �������� ����������(consume) ��� ��������������� �������� 
������ : ���������� ������ � ��������� �� ������ ������� ������, ��������� �������, ����������� �������� ������������(release), ���������� 
�������� ��� ������� ������������ ������� ������.
memory_order_acquire	�������� �������� � ���� ������������� ������ ��������� �������� �������(acquire) ��� ��������������� ��������
������ : ���������� ������, ��������� � ��������� �� ������ ������� ������ �������, ������� �������� ������������(release), ���������� 
�������� � ������ ������.
memory_order_release	�������� ���������� � ���� ������������� ������ ��������� �������� ������������(release) : ���������� ������ �
������ ������� ������, ���������� �������� ��� �������, ������� ��������� �������� ����������(consume) ��� �������(acquire) ��� ��� ��
�������� ������.
memory_order_acq_rel	�������� �������� � ���� ������������� ������ ��������� �������� �������(acquire) ��� ��������������� ��������
������.�������� ���������� � ���� ������������� ������ ��������� �������� ������������(release).
memory_order_seq_cst(sequentially - consistent - ��������������� �������������) �� ��, ��� � memory_order_acq_rel, ���� ����������
������ ����� �������, ��� ������� ��� ������ ����� ��� ���������(��.����) � ���������� �������.
���������� ��������
����������� ������������� � ������������ ������ ����������, ��� ���������� � �������� ������� ��������� ��������������� �����
���������� �������� ����������.��������� ���������� � ��������� �������� :
*/