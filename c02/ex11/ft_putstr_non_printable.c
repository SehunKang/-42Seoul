#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;
	int j;
	char *hexnum;

	i = 0;
	hexnum = "012345689abcde";
	while (str[i] != '\0')
	{
		j = 0;
		if ((0 < str[i] && str[i] < 31) || str[i] == 127)
		{
			while (str[i] > 16)
			{
				str[i] = str[i] / 16;
				j++;
			}
			ft_putchar('\\');
			ft_putchar(hexnum[j]);
			ft_putchar(hexnum[str[i] - 1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
