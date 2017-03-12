#include "task.h"
#include "queue.h"

task::task(unsigned int _reqClock)
{
	try
	{
		if ((_reqClock < 1) || (_reqClock > MAXSIZE))							// - �������� �� ������������ �������
			throw("\nIncorrect value of clock\n");
	}
	catch (char* str)
	{
		cout << str;
	}
	reqClock = _reqClock;
}

unsigned int task::getClock()
{
	return reqClock;
}

