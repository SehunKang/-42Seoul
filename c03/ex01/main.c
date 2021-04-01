#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n);

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_strncmp(argv[1], argv[2], (unsigned int)atoi(argv[3])));
}

