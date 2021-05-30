/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:23:20 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/30 15:38:06 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*buf_stack(char **str_backup, char *buf);
char	*ft_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
int		ret_val(char **str_backup, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);

#endif
