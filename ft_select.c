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

//int main(int argc, char **argv)
//{
//	struct termios test;
//	struct winsize	win;
//	int device;
//	char *name;
//	int slot;
//	char *buffer;
//	char *termtype;
//	char *cm;
//	char *cl;
//	char *test2;
//	extern char *BC;
//	extern char *UP;
//	int y;
//
//	termtype = ft_memalloc(2048);
//	ioctl(0, TIOCGWINSZ, &win);
//	device = STDOUT_FILENO;
//	if (!isatty(device))
//	{
//		printf("Not tty\n");
//		exit(0);
//	}
//	name = ttyname(device);
//	printf("ttyname = %s\n", name);
//	slot = ttyslot();
//	printf("ttyslot = %d\n", slot);
//	termtype = getenv("TERM");
//	buffer = ft_memalloc(2048);
//	y = tgetent(buffer, termtype);
//	printf("buffer = %d | %s\n", y, buffer);
//	tcgetattr(device, &test);
//	printf("%s | %lu | %lu | %lu | %lu | %lu | %lu\n", test.c_cc, test.c_ospeed, test.c_ispeed, test.c_oflag, test.c_lflag,test.c_iflag ,test.c_cflag);
//	BC = tgetstr("le", &BC);
//	UP = tgetstr("up", &UP);
//	printf("%s | %s\n", BC, UP);
//	cm = ft_memalloc(2048);
//	tgetstr("cm", &cm);
//	cl = ft_memalloc(2048);
//	tgetstr("cl", &cl);
//	test2 = tgoto(cm, 25, 25);
//	tputs(test2, 1, ft_fputchar);
//	tputs("Test\n", 1, ft_fputchar);
//	tputs(cl, 1, ft_fputchar);
//	return(0);
//}

void	ft_termios()
{
	struct termios term;
	char *line;

	line = ft_memalloc(1024);

	tcgetattr(STDIN_FILENO, &term);
//	printf("VMIN = %d\n", term.c_cc[VMIN]);
//	printf("VTIME = %d\n", term.c_cc[VTIME]);
//	printf("%lu\n", term.c_lflag);
	term.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);
//	printf("%lu\n", term.c_iflag);
//	printf("VMIN = %d\n", term.c_cc[VMIN]);
//	printf("VTIME = %d\n", term.c_cc[VTIME]);
	term.c_cc[VMIN] = 0;

//	read(STDIN_FILENO, line, 15);
//	printf("line = %s\n", line);
}

void	ft_read()
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
//	if (line[2] == 67)
//		printf("RIGHT\n");
//	if (line[2] == 68)
//		printf("LEFT\n");
	free(line);
	ft_read();
}

int main(int argc, char **argv)
{
	char *termtype = ft_memalloc(2048);
	char *buffer = ft_memalloc(2048);
	int result = 0;
	char	*cm;
	char	*cl;
	char *us;
	char *line;

	int i;
	i = 0;

		struct winsize	win;
	ioctl(0, TIOCGWINSZ, &win);
//	ft_printf("\033[40m\033[2J");
//	i = 1;
//	while (i < win.ws_row)
//	{
//		ft_printf(" \n");
//		i++;
//	}
	//printf("\033[49m");
	line = ft_memalloc(1024);
	ft_termios();
	termtype = getenv("TERM");
//	printf("termtype = %s\n", termtype);
	result = tgetent(buffer, termtype);
//	printf("buffer = %d | %s\n", result, termtype);
	cm = tgetstr("cm", &cm);
//	printf("cm = %s\n", cm);
	cl = tgetstr("cl", &cl);
//	printf("cl = %s\n", cl);
//	tputs(tgoto(cm, 25, 10), 1, ft_fputchar);
//	tputs("Test", 1, ft_fputchar);
	us = tgetstr("us", &us);
	tputs(tgoto(cm, 0, 0), 1, ft_fputchar);
//	ft_printf("\033[44m");
	while (i < win.ws_col)
	{
//		ft_printf(" ");
		i++;
		if (i == (win.ws_col/2 - 4))
		{
//			ft_printf("\033[37mft_select\033[39m");
			i = i + 9;
		}
	}
	i = 0;
	tputs(tgoto(cm, 0, win.ws_col), 1, ft_fputchar);
	while (i < win.ws_col)
	{
//		ft_printf(" ");
		i++;
	}
//	ft_printf("\033[40m");
	tputs(tgoto(cm, 8, 2), 1, ft_fputchar);
//	ft_printf("%s", us);
//	while (*argv)
//		ft_printf("\033[36m%s\033[39m ", *argv++);
	ft_read();

//	printf("line = %s\n", line);
	return (0);
}