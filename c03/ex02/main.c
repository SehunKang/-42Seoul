#include <stdio.h>
char *ft_strcat(char *dest, char *src);

int	main(void)
{
	char str1[50] = "Hello ";
	char *str2 = "World!";

	ft_strcat(str1, str2);
	printf("%s\n", str1);
}

