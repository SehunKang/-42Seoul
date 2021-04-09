#include <stdio.h>
#include <stdlib.h>

int ascendig(int a, int b)
{
	return (a <= b);
}

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ascendig(atoi(argv[1]),atoi(argv[2])));
}
