/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:47:06 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/15 14:34:04 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	print_bits(unsigned long n)
{
	char	bits[5];
	int		i;

	i = 0;
	write(1, "bits sent : ", 12);
	while (9 < n)
	{
		bits[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	bits[i] = n % 10 + '0';
	while (0 <= i)
	{
		write (1, &bits[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;

	val = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		sign = 44 - *str++;
	while ('0' <= *str && *str <= '9')
	{
		val *= 10;
		val += *str++ - '0';
	}
	if (*str)
		val = 0;
	return (sign * val);
}

void	check_conf(int argnum, char **args, unsigned int *str_len, int *pid)
{
	if (argnum != 3)
	{
		write(1, "ERROR : 2 arguments (PID and String) required\n", 46);
		exit(1);
	}
	else
	{
		*pid = ft_atoi(args[1]);
		*str_len = ft_strlen(args[2]);
	}
	if (!(100 <= *pid && *pid < 100000))
		write(1, "ERROR : Wrong PID\n", 18);
	else if (args[2] == NULL)
		write(1, "ERROR : NULL string\n", 19);
	else
		return ;
	exit(1);
}

int	main(int argc, char **argv)
{
	unsigned int	str_len;
	unsigned int	i;
	int				pid;

	check_conf(argc, argv, &str_len, &pid);
	i = 0;
	while (i < 32)
	{
		if (str_len & (2147483648 >> i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
	while ((i / 8 - 4) < str_len)
	{
		if (argv[2][i / 8 - 4] & (128 >> (i % 8)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
	print_bits(i);
}
