/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_alpha.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:13:47 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 10:13:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conversions(va_list ap, char *progress)
{
	if (*progress == 'U')
		g_fl.ll = 1;
	if (*progress == 'D')
		g_fl.l = 1;
	if (*progress == 's' || *progress == 'S')
		ft_conversion_s(va_arg(ap, char*));
	if (*progress == 'd' || *progress == 'i' || *progress == 'D')
		ft_handler_decimal(ap);
	if (*progress == 'u' || *progress == 'U')
		ft_handler_unsigned(ap);
	if (*progress == 'o' || *progress == 'O')
		ft_handler_octal(ap);
	if (*progress == 'c' || *progress == 'C')
		ft_conversion_c(va_arg(ap, int));
	if (*progress == 'p')
		ft_conversion_p(va_arg(ap, void*));
	if (*progress == '%')
		ft_conversion_percent();
	ft_handler_hexadecimal(ap, progress);
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

int		ft_conversion_s(char *argument)
{
	char	*temp;

	if (!(argument))
	{
		g_print = ft_strdup("(null)");
		return (1);
	}
	if (g_fl.zero == 1)
		g_fl.zero = 0;
	if (g_fl.precision == 1 && (int)ft_strlen(argument) > g_fl.precision_v)
		temp = ft_strndup(argument, (size_t)g_fl.precision_v);
	else
		temp = ft_strdup(argument);
	ft_putwidth_string(g_fl.width_v, &temp);
	g_print = ft_strdup(temp);
	free(temp);
	return (1);
}

int		ft_conversion_c(char argument)
{
	if (1 < g_fl.width_v && g_fl.minus == 0)
	{
		while (g_fl.width_v-- - 1 > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	}
	ft_putchar(argument);
	g_return++;
	if (1 < g_fl.width_v && g_fl.minus == 1)
	{
		while (g_fl.width_v-- - 1 > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	}
	return (1);
}

int		ft_conversion_percent(void)
{
	if (1 < g_fl.width_v && g_fl.minus == 0)
	{
		while (g_fl.width_v-- - 1 > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	}
	ft_putchar('%');
	g_return++;
	if (1 < g_fl.width_v && g_fl.minus == 1)
	{
		while (g_fl.width_v-- - 1 > 0)
		{
			ft_putchar(' ');
			g_return++;
		}
	}
	return (1);
}

int		ft_conversion_p(void *argument)
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
	result = ft_putwidth_no_p(g_fl.width_v, result);
	g_print = ft_strdup(result);
	free(result);
	return (1);
}
