/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:16:38 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 19:16:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flags_width(char *progress)
{
	int	result;

	result = 0;
	g_fl.width = 1;
	while (*progress >= '0' && *progress <= '9')
	{
		result = result * 10;
		result = result + (*progress - 48);
		progress++;
	}
	g_fl.width_v = result;
	return (progress);
}

char	*ft_flags_h(char *progress)
{
	progress++;
	if (*progress == 'h')
	{
		g_fl.hh = 1;
		progress++;
	}
	else
		g_fl.h = 1;
	return (progress);
}

char	*ft_flags_l(char *progress)
{
	progress++;
	if (*progress == 'l')
	{
		g_fl.ll = 1;
		progress++;
	}
	else
		g_fl.l = 1;
	return (progress);
}

char	*ft_flags_jz(char *progress)
{
	if (*progress == 'j')
		g_fl.j = 1;
	if (*progress == 'z')
		g_fl.z = 1;
	progress++;
	return (progress);
}

char	*ft_flags_precision(char *progress)
{
	int result;

	if (*progress == '.')
	{
		g_fl.precision = 1;
		result = 0;
		progress++;
		while (*progress >= '0' && *progress <= '9')
		{
			result = result * 10;
			result = result + (*progress - 48);
			progress++;
		}
		g_fl.precision_v = result;
		progress = ft_flags(progress, NULL);
	}
	return (progress);
}
