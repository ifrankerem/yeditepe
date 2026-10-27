#include "../include/tstack.h"

template <class T>
void Stack<T>::insertSorted(const T& x)
{
	Stack<T> s;
	if(this->isEmpty() == true)
	{
		this->push(x);
		return;
	}
	while (this->isEmpty() != true) {
		T y;
	 	this->pop(y);
		if(x > y)
		{
			this->push(y);
			this->push(x);
			break;
		}
		s.push(y);
	}
	while(s.isEmpty() != true)
	{
		if(this->isEmpty() == true)
			this->push(x);
		T y;
		s.pop(y);
		this->push(y);
	}
}
