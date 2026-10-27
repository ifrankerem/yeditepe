#include "../include/stack_queue.h"


void Stack::reverse()
{
	StackNode *prev = nullptr;
	StackNode *curr = topPtr;
	while(curr != nullptr)
	{
		StackNode *next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	topPtr = prev;
}


// * * * * * *