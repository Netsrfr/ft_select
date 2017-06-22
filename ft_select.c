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

void	ft_termios()
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	term.c_cc[VMIN] = 0;
}

void	ft_right(t_cap caps, t_args *args)
{
	while (args->cursor == 0)
		args = args->next;
	args->cursor = 0;
	args->next->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_left(t_cap caps, t_args *args)
{
	while (args->cursor == 0)
		args = args->prev;
	args->cursor = 0;
	args->prev->cursor = 1;
	ft_print_handler(caps, args);
}

void	ft_select(t_cap caps, t_args *args)
{
	while (args->cursor == 0)
		args = args->next;
	args->selected = args->selected == 0 ? 1 : 0;
	ft_print_handler(caps, args);
}

void	ft_read(t_cap caps, t_args *args)
{
	char *line;

	line = ft_memalloc(1024);

	read(1, line, 15);
	if (ft_strcmp(line, "\033") == 0)
	{
		tputs("\033[39m\033[49m\033[2J", 1, ft_fputchar);
		exit(0);
	}
//	if (line[2] == 65)
//		printf("UP\n");
//	if (line[2] == 66)
//		printf("DOWN\n");
	if (line[2] == 67)
		ft_right(caps, args);
	if (line[2] == 68)
		ft_left(caps, args);
	if (ft_strcmp(line, " ") == 0)
		ft_select(caps, args);
	ft_read(caps, args);
}

t_args	*ft_link(void const *content, size_t content_size)
{
	t_args	*link;

	if (!(link = ft_memalloc(sizeof(t_args))))
		return (0);
	link->arg = (void*)content;
	if (content)
	{
//		if (!(link->arg = ft_memalloc(content_size)))
//			return (0);
		ft_memcpy(link->arg, content, content_size);
		link->arg_size = content_size;
	}
	else
	{
		link->arg_size = 0;
		link->next = NULL;
	}
	return (link);
}

void	ft_list(char **argv, t_args *head)
{
	t_args	*link;

	head->arg = ft_strdup(argv[1]);
	head->cursor = 1;
	head->head = 1;
	head->selected = 0;
	link = head;
	argv = &argv[2];
	while (*argv)
	{
		link->next = ft_link(*argv, (ft_strlen(*argv) * sizeof(char)));
		argv++;
		link->next->prev = link;
		link = link->next;
		link->head = 0;

	}
	head->prev = link;
	link->next = head;
	link = head;
	while (link->next->head == 0)
		link = link->next;
}

void	ft_print_arg(t_cap caps, t_args link, size_t width)
{
	int i = 0;
	ft_printe("%s\033[40m\033[33m", caps.me);
	while (i++ + ft_strlen(link.arg) <= width)
		ft_printe(" ");
	if (link.cursor == 1)
		ft_printe("%s", caps.us);
	if (link.selected == 1)
		ft_printe("%s", caps.mr);
	ft_printe("%s%s\033[40m\033[33m ", link.arg, caps.me);
}

void	ft_testprint(t_cap caps, t_args *args)
{
	struct winsize	win;
	size_t width;
	int	row;
	int col;
	t_args *head;

	head = args;

	row = 1;
	col = 1;
	ioctl(0, TIOCGWINSZ, &win);
	width = ft_strlen(args->arg);
	while (args->next->head == 0)
	{
		width = width < ft_strlen(args->arg) ? ft_strlen(args->arg) : width;
		args = args->next;
	}
	width += 4;
	win.ws_xpixel = (unsigned short)(win.ws_col - 16);
	win.ws_ypixel = (unsigned short)(win.ws_row - 4);
	while (head->next->head == 0)
	{
		col = 1;
		while (head->next->head == 0 && col * width < win.ws_xpixel)
		{
			ft_print_arg(caps, *head, width);
			head = head->next;
			col++;
		}
		row++;
		if (col * width > win.ws_xpixel)
			tputs(tgoto(caps.cm, 8, (row * 2)), 1, ft_fputchar);
	}
//	printf("col = %d | width = %lu | xpixel = %hu\n", col, width, win.ws_xpixel);
//	if (col * width > win.ws_xpixel)
	//	tputs(tgoto(caps.cm, 8, ((row + 1) * 2)), 1, ft_fputchar);
	ft_print_arg(caps, *head, width);

}

void	ft_print_handler(t_cap caps, t_args *args)
{
	tputs(tgoto(caps.cm, 8, 2), 1, ft_fputchar);
	while (args->head == 0)
		args = args->next;
	ft_testprint(caps, args);
//	while (args->next->head == 0)
//	{
//		ft_print_arg(caps, *args);
//		args = args->next;
//	}
//	ft_print_arg(caps, *args);
}

void ft_init_display(t_cap caps)
{
	struct winsize	win;
	int				i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &win);
	tputs(tgoto(caps.cm, 0, 0), 1, ft_fputchar);
	ft_printe("%s\033[40m%s\033[44m\033[37m", caps.me, caps.cl);
	while (i < win.ws_col)
	{
		ft_printe(" ");
		i++;
		if (i == (win.ws_col/2 - 4))
		{
			ft_printe("ft_select");
			i = i + 9;
		}
	}
	i = 0;
	tputs(tgoto(caps.cm, 0, win.ws_col), 1, ft_fputchar);
	ft_printe("%s\033[44m\033[37m", caps.me);
	while (i < win.ws_col)
	{
		ft_printe(" ");
		i++;
	}
	ft_printe("%s\033[40m\033[33m", caps.me);
}


void	ft_signal(int sig)
{
	//if (sig == SIGWINCH)
	ft_init_display(g_caps);
}

void	ft_allocate_capabilities(t_cap *caps)
{
	caps->cl = ft_memalloc(16);
	caps->us = ft_memalloc(16);
	caps->me = ft_memalloc(16);
	caps->cm = ft_memalloc(16);
	caps->mr = ft_memalloc(16);
	caps->kr = ft_memalloc(16);
	caps->kl = ft_memalloc(16);

}

void	ft_capabilities(t_cap *caps)
{
	char *buffer = ft_memalloc(2048);
	ft_allocate_capabilities(caps);
	tgetent(buffer, getenv("TERM"));
	caps->cm = tgetstr("cm", &caps->cm);
	caps->cl = tgetstr("cl", &caps->cl);
	caps->us = tgetstr("us", &caps->us);
	caps->me = tgetstr("me", &caps->me);
	caps->mr = tgetstr("mr", &caps->mr);
	caps->kl = tgetstr("kl", &caps->kl);
	caps->kr = tgetstr("kr", &caps->kr);
}

int main(int argc, char **argv)
{
	t_args list;
	t_cap	caps;

	signal(SIGWINCH, ft_signal);
	ft_capabilities(&caps);
	//list = ft_memalloc(sizeof(t_args));
	if (argc >= 2)
		ft_list(argv, &list);
	ft_termios();
	g_caps = caps;
	ft_init_display(caps);
	ft_print_handler(caps, &list);
	ft_read(caps, &list);
	return (0);
}