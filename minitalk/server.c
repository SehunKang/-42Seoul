#include "minitalk.h"

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*cp;

	cp = (unsigned char *)b;
	while (0 < len)
	{
		*cp++ = (unsigned char)c;
		len--;
	}
}

void	putnbr(unsigned long n)
{
	char	c;

	if (9 < n)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_str(t_conf *conf)
{
	if (!((conf->bits - 32) % (1024 * 8)))
	{
		write(1, conf->str, 1024);
		ft_memset(conf->str, 0, 1024);
	}
	if ((conf->bits / 8 - 4) == conf->str_len)
	{
		write(1, conf->str, conf->str_len % 1024);
		write(1, "\n", 1);
		ft_memset(conf->str, 0, 1024);
		conf->bits = 0;
		conf->str_len = 0;
		conf->connected = 0;
	}
}

void	sig_usr(int signo, struct __siginfo *info, void *uap)
{
	static t_conf	conf;

	if (conf.connected == 0)
	{
		conf.connected = 1;
		kill(info->si_pid, SIGUSR1);
	}
	else if (conf.bits < 32)
	{
		if (signo == SIGUSR1)
			conf.str_len += (2147483648 >> conf.bits);
		conf.bits++;
		if (conf.bits == 32 && conf.str_len == 0)
			print_str(&conf);
	}
	else
	{
		if (conf.bits / 8 - 4 != conf.str_len)
			if (signo == SIGUSR1)
				conf.str[(conf.bits / 8 - 4) % 1024] += 128 >> (conf.bits % 8);
		conf.bits++;
		print_str(&conf);
	}
	(void)uap;
}

int	main(void)
{
	struct sigaction	usrsig;

	usrsig.sa_sigaction = &sig_usr;
	sigemptyset(&usrsig.sa_mask);
	usrsig.sa_flags = SA_SIGINFO;
	write (1, "PID = ", 6);
	putnbr(getpid());
	write (1, "\n", 1);
	sigaction(SIGUSR1, &usrsig, 0);
	sigaction(SIGUSR2, &usrsig, 0);
	while (1)
		pause();
}
