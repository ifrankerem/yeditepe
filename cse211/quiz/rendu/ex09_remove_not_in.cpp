#include "../include/linked_list.h"

int LinkedList::removeNotIn(const int arr[], int size)
{
	Node *it = head;
	Node *prev = nullptr;
	int counter = 0;
	while(it != nullptr)
	{
		bool isValid = false;
		for(int i = 0; i < size ; i++)
		{
			if(arr[i] == it->data)
			{
				isValid = true;
				break;
			}
		}
		if(!isValid)
		{
			if(prev == nullptr)
				head = head->next;
			else
				prev->next = it->next; // baglama isi burda iste!!
			Node *temp = it;
			it = it->next;
			counter++;
			delete temp;
		}
		else
		{
			prev = it;
			it = it->next;
		}
	}
	return counter;
}
