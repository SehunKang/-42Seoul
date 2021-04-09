int	ft_strlen(char *str)
{
	int i;

	i = 0;	
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char *cp;
	int	i;

	if (!(cp = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (0);
	i = 0;
	while ((cp[i] = src[i]))
		i++;
	cp[i] = '\0';
	return (cp);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	int i			i;
	struct s_stock_str 	*arr;

	i = 0;
	if (!(arr = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return(arr);
}
