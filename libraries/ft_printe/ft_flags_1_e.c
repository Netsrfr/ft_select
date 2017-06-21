/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_1_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:14:10 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 19:14:10 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

char	*ft_flags_plus_e(char *progress)
{
	g_fe.space = 0;
	g_fe.plus = 1;
	g_fe.count++;
	progress++;
	if (g_fe.precision == 1)
	{
		g_fe.plus = 0;
		g_printe = ft_strdup("+");
	}
	return (progress);
}

char	*ft_flags_minus_e(char *progress)
{
	if (g_fe.zero == 1)
		g_fe.zero = 0;
	g_fe.minus = 1;
	g_fe.count++;
	progress++;
	return (progress);
}

char	*ft_flags_zero_e(char *progress)
{
	if (g_fe.minus == 1)
		progress++;
	else
	{
		g_fe.zero = 1;
		g_fe.count++;
		progress++;
	}
	return (progress);
}

char	*ft_flags_pound_e(char *progress)
{
	g_fe.pound = 1;
	g_fe.count++;
	progress++;
	return (progress);
}

char	*ft_flags_space_e(char *progress)
{
	if (g_fe.plus == 0)
		g_fe.space = 1;
	g_fe.count++;
	progress++;
	return (progress);
}
