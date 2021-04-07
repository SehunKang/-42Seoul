#include <stdio.h>

char	*ft_strdup(char *src);

int	main(void)
{
	char *str1 = "hello";

	char *str2 = ft_strdup(str1);
	printf("%s", str2);
}

