/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:50:44 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 20:50:45 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int j;

	i = argc;
	while (1 < i)
	{
		j = 0;
		while (argv[i - 1][j])
		{
			write(1, &argv[i - 1][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
}
