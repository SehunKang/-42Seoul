#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*cp;
	int		i;

	if((cp = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)) == NULL)
		return (0);
	i = 0;
	while ((cp[i] = src[i]))
		i++;
	cp[i] = '\0';
	return (cp);
}

int		ft_check_charset(char c, char *charset)
{
	int i;

	i = 0;
	while (charset[i] && c != '\0')
	{
		if (c == charset[i])
			return(1);
		i++;
	}
	return (0);
}

int		ft_count_strings(char *str, char *charset)
{
	int	i;
	int set;
	int count;

	count = 0;
	set = 1;
	i = 0;
	while (str[i])
	{
		if (!(ft_check_charset(str[i], charset)))
		{
			if (set > 0)
			{
				count++;
				set = 0;
			}
		}
		else
			set++;
		i++;
	}
	return (count);
			
}

int		main(void)
{
	char *str1 = "zzzzzxxxzAzxzxA  AxAAAyAAAzAAAxyzxyzxyzxxzzyy";
	char *str2 = "xyz";
	int num = ft_count_strings(str1, str2);
	printf("%d\n", num);
}


//char	**ft_split(char *str, char *charset);

