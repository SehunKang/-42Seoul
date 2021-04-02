#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char *str1 = "hello my name is sehun, im fucking awesome!";
	char *str2 = "sehun";
	printf("start : %p\nfound : %p\n", str1, &str1[17]);
	char *ans = ft_strstr(str1, str2);

	printf("string : %s\naddress :%p\n", ans, ans);
}
