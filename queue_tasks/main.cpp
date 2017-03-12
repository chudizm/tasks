#include "queue.h"
#include "task.h"
#include <conio.h>
//using namespace std;

void main()
{
	// -------- TEST1 queue -----------
				/*queue A(3);
	cout << "\nEnqueuing\n";
	for (int i = 0; i < 3; i++)
		A.enq(i+1);
	cout << endl << A << endl;
	cout << "\nPeeking\n";
	for (int i = 0; i < 3; i++)
	{
		int tmp = A.peek();
		cout << tmp << endl;
	}
	cout << "\nDequeuing\n";
	for (int i = 0; i < 3; i++)
	{
		int tmp = A.deq();
		cout << tmp << endl;
	}*/
	// -----------PASSED--------------

	// -------- TEST2 task -----------
				/*
	task A(2); task B(-2);
	
	SO HARD =) */
	// -----------PASSED--------------


	//-----------------����������--------------------
	double taskCreating = 0.7;										// - ����������� �������� ������
	//--------------------�����----------------------
	int taskAmount = 0,												// - ����� ���-�� �����
		taskDone = 0,												// - ���-�� ��������� �����
		taskDenied = 0,												// - ���-�� �����, ���������� �����
		clockAmount = 0,											// - ����� ���-�� ������
		clockStandby = 0;											// - ���-�� ������������� ������
	double taskTime = 0;											// - ������� ����� ���������� ������
	//-------------------�������---------------------
	queue Sys(MAXSIZE);												// - �������, �������� ���������� ������ � ������
	unsigned int maxClockTask,										// - ������������ ���������� ������ � ������
			     clockPassed = 0;									// - ���-�� ������, ����������� �� ������� ������



	//-----------------����������--------------------
	system("cls");
	cout << "Enter the max task's clock: ";
	do
	{
		cin >> maxClockTask;
	} while ((maxClockTask < 0)||(maxClockTask > MAXSIZE));

	system("cls");
	cout << "Simulation has been started. Press ANY key to stop and get a report." << endl << endl;
	//-------------------�������---------------------
	while (!_kbhit())
	{
		clockAmount++;
		task T(rand() % maxClockTask + 1);							// - ������� ������ �� ��������� ���-��� ��������� ������ ��� ����������
		double taskChance = (double)(rand()) / RAND_MAX * 1;		// - ��������� ���� ��������� ������
		if (taskChance > taskCreating)								// - ����������� ������� ���������� �����, ���� ������� �����������															
			Sys.isFull() ? taskDenied++ : Sys.enq(T.getClock());	// - ����� ������ ������ � �������
		if (Sys.isEmpty())
			clockStandby++;											// - ����������� ������� ������ �������, ���� ������� �����
		else if (Sys.peek() == clockPassed)							// - ����� ���� ���-�� ������, ����������� �� ������� ������ ��������� � ����������� ���-���
		{
			taskDone++;												// - ����������� ������� ����������� �����
			Sys.deq();												// - � ������� ��
			clockPassed = 0;										// - ������ ���-�� ������, ����������� �� ������� ����� ������ = 0
			clockStandby++;
		}
		else
			clockPassed++;											// - ����� ����������� ���-�� ������, ����������� �� ������� ������
	}

	//--------------------�����----------------------
	taskAmount = Sys.getAmount();								// - ���������� ������� ���-�� �����
	taskTime = clockAmount / taskDone;							// - � ������� ���-�� ������, ����������� �� ������� ����� ������

	cout << "Amount of done tasks: " << taskDone << endl
		 << "Amount of denied tasks: " << taskDenied << endl
		 << "Amount of tasks in queue: " << taskAmount << endl
		 << "Average time of task: " << taskTime << " (time quantums)" << endl
		 << "Amount of clocks: " << clockAmount << endl
		 << "Amount of downtime clocks: " << clockStandby << endl << endl;
	system("pause");

	return;
}