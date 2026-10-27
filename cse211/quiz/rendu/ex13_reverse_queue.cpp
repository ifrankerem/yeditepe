#include "../include/stack_queue.h"


void reverseQueue(Queue& q)
{
	int x;
	Stack s;
	while(q.dequeue(x))
		s.push(x);
	while(s.pop(x))
		q.enqueue(x);
}