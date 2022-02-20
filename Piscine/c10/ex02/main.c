#include "tail.h"

char *g_basename;
char *g_buf;
int g_bufsize;


void	print_sign(char *str, int i)
{
	if (3 < i)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==\n");
}

void	print_tail(char *path, int fd)
{
	int i;
	int tmp;

	while (read(fd, &g_buf[i % g_bufsize], 1))
	{
		if (errno)
		{
			ft_strerr(path);
			return ;
		}
		i++;
	}
	tmp = i % g_bufsize;
	if (g_bufsize <= i)
		write(1, g_buf + tmp, g_bufsize - tmp);
	write(1, g_buf, tmp);
}

void	check_tail(int argc, char **argv)
{
	int i;
	int fd;

	i = 3;
	while (i < argc)
	{
		errno = 0;
		if ((fd = open(argv[i], O_RDONLY)) == -1)
		{
			ft_strerr(argv[i]);
			continue ;
		}
		if (4 < argc)
			print_sign(argv[i], i);
		print_tail(argv[i], fd);
		close(fd);
		i++;
	}
}

int 	main(int argc, char **argv)
{
	g_basename = argv[0];
	g_bufsize = ft_atoi(argv[2]);
	g_buf = (char*)malloc(g_bufsize);
	if (g_bufsize == 0)
		return (0);
	if (argc == 3)
		print_tail(0, 0);
	else
		check_tail(argc, argv);
	free(g_buf);
	return (0);
}
