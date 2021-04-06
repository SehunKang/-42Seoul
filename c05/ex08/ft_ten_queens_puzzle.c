#include <stdio.h>
#include <unistd.h>

int	g_board[10];
int	g_cnt;

void	ft_write_board(void)
{
	int i;
	char g_cboard[10];

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

void	ft_queens(int queens)
{
	int column;
	int j;
	int placed;

	if (queens == 10)
	{
		ft_write_board();
		return;
	}
	column = 0;
	while (column < 10)
	{
		placed = 1;
		j = 0;
		while (j < queens)
		{
			if (g_board[j] == column || column - g_board[j]
			== queens - j || column - g_board[j] == j - queens)
			{
				placed = 0;
				break;
			}
			j++;
		}
		if (placed)
		{
			g_board[queens] = column;
			ft_queens(queens + 1);
		}
	column++;
	}
}
	
int	ft_ten_queens_puzzle(void)
{
	g_cnt = 0;
	ft_queens(0);
	return (g_cnt);
}
int	main(void)
{
	printf("%d", ft_ten_queens_puzzle());
}
