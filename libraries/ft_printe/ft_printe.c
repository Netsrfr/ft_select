/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:25:47 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/01/17 14:25:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

void		flag_init_e(void)
{
	g_fe.error = 0;
	g_fe.precision = 0;
	g_fe.precision_v = 0;
	g_fe.neg = 0;
	g_fe.count = 0;
	g_fe.pound = 0;
	g_fe.zero = 0;
	g_fe.minus = 0;
	g_fe.plus = 0;
	g_fe.space = 0;
	g_fe.width = 0;
	g_fe.width_v = 0;
	g_fe.h = 0;
	g_fe.hh = 0;
	g_fe.l = 0;
	g_fe.ll = 0;
	g_fe.j = 0;
	g_fe.z = 0;
}

static char	*ft_flags_star_e(char *progress, va_list arguments)
{
	g_fe.width = 1;
	g_fe.width_v = va_arg(arguments, int);
	progress++;
	return (progress);
}

/*
** FLAG JZ Removed!!! Not needed for LS, add if needed.
*/

char		*ft_flags_e(char *progress, va_list arguments)
{
	while (PR('+') || PR('-') || PR('#') || PR(' ') || PR('h') || PR('l')
	|| PR('j') || PR('z') || PR('*') || (*progress >= '0' && *progress <= '9'))
	{
		if (*progress == '*')
			progress = ft_flags_star_e(progress, arguments);
		if (*progress >= '1' && *progress <= '9')
			progress = ft_flags_width_e(progress);
		if (*progress == '+')
			progress = ft_flags_plus_e(progress);
		if (*progress == '-')
			progress = ft_flags_minus_e(progress);
		if (*progress == '0')
			progress = ft_flags_zero_e(progress);
		if (*progress == '#')
			progress = ft_flags_pound_e(progress);
		if (*progress == ' ')
			progress = ft_flags_space_e(progress);
		if (*progress == 'h')
			progress = ft_flags_h_e(progress);
		if (*progress == 'l')
			progress = ft_flags_l_e(progress);
	}
	progress = ft_flags_precision_e(progress);
	return (progress);
}

static int	parser_e(const char *format, va_list arguments)
{
	char	*fmt_ptr;

	fmt_ptr = (char*)format;
	while (*fmt_ptr)
	{
		if (*fmt_ptr == '%')
		{
			flag_init_e();
			fmt_ptr = ft_flags_e(++fmt_ptr, arguments);
			fmt_ptr = ft_conversions_e(arguments, fmt_ptr);
		}
		if (g_printe != NULL)
		{
			g_returne = ft_strlen(g_printe) + g_returne;
			ft_putstre(g_printe);
			free(g_printe);
			g_printe = 0;
		}
		while (*fmt_ptr && *fmt_ptr != '%')
		{
			ft_putchare(*fmt_ptr++);
			g_returne++;
		}
	}
	return (1);
}

ssize_t		ft_printe(const char *format, ...)
{
	va_list	arguments;

	if (g_fe.error == -1)
		return (-1);
	g_returne = 0;
	va_start(arguments, format);
	parser_e(format, arguments);
	va_end(arguments);
	free(g_printe);
	return (g_returne);
}
