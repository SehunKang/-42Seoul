#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int	main(int argc, char **argv)
{
	int i = 1;
	(void)argc;
	while (i <= atoi(argv[1]))
	{
		if (ft_sqrt(i) != 0)
		{
			printf("%d : %d\n", i , ft_sqrt(i));
		}
		i++;
	}
}
