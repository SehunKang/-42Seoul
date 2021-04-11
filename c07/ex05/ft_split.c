#include <stdlib.h>
#include <stdio.h>

char	*ft_strdnup(char *src, int n)
{
	char	*cp;
	int		i;

	if(!(cp = (char *)malloc((n + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

int		ft_check_set(char c, char *charset)
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

int		ft_cnt_strs(char *str, char *charset)
{
	int	i;
	int set;
	int count;

	count = 0;
	set = 1;
	i = 0;
	while (str[i])
	{
		if (ft_check_set(str[i], charset))
			set++;
		else
		{
			if (set > 0)
			{
				count++;
				set = 0;
			}
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int i;
	int j;
	char **arr;
	char *cp;

	arr = (char **)malloc(sizeof(char *) * (ft_cnt_strs(str, charset) + 1));
	i = 0;
	cp = str;
	while(*cp)
	{
		if (ft_check_set(*cp, charset))
			cp++;
		else
		{
			j = 1;
			while (!(ft_check_set(cp[j], charset)) && cp[j])
				j++;
			arr[i] = ft_strdnup(cp, j);
			cp += j;
			i++;
		}
	}
	arr[i] = 0;
	return (arr);
}



int		main(void)
{
	char *str1 = "xxxzzzyyyzyy";//"0xyz0xyz0xxxzzzzzxxxzAzxzxAAxAAAyAAAAzA A A A Axyzxyzxyzxxzzyy A ";
	char *str2 = "xyz";
	int num = ft_cnt_strs(str1, str2);
	char **strs = ft_split(str1, str2);
	int i = 0;
	while (i < num)
	{
		printf("%s\n", strs[i]);
		i++;
	}
}



