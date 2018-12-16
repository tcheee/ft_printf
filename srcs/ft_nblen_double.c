
#include "../includes/ft_printf.h"

void	ft_nblen_double(long long nb, int *sum)
{
	int x;
	int i;
	double y;
	double tmp;

	i = 0;
	if (nb < 0)
	{
		(*sum)++;
		nb = -nb;
	}
	x = (unsigned long long)nb;
	ft_nblen(x, 10, sum);
	(*sum)++;
	y = (nb - x);
	tmp = y;
	tmp = tmp * 10;
	while ((int)tmp == 0 && i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
	while (i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
}
