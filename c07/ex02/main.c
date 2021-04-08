#include <stdio.h>
#include <stdlib.h> 

int	ft_ultimate_range(int **range, int min, int max);

int	main(int argc, char **argv)
{
	(void)argc;
	int *rang;
	int min = atoi(argv[1]);
	int max = atoi(argv[2]);
	int num;
       	num = ft_ultimate_range(&rang, min, max);
	int i = 0;
	while (i < max - min)
	{
		printf("%d ",rang[i]);
		i++;
	}
	printf("\nnum : %d\n", num);
}
