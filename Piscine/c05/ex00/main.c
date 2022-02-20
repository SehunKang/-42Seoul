#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_factorial(int nb);

int	main(int argc, char **argv)
{
	(void)argc;
	int num = ft_iterative_factorial(atoi(argv[1]));
	printf("%d", num);
}
