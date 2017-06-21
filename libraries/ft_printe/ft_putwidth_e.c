/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 09:33:32 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 09:33:32 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

char	*ft_putwidth_e(int width, char *result)
{
	if (g_fe.plus == 1 && g_fe.neg == 0 && g_fe.width == 1 && g_fe.zero == 1)
		width--;
	result = ft_put_precision_e(result, g_fe.precision_v);
	if (g_fe.plus == 1 && g_fe.neg == 0 && g_fe.width == 1 && g_fe.zero == 0)
		ft_join_e(&result, "+", result);
	if (g_fe.neg == 1 && g_fe.zero == 0)
		ft_join_e(&result, "-", result);
	width = (g_fe.neg == 1 && g_fe.zero == 1) ?
		(width - (int)ft_strlen(result)) - 1 : width - (int)ft_strlen(result);
	while (width > 0 && g_fe.minus == 0)
	{
		(g_fe.zero == 1 && g_fe.precision == 0) ?
		ft_join_e(&result, "0", result) : ft_join_e(&result, " ", result);
		width--;
	}
	if (g_fe.neg == 1 && g_fe.zero == 1)
		result = ft_strjoin("-", result);
	while (width > 0 && g_fe.minus == 1)
	{
		ft_join_e(&result, result, " ");
		width--;
	}
	return (result);
}

char	*ft_putwidth_no_p_e(int width, char *result)
{
	while (width > g_fe.precision_v && g_fe.minus == 0)
	{
		result = ft_strjoin(" ", result);
		width--;
	}
	while (width > g_fe.precision_v && g_fe.minus == 1)
	{
		result = ft_strjoin(result, " ");
		width--;
	}
	return (result);
}

void	ft_putwidth_string_e(int width, char **result)
{
	int		strlen;
	char	*temp;

	strlen = (int)ft_strlen(*result);
	while (width > strlen && g_fe.minus == 0)
	{
		temp = *result;
		*result = ft_strjoin(" ", *result);
		free(temp);
		width--;
	}
	while (width > strlen && g_fe.minus == 1)
	{
		temp = *result;
		*result = ft_strjoin(*result, " ");
		free(temp);
		width--;
	}
}

char	*ft_put_precision_e(char *result, int precision)
{
	int log;

	log = (int)ft_strlen(result);
	while (log < precision)
	{
		result = ft_strjoin("0", result);
		precision--;
	}
	return (result);
}

char	*ft_putwidth_o_e(uintmax_t arg, int width, char *result)
{
	result = ft_put_precision_e(result, g_fe.precision_v);
	if (g_fe.neg == 1)
		result = ft_strjoin("-", result);
	width = (int)(width - ft_strlen(result));
	if (g_fe.pound == 1 && g_fe.zero == 0 && g_fe.precision == 0 && arg != 0)
	{
		result = ft_strjoin("0", result);
		g_fe.pound = 0;
		width--;
	}
	while (width > 0 && g_fe.minus == 0)
	{
		if (g_fe.zero == 1 && g_fe.precision == 0)
			result = ft_strjoin("0", result);
		else
			result = ft_strjoin(" ", result);
		width--;
	}
	while (width > 0 && g_fe.minus == 1)
	{
		result = ft_strjoin(result, " ");
		width--;
	}
	return (result);
}
