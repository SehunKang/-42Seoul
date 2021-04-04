#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char str1[] = "hello";
	char str2[] = "world";

	char *str3 = ft_strncat(str1, str2, -1);
	printf("%s\n%s\n%s\n", str1, str2, str3);
}
