#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = argc;
	while (1 < i)
	{
		j = 0;
		while (argv[i - 1][j])
		{
			write(1, &argv[i - 1][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}
