//İrfan Kerem Arslan 20220201001-072 HW-9

#include <stdio.h>

char *first(char *s1,char *s2)
{
	char  *word_end = s1;
	int len = 0;
 	while (*word_end && *word_end != ' ')
        word_end++;
	char *p_2 = s2;
	while(*s2)
	{
		while(*s_1 != *s2)
		{
			len++;
			s_1++;
			s2++;
		}
		if(word_count == len && (*(s2 + 1) == ' ' || *(s2 + 1) == '\0'))
			return s2;
	}
	return NULL;
}

int count_of_first(char *s1, char *s2)
{
	int count = 0;
	char *s_2 = s2;
	while(1)
	{
		s_2 = first(s1,s_2);
		if(s_2 == NULL)
			break;
		count++;
	}
	return count;
}

void print_counts(char *s1, char *s2)
{
	int word_len;
	int nbr;
	int word_count = 0;
	while(*s1)
	{
		char *s_1 = s1;
		nbr = 0;
		word_len = 0;
		while(*s_1 != ' ')
		{
			word_len++;
			s_1++;
			if(*s_1 == '\0')
				break;
		}
		word_count++;
		nbr = count_of_first(s1,s2); 
		printf("count of word %d: %d\n",word_count,nbr);
		s1 += word_len + 1;
		if(*(s1 -1) == '\0')
			break;
	}
}

int main()
{
	//printf("%s\n",first("ab cd", "abc de abc ab"));
	//printf("%d\n",count_of_first("ab cd", "ab abc ab"));
	print_counts("ab cd ef", "ab ef a ef bc ab");

}