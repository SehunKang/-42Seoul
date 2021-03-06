/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 11:05:13 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/10 14:06:56 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	char	*cp;
	int		i;

	if (!(cp = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while ((cp[i] = src[i]))
		i++;
	cp[i] = '\0';
	return (cp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int						i;
	struct s_stock_str		*arr;

	i = 0;
	if (!(arr = malloc(sizeof(struct s_stock_str) * (ac + 1))))
		return (NULL);
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i].size = 0;
	arr[i].str = 0;
	arr[i].copy = 0;
	return (arr);
}
