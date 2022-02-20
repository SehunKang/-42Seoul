#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
//	char *str = "hi low";
	int ret;
	printf("%%qwerqwer%qwerq%%qwer = ");
	ret = ft_printf("%qwerqwer%qwerq%qwer\n");
	printf("%d\n", ret);
	ret = printf("%qwerqwer%qwerq%qwe\n");
	printf("%d\n", ret);
}
