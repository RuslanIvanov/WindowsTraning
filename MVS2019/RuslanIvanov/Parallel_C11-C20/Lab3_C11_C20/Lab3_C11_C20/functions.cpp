#include "functions.h"

void thread_func1(std::vector<int>& v, int N, std::mutex& m, std::promise<int>& promise1)
{
	m.lock();
	for (int i = 0; i < N; i++)
	{
		v.push_back(i + 1);
	}

	std::cout << "\nth["<< std::this_thread::get_id() <<"] v size "<< v.size();
	m.unlock();
	promise1.set_value(1);
}

void thread_func2(std::vector<int>& v, int M, std::mutex& m, std::promise<int>& promise2)
{
	m.lock();
	for (int i = 0; i < M; i++)
	{
		v.push_back((i + M)*(-1));
	}
	std::cout << "\nth[" << std::this_thread::get_id() << "] v size " << v.size();
	m.unlock();
	
	promise2.set_value(2);
}

void thread_transform(std::vector<int>& v, std::promise<int>& promise1,std::promise<int>& promise2)
{//furture
	int rez[2] = { 0 };
	std::future<int>  futTransf[2];

	futTransf[0] = promise1.get_future();
	futTransf[1] = promise2.get_future();

	rez[0] = futTransf[0].get();
	rez[1] = futTransf[1].get();

	std::cout << "\nth[" << std::this_thread::get_id() << "rez = [" << rez[0]<<", "<<rez[1]<<"]";

	std::transform( v.begin(), v.end(), v.begin(), std::negate<int>());

	std::cout << "\nth[" << std::this_thread::get_id() << "] transform size " << v.size();
}

void myThread(spinlock& m, std::string& s)
{
	m.lock();
	s += "_SpinLock_ ";
	std::cout <<"\nidSpinLock ["<<std::this_thread::get_id()<<"] = " << s << std::endl;
	m.unlock();
}

void myThreadLockGuard(spinlock& m, std::string& s)
{
	std::lock_guard<spinlock> lgsp(m);
	s += "_LockGuard_ ";
	std::cout << "\nidLockGuard ["<<std::this_thread::get_id() << "] = " << s<<std::endl;
	
}

void myThreadUniqGuard(spinlock& m, std::string& s)
{
	std::unique_lock<spinlock> lgsp(m);
	s += "_UniqGuard_ ";
	std::cout << "\nidUniqGuard [" << std::this_thread::get_id() << "] = "<< s << std::endl;

}