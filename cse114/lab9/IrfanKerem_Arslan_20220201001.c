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
	printf("--- BONUS ---\n");
	printf("11. GCD (Greatest Common Divisor)\n");
	printf("12. Print Binary\n");
	printf("Make your choice: ");
	scanf("%d", &choice);
	return (choice);
}

int	factorial(int n)
{
	if (n <= 1)
	{
		printf("Calculating : 1! = 1\n");
		return (1);
	}
	printf("Calculating : %d! = %d x %d!\n", n, n, n - 1);
	return (n * factorial(n - 1));
}

int	sum_of_digits(int n)
{
	int	digit;

	digit = n % 10;
	printf("%d", digit);
	if (n < 10)
	{
		printf(" = ");
		return (digit);
	}
	printf(" + ");
	return (digit + sum_of_digits(n / 10));
}

int	power(int base, int exponent)
{
	if (exponent == 0)
		return (1);
	if (exponent == 1)
		return (base);
	return (base * power(base, exponent - 1));
}

int	print_ascending(int start, int end)
{
	printf("%d", start);
	if (start == end)
		return (end);
	printf(" ");
	return (print_ascending((start + 1), end));
}

int	print_descending(int start, int end)
{
	printf("%d", start);
	if (start == end)
		return (end);
	printf(" ");
	return (print_descending((start - 1), end));
}

int	multiply(int a, int b)
{
	if (b == 0)
		return (0);
	if (b == 1)
	{
		printf("Calculating: %d x %d = %d\n", a, b, a);
		return (a);
	}
	printf("Calculating: %d x %d = %d + (%d x %d)\n", a, b, a, a, b - 1);
	return (a + multiply(a, b - 1));
}

int	divide(int a, int b)
{
	if (a < b)
	{
		printf("Calculating: %d / %d = %d\n", a, b, 0);
		return (0);
	}
	printf("Calculating: %d / %d = %d + (%d / %d)\n", a, b, 1, (a - b), b);
	return (1 + divide(a - b, b));
}

int	count_digits(int n)
{
	if (n < 10)
		return (1);
	return (1 + count_digits(n / 10));
}
int reverse_number(int n)
{
	int	last_digit;
	int	digits;

	if (n < 10)
		return (n);
	last_digit = n % 10;
	digits = count_digits(n);
	return (last_digit * power(10, digits - 1) + reverse_number(n / 10));
}

int	gcd(int a, int b)
{
	if (b == 0)
		return (a);
	printf("Calculating: gcd(%d, %d) = gcd(%d, %d)\n", a, b, b, a % b);
	return (gcd(b, a % b));
}

void	print_binary(int n)
{
	if (n == 0)
		return;
	print_binary(n / 2);
	printf("%d", n % 2);
}

int	main(void)
{
	int choice = welcome();
	if (choice == 1 || choice == 2 || choice == 8 || choice == 9 || choice == 12)
	{
		int number;
		printf("Enter a number: ");
		scanf("%d", &number);
		if (choice == 1)
			printf("Result: %d! = %d", number, factorial(number));
		else if (choice == 2)
		{
			printf("Sum of Digits : ");
			printf("%d", sum_of_digits(number));
		}
		else if (choice == 8)
			printf("Number of digits : %d", count_digits(number));
		else if (choice == 9)
			printf("Reversed number: %d", reverse_number(number));
		else
		{
			printf("Binary: ");
			if (number == 0)
				printf("0");
			else
				print_binary(number);
		}
	}
	else if (choice == 3)
	{
		int base;
		int exponent;
		printf("Enter base: ");
		scanf("%d", &base);
		printf("Enter exponent: ");
		scanf("%d", &exponent);
		printf("Result: %d^%d = ", base, exponent);
		printf("%d", power(base, exponent));
	}
	else if (choice == 4 || choice == 5)
	{
		int start;
		int end;
		printf("Enter start: ");
		scanf("%d", &start);
		printf("Enter end: ");
		scanf("%d", &end);
		printf("Numbers: ");
		if (choice == 4)
			print_ascending(start, end);
		else
			print_descending(start, end);
	}
	else if (choice == 6 || choice == 11)
	{
		int first;
		int second;
		int result;
		printf("Enter first number: ");
		scanf("%d", &first);
		printf("Enter second number: ");
		scanf("%d", &second);
		if(choice == 6)
		{
			result = multiply(first, second);
			printf("Result : %d x %d = %d", first, second, result);
		}
		else
		{
			result = gcd(first, second);
			printf("Result: gcd(%d, %d) = %d", first, second, result);
		}
	}
	else if (choice == 7)
	{
		int dividend;
		int divisor;
		int result;
		printf("Enter dividend: ");
		scanf("%d", &dividend);
		printf("Enter divisor: ");
		scanf("%d", &divisor);
		result = divide(dividend, divisor);
		printf("Result : %d / %d = %d", dividend, divisor, result);
	}
	return 0;
}