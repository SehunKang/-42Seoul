/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testqueens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:34:39 by sehkang           #+#    #+#             */
/*   Updated: 2021/04/07 10:03:47 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_board[10];
int	g_cnt;
int	g_placed;

void	ft_write_board(void)
{
	int					i;
	char				g_cboard[10];

	i = 0;
	while (i < 10)
	{
		g_cboard[i] = '0' + g_board[i];
		i++;
	}
	write(1, g_cboard, 10);
	write(1, "\n", 1);
	g_cnt++;
}

int		ft_check_place(int column, int j, int queens)
{
	if (g_board[j] == column || column - g_board[j]
	== queens - j || column - g_board[j] == j - queens)
	{
		g_placed = 0;
		return (1);
	}
	return (0);
}

void	ft_queens(int queens)
{
	int column;
	int j;

	if (queens == 10)
	{
		ft_write_board();
		return ;
	}
	column = 0;
	while (column < 10)
	{
		g_placed = 1;
		j = -1;
		while (++j < queens)
		{
			if (ft_check_place(column, j, queens))
				break ;
		}
		if (g_placed)
		{
			g_board[queens] = column;
			ft_queens(queens + 1);
		}
		column++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	g_cnt = 0;
	ft_queens(0);
	return (g_cnt);
}
