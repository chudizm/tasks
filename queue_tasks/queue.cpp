#include "queue.h"

// ------------------------------<����������>-------------------------------------
	
																	
queue::queue(const unsigned int& _size)									// - �������������
{
	try
	{
		if ((_size < 1) || (_size > MAXSIZE))							// - �������� �� ������������ �������
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
queue::queue(const queue& arg)										// - �����������
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
int queue::getSize()														// - �������� ������ �������
{
	return size;
}
void queue::enq(const int& el)											// - ���������� �������� � �������
{
	try																	// - �������� ������� ����� � �������
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
	if (end > size)														// - �������� "���������" ���������� �������
		end = end - size + 1;											// - ����������� end � ������ �������
}
int queue::deq()														// - �������� ������� � ������� �������� �� �������
{
	try																	// - �������� ������� ��������� ��� ����������
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
	if (start > size)													// - �������� ��������� ���������� �������
		start = start - size + 1;										// - ���������� start �� ������ �������
	return buf;
}
/*int queue::peek()														// - �������� ������� �� ������� ��������
{
	try																	// - �������� ������� ��������� ��� ���������
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
queue::~queue()														// - ����������
{
	delete[] pMem;
	pMem = NULL;
}
