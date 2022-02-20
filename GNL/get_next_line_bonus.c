/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/01 17:57:42 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buf_stack(char **str_backup, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str_backup, buf);
	free(*str_backup);
	return (tmp);
}

int		ret_val(char **str_backup, char **line)
{
	char	*ret_str;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*str_backup)[i] != '\n')
		i++;
	if (!(ret_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	ret_str = ft_memcpy(ret_str, *str_backup, i);
	ret_str[i] = '\0';
	*line = ret_str;
	if (!(tmp = ft_strdup(*str_backup + i + 1)))
		return (-1);
	free(*str_backup);
	*str_backup = tmp;
	return (1);
}

int		ret_eof(char **str_backup, char **line)
{
	*line = ft_strdup(*str_backup);
	free(*str_backup);
	*str_backup = NULL;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *str_backup[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		r_bytes;

	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if ((r_bytes = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[r_bytes] = '\0';
		str_backup[fd] = buf_stack(&str_backup[fd], buf);
	}
	else
		return (-1);
	while (!(ft_strchr(str_backup[fd], '\n')))
	{
		if (r_bytes == 0)
			return (ret_eof(&str_backup[fd], line));
		if ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[r_bytes] = '\0';
			str_backup[fd] = buf_stack(&str_backup[fd], buf);
		}
	}
	return (ret_val(&str_backup[fd], line));
}
