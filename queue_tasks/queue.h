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
	~queue();								// - ����������
};