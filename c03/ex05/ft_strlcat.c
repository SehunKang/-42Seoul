#include <stdio.h>
unsigned int	strleng(char *str)
{
	unsigned int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dest_len;
	unsigned int src_len;

	dest_len = strleng(dest);
	src_len = strleng(src);
	i = 0;
	if(size <= dest_len)
		return (src_len + size);	
	while (i < size - dest_len - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
