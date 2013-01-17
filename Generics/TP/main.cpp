
#include <iostream>
#include <string>
#include "ThreadPool.h"

#ifndef WIN32
# include <unistd.h>
# define Sleep(x)	sleep(x/1000)
#endif

class Task
{
	std::string		name;

public:
	Task(std::string const& s)
		: name(s)
	{
	}

	void	operator()()
	{
		std::cout << "Working on task : " << this->name << std::endl;
		Sleep(8000);
		std::cout << "Back to sleep!" << std::endl;
	}
};

int main()
{
	std::cout << "Launching ThreadPool" << std::endl;
	TP::ThreadPool<Task>*	tp = TP::ThreadPool<Task>::getInstance(5);

	std::cout << "StorageSize : " << tp->storageSize() << std::endl;
	std::cout << "PoolSize : " << tp->poolSize() << std::endl;
	std::cout << "is saturated : " << tp->isSaturated() << std::endl;
	std::cout << "Push 6 Tasks" << std::endl;
	tp->push(new Task("Poney"));
	tp->push(new Task("Soleil"));
	tp->push(new Task("Elephant"));
	tp->push(new Task("Maison"));
	tp->push(new Task("Loutre"));
	tp->push(new Task("SHEVAL"));
	std::cout << "StorageSize : " << tp->storageSize() << std::endl;
	Sleep(1000);
	std::cout << "StorageSize : " << tp->storageSize() << std::endl;
	std::cout << "is saturated : " << tp->isSaturated() << std::endl;
	std::cout << "Launching more threads" << std::endl;
	tp->allocate();
	std::cout << "is saturated : " << tp->isSaturated() << std::endl;
	std::cout << "StorageSize : " << tp->storageSize() << std::endl;
	std::cout << "PoolSize : " << tp->poolSize() << std::endl;
	std::cout << "Waiting for the end" << std::endl;
	Sleep(20000);
	std::cout << "is saturated : " << tp->isSaturated() << std::endl;
	Sleep(10000);
}