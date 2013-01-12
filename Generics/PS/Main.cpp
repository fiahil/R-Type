
#include <iostream>
#include "PoolSystem.h"

class A : public PS::IPoolSystemElement
{
	bool usage;

public:
	A()
		: usage(false)
	{
	}

	void initialize()
	{
	}

	bool isUsed() const
	{
		return usage;
	}

	void start()
	{
		usage = true;
	}
};


int main()
{
	PS::PoolSystem<A>	pool(5);

	std::cout << "is saturated " << pool.isSaturated() << std::endl;
	std::cout << "size " << pool.poolSize() << std::endl;
	pool.allocate();
	std::cout << "Allocate\nsize " << pool.poolSize() << std::endl;
	pool.clean();
	std::cout << "Clean\nsize " << pool.poolSize() << std::endl;
	pool.allocate();
	pool.peek()->start();
	pool.peek()->start();
	pool.peek()->start();
	pool.peek()->start();
	std::cout << "Start x4" << std::endl;
	std::cout << "is saturated " << pool.isSaturated() << std::endl;
	pool.peek()->start();
	std::cout << "Start" << std::endl;
	std::cout << "is saturated " << pool.isSaturated() << std::endl;
	pool.clean();
	std::cout << "Clean\nsize " << pool.poolSize() << std::endl;
}