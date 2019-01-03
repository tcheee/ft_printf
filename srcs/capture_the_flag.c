/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_the_flag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 11:27:07 by tcherret          #+#    #+#             */
/*   Updated: 2019/01/03 14:37:33 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_flag(t_flag *flag)
{
	(*flag).hl = 0;
	(*flag).sign = 0;
	(*flag).precis = 0;
	(*flag).zero = 0;
	(*flag).space = 0;
	(*flag).hash = 0;
	(*flag).neg = 0;
}

void	capture_the_flag(const char *f, int t, t_flag *flag)
{
	init_flag(flag);
	(*flag).hl = check_flag_hl(f, t);
	(*flag).sign = flag_plus_space(f, t);
	(*flag).precis = flag_precision(f, t);
	(*flag).zero = flag_0(f, t);
	(*flag).hash = get_hash(f, t);
	(*flag).space = get_space_number(f, t, *flag);
}
