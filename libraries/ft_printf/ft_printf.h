/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:44:07 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/01/10 09:44:07 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <limits.h>
# define PR(x) (*progress == x)
# define RED "\x1b[31m"
# define DEF "\x1b[39m"
# define WHITE "\x1b[37m"

typedef struct		s_pf_flag
{
	int		error;
	int		precision;
	int		precision_v;
	int		neg;
	int		count;
	int		pound;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		width_v;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		j;
	int		z;
}					t_flag;

t_flag				g_fl;
ssize_t				g_return;
char				*g_print;

ssize_t				ft_printf(const char *format, ...);
void				flag_init(void);
char				*ft_flags(char *progress, va_list arguments);

char				*ft_flags_plus(char *progress);
char				*ft_flags_minus(char *progress);
char				*ft_flags_zero(char *progress);
char				*ft_flags_pound(char *progress);
char				*ft_flags_space(char *progress);

char				*ft_flags_width(char *progress);
char				*ft_flags_h(char *progress);
char				*ft_flags_l(char *progress);
char				*ft_flags_precision(char *progress);

char				*ft_conversions(va_list ap, char *progress);
int					ft_conversion_s(char *argument);
int					ft_conversion_c(char argument);
int					ft_conversion_percent(void);
int					ft_conversion_p(void *argument);

char				*ft_spaces(char *result, int strlen);
int					ft_conversion_d(intmax_t argument);
int					ft_conversion_u(uintmax_t argument);
int					ft_conversion_o(uintmax_t argument);

void				ft_handler_decimal(va_list ap);
void				ft_handler_unsigned(va_list ap);
void				ft_handler_octal(va_list ap);
void				ft_join(char **result, const char *s1, const char *s2);

char				*ft_putwidth(int width,
								char *result);
char				*ft_putwidth_no_p(int width, char *result);
char				*ft_putwidth_o(uintmax_t arg, int width, char *result);
void				ft_putwidth_string(int width, char **result);
char				*ft_put_precision(char *result, int precision);

char				*ft_putwidth_hex(char x, int precision, uintmax_t arg,
									char *result);
int					ft_conversion_x(uintmax_t argument, char conversion);
void				ft_handler_hexadecimal(va_list ap, char *progress);
char				*ft_hex_pound(char *result, char x, uintmax_t arg);
#endif
