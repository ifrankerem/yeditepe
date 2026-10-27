#include "../include/stack_queue.h"

bool Queue::moveToFront(QueueItemType value)
{
	QueueNode *prev = nullptr;
	QueueNode *curr = frontPtr;
	while(curr != nullptr && curr->item != value)
	{
		prev = curr;
		curr = curr->next;
	}
	if(curr == nullptr)
		return false; //bos q
	if(prev == nullptr)
		return true; // zaten en onde
	prev->next = curr->next; // value degerli curr u kopar
	if(curr == backPtr)
		backPtr = prev; //backpntr guncelle eger kopardigimiz ise
	curr->next = frontPtr;
	frontPtr = curr; //frontu guncelle
	return true;
}