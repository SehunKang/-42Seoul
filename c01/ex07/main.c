#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

int		main()
{
	int arr[] = {792, 383, 613, 2437, 3323, 1061};

	ft_rev_int_tab(arr, 6);

	printf("%d %d %d %d %d %d",arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
}

