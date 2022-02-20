#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *str = NULL;
	printf("%s, %p\n", str, str);
	printf("%lu\n", strlen(str));
}
	
