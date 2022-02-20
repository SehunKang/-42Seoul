/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 19:31:55 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/04 19:32:10 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 1;
	while (*s1 != '\0' && (*s1 == *s2) && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
