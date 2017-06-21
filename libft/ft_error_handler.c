/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:20:20 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/12/07 15:20:20 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_error_handler(int error, char *ret1, char *ret2, char *ret3)
{
	if (*ret1)
		free(ret1);
	if (*ret2)
		free(ret2);
	if (*ret3)
		free(ret3);
	return (error);
}
