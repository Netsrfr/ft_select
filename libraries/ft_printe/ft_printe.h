/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:44:07 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/01/10 09:44:07 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTE_H
# define FT_PRINTE_H
# include <stdarg.h>
# include <stdlib.h>
# include "../../libft/libft.h"
# include <limits.h>
# define PR(x) (*progress == x)

typedef struct		s_pf_fl_e
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
}					t_fl_e;

t_fl_e				g_fe;
ssize_t				g_returne;
char				*g_printe;

ssize_t				ft_printe(const char *format, ...);
void				flag_init_e(void);
char				*ft_flags_e(char *progress, va_list arguments);

char				*ft_flags_plus_e(char *progress);
char				*ft_flags_minus_e(char *progress);
char				*ft_flags_zero_e(char *progress);
char				*ft_flags_pound_e(char *progress);
char				*ft_flags_space_e(char *progress);

char				*ft_flags_width_e(char *progress);
char				*ft_flags_h_e(char *progress);
char				*ft_flags_l_e(char *progress);
char				*ft_flags_precision_e(char *progress);

char				*ft_conversions_e(va_list ap, char *progress);
int					ft_conversion_s_e(char *argument);
int					ft_conversion_c_e(char argument);
int					ft_conversion_percent_e(void);
int					ft_conversion_p_e(void *argument);

char				*ft_spaces_e(char *result, int strlen);
int					ft_conversion_d_e(intmax_t argument);
int					ft_conversion_u_e(uintmax_t argument);
int					ft_conversion_o_e(uintmax_t argument);

void				ft_handler_decimal_e(va_list ap);
void				ft_handler_unsigned_e(va_list ap);
void				ft_handler_octal_e(va_list ap);
void				ft_join_e(char **result, const char *s1, const char *s2);

char				*ft_putwidth_e(int width,
								char *result);
char				*ft_putwidth_no_p_e(int width, char *result);
char				*ft_putwidth_o_e(uintmax_t arg, int width, char *result);
void				ft_putwidth_string_e(int width, char **result);
char				*ft_put_precision_e(char *result, int precision);

char				*ft_putwidth_hex_e(char x, int precision, uintmax_t arg,
									char *result);
int					ft_conversion_x_e(uintmax_t argument, char conversion);
void				ft_handler_hexadecimal_e(va_list ap, char *progress);
char				*ft_hex_pound_e(char *result, char x, uintmax_t arg);
#endif
