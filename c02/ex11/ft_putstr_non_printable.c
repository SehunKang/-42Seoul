/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:30:53 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/31 21:39:13 by sehkang          ###   ########.fr       */
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
	int		j;

	i = 0;
	hexnum = "012345689abcde";
	while (str[i] != '\0')
	{
		j = 0;
		if ((0 < str[i] && str[i] < 31) || str[i] == 127)
		{
			while (str[i] > 16)
			{
				str[i] = str[i] / 16;
				j++;
			}
			ft_putchar('\\');
			ft_putchar(hexnum[j]);
			ft_putchar(hexnum[str[i] - 1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
