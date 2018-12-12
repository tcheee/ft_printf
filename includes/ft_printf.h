/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:07:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/12 14:46:53 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char * format, ...);
int		dispatcher(va_list ap, int i, const char *format);
int		capture_the_flag(const char *format, int i);
void	increment(const char *format, int *i);

void	ft_putnbr_base(unsigned long long nb, int base);
void	ft_putnbr_basemaj(unsigned long long nb, int base);
void	ft_putnbr_double(double nb);

int		ft_print_char(va_list ap);
int		ft_print_string(va_list ap);
int		ft_print_number(va_list ap, const char *f, int i);
int		ft_print_hex(va_list ap);
int		ft_print_octal(va_list ap);
int		ft_print_unsign(va_list ap);
int		ft_print_uhex(va_list ap);
int		ft_print_uhexmaj(va_list ap);
int		ft_print_float(va_list ap, const char *f, int i);
int		ft_print_percent(void);

#endif
