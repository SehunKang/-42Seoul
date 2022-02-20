#include <stdio.h>

void	ft_swap(int *a, int *b);

int		main(void)
{
	int a = 10;
	int b = 0;

	ft_swap(&a, &b);

	printf("%d, %d\n", a, b);
}


