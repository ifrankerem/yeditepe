#include <cstddef>
#include <string>
#include "../include/tstack.h"

int countUnique(const std::string& str)
{
	Stack<char> s;
	Stack<char> temp;
	int counter = 0;
	for(size_t i = 0; i < str.size(); i++)
		s.push(str[i]);
	while(s.isEmpty() != true)
	{
		char x;
		bool flag = false;
		s.pop(x);
		while (s.isEmpty() != true) {
			char y;
			s.pop(y);
			if(x != y)
				temp.push(y);
			else
				flag = true;
		}
		if(flag == false)
			counter++;
		char c;
		while(temp.pop(c))
			s.push(c);
	}
	return counter;
}
