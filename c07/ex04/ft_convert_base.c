#include <stdlib.h>

int	ft_isspace(char c);
int	ft_isneg(char c, int *sign);
int	ft_checkbase(char *base);
int	ft_findbval(char c, char *base);
int	ft_atoi_base(char *str, char *base);

int	ft_find_digitlen(int pre_val, int t_len)
{
	int i;
	int check_neg;
	
	check_neg = pre_val;
	if (pre_val < 0)
		pre_val = -pre_val;
	i = 0;
	while (0 < pre_val)
	{
		pre_val /= t_len;
		i++;
	}
	if (check_neg < 0)
		i++;
	return (i);
}

void	ft_convert_value(int num, char *r_val, int d_len, char *base)
{
	int i;
	int b_len;

	i = 1;
	b_len = ft_checkbase(base);
	if (0 < num)
	{
		while (i <= d_len)
		{
			r_val[d_len - i] = base[num % b_len];
			i++;
			num /= b_len;
		}
	}
	else if (num < 0)
	{
		num = -num;
		r_val[0] = '-';
		while (i < d_len)
		{
			r_val[d_len - i] = base[num % b_len];
			i++;
			num /= b_len;
		}
	}
	r_val[i] = '\0';
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int from_len;
	int to_len;
	int num;
	char *val;
	int digit_len;

	from_len = ft_checkbase(base_from);
	to_len = ft_checkbase(base_to);
	if (from_len < 2 || to_len < 2)
		return (NULL);
	num = ft_atoi_base(nbr, base_from);
	digit_len = ft_find_digitlen(num, to_len);
	val = (char *)malloc(sizeof(char) * digit_len + 1);
	ft_convert_value(num, val, digit_len, base_to);
	
	return(val);
}

