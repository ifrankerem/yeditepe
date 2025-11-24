//İrfan Kerem Arslan 20220201001-072 HW-6

#include <stdio.h>

int	first_index(const int A[], int size, int n)
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

int	last_index(const int A[], int size, int n)
{
	for (int i = size; i >= 0; i--)
	{
		if (A[i] == n)
		{
			return (i);
		}
	}
	return (-1);
}

int	count_in_array(const int A[], int size, int n)
{
	int	count;
	int	index;

	count = 0;
	index = first_index(A, size, n);
	while (index != -1)
	{
		count++;
		A += index + 1;
		size -= index + 1;
		index = first_index(A, size, n);
	}
	return (count);
}

void	reverse_array(int A[], int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i <= j)
	{
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
}

int	partial_reverse(int A[], int size, int n)
{
	int	count;
	int	first_i;
	int	last_i;

	count = count_in_array(A, size, n);
	if (count < 2)
		return (-1);
	first_i = first_index(A, size, n);
	last_i = last_index(A, size, n);
	if (last_i - first_i <= 2)
		return (0);
	A += first_i + 1;
	size = last_i - first_i - 1;
	reverse_array(A, size);
	return (1);
}

int	main(void)
{
	int A[11] = {9, 3, 11, 12, 13, 14, 15, 16, 3, 4, 5};
	partial_reverse(A, 11, 3);
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", A[i]);
	}
}