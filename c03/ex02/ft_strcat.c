#include <stdio.h>

int	main(void);

char	*ft_strcat(char *dest, char *src)
{
	printf("%d,%p\n", dest[0], dest);
	while (*++dest);
	printf("%s,%p\n", dest, dest);
	while ((*dest++ = *src++));
	int i = 0;
	while (++i < 10)
	{
		printf("%c", dest[i]);
	}
	printf("%s, %p\n",dest, dest);
	return (dest);
}

