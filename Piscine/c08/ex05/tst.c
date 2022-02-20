#include <unistd.h>
#include "ft_stock_str.h"
#include <stdlib.h>
#include "ft_strs_to_tab.c"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
void	ft_putnbr(int nb)
{
	char c;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		c = 48 + nb % 10;
		write(1, &c, 1);
	}
}


void	ft_write_struct(struct s_stock_str *par)
{
	ft_putstr(par->str);
	write(1, "\n", 1);
	ft_putnbr(par->size);
	write(1, "\n", 1);
	ft_putstr(par->copy);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while(par[i].str != 0)
	{
		ft_write_struct(&par[i]);
		i++;
	}
}
int	main(void)
{
	struct s_stock_str *arr;
	char **star;

	star = (char **)malloc(sizeof(char *) * 2);
	star[0] = (char *)malloc(sizeof(char) * 3);
	star[1] = (char *)malloc(sizeof(char) * 3);
	star[0] = "aa";
	star[1] = "xx";
	arr =(struct s_stock_str *)malloc(sizeof(struct s_stock_str) * 3);
	ft_show_tab(ft_strs_to_tab(2, star));
}

