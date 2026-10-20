#include "../include/linked_list.h"
#include <vector>

std::vector<int> LinkedList::newMinimums() const
{
	std::vector<int> x;
	if(head == nullptr)
		return x;
	Node *it = head;
	while(it != nullptr)
	{
		bool flag = false;
		Node *it2 = head;
		while (it2 != it)
	 	{
			if(it2->data < it->data || it2->data == it->data)
			{
				flag = true;
				break;
			}
			it2 = it2->next;
		}
		if(flag == false)
			x.push_back(it->data);
		it = it->next;
	}
	return x;
}

// std::vector<int> LinkedList::newMinimums() const
// {
//         std::vector<int> x;
//         for (Node *it = head; it != nullptr; it = it->next)
//                 if (x.empty() || it->data < x.back())
//                         x.push_back(it->data);
//         return x;
// }
// 
// usage of x.back() is so easy