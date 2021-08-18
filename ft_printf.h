/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehkang <sehkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 10:51:42 by sehkang           #+#    #+#             */
/*   Updated: 2021/06/10 15:58:32 by sehkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_opt
{
	int			left;
	int			zero;
	int			width;
	int			precision;
}				t_opt;

extern int		g_ret;

int				ft_printf(const char *str, ...);
const char		*check_opt(const char *str, va_list *ap);
const char		*check_flag(const char *str, t_opt *opt);
const char		*check_prec(const char *str, t_opt *opt, va_list *ap);
const char		*check_width(const char *str, t_opt *opt, va_list *ap);
int				check_spec(char c, va_list *ap, t_opt opt);
void			set_opt(t_opt *opt);
void			print_capx(va_list *ap, t_opt opt);
void			print_x(va_list *ap, t_opt opt);
void			print_u(va_list *ap, t_opt opt);
void			print_d(va_list *ap, t_opt opt);
void			print_out(char *str, t_opt *opt, int max_len, int total_len);
void			print_p(va_list *ap, t_opt opt);
void			print_s(va_list *ap, t_opt opt);
void			print_c(va_list *ap, t_opt opt);
void			print_per(t_opt opt);
void			check_print_neg(char c);
char			*ft_itoa(long long n);
char			*ft_itoa_base_x(long long n);
char			*ft_itoa_base_capx(long long n);
char			*ft_itoa_base_add(unsigned long long n);
int				int_len(long long num);
int				int_len_base(long long num);
int				ft_strlen(const char *s);
int				ft_isdigit(int c);
int				ft_strnlen(const char *s, int maxlen);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);

#endif
