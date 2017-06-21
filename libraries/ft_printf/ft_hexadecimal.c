/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 08:10:02 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/03 08:10:02 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handler_hexadecimal(va_list ap, char *progress)
{
	if (*progress == 'x' || *progress == 'X')
	{
		if (g_fl.ll == 1 || g_fl.j == 1 || g_fl.z == 1)
			ft_conversion_x(va_arg(ap, unsigned long long int), *progress);
		else if (g_fl.l == 1)
			ft_conversion_x(va_arg(ap, unsigned long int), *progress);
		else if (g_fl.h == 1)
			ft_conversion_x((unsigned short int)va_arg(ap, unsigned int),
							*progress);
		else if (g_fl.hh == 1)
			ft_conversion_x((unsigned char)va_arg(ap, unsigned int), *progress);
		else
			ft_conversion_x(va_arg(ap, unsigned int), *progress);
	}
}

int		ft_conversion_x(uintmax_t argument, char conversion)
{
	char	*result;
	int		i;

	i = 0;
	if (g_fl.precision_v == 0 && g_fl.precision == 1 && argument == 0)
		result = ft_strdup("");
	else
		result = ft_itoa_base_unsigned(argument, 16);
	if (conversion == 'x')
		while (result[i])
		{
			result[i] = (char)ft_tolower(result[i]);
			i++;
		}
	if (g_print)
		g_print = ft_strjoin(g_print, result);
	else
		g_print = ft_strdup(result);
	result = ft_putwidth_hex(conversion, g_fl.precision_v, argument, result);
	g_print = ft_strdup(result);
	free(result);
	return (1);
}

char	*ft_hex_pound(char *result, char x, uintmax_t arg)
{
	if (x == 'x' && arg != 0)
		result = ft_strjoin("0x", result);
	if (x == 'X' && arg != 0)
		result = ft_strjoin("0X", result);
	return (result);
}

char	*ft_putwidth_hex(char x, int precision, uintmax_t arg, char *result)
{
	result = ft_put_precision(result, precision);
	if (g_fl.pound == 1 && arg != 0)
		g_fl.width_v = g_fl.width_v - 2;
	g_fl.width_v = (int)(g_fl.width_v - ft_strlen(result));
	if (g_fl.pound == 1 && g_fl.zero == 0)
		result = ft_hex_pound(result, x, arg);
	while (g_fl.width_v > 0 && g_fl.minus == 0)
	{
		if (g_fl.zero == 1 && g_fl.precision == 0)
			result = ft_strjoin("0", result);
		else
			result = ft_strjoin(" ", result);
		g_fl.width_v--;
	}
	while (g_fl.width_v > 0 && g_fl.minus == 1)
	{
		result = ft_strjoin(result, " ");
		g_fl.width_v--;
	}
	if (g_fl.pound == 1 && g_fl.zero == 1)
		result = ft_hex_pound(result, x, arg);
	return (result);
}
