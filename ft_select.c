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
	tcgetattr(STDIN_FILENO, &g_sig.term);
	term.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
	term.c_cc[VMIN] = 0;
}



void	ft_exit(t_cap caps, t_args *args)
{
	{
		//tputs("\033[39m\033[49m\033[2J", 1, ft_fputchar);
		ft_printe("\033[39m\033[49m\033[2J");
		ft_printe("%s%s", caps.me, caps.ve);
		exit(0);
	}
}





void	ft_read(t_cap caps, t_args *args)
{
	char *line;

	line = ft_memalloc(1024);
	int	pipe;

	pipe = open("/dev/stdin", O_RDONLY);

	read(pipe, line, 15);
	if (ft_strcmp(line, "\033") == 0)
		ft_exit(caps, args);
	if (line[2] >= 65 && line[2] <= 68)
		ft_arrows(line[2], caps, args);
	if (ft_strcmp(line, " ") == 0)
		ft_select(caps, args);
	if (*line == 127)
		ft_delete(caps, args);
	if (*line == 10)
		ft_return(caps, args);
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

	//head = ft_memalloc(sizeof(t_args));
	//ft_memcpy(head->arg, argv[1], (ft_strlen(argv[1]) * sizeof(char)));
	//head->arg = ft_strdup(argv[1]);
	head->arg = argv[1];
	//head = ft_link(*argv, (ft_strlen(*argv) * sizeof(char)));
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

	if (link.cursor == 1)
		ft_printe("%s", caps.us);
	if (link.selected == 1)
		ft_printe("%s", caps.mr);
	ft_printe("%s%s\033[40m\033[33m", link.arg, caps.me);
	while (i++ + ft_strlen(link.arg) < width)
		ft_printe(" ");
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

void	ft_set_win(struct winsize *win)
{
	ioctl(0, TIOCGWINSZ, win);
	win->ws_xpixel = (unsigned short)(win->ws_col > 11 ? (win->ws_col - 11) : 0);
	win->ws_ypixel = (unsigned short)(win->ws_col > 4 ? (win->ws_row - 4) : 0);
}

void	ft_position(t_args *head, struct winsize win, size_t width)
{
	int row;
	int col;

	row = 1;
	col = 1;
	while (head->next->head == 0)
	{
		while (head->next->head == 0 && (col * width) < win.ws_xpixel)
		{
			head->x = col;
			head->y = row;
			head = head->next;
			col++;
		}
		if (col * width >= win.ws_xpixel)
		{
			row++;
			col = 1;
		}
	}
	head->x = col;
	head->y = row;
}

void	ft_start(t_args **head, struct winsize win, int *start)
{
	t_args	*temp;

	temp = *head;
	*start = 1;
	ft_cursor(&temp);
	if (temp->y > win.ws_ypixel)
	{
		*start = ((temp->y - win.ws_ypixel) + 1);
		while ((*head)->y != *start)
			*head = (*head)->next;
	}
}

void	ft_layout(t_cap caps, t_args *args)
{
	struct winsize	win;
	size_t width;
	int	row;
	int start;

	ft_width(args, &width);
	ft_set_win(&win);
	if (width >= win.ws_xpixel || win.ws_row < 5)
		return ;
	ft_position(args, win, width);
	ft_start(&args, win, &start);
	row = start;
	if (args->next == args)
		ft_print_arg(caps, *args, width);
	while (args->next->head == 0 && row - start < win.ws_ypixel)
	{
		while (args->next->head == 0 && args->y == row)
		{
			ft_print_arg(caps, *args, width);
			args = args->next;
		}
		row++;
		if (args->y == row)
			tputs(tgoto(caps.cm, 8, (((row - start) + 2))), 1, ft_fputchar);
		if (args->next->head == 1 && args->y - start < win.ws_ypixel)
			ft_print_arg(caps, *args, width);
	}
	ft_printe("%s", caps.ce);

}

void	ft_print_handler(t_cap caps, t_args *args)
{
	g_sig.args = args;

	tputs(tgoto(caps.cm, 8, 2), 1, ft_fputchar);
	ft_head(&args);
	ft_layout(caps, args);
}

void ft_init_display(t_cap caps)
{
	struct winsize	win;
	int				i;

	i = 0;
	ioctl(0, TIOCGWINSZ, &win);
	tputs(tgoto(caps.cm, 0, 0), 1, ft_fputchar);
	ft_printe("%s\033[40m%s\033[44m\033[37m", caps.me, caps.cl);
	while (i++ < win.ws_col)
	{
		ft_printe(" ");
		if (i == (win.ws_col/2 - 4))
		{
			ft_printe("ft_select");
			i = i + 9;
		}
	}
	i = 83;
	tputs(tgoto(caps.cm, 0, win.ws_col), 1, ft_fputchar);
	ft_printe("%s\033[44m\033[37m%s", caps.me, caps.ce);
	tputs(tgoto(caps.cm, 4, win.ws_col), 1, ft_fputchar);
	if (win.ws_col >= 18)
	{
		tputs(tgoto(caps.cm, win.ws_col - 14, win.ws_row), 1, ft_fputchar);
		ft_printe("ESC = EXIT");
	}
	if (win.ws_col >= 56)
	{
		tputs(tgoto(caps.cm, 4, win.ws_row), 1, ft_fputchar);
		ft_printe("NAVIGATION = UP, DOWN, LEFT, RIGHT");
	}
	if (win.ws_col >= 94)
	{
		tputs(tgoto(caps.cm, ((win.ws_col - 90) / 3) + 41, win.ws_row), 1, ft_fputchar);
		ft_printe("SELECT = SPACE");
		tputs(tgoto(caps.cm, ((win.ws_col - 90) / 3) * 2 + 59, win.ws_row), 1, ft_fputchar);
		ft_printe("RETURN = CONFIRM");

	}
	if (win.ws_col >= 42)

//	while (i < win.ws_col)
//	{
//		ft_printe(" ");
//		i++;
//	}
	ft_printe("%s%s\033[40m\033[33m", caps.me, caps.vi);
}

void	ft_signal(int sig)
{
	g_sig.term.c_lflag |= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_sig.term);
	kill(0, SIGTSTP);

}

