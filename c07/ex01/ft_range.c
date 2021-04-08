#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *arr;
	unsigned int size;
	unsigned int i;

	size = max - min;
	if (max <= min)
		return (NULL);
	if((arr = malloc(sizeof(int) * size)) == NULL)
		return (NULL);
	i = 0;
	while(i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

int main()
{
	int *arr;
	arr = ft_range(-100, 100);
	int i = 0;
	while(i <= 200)
	{
		printf("%d ", arr[i]);
		i++;
	}
}
	
