/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwidth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 09:33:32 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 09:33:32 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putwidth(int width, char *result)
{
	if (g_fl.plus == 1 && g_fl.neg == 0 && g_fl.width == 1 && g_fl.zero == 1)
		width--;
	result = ft_put_precision(result, g_fl.precision_v);
	if (g_fl.plus == 1 && g_fl.neg == 0 && g_fl.width == 1 && g_fl.zero == 0)
		ft_join(&result, "+", result);
	if (g_fl.neg == 1 && g_fl.zero == 0)
		ft_join(&result, "-", result);
	width = (g_fl.neg == 1 && g_fl.zero == 1) ?
		(width - (int)ft_strlen(result)) - 1 : width - (int)ft_strlen(result);
	while (width > 0 && g_fl.minus == 0)
	{
		(g_fl.zero == 1 && g_fl.precision == 0) ?
				ft_join(&result, "0", result) : ft_join(&result, " ", result);
		width--;
	}
	if (g_fl.neg == 1 && g_fl.zero == 1)
		result = ft_strjoin("-", result);
	while (width > 0 && g_fl.minus == 1)
	{
		ft_join(&result, result, " ");
		width--;
	}
	return (result);
}

char	*ft_putwidth_no_p(int width, char *result)
{
	while (width > g_fl.precision_v && g_fl.minus == 0)
	{
		result = ft_strjoin(" ", result);
		width--;
	}
	while (width > g_fl.precision_v && g_fl.minus == 1)
	{
		result = ft_strjoin(result, " ");
		width--;
	}
	return (result);
}

void	ft_putwidth_string(int width, char **result)
{
	int		strlen;
	char	*temp;

	strlen = (int)ft_strlen(*result);
	while (width > strlen && g_fl.minus == 0)
	{
		temp = *result;
		*result = ft_strjoin(" ", *result);
		free(temp);
		width--;
	}
	while (width > strlen && g_fl.minus == 1)
	{
		temp = *result;
		*result = ft_strjoin(*result, " ");
		free(temp);
		width--;
	}
}

char	*ft_put_precision(char *result, int precision)
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

char	*ft_putwidth_o(uintmax_t arg, int width, char *result)
{
	result = ft_put_precision(result, g_fl.precision_v);
	if (g_fl.neg == 1)
		result = ft_strjoin("-", result);
	width = (int)(width - ft_strlen(result));
	if (g_fl.pound == 1 && g_fl.zero == 0 && g_fl.precision == 0 && arg != 0)
	{
		result = ft_strjoin("0", result);
		g_fl.pound = 0;
		width--;
	}
	while (width > 0 && g_fl.minus == 0)
	{
		if (g_fl.zero == 1 && g_fl.precision == 0)
			result = ft_strjoin("0", result);
		else
			result = ft_strjoin(" ", result);
		width--;
	}
	while (width > 0 && g_fl.minus == 1)
	{
		result = ft_strjoin(result, " ");
		width--;
	}
	return (result);
}
