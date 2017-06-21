/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:56:36 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 17:56:36 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printe.h"

void	ft_handler_decimal_e(va_list ap)
{
	if (g_fe.ll == 1 || g_fe.j == 1 || g_fe.z == 1)
		ft_conversion_d_e(va_arg(ap, long long int));
	else if (g_fe.l == 1)
		ft_conversion_d_e(va_arg(ap, long int));
	else if (g_fe.h == 1)
		ft_conversion_d_e((short int)va_arg(ap, int));
	else if (g_fe.hh == 1)
		ft_conversion_d_e((signed char)va_arg(ap, int));
	else
		ft_conversion_d_e(va_arg(ap, int));
}

void	ft_handler_unsigned_e(va_list ap)
{
	if (g_fe.ll == 1 || g_fe.j == 1 || g_fe.z == 1)
		ft_conversion_u_e(va_arg(ap, unsigned long long int));
	else if (g_fe.l == 1)
		ft_conversion_u_e(va_arg(ap, unsigned long int));
	else if (g_fe.h == 1)
		ft_conversion_u_e((unsigned short int)va_arg(ap, unsigned int));
	else if (g_fe.hh == 1)
		ft_conversion_u_e((unsigned char)va_arg(ap, unsigned int));
	else
		ft_conversion_u_e(va_arg(ap, unsigned int));
}

void	ft_handler_octal_e(va_list ap)
{
	if (g_fe.ll == 1 || g_fe.j == 1 || g_fe.z == 1)
		ft_conversion_o_e(va_arg(ap, unsigned long long int));
	else if (g_fe.l == 1)
		ft_conversion_o_e((unsigned long int)va_arg(ap, int));
	else if (g_fe.h == 1)
		ft_conversion_o_e((unsigned short int)va_arg(ap, unsigned int));
	else if (g_fe.hh == 1)
		ft_conversion_o_e((unsigned char)va_arg(ap, unsigned int));
	else
		ft_conversion_o_e(va_arg(ap, unsigned int));
}

void	ft_join_e(char **result, const char *s1, const char *s2)
{
	char	*temp;

	temp = *result;
	*result = ft_strjoin(s1, s2);
	free(temp);
}
