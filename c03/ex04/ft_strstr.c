/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:37:11 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/04 20:38:38 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	j;

	while (*str)
	{
		j = 0;
		while (*(str + j) == *(to_find + j))
		{
			j++;
			if (!*(to_find + j))
				return (str);
		}
		str++;
	}
	return (NULL);
}
