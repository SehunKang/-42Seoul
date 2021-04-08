#include <stdlib.h>
int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_fullen(int size, char **strs, char *sep)
{
	int i;
	int fullen;

	i = 0;
	fullen = 0;
	while (i < size)
	{
		fullen += ft_strlen(strs[i]);
		i++;
	}
	fullen += ft_strlen(sep) * (size - 1);
	return (fullen);
}

void	ft_strcat(char *d_str, char *s_str)
{
	while (*d_str)
		d_str++;
	while (*s_str)
	{
		*d_str = *s_str;
		d_str++;
		s_str++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int full_len;
	char *r_str;
	char *cp_str;
	int i;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	full_len = ft_fullen(size, strs, sep);
	if ((r_str = (char *)malloc(sizeof(char) * (full_len + 1))) == NULL)
		return (NULL);
	cp_str = r_str;
	i = 0;
	while(i < size - 1)
	{
		ft_strcat(cp_str, strs[i]);
		ft_strcat(cp_str, sep);
		i++;
	}
	ft_strcat(cp_str, strs[i]);
	return (r_str);
}

