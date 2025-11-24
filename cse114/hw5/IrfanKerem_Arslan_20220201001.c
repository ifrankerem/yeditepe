//İrfan Kerem Arslan 20220201001-072 HW-5

#include <stdio.h>

int	index_of_first(const int A[], int size, int n)
{
	for (int i = 0; i <= size - 1; i++)
	{
		if (A[i] == n)
		{
			return (i);
		}
	}
	return (-1);
}

int	count_with_first(const int A[], int size, int n)
{
	int	count;
	int	index;

	count = 0;
	index = index_of_first(A, size, n);
	while (index != -1)
	{
		count++;
		A += index + 1;
		size -= index + 1;
		index = index_of_first(A, size, n);
	}
	return (count);
}

int	main(void)
{
	int A[9] = {1, 2, 2, 2, 1, 3, 3, 4, 5};
	printf("%d\n", count_with_first(A, 9, 2));
}