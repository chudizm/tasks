#pragma once
#include <iostream>

using namespace std;
const unsigned int MAXSIZE = 100;

class queue
{
protected:
	int start,								// - ������ ������� �������
	    end,								// - ��������� ������� �������
	    buf;								// - ������������� ������� ��������
	int* pMem;								// - ������ ��� �������� ��������� size - 1
	unsigned int size,						// - ������ �������
				 amount;					// - ���-�� ���������, ����������� � �������
public:
	queue(const unsigned int& _size);		// - �������������
	queue(const queue& arg);				// - �����������
	bool isFull();							// - �������� �� �������
	bool isEmpty();							// - �������� �� �������
	int getSize();							// - �������� ������ �������
	void enq(const int& el);				// - ��������� �������� el � �������
	int deq();								// - �������� ������� � ������� �������� �� �������, ������ ������ �������
	//int peek();								// - �������� ������� �� ������� ��������
	~queue();								// - ����������
};