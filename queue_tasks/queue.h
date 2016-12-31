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
	~queue();								// - деструктор
};