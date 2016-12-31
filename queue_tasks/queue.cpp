#include "queue.h"

// ------------------------------<РЕАЛИЗАЦИИ>-------------------------------------
	
																	// - инициализация
queue::queue(const unsigned int& _size)
{
	try
	{
		if ((_size < 1) || (_size > MAXSIZE))							// - проверка на корректность размера
			throw("Incorrect size of queue");
	}
	catch (char* str)
	{
		cout << str;
	}
	size = _size;
	start = 0;
	end = 0;
	amount = 0;
	pMem = new int[size + 1];
}
																	// - копирование
queue::queue(const queue& arg)
{
	size = arg.size;
	start = arg.start;
	end = arg.end;
	amount = arg.amount;
	pMem = new int[size + 1];
	for (int i = 0; i <= size; i++)
		pMem[i] = arg.pMem[i];
}
																	// - деструктор
queue::~queue()
{
	delete[] pMem;
	pMem = NULL;
}
