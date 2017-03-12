#include "queue.h"

// ------------------------------<РЕАЛИЗАЦИИ>-------------------------------------
	
																	// - инициализация
queue::queue(const unsigned int& _size)
{
	try
	{
		if ((_size < 1) || (_size > MAXSIZE))							// - проверка на корректность размера
			throw("\nIncorrect size of queue\n");
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
bool queue::isFull()
{
	return (amount==size);
}
bool queue::isEmpty()
{
	return (amount==0);
}
int queue::getSize()
{
	return size;
}
int queue::getAmount()
{
	return amount;
}
void queue::enq(const int& el)
{
	try
	{
		if (isFull()) throw("\nQueue is full\n");
	}
	catch (char* err)
	{
		cout << err;
		return;
	}
	
	pMem[end] = el;
	amount++; end++;
	if (end > size)											// - переход в начало, если конец > размер
		end = end - size + 1;
}
int queue::deq()
{
	try
	{
		if (isEmpty()) throw("\nQueue is empty\n");
	}
	catch (char* err)
	{
		cout << err;
		return 0;
	}

	buf = pMem[start];
	start++; amount--;
	if (start > size)										// - переход в начало, если старт > размер
		start = start - size + 1;
	return buf;
}
int queue::peek()
{
	try
	{
		if (isEmpty()) throw("\nQueue is empty\n");
	}
	catch (char* err)
	{
		cout << err;
		return 0;
	}
	return pMem[start];
}
queue::~queue()
{
	delete[] pMem;
	pMem = NULL;
}

ostream& operator<<(ostream& os, const queue& arg)
{
	if (!(arg.amount))
		os << "Queue is empty";
	else
	{
		int _amount = arg.amount;
		int _end = arg.end;
		while (_amount != 0)
		{
			os << arg.pMem[_end - 1] << ' ';
			_amount--; _end--;
		}
	}
	return os;
}
