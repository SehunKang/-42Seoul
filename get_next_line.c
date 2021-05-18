/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:05:29 by sehkang           #+#    #+#             */
/*   Updated: 2021/05/17 22:04:01 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_lines.h"

int	get_next_line(int fd, char **line)
{
	static char *str_backup[OPEN_MAX];
	char buf[BUFFER_SIZE];


