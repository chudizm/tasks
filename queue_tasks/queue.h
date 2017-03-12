#pragma once
#include <iostream>

using namespace std;
const unsigned int MAXSIZE = 100;

class queue
{
protected:
	int start;								// - первый элемент очереди
	int end;								// - последний элемент очереди
	unsigned int size;						// - размер очереди
	unsigned int amount;					// - кол-во элементов, находящихся в очереди
	int* pMem;								// - память под хранение элементов size - 1
	int buf;								// - промежуточная позиция элемента
public:
	queue(const unsigned int& _size);		// - инициализация
	queue(const queue& arg);				// - копирование
	bool isFull();							// - проверка на полноту
	bool isEmpty();							// - проверка на пустоту
	int getSize();							// - вернуть размер очереди
	int getAmount();						// - вернуть количество элементов в очереди
	void enq(const int& el);				// - поставить элемент в конец очереди
	int deq();								// - вытащить элемент из начала очереди
	int peek();								// - посмотреть выходной элемент
	~queue();								// - деструктор

	friend ostream& operator<<(ostream &os, const queue& arg);
};