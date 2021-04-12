#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *str[] = {"hello", "my", "name", "is", "sehun"};
	char str2[] = "XXX";
	
	char *endstr;

	endstr = ft_strjoin(5, str, str2);
	printf("%s\n", endstr);
}

