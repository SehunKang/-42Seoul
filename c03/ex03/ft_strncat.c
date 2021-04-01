char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	while (*++dest);
	while ((*dest++ = *src++) && --nb);
	*dest++ = '\0';
	return (dest);
}

