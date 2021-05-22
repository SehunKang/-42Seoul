/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/22 13:22:11 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *buf_stack(char **str_backup, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str_backup, buf);
	free(*str_backup);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char *str_backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			result;
	int			r_bytes;

	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (str_backup[fd] == NULL)
	{
		str_backup[fd] = ft_strdup("");
		while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[r_bytes] = '\0';
			str_backup[fd] = buf_stack(&str_backup[fd], buf);
		}
	}
	result = 1;
	*line = str_backup[fd];
	return (result);
}

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int fd;
	fd = open("./a.txt", O_RDONLY);
	char **line;
	int i;
	i = get_next_line(fd, line);
	close(fd);
	int j = 0;
	char *str;
	str = *line;
	printf("fd = %d\nresult(i) = %d\nstr = **%s**\n", fd, i, *line);
}
