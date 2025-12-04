//İrfan Kerem Arslan 20220201001-072 HW-7
#include <stdio.h>

int	*first_in_array(int *first, int *last, int n)
{
	int	*p;

	p = first;
	while (p != last)
	{
		if (*p == n)
			return (p);
		p++;
	}
	return (last);
}

int	count_in_array_v3(int *first, int *last, int n)
{
	int	count;
	int	*p;

	count = 0;
	p = first_in_array(first, last, n);
	while (p != last)
	{
		count++;
		first = p + 1;
		p = first_in_array(first, last, n);
	}
	return (count);
}

int	main(void)
{
	int A[11] = {9, 3, 11, 12, 13, 14, 15, 16, 3, 4, 5};
	// printf("%p\n", &A[2]);
	// printf("%p\n", first_in_array(A, A + 11, 11));
	printf("%d\n", count_in_array_v3(A, A + 11, 4));
}