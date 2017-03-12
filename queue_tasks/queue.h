#pragma once
#include <iostream>

using namespace std;
const unsigned int MAXSIZE = 100;

class queue
{
protected:
	int start;								// - ������ ������� �������
	int end;								// - ��������� ������� �������
	unsigned int size;						// - ������ �������
	unsigned int amount;					// - ���-�� ���������, ����������� � �������
	int* pMem;								// - ������ ��� �������� ��������� size - 1
	int buf;								// - ������������� ������� ��������
public:
	queue(const unsigned int& _size);		// - �������������
	queue(const queue& arg);				// - �����������
	bool isFull();							// - �������� �� �������
	bool isEmpty();							// - �������� �� �������
	int getSize();							// - ������� ������ �������
	int getAmount();						// - ������� ���������� ��������� � �������
	void enq(const int& el);				// - ��������� ������� � ����� �������
	int deq();								// - �������� ������� �� ������ �������
	int peek();								// - ���������� �������� �������
	~queue();								// - ����������

	friend ostream& operator<<(ostream &os, const queue& arg);
};