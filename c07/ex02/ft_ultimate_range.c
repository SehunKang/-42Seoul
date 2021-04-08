#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int *arr;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	if ((arr = (int *)malloc(sizeof(int) * size)) == NULL)
	       return (-1);
	*range = arr;
	i = 0;
	while (i <= size - 1)
	{
		arr[i] = min + i;
		i++;
	}
	return (size);
}
