/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:37:11 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/05 10:18:57 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	j;
	char *cp;

	cp = str;
	if (*to_find == '\0')
		return (str);
	while (*cp)
	{
		j = 0;
		while (*(cp + j) == *(to_find + j))
		{
			j++;
			if (!*(to_find + j))
				return (cp);
		}
		cp++;
	}
	return (0);
}
