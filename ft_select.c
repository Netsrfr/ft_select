/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:13:45 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/19 16:13:45 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_alpha(char letter, t_cap caps, t_args *args)
{
	t_args	*current;

	ft_cursor(&args);
	current = args;
	args = args->next;
	while (args->cursor == 0 && *(args->arg) != letter)
		args = args->next;
	if (args->cursor == 0 && *(args->arg) == letter)
	{
		args->cursor = 1;
		current->cursor = 0;
	}
	ft_print_handler(caps, args);
}

static t_args	*ft_link(void const *content, size_t content_size)
{
	t_args	*link;

	if (!(link = ft_memalloc(sizeof(t_args))))
		return (0);
	link->arg = (void*)content;
	if (content)
	{
		ft_memcpy(link->arg, content, content_size);
	}
	else
	{
		link->next = NULL;
	}
	return (link);
}

static void		ft_list(char **argv, t_args **link)
{
	t_args	*head;

	*link = ft_link(argv[1], ft_strlen(argv[1]) * sizeof(char));
	(*link)->cursor = 1;
	(*link)->head = 1;
	(*link)->selected = 0;
	head = *link;
	argv = &argv[2];
	while (*argv)
	{
		(*link)->next = ft_link(*argv, (ft_strlen(*argv) * sizeof(char)));
		argv++;
		(*link)->next->prev = (*link);
		*link = (*link)->next;
		(*link)->head = 0;
	}
	(*link)->next = head;
	head->prev = *link;
	ft_head(link);
}

void			ft_read(t_cap caps, t_args *args)
{
	char	*line;
	int		pipe;

	line = ft_memalloc(1024);
	pipe = open("/dev/stdin", O_RDONLY);
	read(pipe, line, 15);
	if (line[0] == '\033' && line[2] >= 65 && line[2] <= 68)
		ft_arrows(line[2], caps, args);
	ft_keys(line, caps, &args);
	if (ft_strlen(line) == 1)
		if ((*line >= 65 && *line <= 90) || (*line >= 97 && *line <= 122))
			ft_alpha(*line, caps, args);
	ft_read(caps, args);
}

int				main(int argc, char **argv)
{
	t_args	*head;
	t_cap	caps;

	ft_capabilities(&caps);
	g_sig.caps = caps;
	ft_sigaction();
	if (argc >= 2)
		ft_list(argv, &head);
	else
	{
		ft_printe("%s requires one or more arguments\n", CE);
		ft_free_capabilities(&caps);
		exit(0);
	}
	ft_termios();
	ft_init_display(caps);
	ft_print_handler(caps, (head));
	ft_read(caps, (head));
	return (0);
}
