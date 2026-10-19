#include "../include/node.h"

Node* nthFromEnd(Node* head, int n)
{
	if(n < 1 || head == nullptr)
		return nullptr;
	Node *it = head;
	int counter = 0;
	while(it != nullptr)
	{
		counter++;
		it = it->next;
	}
	if(n > counter)
		return nullptr;
	Node *it2 = head;
	for(int i = 0 ; i < counter - n ; i++)
		it2 = it2->next;
	return it2;

	
}
