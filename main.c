#include "ft_printf.h"
#include "stdio.h"

int main()
{
	printf("%Lf", -56.2012685l);
	ft_printf("%Lf", -56.2012685l);
	return (0);
}
