/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
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

void	ft_delete(t_cap caps, t_args **args)
{
	t_args	*ptr;

	ft_cursor(args);
	ptr = (*args)->next;
	if ((*args)->next == *args)
		ft_exit(caps, *args);
	else
	{
		(*args)->next->prev = (*args)->prev;
		(*args)->prev->next = (*args)->next;
		if ((*args)->head == 1)
		{
			ptr->cursor = 1;
			ptr->head = 1;
		}
		else
			(*args)->prev->cursor = 1;
	}
	ft_head(&ptr);
	free(*args);
	*args = ptr;
	ft_init_display(caps);
	ft_print_handler(caps, *args);
}

void	ft_return(t_cap caps, t_args *args)
{
	ft_head(&args);
	ft_printe("%s%s%s", caps.me, caps.ve, caps.te);
	if (args->selected == 1)
		ft_printf("%s ", args->arg);
	if (args->next == args)
		exit(0);
	args = args->next;
	while (args->head == 0)
	{
		if (args->selected == 1)
			ft_printf("%s ", args->arg);
		args = args->next;
	}
	ft_free_capabilities(&caps);
	ft_free_args(&args);
	exit(0);
}

void	ft_exit(t_cap caps, t_args *args)
{
	{
		tputs(tgoto(caps.cm, 0, 0), 1, ft_fputchar);
		ft_printe("%s%s%s", caps.me, caps.ve, caps.te);
		ft_free_capabilities(&caps);
		ft_free_args(&args);
		exit(0);
	}
}

void	ft_keys(char *line, t_cap caps, t_args **args)
{
	if (ft_strcmp(line, "\033") == 0)
		ft_exit(caps, *args);
	else if (ft_strcmp(line, " ") == 0)
		ft_select(caps, *args);
	else if (*line == 127 || ft_strcmp(line, "\033[3~") == 0)
		ft_delete(caps, args);
	else if (*line == 10)
		ft_return(caps, *args);
}
