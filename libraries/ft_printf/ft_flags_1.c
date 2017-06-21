/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:14:10 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 19:14:10 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags_plus(char *progress)
{
	g_fl.space = 0;
	g_fl.plus = 1;
	g_fl.count++;
	progress++;
	if (g_fl.precision == 1)
	{
		g_fl.plus = 0;
		g_print = ft_strdup("+");
	}
	return (progress);
}

char	*ft_flags_minus(char *progress)
{
	if (g_fl.zero == 1)
		g_fl.zero = 0;
	g_fl.minus = 1;
	g_fl.count++;
	progress++;
	return (progress);
}

char	*ft_flags_zero(char *progress)
{
	if (g_fl.minus == 1)
		progress++;
	else
	{
		g_fl.zero = 1;
		g_fl.count++;
		progress++;
	}
	return (progress);
}

char	*ft_flags_pound(char *progress)
{
	g_fl.pound = 1;
	g_fl.count++;
	progress++;
	return (progress);
}

char	*ft_flags_space(char *progress)
{
	if (g_fl.plus == 0)
		g_fl.space = 1;
	g_fl.count++;
	progress++;
	return (progress);
}
