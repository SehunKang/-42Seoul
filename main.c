#include <stdio.h>
#include "libft.h"

size_t ft_strlen(const char *s);

int	main(void)
{
	printf("%lu\n", ft_strlen("12345"));
	printf("%lu\n", strlen("12345"));
}
