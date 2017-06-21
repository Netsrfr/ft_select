/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:56:36 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/03/30 17:56:36 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handler_decimal(va_list ap)
{
	if (g_fl.ll == 1 || g_fl.j == 1 || g_fl.z == 1)
		ft_conversion_d(va_arg(ap, long long int));
	else if (g_fl.l == 1)
		ft_conversion_d(va_arg(ap, long int));
	else if (g_fl.h == 1)
		ft_conversion_d((short int)va_arg(ap, int));
	else if (g_fl.hh == 1)
		ft_conversion_d((signed char)va_arg(ap, int));
	else
		ft_conversion_d(va_arg(ap, int));
}

void	ft_handler_unsigned(va_list ap)
{
	if (g_fl.ll == 1 || g_fl.j == 1 || g_fl.z == 1)
		ft_conversion_u(va_arg(ap, unsigned long long int));
	else if (g_fl.l == 1)
		ft_conversion_u(va_arg(ap, unsigned long int));
	else if (g_fl.h == 1)
		ft_conversion_u((unsigned short int)va_arg(ap, unsigned int));
	else if (g_fl.hh == 1)
		ft_conversion_u((unsigned char)va_arg(ap, unsigned int));
	else
		ft_conversion_u(va_arg(ap, unsigned int));
}

void	ft_handler_octal(va_list ap)
{
	if (g_fl.ll == 1 || g_fl.j == 1 || g_fl.z == 1)
		ft_conversion_o(va_arg(ap, unsigned long long int));
	else if (g_fl.l == 1)
		ft_conversion_o((unsigned long int)va_arg(ap, int));
	else if (g_fl.h == 1)
		ft_conversion_o((unsigned short int)va_arg(ap, unsigned int));
	else if (g_fl.hh == 1)
		ft_conversion_o((unsigned char)va_arg(ap, unsigned int));
	else
		ft_conversion_o(va_arg(ap, unsigned int));
}

void	ft_join(char **result, const char *s1, const char *s2)
{
	char	*temp;

	temp = *result;
	*result = ft_strjoin(s1, s2);
	free(temp);
}
