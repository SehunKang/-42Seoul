#ifndef TAIL_H
# define TAIL_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>

int	ft_atoi(char *str);
void	print_error(int fd, char *str);
void	ft_strerr(char *path);
void	ft_putstr(char *str);

char *g_basename;

#endif
