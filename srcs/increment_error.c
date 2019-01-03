/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:18:32 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 16:06:37 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		increment_error1(const char *f, int *i, int j)
{
	if (f[j] == 'c' || f[j] == 's' || f[j] == 'p'
			|| f[j] == 'd' || f[j] == 'i' || f[j] == 'o'
			|| f[j] == 'u' || f[j] == 'x' || f[j] == 'X' || f[j] == 'l'
			|| f[j] == 'f' || f[j] == '%' || f[j] == 'h')
		(*i)++;
	if (f[j] >= 58 && f[j] != 'c' && f[j] != 's' && f[j] != 'p'
			&& f[j] != 'd' && f[j] != 'i' && f[j] != 'o' && f[j] != 'u'
			&& f[j] != 'x' && f[j] != 'X' && f[j] != 'f' && f[j] != '%'
			&& f[j] != 'h' && f[j] != 'l')
		return (-1);
	return (0);
}

void			increment_error(const char *f, int *i, int *b)
{
	int		t;
	int		j;
	t_flag	flag;

	j = *i;
	t = *i;
	capture_the_flag(f, t, &flag);
	while (f[j] != '\0' && f[j] != '%')
	{
		if (f[j] < 58 || f[j] > 126)
		{
			if (f[j] >= '0' && f[j] <= '9')
				(*i)++;
			else if (f[j] == '.' || f[j] == '+' || f[j] == '#')
				(*i)++;
			else if (f[j] == '-')
			{
				if (*b == -5)
					if (flag_space_neg_nb_error(f, t) != 0)
						*b = -flag_space_neg_nb_error(f, t);
				(*i)++;
			}
			else if (f[j] == ' ')
				(*i)++;
		}
		if (increment_error1(f, i, j) == -1)
			return ;
		j++;
	}
}
