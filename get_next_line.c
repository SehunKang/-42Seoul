/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/20 15:34:20 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_lines.h"

char *buf_stack(char *str_backup, char *buf)
{
	char *tmp;

	tmp = ft_strjoin(str_backup, buf);
	free(str_backup);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char *str_backup[OPEN_MAX];
	char		buf[BUFFER_SIZE];
	int			result;
	int			r_bytes;

	while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r_bytes + 1] = '\0';
		str_backup[fd] = buf_stack(&str_backup[fd], buf);
	}
	result = 1;
	return (result);
}
