#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "display_file.h"

void	print_error(int fd, char *str)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
}

int	display_file(char *argv)
{
	int fd;
	int len;
	char buf[MAX];

	fd = open(argv, O_RDONLY);
	if ((len = read(fd, buf, 1) > 0))
	{
		write(1, buf, len);
		while ((len = read(fd, buf, MAX)) > 0)
			write(1, buf, len);
	}
	else
	{
		print_error(2, READERR);
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		print_error(2, ARGMISS);
		return(1);
	}
	else if (argc > 2)
	{
		print_error(2, ARGOVER);
		return(1);
	}
	return (display_file(argv[1]));
}
