
#include <iostream>
#include <queue>

#include "Consumer.h"
#include "Producer.h"
#include "Storage.h"

class Packet
{
	static int ID;

	int id;

public:
	Packet(int i = ID)
		: id(i)
	{
		ID = i + 1;
	}

	void beep()
	{
		std::cout << "beep " << id << std::endl;
	}
};

int Packet::ID = 0;

class Notifier
{
public:
	void	notify()
	{
		std::cout << "Notify!" << std::endl;
	}

	void	wait()
	{
		std::cout << "Waiting for signal..." << std::endl;
	}

};

template <class T>
class my_queue : public std::queue<T>
{
public:
	T pop()
	{
		T i = this->front();
		std::queue<T>::pop();
		return i;
	}
};

int main()
{
	PC::Storage<Packet, my_queue<Packet*>, Notifier>		s;

	PC::Producer<Packet, PC::Storage<Packet, my_queue<Packet*>, Notifier> >	p1(s);
	PC::Producer<Packet, PC::Storage<Packet, my_queue<Packet*>, Notifier> >	p2(s);

	PC::Consumer<Packet, PC::Storage<Packet, my_queue<Packet*>, Notifier> >	c1(s);
	PC::Consumer<Packet, PC::Storage<Packet, my_queue<Packet*>, Notifier> >	c2(s);


	std::cout << "c1 wait" << std::endl;
	c1.wait();

	std::cout << "p1 Produce 5" << std::endl;
	p1.produce(5);
	std::cout << "s size : " << s.size() << std::endl;

	std::cout << "p2 Produce Packet n10" << std::endl;
	p2.produce(new Packet(10));
	std::cout << "s size : " << s.size() << std::endl;

	std::cout << "c1 consume" << std::endl;
	c1.consume()->beep();
	std::cout << "s size : " << s.size() << std::endl;

	std::cout << "c2 consume" << std::endl;
	c2.consume()->beep();
	std::cout << "s size : " << s.size() << std::endl;

	std::cout << "c1 consume x4" << std::endl;
	c1.consume()->beep();
	c1.consume()->beep();
	c1.consume()->beep();
	c1.consume()->beep();

	std::cout << "s size : " << s.size() << std::endl;
}