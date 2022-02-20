#include <stdio.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int num;
	(void)argc;

	num = ft_atoi(argv[1]);
	printf("num = %d\n", num);
}

