char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;

	i = 0;
	while (*++dest);
	while ((*dest = *src) && i < nb)
	{
		dest++;
		src++;
		i++;
	}
	*dest++ = '\0';
	return (dest);
}

