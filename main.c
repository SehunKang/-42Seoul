#include <stdio.h>
#include "ft_printf.h"
int main(void)
{
//	char *str = ft_itoa(-100);
//	printf("%s\n", str);

    int ret;
	long long tst;
	char *str;
	str = "abc";
	tst = (long long)str;
	ret = ft_printf(">>>>%p<<<<", str);
	printf("\n%d\n", ret);
	ret = printf("\n****%llx****\n", tst);
	printf("%d\n", ret);
}
