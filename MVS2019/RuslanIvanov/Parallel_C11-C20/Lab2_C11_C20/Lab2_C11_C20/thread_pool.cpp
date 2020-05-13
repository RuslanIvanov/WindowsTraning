#include "thread_pool.h"

std::atomic<size_t> thread_pool::countTask;

thread_pool::thread_pool()
{// constructor
	size_t nThreads = std::thread::hardware_concurrency();//4;//<количество потоков в пуле>;
	std::cout << "\nkernels  = " << nThreads<<"\n";
	m_stop = false;
	
	//«апускаем потоки:
	for (size_t i = 0; i < nThreads; i++)
	{
		try
		{
			threads.emplace_back(&thread_pool::task_thread_cv, this);
			//может быть сгенерировано исключение => по-хорошему нужно обработать - обработано в функции потока
		}
		catch (std::system_error) { std::cout << "\nError start thread number "<<i+1; }
	}
}

void thread_pool::task_thread_cv()
{
	thread_local size_t countTaskThisThread = 0;//было у мен€ т.к. подсчет выполн€емых задач в каждом потоке, а не всего

	while (!m_stop.load()) // atomic
	{
		std::function<void()> task;

		/*Ћюбой поток, который намерен ждать на std::condition_variable должен сначала приобрести std::unique_lock.
		ќпераци€ ожидани€ атомарно освобождает мьютекс и приостанавливает выполнение потока.
		 огда переменна€ услови€ уведомл€етс€, поток пробуждаетс€, и мьютекс снова приобретаетс€.*/
		{
		std::unique_lock <std::mutex > l(m);
	
		/*while (!pred()) { wait(lock);}*/
		//std::cout << "\nwait...id  = " << std::this_thread::get_id();
		cv.wait(l, [this]() { return !tasks.empty() || m_stop.load(); });//gdать пока не добав€т кого то в очередь или не скажут стоп
		if (m_stop.load()) 
		{ 
			//std::cout << "\nthread  go to stop... ";
			break; 
		}

		task = tasks.front();
		tasks.pop();
		}//деструктор l
		
		if (task)
		{
			task();//убрать из секцции => дорого
			countTask.fetch_add(1);//atom 
			//countTask++;//тоже моно
			countTaskThisThread++;
		}
		
	}

	std::lock_guard<std::mutex> out(m_sinx_out);
	std::cout << "\nid thread =  " << std::this_thread::get_id() << ", number of completed all tasks = " << countTask; 
	std::cout << "\nid thread =  " << std::this_thread::get_id() << ", number of completed tasks in this thread = " << countTaskThisThread;
}

void  thread_pool::stopRun_cv()
{
	{
		//std::lock_guard<std::mutex> lk{ m };// а если m_stop - atomic ?? надо m ?
		m_stop.store(true);//atomic

	}
	// а стоп надо сказать всем!!
	cv.notify_all();// 
	//cv.notify_one(); //????надо пробудить 1 го в очереди а не всех
}

void thread_pool::add_task_cv(std::function<void()>& pfunc)
{
	{
		std::lock_guard<std::mutex> lk{ m };
		tasks.push(pfunc);
	}
	//cv.notify_all();
	cv.notify_one(); //push толко одному 
	//std::cout << "\npush...";
}

void thread_pool::add_task(std::function<void()>& pfunc)
{
	m.lock();
	tasks.push(pfunc);
	m.unlock();
	std::cout << "\npush...";
}

thread_pool:: ~thread_pool() 
{
	m_stop.store(true);
	cv.notify_all();//остановить всех
	for (std::thread& t : threads)
	{
		if (t.joinable())
		{
			std::cout << "\ndelete th id = " << t.get_id()<<"\n";
			t.join();
			
		}
	}
}