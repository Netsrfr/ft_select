/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 09:25:23 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/07/01 09:25:23 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_cursor(t_args **args)
{
	while ((*args)->cursor == 0)
		(*args) = (*args)->next;
}

void	ft_head(t_args **args)
{
	while ((*args)->head == 0)
		(*args) = (*args)->next;
}

void	ft_free_args(t_args **args)
{
	t_args	*ptr;

	ft_head(args);
	*args = (*args)->next;
	while ((*args)->head == 0)
	{
		ptr = *args;
		*args = (*args)->next;
		free(ptr);
	}
	free(*args);
}

void	ft_free_colors(void)
{
	free(g_colors->next->next->next->colors);
	free(g_colors->next->next->next);
	free(g_colors->next->next->colors);
	free(g_colors->next->next);
	free(g_colors->next->colors);
	free(g_colors->next);
	free(g_colors->colors);
	free(g_colors);
}

void	ft_width(t_args *head, size_t *width)
{
	*width = ft_strlen(head->arg);
	while (head->next->head == 0)
	{
		*width = *width < ft_strlen(head->arg) ? ft_strlen(head->arg) : *width;
		head = head->next;
	}
	*width += 4;
}
