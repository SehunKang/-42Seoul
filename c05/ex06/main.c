#include <stdio.h>
#include <stdlib.h>

int	ft_is_prime(int nb);

int	main(int argc, char **argv)
{
	(void)argc;
	if (ft_is_prime(atoi(argv[1])) == 1)
		printf("%d is a primenumber\n", atoi(argv[1]));
	else
		printf("%d is not a primenumber\n", atoi(argv[1]));
}
