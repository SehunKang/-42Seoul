#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char *str1 = "Hello, my name is sehun, wassup?";
	char *str2 = " ";

	char *str3 = ft_strstr(str1, str2);
	char *str4 = &str1[18];
	printf("%p : %s\n%p : %s\n%p : %s\n%p : %s\n", str1, str1,str4,str4, str2, str2, str3, str3);
}
