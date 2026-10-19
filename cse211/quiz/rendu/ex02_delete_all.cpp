#include "../include/node.h"


int deleteAll(Node*& head, int value)
{
	Node *it = head;
	Node *prev = nullptr;
	int counter = 0;
	while(it != nullptr)
	{
		if(it->data == value)
		{	
			if(prev == nullptr)
				head = head->next;
			else
				prev->next = it->next;
			Node *temp = it;
			it = it->next;				
			delete temp;
			counter++;
		}
		else
		{
			prev = it;
			it = it->next;
		}
	}
	return counter;
}