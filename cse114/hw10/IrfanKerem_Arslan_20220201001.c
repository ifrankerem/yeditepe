//İrfan Kerem Arslan 20220201001-072 HW-11

#include <stdio.h>

void foo(char *x, int state)
{
	int i = 0;
	if(x[i] == '\0')
		return;
	if(state == 0)
	{
		if(x[i] == ' ')
			foo(&x[i+1],1);
		foo(&x[i+1],0);
	}	
	if(state == 1)
	{
		if(x[i] == ' ')
			foo(&x[i+1],2);
		else
			foo(&x[i+1],1);
	}
	if(state == 2)
	{
		if(x[i] == ' ' || x[i] == '\0')
			return;
		printf("%c",x[i]);
		foo(&x[i+1],2);
	}
}
int main()
{
	char *x = "deneme 31 cek";
	foo(x,0);
}