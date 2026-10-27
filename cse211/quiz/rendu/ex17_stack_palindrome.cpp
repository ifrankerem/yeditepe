#include "../include/tstack.h"

template <class T>
bool Stack<T>::isPalindrome()
{
	Stack<T> s;
	Stack<T> temp, copy,copy2;
	T x;
	while (this->pop(x))
    	temp.push(x);
	while (temp.pop(x))
	{
	    this->push(x); 
	    copy.push(x);
		copy2.push(x);
	}
	while(copy.isEmpty() != true)
	{
		T x;
		copy.pop(x);
		s.push(x);
	}
	while(s.isEmpty() != true)
	{
		T y;
		T z;
		s.pop(y);
		copy2.pop(z);
		if(y != z)
			return false;
	}
	return true;
}
