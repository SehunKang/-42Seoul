#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int		main(void)
{
	int a = 17;
	int b = 5;
	int div;
	int mod;

	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d\n", div, mod);
}

