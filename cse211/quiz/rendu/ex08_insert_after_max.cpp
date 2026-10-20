#include "../include/linked_list.h"
#include <climits>
// 
// void LinkedList::insertAfterMax(int value)
// {
// 	if(head == nullptr)
// 		return;
// 	Node *it = head;
// 	int max = INT_MIN;
// 	while(it != nullptr)
// 	{
// 		Node *it2 = head;
// 		while(it2 != it)
// 		{
// 			if(it2->data < it->data && it->data > max)
// 				max = it->data;
// 			else
// 				break;
// 			it2 = it2->next;
// 		}
// 		it = it->next;
// 	}
// 	Node *it3 = head;
// 	while(it3 != nullptr)
// 	{
// 		if(it3->data == max)
// 		{
// 			Node *it4 = it3;
// 			it4 = it4->next;
// 			while(it4 != nullptr)
// 			{
// 				if(it4->data == max)
// 				{
// 					it3 = it4;
// 					break;
// 				}
// 				it4 = it4->next;
// 			}
// 			break;
// 		}
// 		it3 = it3->next;
// 	}
// 	Node *n = new Node;
// 	n->next = it3->next;
// 	n->data = value;
// 	it3->next = n;
// }


void LinkedList::insertAfterMax(int value)
{
    if (head == nullptr)
            return;
    Node *maxNode = head;
    Node *it = head->next;
    while(it != nullptr)
    {
    	if(it->data >= maxNode->data)
     		maxNode = it;
     	it = it->next;
    }
    maxNode->next = new Node{value,maxNode->next};
}
