/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:07:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/14 18:56:42 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char * format, ...);
int		dispatcher(va_list ap, int i, const char *format);

void	increment(const char *format, int *i);
void	ft_putnbr_base(unsigned long long nb, int base);
void	ft_putnbr_basemaj(unsigned long long nb, int base);
void	ft_putnbr_double(double nb);
void	ft_nblen(unsigned long long nb, int base, int *sum);
void	ft_nputstr(const char *str, int size);
void	flag_space(const char *f, int nb, int t, int *ret);
void	flag_space_neg(const char *f, int nb, int t, int *ret);
int		flag_plus_space(const char *f, int *nb, int t, int *ret);
void	print_flag_plus_space(int b, char c);
void	print_flag_plus_space1(int b, char c);
int		flag_precision(const char *f, int nb, int t);
int		flag_precision_nb(const char *f, int nb, int t, int *ret);

int		ft_print_char(va_list ap, const char *f, int t);
int		ft_print_string(va_list ap, const char *f, int t);
int		ft_print_number(va_list ap, const char *f, int i, int t);
int		ft_print_hex(va_list ap, const char *f, int t);
int		ft_print_octal(va_list ap, const char *f, int i, int t);
int		ft_print_unsign(va_list ap, const char *f, int i, int t);
int		ft_print_uhex(va_list ap, const char *f, int i, int t);
int		ft_print_uhexmaj(va_list ap, const char *f, int i, int t);
int		ft_print_float(va_list ap, const char *f, int i);
int		ft_print_percent(const char *f, int t);

#endif
