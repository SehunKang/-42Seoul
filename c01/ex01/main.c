#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);

int		main(void)
{
	int x;
	int *a = &x;
	int **b = &a;
	int ***c = &b;
	int ****d = &c;
	int *****e = &d;
	int ******f = &e;
	int *******g = &f;
	int ********h = &g;
	int *********i = &h;
	ft_ultimate_ft(i);
	printf("%d\n", x);
}


	
