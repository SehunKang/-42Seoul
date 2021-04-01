char	*ft_strstr(char *str, char *to_find)
{
	int j;

	while(*str)
	{
		j = 0;
		while(*(str + j) == *(to_find + j))
		{
			j++;
			if (!*(to_find + j))
				return(str);
		}
		str++;
	}

	return (str);
}
