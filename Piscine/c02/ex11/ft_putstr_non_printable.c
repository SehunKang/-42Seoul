/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:30:53 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/04 20:09:45 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hexnum;

	i = 0;
	hexnum = "0123456789abcdef";
	while (str[i] != '\0')
	{
		if (!(31 < str[i] && str[i] < 127))
		{
			ft_putchar('\\');
			ft_putchar(hexnum[(unsigned char)str[i] / 16]);
			ft_putchar(hexnum[(unsigned char)str[i] % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
