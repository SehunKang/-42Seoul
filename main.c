#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *line;
	int result;

	fd = open("./a.txt", O_RDONLY);
	int i = 0;
	printf("fd = %d\n", fd);
	while ((result =get_next_line(fd, &line)) > 0)
	{
		printf("result : %d\nline : %s\n", result, line);	
	}
	printf("result : %d\nline : %s\n", result, line);	
	close(fd);
}
