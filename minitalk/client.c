/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 22:47:06 by sehkang           #+#    #+#             */
/*   Updated: 2021/07/19 18:25:59 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char			*g_str;
static unsigned int	g_str_len;

unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
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

void	check_conf(int argnum, char **args, int *pid)
{
	if (argnum != 3)
	{
		write(1, "ERROR : 2 arguments (PID and String) required\n", 46);
		exit(1);
	}
	else
	{
		*pid = ft_atoi(args[1]);
		g_str_len = ft_strlen(args[2]);
		g_str = args[2];
	}
	if (!(100 <= *pid && *pid < 100000))
		write(1, "ERROR : Wrong PID\n", 18);
	else if (args[2] == NULL)
		write(1, "ERROR : NULL string\n", 19);
	else
		return ;
	exit(1);
}

void	sig_usr(int signo, struct __siginfo *info, void *uap)
{
	static unsigned int	i;

	i = 0;
	while (i < 32)
	{
		if (g_str_len & (2147483648 >> i))
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
		usleep(25);
		i++;
	}
	while ((i / 8 - 4) < g_str_len)
	{
		if (g_str[i / 8 - 4] & (128 >> (i % 8)))
			kill(info->si_pid, SIGUSR1);
		else
			kill(info->si_pid, SIGUSR2);
		usleep(25);
		i++;
	}
	exit(1);
	(void)signo;
	(void)uap;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	usrsig;

	usrsig.sa_sigaction = &sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_flags = SA_SIGINFO;
	check_conf(argc, argv, &pid);
	kill(pid, SIGUSR1);
	sigaction(SIGUSR1, &usrsig, 0);
	sleep(1);
	write(1, "Wrong PID\n", 10);
	exit(1);
}
