/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:07:49 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/10 10:12:27 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char		*cp;
	int			i;

	if ((cp = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)) == NULL)
		return (0);
	i = 0;
	while ((cp[i] = src[i]))
		i++;
	cp[i] = '\0';
	return (cp);
}
