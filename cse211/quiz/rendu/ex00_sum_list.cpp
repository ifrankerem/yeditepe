#include "../include/node.h"

int sumList(Node* head)
{
	if(head == nullptr)
		return 0;	//empty list
	Node *curr = head;
	int value = 0;
	if(curr->next == nullptr)
		return curr->data;
	while(curr != nullptr)
	{
		value += curr->data;
		curr = curr->next;
	}
	return value;
}
