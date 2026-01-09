//İrfan Kerem Arslan 20220201001-072 HW-8

#include <stdio.h>

int *start(int *first)
{
	int *ret;
	while(*first != 0)
		first++;
	ret = first;
	return ret;
}

int *end(int *last)
{
	int *ret;
	while(*last != 0)
		last--;
	ret = last;
	return ret;
}

void print_reverse(int *p, int *q)
{
	while(p != q)
	{
		printf("%d\n",*q);
		q--;
	}
	printf("%d\n", *q);
}

int main()
{
	int arr[] = {1,2,3,4,0,0,0,0,5,6,7,8,9,};
	int *s = start(&arr[0]);
	int	*e = end(&arr[12]);
	print_reverse(&arr[0],s -1);
	printf("-----------------\n");
	print_reverse(e + 1,&arr[12]);
}