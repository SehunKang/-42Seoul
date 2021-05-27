/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/27 14:43:26 by sehkang          ###   ########.fr       */
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
	char	*ret_str;
	char	*tmp;
	size_t	i;

	i = 0;
	if ((*str_backup)[i] == '\0')
		return (0);
	while ((*str_backup)[i] != '\n' && (*str_backup)[i])
		i++;
	if(!(ret_str = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	ret_str = ft_memcpy(ret_str, *str_backup, i);
	ret_str[i] = '\0';
	if(!(tmp = ft_substr(*str_backup, i + 1, ft_strlen(*str_backup) - i)))
		return (-1);
	free(*str_backup);
	*str_backup = tmp;
	*line = ret_str;
	return (1);
}

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
	if (r_bytes == 0 && str_backup[fd][0] == NULL)
		str_backup[fd][0] = ft_strdup("");
	return (ret_val(&str_backup[fd][0], line));
	
}
