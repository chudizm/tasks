#include "queue.h"

void main()
{
	queue A(3);
	A.enq(1); A.enq(2); A.enq(3);
	/*cout << "Empty?\t" << A.isEmpty() << endl << "Full?\t" << A.isFull() << endl << A.deq() << A.deq() << A.deq() << endl;
	cout << "Empty?\t" << A.isEmpty() << endl << "Full?\t" << A.isFull() << endl;*/
	for (int i = 0; i < A.getSize()+1; i++)
	{
		cout << i << " interation:\n\n" << "A.isEmpty == " << A.isEmpty() << endl << "A.isFull == " << A.isFull() << endl << endl << "Dequeued: " << A.deq() << endl << endl;

	}
	system("pause");
}