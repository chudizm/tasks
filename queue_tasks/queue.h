#pragma once
#include <iostream>

using namespace std;
const unsigned int MAXSIZE = 100;

class queue
{
protected:
	int start,								// - первый элемент очереди
	    end,								// - последний элемент очереди
	    buf;								// - промежуточная позиция элемента
	int* pMem;								// - память под хранение элементов size - 1
	unsigned int size,						// - размер очереди
				 amount;					// - кол-во элементов, находящихся в очереди
public:
	queue(const unsigned int& _size);		// - инициализация
	queue(const queue& arg);				// - копирование
	bool isFull();							// - проверка на полноту
	bool isEmpty();							// - проверка на пустоту
	int getSize();							// - получить размер очереди
	void enq(const int& el);				// - добавлене элемента el в очередь
	int deq();								// - удаление первого в очереди элемента из очереди, вернет первый элемент
	//int peek();								// - просмотр первого из очереди элемента
	~queue();								// - деструктор
};