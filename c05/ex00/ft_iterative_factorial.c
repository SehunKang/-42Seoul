int		ft_iterative_factorial(int nb)
{
	int i;
	int val;

	i = 0;
	val = 1;
	if (nb < 0)
		return (0);
	while (++i != nb + 1)
		val *= i;
	return (val);
}
