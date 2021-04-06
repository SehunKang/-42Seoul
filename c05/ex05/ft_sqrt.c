int	ft_sqrt(int nb)
{
	int i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return(nb);
	while (i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
