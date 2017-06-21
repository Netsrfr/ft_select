/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_numerical.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:15:25 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 10:15:25 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_spaces(char *result, int strlen)
{
	if (g_fl.width == 0 && g_fl.precision == 0 && g_fl.neg == 0)
		result = ft_strjoin(" ", result);
	if (g_fl.width == 1)
	{
		if (g_fl.neg == 0 && strlen < g_fl.width_v)
			result = ft_strjoin(" ", result);
		if (g_fl.precision == 1 && g_fl.precision_v > g_fl.width_v)
			result = ft_strjoin(" ", result);
	}
	return (result);
}

int		ft_conversion_d(intmax_t argument)
{
	char	*result;

	if (argument < 0)
	{
		g_fl.neg = 1;
		argument = argument * -1;
	}
	if (g_fl.precision_v == 0 && g_fl.precision == 1 && argument == 0)
		result = ft_strdup("");
	else
		result = ft_itoa(argument);
	result = ft_putwidth(g_fl.width_v,
						result);
	if ((g_fl.plus == 1 && g_fl.neg == 0 && g_fl.width == 0) ||
	(g_fl.plus == 1 && g_fl.neg == 0 && g_fl.width == 1 && g_fl.zero == 1))
		result = ft_strjoin("+", result);
	if (g_fl.space == 1)
		result = ft_spaces(result, (int)ft_strlen(result));
	if (g_print)
		g_print = ft_strjoin(g_print, result);
	else
		g_print = ft_strdup(result);
	free(result);
	return (1);
}

int		ft_conversion_u(uintmax_t argument)
{
	char	*result;

	result = ft_itoa_unsigned(argument);
	result = ft_putwidth(g_fl.width_v,
						result);
	g_print = ft_strdup(result);
	free(result);
	return (1);
}

int		ft_conversion_o(uintmax_t argument)
{
	char *result;

	if (g_fl.precision_v == 0 && g_fl.precision == 1 && argument == 0)
	{
		if (g_fl.pound == 0)
			result = ft_strdup("");
		else
			result = ft_strdup("0");
	}
	else
		result = ft_itoa_base_unsigned(argument, 8);
	if (g_print)
		g_print = ft_strjoin(g_print, result);
	else
		g_print = ft_strdup(result);
	if (g_fl.plus == 1)
		g_fl.width_v--;
	result = ft_putwidth_o(argument, g_fl.width_v, result);
	g_print = ft_strdup(result);
	if (g_fl.pound == 1 && g_fl.precision == 0 && argument != 0)
		g_print = ft_strjoin("0", g_print);
	free(result);
	return (1);
}
