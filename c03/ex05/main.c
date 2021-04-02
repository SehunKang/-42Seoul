#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "World!";

	int num = ft_strlcat(str1, str2, 11);

	printf("num = %d\nstr = %s\n", num, str1);
}


