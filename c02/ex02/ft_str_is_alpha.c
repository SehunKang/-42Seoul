#include <stdio.h>

int	ft_str_is_alpha(char *str)
{

	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 65 || (90 < str[i] && str[i] < 97))
			return (0);
		else if (122 < str[i])
			return (0);
		i++;
	}

	return (1);
}

int main()
{
	char *str1 = "12345a12345";
	char *str2 = "abcde";
	char *str3 = "";
	char *str4 = "-1234^5";
	char *str5 = "0Z";

	int a = ft_str_is_alpha(str1); 
	int b = ft_str_is_alpha(str2); 
	int c = ft_str_is_alpha(str3); 
	int d = ft_str_is_alpha(str4); 
	int e = ft_str_is_alpha(str5); 

	printf("a%d b%d c%d d%d e%d", a, b, c, d, e);
}

