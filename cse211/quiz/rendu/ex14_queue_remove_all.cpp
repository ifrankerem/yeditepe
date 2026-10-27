#include "../include/stack_queue.h"

int Queue::removeAll(QueueItemType value)
{
	int counter = 0;
	QueueNode *curr = frontPtr;
	QueueNode *prev = nullptr;
	while(curr != nullptr)
	{
		QueueNode *next = curr->next;
		if(curr->item == value)
		{
			if(prev == nullptr) //removeing frontPTR
				frontPtr = curr->next;
			else
				prev->next = next;
			if(curr == backPtr)
				backPtr = prev;
			counter++;
			delete curr;
		}
		else {
			prev = curr;
		}
		curr = next;
	}
	return counter;
}