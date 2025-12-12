// 20220201001-072 lAB 9
#include <stdio.h>

int	welcome(void)
{
	int	choice;

	printf("Welcome to Labwork 9 String Operations! By using this machine you can do:\n");
	printf("1. Calculate Factorial\n");
	printf("2. Sum of Digits\n");
	printf("3. Power Calculation\n");
	printf("4. Print Numbers (Ascending)\n");
	printf("5. Print Numbers (Descending)\n");
	printf("6. Multiplication (Recursive)\n");
	printf("7. Division (Recursive)\n");
	printf("8. Count Digits\n");
	printf("9. Reverse Number\n");
	printf("10. Exit\n");
	printf("Make your choice: ");
	scanf("%d", &choice);
	return (choice);
}

int factorial(int n)
{
	if(n <= 1)
	{
		printf("Calculating : 1! = 1\n");
		return 1;
	}
	printf("Calculating : %d! = %d x %d!\n",n,n,n-1);
	return n * factorial(n-1);
}

int sum_of_digits(int n)
{
	int digit = n % 10;
	return (digit + sum_of_digits(n/10));
}


int main()
{
	// printf("%d\n",factorial(5));
	printf("%d\n",sum_of_digits(12345));
}