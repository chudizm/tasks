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


	//-----------------ПЕРЕМЕННЫЕ--------------------
	double taskCreating = 0.7;										// - вероятность создания задачи
	//--------------------ОТЧЕТ----------------------
	int taskAmount = 0,												// - общее кол-во задач
		taskDone = 0,												// - кол-во сделанных задач
		taskDenied = 0,												// - кол-во задач, получивших отказ
		clockAmount = 0,											// - общее кол-во тактов
		clockStandby = 0;											// - кол-во простаивающих тактов
	double taskTime = 0;											// - среднее время выполнения задачи
	//-------------------СИСТЕМА---------------------
	queue Sys(MAXSIZE);												// - очередь, хранящая количество тактов у задачи
	unsigned int maxClockTask,										// - максимальное количество тактов у задачи
			     clockPassed = 0;									// - кол-во тактов, потраченных на текущую задачу



	//-----------------РЕАЛИЗАЦИЯ--------------------
	system("cls");
	cout << "Enter the max task's clock: ";
	do
	{
		cin >> maxClockTask;
	} while ((maxClockTask < 0)||(maxClockTask > MAXSIZE));

	system("cls");
	cout << "Simulation has been started. Press ANY key to stop and get a report." << endl << endl;
	//-------------------СИСТЕМА---------------------
	while (!_kbhit())
	{
		clockAmount++;
		task T(rand() % maxClockTask + 1);							// - создаем задачу со случайным кол-вом требуемых тактов для выполнения
		double taskChance = (double)(rand()) / RAND_MAX * 1;		// - вычисляем шанс появления задачи
		if (taskChance > taskCreating)								// - увеличиваем счетчик отказанных задач, если очередь переполнена															
			Sys.isFull() ? taskDenied++ : Sys.enq(T.getClock());	// - иначе ставим задачу в очередь
		if (Sys.isEmpty())
			clockStandby++;											// - увеличиваем счетчик тактов простоя, если очередь пуста
		else if (Sys.peek() == clockPassed)							// - иначе если кол-во тактов, потраченных на текущую задачу совпадает с необходимым кол-вом
		{
			taskDone++;												// - увеличиваем счетчик выполненных задач
			Sys.deq();												// - и удаляем ее
			clockPassed = 0;										// - теперь кол-во тактов, потраченных на решение новой задачи = 0
			clockStandby++;
		}
		else
			clockPassed++;											// - иначе увеличиваем кол-во тактов, потраченных на текущую задачу
	}

	//--------------------ОТЧЕТ----------------------
	taskAmount = Sys.getAmount();								// - записываем текущее кол-во задач
	taskTime = clockAmount / taskDone;							// - и среднее кол-во тактов, потраченное на решение одной задачи

	cout << "Amount of done tasks: " << taskDone << endl
		 << "Amount of denied tasks: " << taskDenied << endl
		 << "Amount of tasks in queue: " << taskAmount << endl
		 << "Average time of task: " << taskTime << " (time quantums)" << endl
		 << "Amount of clocks: " << clockAmount << endl
		 << "Amount of downtime clocks: " << clockStandby << endl << endl;
	system("pause");

	return;
}