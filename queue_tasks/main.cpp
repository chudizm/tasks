#include "queue.h"

void main()
{
	// -------- TEST -----------
	queue A(3);
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
	}
	// -------------------------
	system("pause");
}