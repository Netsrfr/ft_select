/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 08:10:02 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/03 08:10:02 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

void	ft_handler_hexadecimal_e(va_list ap, char *progress)
{
	if (*progress == 'x' || *progress == 'X')
	{
		if (g_fe.ll == 1 || g_fe.j == 1 || g_fe.z == 1)
			ft_conversion_x_e(va_arg(ap, unsigned long long int), *progress);
		else if (g_fe.l == 1)
			ft_conversion_x_e(va_arg(ap, unsigned long int), *progress);
		else if (g_fe.h == 1)
			ft_conversion_x_e((unsigned short int)va_arg(ap, unsigned int),
							*progress);
		else if (g_fe.hh == 1)
			ft_conversion_x_e((unsigned char)va_arg(ap, unsigned int),
							*progress);
		else
			ft_conversion_x_e(va_arg(ap, unsigned int), *progress);
	}
}

int		ft_conversion_x_e(uintmax_t argument, char conversion)
{
	char	*result;
	int		i;

	i = 0;
	if (g_fe.precision_v == 0 && g_fe.precision == 1 && argument == 0)
		result = ft_strdup("");
	else
		result = ft_itoa_base_unsigned(argument, 16);
	if (conversion == 'x')
		while (result[i])
		{
			result[i] = (char)ft_tolower(result[i]);
			i++;
		}
	if (g_printe)
		g_printe = ft_strjoin(g_printe, result);
	else
		g_printe = ft_strdup(result);
	result = ft_putwidth_hex_e(conversion, g_fe.precision_v, argument, result);
	g_printe = ft_strdup(result);
	free(result);
	return (1);
}

char	*ft_hex_pound_e(char *result, char x, uintmax_t arg)
{
	if (x == 'x' && arg != 0)
		result = ft_strjoin("0x", result);
	if (x == 'X' && arg != 0)
		result = ft_strjoin("0X", result);
	return (result);
}

char	*ft_putwidth_hex_e(char x, int precision, uintmax_t arg, char *result)
{
	result = ft_put_precision_e(result, precision);
	if (g_fe.pound == 1 && arg != 0)
		g_fe.width_v = g_fe.width_v - 2;
	g_fe.width_v = (int)(g_fe.width_v - ft_strlen(result));
	if (g_fe.pound == 1 && g_fe.zero == 0)
		result = ft_hex_pound_e(result, x, arg);
	while (g_fe.width_v > 0 && g_fe.minus == 0)
	{
		if (g_fe.zero == 1 && g_fe.precision == 0)
			result = ft_strjoin("0", result);
		else
			result = ft_strjoin(" ", result);
		g_fe.width_v--;
	}
	while (g_fe.width_v > 0 && g_fe.minus == 1)
	{
		result = ft_strjoin(result, " ");
		g_fe.width_v--;
	}
	if (g_fe.pound == 1 && g_fe.zero == 1)
		result = ft_hex_pound_e(result, x, arg);
	return (result);
}
