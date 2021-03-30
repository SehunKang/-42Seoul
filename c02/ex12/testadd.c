#include <unistd.h>
int	main(void)
{
	int *a;
	int b = 1;
	*a = &b; 
	write(1, a, 4);
}
		
