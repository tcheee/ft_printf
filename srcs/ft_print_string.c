/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:09:00 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 18:14:12 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_space(int *nb)
{
	if (*nb == -5)
		*nb = 0;
}

static void		get_space_print_string(t_flag flag, int *nb, char *str)
{
	if (flag.sign != 3)
		flag_space_str(flag, nb);
	if (str != NULL && flag.precis != 0)
		ft_putnstr(str, flag.precis);
	else if (str == NULL && flag.precis == -10)
		ft_putstr("(null)");
	else if (str == NULL && flag.precis != -10)
		ft_putnstr("(null)", flag.precis);
	if (flag.sign == 3)
		flag_space_neg(flag.space, *nb, nb);
}

int				ft_print_string(va_list ap, t_flag flag)
{
	char	*str;
	int		nb;

	nb = 0;
	str = va_arg(ap, char*);
	if (str && str[0] != '\0' && flag.precis != 0)
		nb = ft_strlen(str);
	else if (str == '\0' && flag.precis == -10)
		nb = 6;
	else if (str == '\0' && flag.precis != -10 && flag.precis != 0)
		nb = flag.precis;
	get_space(&nb);
	if (str != '\0' && flag.precis > nb)
		flag.precis = nb;
	else if (str != '\0' && flag.precis > 0 && flag.precis != 0)
		nb = flag.precis;
	else if (str != '\0' && flag.precis == -5)
	{
		flag.precis = 0;
		nb = 0;
	}
	else if (str != '\0' && flag.precis != 0)
		flag.precis = nb;
	get_space_print_string(flag, &nb, str);
	return (nb);
}
