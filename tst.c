#include <stdio.h>
#include "ft_printf.h"
int	main(void)
{
	char *str;

	str = "abc";
	int ret;
/*	ret = printf("-->|%-4.*d|<--\n", -4, 214748493);
	printf("%d\n", ret);
	ft_printf("-->|%-4.*d|<--\n", -4, 214748493);
	printf("%d\n", ret);
*/
	int d = -135;
//	ft_printf("-->|%0*.*d|<--\n", 3, 6, d);
//	printf("-->|%0*.*d|<--\n", 3, 6, d);
/*	ft_printf("-->|%3.*%|<--\n", 4);
	ft_printf("-->|%3.*%|<--\n", 3);
	ft_printf("-->|%3.*%|<--\n", -2);
	ft_printf("-->|%3.*%|<--\n", -1);
	printf("-->|%3.*%|<--\n", 4);
	printf("-->|%3.*%|<--\n", 3);
	printf("-->|%3.*%|<--\n", -2);
	printf("-->|%3.*%|<--\n", -1);
	ft_printf("-->|%3.*c|<--\n", 4, 'x');
	ft_printf("-->|%3.*c|<--\n", 3, 'x');
	ft_printf("-->|%3.*c|<--\n", -2, 'x');
	ft_printf("-->|%3.*c|<--\n", -1, 'x');
	printf("-->|%3.*c|<--\n", 4, 'x');
	printf("-->|%3.*c|<--\n", 3, 'x');
	printf("-->|%3.*c|<--\n", -2, 'x');
	printf("-->|%3.*c|<--\n", -1, 'x');*/
	ret = ft_printf("-->|%-*p|<--\n", -16, str);
	printf("%d\n", ret);
	ret = ft_printf("-->|%-*p|<--\n", 0, str);
	printf("%d\n", ret);
	ret = ft_printf("-->|%-*p|<--\n", 16, str);
	printf("%d\n", ret);
	ret = printf("-->|%-*p|<--\n", -16, str);
	printf("%d\n", ret);
	ret = printf("-->|%-*p|<--\n", 0, str);
	printf("%d\n", ret);
	ret = printf("-->|%-*p|<--\n", 16, str);
	printf("%d\n", ret);
}

