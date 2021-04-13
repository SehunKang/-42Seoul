#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>

char *g_basename;

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
void	ft_cat(char *path, int fd)
{
	int len;
	char buf[1];

	while ((len = read(fd, buf, 1)))
	{
		if (errno)
		{
			ft_strerr(path);
			return ;
		}
		write(1, buf, len);
	}
}

int 	main(int argc, char **argv)
{
	int i;
	int fd;

	g_basename = argv[0];
	if (argc == 1)
	{
		ft_cat(0, 0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if ((fd = open(argv[i], O_RDONLY)) == -1)
			{
				ft_strerr(argv[i]);
				continue;
			}
			ft_cat(argv[i], fd);
			close(fd);
			i++;
		}
		return (0);
	}
}

