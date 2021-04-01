#include <stdio.h>
#include <stdlib.h>
char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(/*int argc, char **argv*/)
{
	//(void)argc;
	char str1[50] = "The World ";
	char *str2 = "is mine!";
	ft_strncat(str1, str2, 10);

	printf("%s", str1);
}

