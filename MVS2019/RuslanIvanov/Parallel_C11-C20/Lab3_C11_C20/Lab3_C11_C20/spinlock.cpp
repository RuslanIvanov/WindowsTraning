#include "spinlock.h"
size_t spinlock::count;
void spinlock::lock() 
{
    //исп. только атомарность
	while (f.test_and_set(std::memory_order_relaxed))////атомарно устанавливает флаг true и получает его предыдущее значение 
	{ 
       // std::cout<<"\nlock...";  
        m_write_entered = 1;
    }
   
    //std::cout << "\nlock once";
}

void spinlock::unlock() 
{
	f.clear(); //атомарно устанавливает флаг false
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
{//Перед установкой флага, читатель проверяет есть ли писатель – т.е. есть ли эксклюзивная блокировка
    while (someone_has_exclusive_lock() || maximal_number_of_readers_reached()) 
    {//При первом вызове lock_shared() поток автоматически будет регистрироваться – взводя определеный бит.
     //Если потоков больше, чем размер ulong, то остальные потоки при вызове lock_shared() будут вызывать эксклюзивную блокировку писателя.
       // lock();//wait
       bool b = f.test_and_set(std::memory_order_relaxed);//??
       //std::condition_variable_any
    }

    increment_readers();//чтобы читатели не мешали друг другу, для этого они должны писать информацию о своих
    //shared-блокировках в разные ячейки памят
}

void spinlock::do_unlock_shared()
{
    decrement_readers();
   
    if (someone_has_exclusive_lock())// если была экскл. блокировка и нет читателей
    {
        if (number_of_readers() == 0) 
        {           
            unlock();//notify_one
        }
    }
    else 
    {//last
        
        if (number_of_readers() == 0)//когда последний читатель
            unlock();//notify_one
    }
}


/*
std::memory_order
C++ Библиотека атомарных операций
Определён в заголовочном файле <atomic>
enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
};
(начиная с C++11)
std::memory_order(упорядочение доступа к памяти) определяет, как обычный, неатомарный доступ к памяти, упорядочивается вокруг 
атомарных операций.При отсутствии каких - либо ограничений, на многоядерных системах, когда множество потоков одновременно читает
и пишет в несколько переменных, один поток может наблюдать изменение значений переменных в порядке, отличающемся от того, в котором
другой поток записывает их.На самом деле, видимый порядок изменений может отличаться даже среди нескольких читающих потоков.

Для атомарных операций по умолчанию библиотекой предоставляется последовательно согласованное упорядочение(sequentially consistent 
ordering) (см обсуждение ниже).Такое поведение может повредить быстродействию, но атомарным операциям библиотеки может быть передан 
дополнительный std::memory_order аргумент, чтобы указать точные ограничения, помимо атомарности, которые компилятор и процессор должны 
обеспечить для этой операции.

Константы
Заголовочный файл <atomic>
Значение	Объяснение
memory_order_relaxed	Ослабленное(Relaxed) упорядочение: отсутствуют ограничения синхронизации и упорядочения, для данной операции 
требуется только атомарность.
memory_order_consume	Операция загрузки с этим упорядочением памяти выполняет операцию поглощения(consume) над задействованной областью 
памяти : предыдущие записи в зависимую от данных область памяти, сделанные потоком, выполнившим операцию освобождения(release), становятся 
видимыми для цепочки зависимостей данного потока.
memory_order_acquire	Операция загрузки с этим упорядочением памяти выполняет операцию захвата(acquire) над задействованной областью
памяти : предыдущие записи, сделанные в зависимую от данных область памяти потоком, который выполнил освобождение(release), становятся 
видимыми в данном потоке.
memory_order_release	Операция сохранения с этим упорядочением памяти выполняет операцию освобождения(release) : предыдущие записи в
другие области памяти, становятся видимыми для потоков, которые выполняют операцию поглощения(consume) или захвата(acquire) над той же
областью памяти.
memory_order_acq_rel	Операция загрузки с этим упорядочением памяти выполняет операцию захвата(acquire) над задействованной областью
памяти.Операция сохранения с этим упорядочением памяти выполняет операцию освобождения(release).
memory_order_seq_cst(sequentially - consistent - последовательно согласованное) То же, что и memory_order_acq_rel, плюс существует
единый общий порядок, при котором все потоки видят все изменения(см.ниже) в одинаковом порядке.
Формальное описание
Межпоточная синхронизация и упорядочение памяти определяют, как вычисления и побочные эффекты выражений упорядочиваются между
различными потоками выполнения.Отношения определены в следующих правилах :
*/