#include <stdio.h>

// Soru: Sayının basamakları toplamını recursion olarak hesapla.
int	f(int n)
{
	if (n <= 9)
		return (n);
	return (n % 10 + f(n / 10));
}
// Soru: Dizideki (negatifleri atlayarak) elemanların basamak toplamlarını recursion topla.
int	g(int A[], int n)
{
	if (n < 1)
		return (f(A[n]));
	if (A[n] < 0)
		n--;
	return (f(A[n]) + g(A, n - 1));
}

// Soru: Bir cümledeki 3. kelimenin son harfinin adresini döndür.
char	*find_last(char *str)
{
	int	word_count;

	word_count = 0;
	while (*str == ' ')
		str++;
	while (*str)
	{
		if (*str == ' ')
			word_count++;
		if (word_count == 3)
		{
			while (*str != ' ')
				str++;
			return (str);
		}
		str++;
	}
	return (NULL);
}

// Soru: 3. kelimeyi tersten alıp dest içine kopyala ve yazdır.
void	foo(char *dest, char *str)
{
	char	*last;

	char *first = dest; // for debugging
	last = find_last(str);
	last--;
	while (*last != ' ')
	{
		*dest = *last;
		dest++;
		last--;
	}
	*dest = '\0';
	printf("%s", first); // for debugging
}

// Soru: Dizide 3 kez geçen n sayısını bul; ilk iki tekrar arası toplama ve ikinci ile üçüncü tekrar arası toplama farkını döndür.
int	sum(int A[], int size)
{
	int	i = 0, j = 0, first = 0, second = 0, found = 0, third = 0, n = 0,
			sum_1 = 0, sum_2;

	i = 0, j = 0, first = 0, second = 0, found = 0, third = 0, n = 0, sum_1 = 0,
		sum_2 = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (A[i] == A[j])
				n = A[j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (A[i] == n)
		{
			first = i;
			i += 1;
			while (A[i] != n)
			{
				sum_1 += A[i];
				i++;
			}
			second = i;
			found = 1;
			i += 1;
			while (A[i] != n)
			{
				sum_2 += A[i];
				i++;
			}
			third = i;
		}
		i++;
	}
	return (sum_1 - sum_2);
}

int	main(void)
{
	char dest[250];
	int A[4] = {347, 347, -347, 347};
	// printf("%d\n",f(347));
	// printf("%d\n",g(A,4));
	char *str = "sagopa kajmer kuvvet mira";
	char *p = find_last(str);
	int B[10] = {1, 2, 9, 12, 13, 9, 15, 16, 9, 5};
	printf("%d\n", sum(B, 10)); // -6
	// foo(dest,str);
	// printf("%s",p);
}