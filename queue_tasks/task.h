#pragma once

class task								// ����� ������
{
private:
	unsigned int reqClock;				// - ����������� �������� �������
public:
	task(unsigned int _reqClock = 1);
	unsigned int getClock();			// - ������� ����������� �������� �������							
};