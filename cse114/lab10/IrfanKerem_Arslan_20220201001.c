// 20220201001-072 LAB10

#include <stdio.h>
#include <stdlib.h>

int	welcome(void)
{
	int	choice;

	printf("Welcome to Labwork 10 Darkness of Recursive World! By using this machine you can do:\n");
	printf("1. The Labyrinth of the Hero\n");
	printf("2. Shadow Binding\n");
	printf("3. Exit\n");
	printf("Make your choice:\n");
	scanf("%d", &choice);
	return (choice);
}

void shadow_binding(char *x, int printing)
{
	if (*x == '\0')
		return;
	if (*x == '(')
		printing = 1;
	if (printing)
	{
		printf("%c", *x);
		if (*x == ')')
			return;
	}
	shadow_binding(x + 1, printing);
}


int	find_exit(int map[4][4], int x, int y, int size)
{
	if (x < 0 || y < 0 || x >= size || y >= size)
		return (0);
	if (map[y][x] == 1 || map[y][x] == 2)
		return (0);
	if (map[y][x] == 9)
		return (1);
	map[y][x] = 2;
	// ı fixed that while we were in the class that we cant figure it out bayram hocam.
	if (find_exit(map, x + 1, y, size))
		return (1);
	if (find_exit(map, x - 1, y, size))
		return (1);
	if (find_exit(map, x, y + 1, size))
		return (1);
	if (find_exit(map, x, y - 1, size))
		return (1);
	return (0);
}

int	main(void)
{
	int	ok_maze[4][4] = {	{0, 1, 0, 0}, 
							{0, 1, 0, 1}, 
							{0, 0, 0, 1}, 
							{1, 1, 0,9}};
	int	not_ok_maze[4][4] = {	{0, 1, 0, 0}, 
								{0, 1, 0, 1}, 
								{0, 0, 1, 1}, 
								{1, 1, 1, 9}};

	char secret1[] = "-*xyz(magic)123*-";
	char secret2[] = "empty()space";
	int choice;

	choice = welcome();
	while (choice != 3)
	{
		if (choice == 1)
		{
			if (find_exit(ok_maze, 0, 0, 4))
				printf("There is a path!\n");
			else
				printf("No path!\n");
			if (find_exit(not_ok_maze, 0, 0, 4))
				printf("There is a path!\n");
			else
				printf("No path!\n");
		}
		else if (choice == 2)
		{
			shadow_binding(secret1, 0);
			printf("\n");
			shadow_binding(secret2, 0);
			printf("\n");
		}
		else
			printf("Invalid choice!\n");
		choice = welcome();
	}
	printf("Goodbye!\n");
}
