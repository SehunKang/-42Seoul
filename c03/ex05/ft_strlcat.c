unsigned int	ft_strlcat(char *dest, char *stc, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (*dest)
	{
		dest++;
		i++;
	}
	while (j < size - i - 1)
		*dest++ = *stc++;

