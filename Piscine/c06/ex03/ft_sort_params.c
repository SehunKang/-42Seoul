/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 20:28:35 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 20:48:58 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_argv_write(char **argv, int argc)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_sort_argv(char **arg, int size)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j + 1 < size)
		{
			k = 0;
			while (arg[j][k] == arg[j + 1][k])
				k++;
			if (arg[j][k] > arg[j + 1][k])
			{
				temp = arg[j];
				arg[j] = arg[j + 1];
				arg[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	ft_sort_argv(argv, argc);
	ft_argv_write(argv, argc);
}
