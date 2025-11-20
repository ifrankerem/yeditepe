//İrfan Kerem Arslan 20220201001-072 LAB7

#include <stdio.h>
#include <limits.h> //for limits INT_MAX and INT_MIN

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
//PART 3

void printDoubleArrayPtr(double *arr, int size)
{
	int i = -1;
	while(++i < size)
	{
		printf("%lf\n",*arr);
		arr++;
	}
}
float avgArrayPtr(int *arr,int size)
{
	float avg = 0;
	int i = -1;
	while(++i < size)
	{
		avg += *arr;
		arr++;
	}
	avg /= size;
	return(avg);
}

int findMaxPtr(int *arr,int size)
{
	int max = INT_MIN;
	int i = -1;
	while(++i < size)
	{
		if(*arr > max)
			max = *arr;
		arr++;
	}
	return(max);
}
//PART 4

void swapFloats(float *a, float *b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void negate(int *n)
{
	*n *= -1;
}

void rect_stats(int width, int height, int *area, int *perimeter)
{
	*area = width * height;
	*perimeter = 2 * (width + height);
}

//PART 5

void demonstrateDoublePtrFloat()
{
	float f = 3.14;
	float *ptr = &f;
	float **pptr = &ptr;
	printf("*ptr = %lf\n **pptr = %lf\n",*ptr,**pptr);
}

void modifyCharViaDoublePtr(char **p)
{
	**p = 'Z';
}

void pointToMax(int **pp, int *a , int *b)
{
	if(*a > *b)
		**pp = *a;
	else 
		**pp = *b;
}

//You can test 

int	main(void)
{
	longPointerOps();
	doublePointerOps();
	charChangeCase();
	modifyBalance();
	updateTemperature();
	int val = 150;
	int *p_val = &val;
	clampValue(p_val,0,100);
	printf("%d\n",val);
	double arr[3] = {1,2,3};
	printDoubleArrayPtr(arr,3);
	int avg[4] = {1,2,3,4};
	printf("%lf\n",avgArrayPtr(avg,4));
	printf("%d\n",findMaxPtr(avg,4));
	float x = -4;
	float y = 3;
	swapFloats(&x,&y);
	printf("After Swap:\n x: %lf\n y:%lf\n",x,y);
	int u = 5;
	negate(&u);
	printf("Negated u: %d\n",u);
	int w = 3;
	int h = 8;
	int area;
	int perimeter;
	rect_stats(w,h,&area,&perimeter);
	printf("Stats:\nArea: %d\nPerimeter: %d\n",area,perimeter);
	demonstrateDoublePtrFloat();
	char a = 'a';
	char *ptr = &a;
	char **p_p = &ptr;
	modifyCharViaDoublePtr(p_p);
	printf("After modify: %c\n",a);
	int t = 5;
	int q = 10;
	int z = 42;
	int *p = &z;
	int **pp = &p;
	pointToMax(pp,&t,&q);
	printf("Max from a to b is: %d\n",**pp);
}
