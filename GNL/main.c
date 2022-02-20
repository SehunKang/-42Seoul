#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	char *line;
	int fd;
	int res;

	fd = open("./a.txt", O_RDONLY);
	while (res != 0)
	{
		res = get_next_line(fd, &line);
		printf("fd = %d, %d - %s\n",fd, res, line);
		free(line);
	}
	/*
	fd = open("./b.txt", O_RDONLY);
	for (int i = 0; i < 2; i++)
	{
		res = get_next_line(fd, &line);
		printf("fd = %d, %d - %s\n",fd, res, line);
		free(line);
	}
	for (int i = 0; i < 2; i++)
	{
		res = get_next_line(3, &line);
		printf("fd = %d, %d - %s\n",3 , res, line);
	}
	for (int i = 0; i < 2; i++)
	{
		res = get_next_line(4, &line);
		printf("fd = %d, %d - %s\n",4 , res, line);
	}*/
}

