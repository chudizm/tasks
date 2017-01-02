#include "queue.h"

// ------------------------------<РЕАЛИЗАЦИИ>-------------------------------------
	
																	
queue::queue(const unsigned int& _size)									// - инициализация
{
	try
	{
		if ((_size < 1) || (_size > MAXSIZE))							// - проверка на корректность размера
			throw("\nIncorrect size of queue\n");
	}
	catch (char* str)
	{
		cout << str;
		return;
	}
	size = _size;
	start = 0;
	end = 0;
	amount = 0;
	pMem = new int[size + 1];
}																	
queue::queue(const queue& arg)										// - копирование
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
	bool res = (amount == size);
	return res;
}
bool queue::isEmpty()
{
	bool res = (amount == 0);
	return res;
}
int queue::getSize()														// - получить размер очереди
{
	return size;
}
void queue::enq(const int& el)											// - добавление элемента в очередь
{
	try																	// - проверка наличия места в очереди
	{
		if (isFull()) throw("\nNo free space in queue\n");
	}
	catch (char* str)
	{
		cout << str;
		return;
	}
	pMem[end] = el;
	end++; 
	amount++;
	if (end > size)														// - проверка "кругового" заполнения очереди
		end = end - size + 1;											// - возвращение end в начало очереди
}
int queue::deq()														// - удаление первого в очереди элемента из очереди
{
	try																	// - проверка наличия элементов для извлечения
	{
		if (isEmpty()) throw("\nNo elements to dequeue\n");
	}
	catch (char* str)
	{
		cout << str;
		return NULL;
	}
	buf = pMem[start];
	start++;
	amount--;
	if (start > size)													// - проверка кругового заполнения очереди
		start = start - size + 1;										// - возвращаем start на начало очереди
	return buf;
}
/*int queue::peek()														// - просмотр первого из очереди элемента
{
	try																	// - проверка наличия элементов для просмотра
	{
		if (isEmpty()) throw("\nNo elements to show\n");
	}
	catch (char* str)
	{
		cout << str;
		return NULL;
	}
	return pMem[start];
}*/
queue::~queue()														// - деструктор
{
	delete[] pMem;
	pMem = NULL;
}
