/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:11:50 by sehkang           #+#    #+#             */
/*   Updated: 2021/03/31 21:24:11 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *g_hex;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	p_out_memory(unsigned long address, int r_num)
{
	if (r_num != 16)
	{
		p_out_memory(address / 16, r_num + 1);
		ft_putchar(g_hex[address % 16]);
		if (r_num == 0)
		{
			ft_putchar(':');
			ft_putchar(' ');
		}
	}
}

void	p_out_hexval(char *str, int str_index, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16)
	{
		if (str_index + i < size)
		{
			ft_putchar(g_hex[(str[str_index + i] / 16)]);
			ft_putchar(g_hex[(str[str_index + i] % 16)]);
			if (i % 2 == 1)
				ft_putchar(' ');
		}
		else
			ft_putchar(' ');
		i++;
	}
}

void	p_out_string(char *str, unsigned int str_index, unsigned int size)
{
	int i;

	i = 0;
	while (i < 16 && str_index + i < size)
	{
		if (31 < str[str_index + i] && str[str_index + i] < 127)
			ft_putchar(str[str_index + i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;

	g_hex = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		if (i % 16 == 0)
		{
			p_out_memory((unsigned long)addr + i, 0);
			p_out_hexval((char*)addr, i, size);
			p_out_string((char*)addr, i, size);
			ft_putchar('\n');
		}
		i++;
	}
	return (addr);
}
