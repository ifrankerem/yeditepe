//İrfan Kerem Arslan 20220201001-072 LAB7

#include <stdio.h>

// PART 1

void	longPointerOps(void)
{
	long	int		bigNum;
	long	int		*ptr;

	bigNum = 100000;
	ptr = &bigNum;
	printf("bigNum = %ld\n*ptr = %ld\naddress of bigNum = %p\naddress of ptr = %p\n", bigNum, *ptr, &bigNum, &ptr);
}

void	 doublePointerOps(void)
{
	double		gravity;
	double		*p_gravity;

	gravity = 9.81;
	p_gravity = &gravity;
	printf("*p_gravity = %lf\naddress of gravity = %p\n", *p_gravity,&gravity);
}

void	 charChangeCase(void)
{
	char 		ch;
	char		*p_ch;

	ch = 'a';
	p_ch = &ch;
	*p_ch = 'A';
	printf("New value of ch = %c\n",ch);
}

//PART 2

void	 modifyBalance(void)
{
	float 		balance;
	float		*p_bal;

	balance = 100.50;
	p_bal = &balance;
	*p_bal = 250.75;
	printf("New value of balance = %lf\n",balance);
}

void	 updateTemperature(void)
{
	double 		temp;
	double		*ptr;

	temp = 36.5;
	ptr = &temp;
	*ptr = 37.2;
	printf("New value of temp = %lf\n",temp);
}

void clampValue(int *p_val, int min, int max)
{
	if(*p_val <= min)
		*p_val = min;
	else if(*p_val >= max)
		*p_val = max;
}

void printDoubleArrayPtr(double *arr, int size)
{
	int i = -1;
	while(++i < size)
	{
		printf("%lf\n",*arr);
		arr++;
	}
}


int	main(void)
{
	//PART 1 FUNCTIONS
	//longPointerOps();
	//doublePointerOps();
	//charChangeCase();
	//PART 2 FUNCTİONS
	//modifyBalance();
	//updateTemperature();
	// int val = 150;
	// int *p_val = &val;
	// clampValue(p_val,0,100);
	// printf("%d\n",val);
	// double arr[3] = {1,2,3};
	// printDoubleArrayPtr(arr,3);
}
