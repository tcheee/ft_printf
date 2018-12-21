/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:07:24 by tcherret          #+#    #+#             */
/*   Updated: 2018/12/21 14:09:34 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_flag
{
int		hl;
int		sign;
int		precis;
int		zero;
int		space;
int		hash;
}				t_flag;

int		ft_printf(const char * format, ...);
int		dispatcher(va_list ap, int i, const char *format);
void	capture_the_flag(const char *f, int t, t_flag *flag);

void	increment(const char *format, int *i);
void	increment_error(const char *format, int *i, int *sum, int *b);

int		check_error(const char *f, int i);
int		check_flag_hl(const char *f, int t);
int		flag_0(const char *f, int t);
int		get_space_number(const char *f, int t);
int		get_hash(const char *f, int t);
void	flag_space(int space, int nb, int zero, int *ret);
void	flag_space_o(t_flag flag, int *ret);
void	flag_space_percent(const char *f, int nb, int t, int *ret);
void	flag_space_neg(int space, int nb, int *ret);
int		flag_space_neg_nb_error(const char *f, int t);

void	ft_nblen(long long nb, int base, int *sum);
void	ft_nblen_double(long long nb, int *sum);
void	ft_nblen_unsign(unsigned long long nb, int base, int *ret);
void	flag_space_neg_print_error(int b, int *sum);
int		flag_plus_space(const char *f, int t);
int		flag_plus_space_percent(const char *f, int t);
void	print_flag_plus_space(int hl, int zero, int var, int *ret);
void	print_flag_plus_space1(int hl, int zero, int *var, int *ret);
int		get_precision(const char *f, int t, int *ret);
int		get_precision2(const char *f, int t);
int		flag_precision(const char *f, int t);
void	flag_precision_nb(int precis, int size, int *ret);
void	flag_hashxmaj(t_flag flag, int *ret);
void	flag_hashx(t_flag flag, int *ret);
void	flag_hasho(t_flag flag, int *ret);
void	flag_hashf(t_flag flag, int *ret);

int		ft_print_char(va_list ap, t_flag flag);
int		ft_print_string(va_list ap,  t_flag flag);
int		ft_print_number(va_list ap, t_flag flag);
int		ft_print_hex(t_flag flag, va_list ap);
int		ft_print_octal(va_list ap, t_flag flag);
int		ft_print_unsign(va_list ap, t_flag flag/*, const char *f, int i*/);
int		ft_print_uhex(va_list ap, t_flag flag);
int		ft_print_uhexmaj(va_list ap/*, const char *f, int t*/, t_flag flag);
int		ft_print_float(va_list ap, const char *f, int t, t_flag flag);
int		ft_print_percent(t_flag flag, const char *f, int t);

void	ft_putnbr_base(long long nb, int base);
void	ft_putnbr_base_addr(unsigned long long nb, int base, int *ret);
void	ft_putnbr_basemaj(long long nb, int base);
void	ft_putnbr_double(double nb, int size);
void	ft_putnbr_unsign(unsigned long long nb, int base);
void	ft_nblen(long long nb, int base, int *sum);
void	ft_nblen_double(long long nb, int *sum);
void	ft_nblen_unsign(unsigned long long nb, int base, int *ret);
void	ft_putnstr(const char *str, int size);

#endif
