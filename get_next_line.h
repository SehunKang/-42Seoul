/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:23:20 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/20 20:24:52 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 1 
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);

#endif