void	ft_sigwinch(int sig)
{
	if (sig == SIGWINCH)
	{
		ft_init_display(g_sig.caps);
		ft_print_handler(g_sig.caps, g_sig.args);
	}
}

void	ft_allocate_capabilities(t_cap *caps)
{
	caps->cl = ft_memalloc(16);
	caps->ce = ft_memalloc(16);
	caps->us = ft_memalloc(16);
	caps->me = ft_memalloc(16);
	caps->mr = ft_memalloc(16);
	caps->vi = ft_memalloc(16);
	caps->ve = ft_memalloc(16);
	caps->kr = ft_memalloc(16);
	caps->kl = ft_memalloc(16);
	caps->cm = ft_memalloc(16);


}

void	ft_capabilities(t_cap *caps)
{
	char *buffer = ft_memalloc(2048);
	ft_allocate_capabilities(caps);
	if((tgetent(buffer, getenv("TERM")) == -1))
	{
		free(buffer);
		ft_printe("ft_select: error: terminal type invalid or TERM does not exist\n");
		exit(0);
	}
	caps->cm = tgetstr("cm", &caps->cm);
	caps->cl = tgetstr("cl", &caps->cl);
	caps->ce = tgetstr("ce", &caps->ce);
	caps->us = tgetstr("us", &caps->us);
	caps->me = tgetstr("me", &caps->me);
	caps->mr = tgetstr("mr", &caps->mr);
	caps->vi = tgetstr("vi", &caps->vi);
	caps->ve = tgetstr("ve", &caps->ve);
	caps->kl = tgetstr("kl", &caps->kl);
	caps->kr = tgetstr("kr", &caps->kr);
}

void	ft_action(void)
{
	struct sigaction action;


	action.sa_handler = ft_signal;
	action.sa_flags = SA_RESETHAND;
	action.sa_mask = SIGTSTP;
	sigaction(SIGTSTP, &action, NULL);
}

void	ft_continue(int sig)
{

	//ft_action();
//	ft_termios();
	ft_init_display(g_sig.caps);
	ft_print_handler(g_sig.caps, g_sig.args);
	ft_read(g_sig.caps, g_sig.args);
}

void	ft_actiontest(void)
{
	struct sigaction action;

	action.sa_handler = ft_continue;
	action.sa_flags = SA_RESETHAND;
	action.sa_mask = SIGCONT;
	sigaction(SIGCONT, &action, NULL);
}



//TODO: Initiate termios on SIGCONT
//TODO: Set sigaction SIGTSTP on SIGCONT
//TODO: Restore terminal settings on SIGTSTP



int main(int argc, char **argv)
{
	t_args *list;
	t_cap	caps;

	ft_actiontest();
	signal(SIGWINCH, ft_sigwinch);
	signal(SIGCONT, ft_continue);
	ft_capabilities(&caps);
	list = ft_memalloc(sizeof(t_args));
	if (argc >= 2)
		ft_list(argv, list);
	else
	{
		ft_printe("ft_select: requires one or more arguments\n");
		exit(0);
	}

	ft_termios();
	g_sig.caps = caps;
	g_caps = caps;
	ft_init_display(caps);
	ft_print_handler(caps, &(*list));
	ft_read(caps, &(*list));

	return (0);
}