//İrfan Kerem Arslan 20220201001-072 HW-4
#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	int k = 2;
	while(++i <= 10)
	{
		int i_save = i;
		j = 0;
		k = i+1;
		while(j <= 20)
		{
			printf("%d ",i);
			i = i + k;
			k *= 2;
			j++;
		}
		printf("\n");
		i = i_save; 
		k++;
	}
}
