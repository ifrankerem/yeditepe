// 20220201001-072 lAB 8

#include <stdio.h>

int	welcome(void)
{
	int	choice;

	printf("Welcome to Labwork 8 String Operations! By using this machine you can do:\n");
	printf("1. Swap Characters\n");
	printf("2. Trim Unnecessary Parts\n");
	printf("3. Count Words\n");
	printf("4. Exit\n");
	printf("Make your choice: ");
	scanf("%d", &choice);
	return (choice);
}

void	swap_characters(char *str, int size)
{
	char	temp;

	int index1, index2;
	printf("Enter the first index: ");
	scanf("%d", &index1);
	printf("Enter the second index: ");
	scanf("%d", &index2);
	if (index1 >= 0 && index1 < size && index2 >= 0 && index2 < size)
	{
		temp = str[index1];
		str[index1] = str[index2];
		str[index2] = temp;
		printf("%s\n", str);
	}
	else
	{
		printf("Invalid indexes!\n");
	}
}

void	trim_plus(char *str, int size)
{
	char	result[500];
	int		j;

	j = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] != '+')
		{
			result[j] = str[i];
			j++;
		}
	}
	result[j] = '\0';
	printf("%s\n", result);
}

int	count_words(char *str, int size, char key)
{
	int	count;
	int	newWord;

	count = 0;
	newWord = 1;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ' ')
			newWord = 1;
		else
		{
			if (newWord == 1)
			{
				if (str[i] == key || str[i] == (key - 32) || str[i] == (key
						+ 32))
				{
					count++;
				}
				newWord = 0;
			}
		}
	}
	return (count);
}

int	ft_strlen(char *x)
{
	int	i;

	i = -1;
	while (x[++i])
		;
	return (i);
}

int	main(void)
{
	int		choice;
	char	sentence2[] = "pesim+++ist sago+pa kaj+++mer";
	char	sentence3[] = "kötü	insanları tanıma senesi";
	char	swapStr[] = "bukelamun gözler sansi salvo kafiyesi";
	int		size1;
	int		size2;
	char	key;
	int		size3;
	int		wordCount;

	choice = welcome();
	while (choice != 4)
	{
		if (choice == 1)
		{
			size1 = ft_strlen(swapStr);
			swap_characters(swapStr, size1);
		}
		else if (choice == 2)
		{
			size2 = ft_strlen(sentence2);
			trim_plus(sentence2, size2);
		}
		else if (choice == 3)
		{
			printf(">> Enter the key: ");
			scanf(" %c", &key);
			size3 = ft_strlen(sentence3);
			wordCount = count_words(sentence3, size3, key);
			printf("There are %d words that start with %c.\n", wordCount, key);
		}
		else
		{
			printf("Invalid choice!\n");
		}
		choice = welcome();
	}
	return (0);
}
