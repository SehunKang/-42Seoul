/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:51:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/08 20:31:24 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
typedef struct s_opt
{
	int	left;
	int zero;
	int width;
	int precision;
}			s_opt;

extern int	g_ret;

int			ft_printf(const char *str, ...);
const char  *check_opt(const char *str, va_list *ap);
const char  *check_flag(const char *str, s_opt *opt);
const char  *check_prec(const char *str, s_opt *opt, va_list *ap);
const char  *check_width(const char *str, s_opt *opt, va_list *ap);
int			check_spec(char c, va_list *ap, s_opt opt);
void		set_opt(s_opt *opt);
void		print_capx(va_list *ap, s_opt opt);
void		print_x(va_list *ap, s_opt opt);
void		print_u(va_list *ap, s_opt opt);
void		print_d(va_list *ap, s_opt opt);
void		print_out(char *str, s_opt *opt, int max_len, int total_len);
void		print_p(va_list *ap, s_opt opt);
void		print_s(va_list *ap, s_opt opt);
void		print_c(va_list *ap, s_opt opt);
void		print_per(s_opt opt);
void		check_print_neg(char c);
int			ft_atoi(const char *str);
char		*ft_itoa(ssize_t n);
char		*ft_itoa_base_x(ssize_t n);
char		*ft_itoa_base_capx(ssize_t n);
char		*ft_itoa_base_add(unsigned long long n);
size_t		int_len(ssize_t num);
size_t		int_len_base(size_t num);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
size_t		ft_strnlen(const char *s, size_t maxlen);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
#endif
