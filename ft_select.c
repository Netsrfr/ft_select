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
		ft_delete(caps, &args);
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

	head->arg = argv[1];
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
	ft_head(&link);
}

void	ft_interrupt(int sig)
{
	ft_printe("INTERRUPT\n");
	sleep(1);
	exit(SIGINT);
}

void	ft_test1()
{
	struct sigaction action;

	action.sa_handler = ft_interrupt;
	action.sa_flags = SA_SIGINFO;
	action.sa_mask = SIGINT;
	sigaction(SIGINT, &action, NULL);
}

void	ft_signal(int sig)
{
	ft_printe("SLEEPING\n");
	sleep(1);
	//g_sig.term.c_lflag |= ~(ICANON|ECHO);
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

void	ft_action(void)
{
	struct sigaction action;

	action.sa_handler = ft_signal;
	action.sa_flags = SA_RESETHAND;
	action.sa_mask = SIGTSTP;
	sigaction(SIGTSTP, &action, NULL);
	ft_test1();
}

void	ft_actiontest(void)
{
	struct sigaction action;

	action.sa_handler = ft_continue;
	action.sa_flags = SA_NODEFER;
	action.sa_mask = SIGCONT;
	sigaction(SIGCONT, &action, NULL);
}

void	ft_continue(int sig)
{
	ft_printe("WAKING\n");
	sleep(1);
	ft_action();
	ft_termios();
	ft_init_display(g_sig.caps);
	ft_print_handler(g_sig.caps, g_sig.args);
	ft_read(g_sig.caps, g_sig.args);
}



//TODO: Initiate termios on SIGCONT
//TODO: Set sigaction SIGTSTP on SIGCONT
//TODO: Restore terminal settings on SIGTSTP





int main(int argc, char **argv)
{
	t_args *list;
	t_cap	caps;

	ft_test1();
	ft_action();
	signal(SIGWINCH, ft_sigwinch);
	ft_actiontest();
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