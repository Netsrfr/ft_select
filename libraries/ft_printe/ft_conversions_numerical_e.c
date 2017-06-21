/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_numerical_e.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 10:15:25 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 10:15:25 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

char	*ft_spaces_e(char *result, int strlen)
{
	if (g_fe.width == 0 && g_fe.precision == 0 && g_fe.neg == 0)
		result = ft_strjoin(" ", result);
	if (g_fe.width == 1)
	{
		if (g_fe.neg == 0 && strlen < g_fe.width_v)
			result = ft_strjoin(" ", result);
		if (g_fe.precision == 1 && g_fe.precision_v > g_fe.width_v)
			result = ft_strjoin(" ", result);
	}
	return (result);
}

int		ft_conversion_d_e(intmax_t argument)
{
	char	*result;

	if (argument < 0)
	{
		g_fe.neg = 1;
		argument = argument * -1;
	}
	if (g_fe.precision_v == 0 && g_fe.precision == 1 && argument == 0)
		result = ft_strdup("");
	else
		result = ft_itoa(argument);
	result = ft_putwidth_e(g_fe.width_v,
							result);
	if ((g_fe.plus == 1 && g_fe.neg == 0 && g_fe.width == 0) ||
	(g_fe.plus == 1 && g_fe.neg == 0 && g_fe.width == 1 && g_fe.zero == 1))
		result = ft_strjoin("+", result);
	if (g_fe.space == 1)
		result = ft_spaces_e(result, (int)ft_strlen(result));
	if (g_printe)
		g_printe = ft_strjoin(g_printe, result);
	else
		g_printe = ft_strdup(result);
	free(result);
	return (1);
}

int		ft_conversion_u_e(uintmax_t argument)
{
	char	*result;

	result = ft_itoa_unsigned(argument);
	result = ft_putwidth_e(g_fe.width_v,
							result);
	g_printe = ft_strdup(result);
	free(result);
	return (1);
}

int		ft_conversion_o_e(uintmax_t argument)
{
	char *result;

	if (g_fe.precision_v == 0 && g_fe.precision == 1 && argument == 0)
	{
		if (g_fe.pound == 0)
			result = ft_strdup("");
		else
			result = ft_strdup("0");
	}
	else
		result = ft_itoa_base_unsigned(argument, 8);
	if (g_printe)
		g_printe = ft_strjoin(g_printe, result);
	else
		g_printe = ft_strdup(result);
	if (g_fe.plus == 1)
		g_fe.width_v--;
	result = ft_putwidth_o_e(argument, g_fe.width_v, result);
	g_printe = ft_strdup(result);
	if (g_fe.pound == 1 && g_fe.precision == 0 && argument != 0)
		g_printe = ft_strjoin("0", g_printe);
	free(result);
	return (1);
}
