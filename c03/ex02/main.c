#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char str1[] = "hello";
	char str2[] = "world";

	char *str3 = ft_strcat(str1, str2);
	printf("%s\n%s\n%s\n", str1, str2, str3);
}
