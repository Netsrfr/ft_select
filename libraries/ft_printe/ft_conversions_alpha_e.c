/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_alpha_e.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:13:47 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 10:13:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

char	*ft_conversions_e(va_list ap, char *progress)
{
	if (*progress == 'U')
		g_fe.ll = 1;
	if (*progress == 'D')
		g_fe.l = 1;
	if (*progress == 's' || *progress == 'S')
		ft_conversion_s_e(va_arg(ap, char*));
	if (*progress == 'd' || *progress == 'i' || *progress == 'D')
		ft_handler_decimal_e(ap);
	if (*progress == 'u' || *progress == 'U')
		ft_handler_unsigned_e(ap);
	if (*progress == 'o' || *progress == 'O')
		ft_handler_octal_e(ap);
	if (*progress == 'c' || *progress == 'C')
		ft_conversion_c_e(va_arg(ap, int));
	if (*progress == 'p')
		ft_conversion_p_e(va_arg(ap, void*));
	if (*progress == '%')
		ft_conversion_percent_e();
	ft_handler_hexadecimal_e(ap, progress);
	if (PR('s') || PR('S') || PR('d') || PR('D') || PR('i') || PR('u')
		|| PR('U') || PR('o') || PR('O') || PR('c') || PR('C') || PR('%') ||
		PR('x') || PR('X') || PR('p'))
		return (++progress);
	else
		return (progress);
}

/*
** String Conversion
** Negates zero flag when present due to undefined behavior per gcc warning
** when using '0' with '%s'
*/

int		ft_conversion_s_e(char *argument)
{
	char	*temp;

	if (!(argument))
	{
		g_printe = ft_strdup("(null)");
		return (1);
	}
	if (g_fe.zero == 1)
		g_fe.zero = 0;
	if (g_fe.precision == 1 && (int)ft_strlen(argument) > g_fe.precision_v)
		temp = ft_strndup(argument, (size_t)g_fe.precision_v);
	else
		temp = ft_strdup(argument);
	ft_putwidth_string_e(g_fe.width_v, &temp);
	g_printe = ft_strdup(temp);
	free(temp);
	return (1);
}

int		ft_conversion_c_e(char argument)
{
	if (1 < g_fe.width_v && g_fe.minus == 0)
	{
		while (g_fe.width_v-- - 1 > 0)
		{
			ft_putchare(' ');
			g_returne++;
		}
	}
	ft_putchare(argument);
	g_returne++;
	if (1 < g_fe.width_v && g_fe.minus == 1)
	{
		while (g_fe.width_v-- - 1 > 0)
		{
			ft_putchare(' ');
			g_returne++;
		}
	}
	return (1);
}

int		ft_conversion_percent_e(void)
{
	if (1 < g_fe.width_v && g_fe.minus == 0)
	{
		while (g_fe.width_v-- - 1 > 0)
		{
			ft_putchare(' ');
			g_returne++;
		}
	}
	ft_putchare('%');
	g_returne++;
	if (1 < g_fe.width_v && g_fe.minus == 1)
	{
		while (g_fe.width_v-- - 1 > 0)
		{
			ft_putchare(' ');
			g_returne++;
		}
	}
	return (1);
}

int		ft_conversion_p_e(void *argument)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_itoa_base((long)argument, 16);
	while (result[i])
	{
		result[i] = (char)ft_tolower(result[i]);
		i++;
	}
	result = ft_strjoin("0x", result);
	result = ft_putwidth_no_p_e(g_fe.width_v, result);
	g_printe = ft_strdup(result);
	free(result);
	return (1);
}
