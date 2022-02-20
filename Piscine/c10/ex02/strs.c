#include "tail.h"

int	ft_atoi(char *str)
{
	int value;

	value = 0;

	while (*str)
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	return (value);
}

void	print_error(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

void	ft_strerr(char *path)
{
	print_error(2, basename(g_basename));
	print_error(2, ": ");
	print_error(2, path);
	print_error(2, ": ");
	print_error(2, strerror(errno));
	print_error(2, "\n");
	errno = 0;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
