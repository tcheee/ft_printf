/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:07:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/19 17:39:11 by tcherret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char * format, ...);
int		dispatcher(va_list ap, int i, const char *format);

int		check_error(const char *f, int i);
int		check_flag_hl(const char *f, int t);
void	increment(const char *format, int *i);
void	increment_error(const char *format, int *i, int *sum, int *b);
void	ft_putnbr_base(long long nb, int base);
void	ft_putnbr_base_addr(unsigned long long nb, int base, int *ret);
void	ft_putnbr_basemaj(long long nb, int base);
void	ft_putnbr_double(double nb, int size);
void	ft_putnbr_unsign(unsigned long long nb, int base);
void	ft_nblen(long long nb, int base, int *sum);
void	ft_nblen_double(long long nb, int *sum);
void	ft_nblen_unsign(unsigned long long nb, int base, int *ret);
void	ft_putnstr(const char *str, int size);
void	flag_space(const char *f, int nb, int t, int *ret);
void	flag_space_o(const char *f, int nb, int t, int *ret);
int		flag_space_x(const char *f, int nb, int t, int *ret);
void	flag_space_percent(const char *f, int nb, int t, int *ret);
void	flag_space_neg(const char *f, int nb, int t, int *ret);
int		flag_space_neg_nb_error(const char *f, int t);
void	flag_space_neg_print_error(int b, int *sum);
int		flag_plus_space(const char *f, int *nb, int t, int var);
int		flag_plus_space_percent(const char *f, int t);
void	print_flag_plus_space(const char *f, int t, int j, int var);
void	print_flag_plus_space1(const char *f, int t, int j, int *var);
int		flag_precision(const char *f, int t);
int		flag_precision_nb(const char *f, int nb, int t, int *ret);
void	flag_hashxmaj(const char *f, int t, int *ret);
void	flag_hashx(const char *f, int t, int *ret);
int		flag_hasho(const char *f, int t, int *ret);
void	flag_hashf(const char *f, int t, int *ret);

int		ft_print_char(va_list ap, const char *f, int t);
int		ft_print_string(va_list ap, const char *f, int t);
int		ft_print_number(va_list ap, const char *f, int t);
int		ft_print_hex(va_list ap, const char *f, int t);
int		ft_print_octal(va_list ap, const char *f, int i, int t);
int		ft_print_unsign(va_list ap, const char *f, int i, int t);
int		ft_print_uhex(va_list ap, const char *f, int i, int t);
int		ft_print_uhexmaj(va_list ap, const char *f, int i, int t);
int		ft_print_float(va_list ap, const char *f, int i, int t);
int		ft_print_percent(const char *f, int t);

#endif
