/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:27:48 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/04 20:30:20 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	char			*cp;

	cp = dest;
	i = 0;
	while (*cp)
		cp++;
	while ((*cp = *src) && i < nb)
	{
		cp++;
		src++;
		i++;
	}
	*cp++ = '\0';
	return (dest);
}
