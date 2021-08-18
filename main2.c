#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main(void)
{
	int fd;
	int res;
	char *line;

	while((fd = open("./a.txt", O_RDONLY)) > 0)
		printf("%d\n", fd);
}

