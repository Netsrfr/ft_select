/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:41:56 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/30 18:41:56 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select(t_cap caps, t_args *args)
{
	ft_cursor(&args);
	args->selected = args->selected == 0 ? 1 : 0;
	ft_print_handler(caps, args);
}

void	ft_delete(t_cap caps, t_args *args)
{
	t_args	*ptr;

	ft_cursor(&args);
	ptr = args->next;
	if (args->next == args)
		ft_exit(caps, args);
	else
	{
		args->next->prev = args->prev;
		args->prev->next = args->next;
		if (args->head == 1)
		{
			args->cursor = 0;
//			args->head = 0;
			args->next->cursor = 1;
			args->next->head = 1;
//			ptr = args->next;
			free(args);
		}
		else
		{
			args->prev->cursor = 1;
//			ptr = args->prev;
		}
	}
	ft_head(&ptr);
	ft_init_display(caps);
	ft_print_handler(caps, ptr);
}

void	ft_return(t_cap caps, t_args *args)
{
	ft_head(&args);
	if (args->selected == 1)
		ft_printf("%s ", args->arg);
	if (args->next == args)
		exit(0);
	while (args->next->head == 0)
	{
		if (args->selected == 1)
			ft_printf("%s ", args->arg);
		args = args->next;
	}
	exit(0);
}
