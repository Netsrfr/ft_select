/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:32:28 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/26 16:32:28 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putchare(char c)
{
	write(2, &c, 1);
}

int		ft_fputchar(int c)
{
	write(2, &c, 1);
	return (1);
}