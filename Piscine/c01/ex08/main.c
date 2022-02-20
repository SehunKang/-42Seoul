#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int		main(void)
{
	int arr[] = {0, -10, 100, 10, 1, -1};
	
	ft_sort_int_tab(arr, 6);

	printf("%d, %d, %d, %d, %d, %d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5]);
}

