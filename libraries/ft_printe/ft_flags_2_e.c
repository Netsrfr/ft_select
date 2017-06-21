/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 19:16:38 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 19:16:38 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

char	*ft_flags_width_e(char *progress)
{
	int	result;

	result = 0;
	g_fe.width = 1;
	while (*progress >= '0' && *progress <= '9')
	{
		result = result * 10;
		result = result + (*progress - 48);
		progress++;
	}
	g_fe.width_v = result;
	return (progress);
}

char	*ft_flags_h_e(char *progress)
{
	progress++;
	if (*progress == 'h')
	{
		g_fe.hh = 1;
		progress++;
	}
	else
		g_fe.h = 1;
	return (progress);
}

char	*ft_flags_l_e(char *progress)
{
	progress++;
	if (*progress == 'l')
	{
		g_fe.ll = 1;
		progress++;
	}
	else
		g_fe.l = 1;
	return (progress);
}

char	*ft_flags_precision_e(char *progress)
{
	int result;

	if (*progress == '.')
	{
		g_fe.precision = 1;
		result = 0;
		progress++;
		while (*progress >= '0' && *progress <= '9')
		{
			result = result * 10;
			result = result + (*progress - 48);
			progress++;
		}
		g_fe.precision_v = result;
		progress = ft_flags_e(progress, NULL);
	}
	return (progress);
}
