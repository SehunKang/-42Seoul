/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/26 22:25:24 by sehkang          ###   ########.fr       */
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

int	ret_val(char **str_backup, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (*str_backup[i] != '\n' && *str_backup[i])
		i++;
	tmp = ft_memcpy(tmp, *str_backup, i);



int	get_next_line(int fd, char **line)
{
	static char *str_backup[OPEN_MAX][2];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		r_bytes;

	if (fd < 0 || OPEN_MAX < fd || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (str_backup[fd][1] == NULL)
	{
		str_backup[fd][1] = "1";
		while ((r_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[r_bytes] = '\0';
			str_backup[fd][0] = buf_stack(&str_backup[fd][0], buf);
		}
	}
	return (ret_val(&str_backup[fd][0], line));
}
