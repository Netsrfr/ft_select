/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:14:06 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/06/19 16:14:06 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/ft_printe/ft_printe.h"
# include <termcap.h>
# include <sys/termios.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define CE ("ft_select: \x1b[31merror:\x1b[39m")
# define GOTO_X(x) (tputs(tgoto(caps.cm, x, win.ws_row), 1, ft_fputchar))

typedef struct		s_args
{
	char			*arg;
	int				head;
	int				cursor;
	int				selected;
	int				x;
	int				y;
	struct s_args	*next;
	struct s_args	*prev;
}					t_args;

typedef struct		s_cap
{
	char			*cm;
	char			*cl;
	char			*ce;
	char			*us;
	char			*mr;
	char			*me;
	char			*vi;
	char			*ve;
	char			*kl;
	char			*kr;
	char			*ti;
	char			*te;
}					t_cap;

typedef struct		s_sig
{
	t_cap			caps;
	t_args			*args;
	struct termios	term;
}					t_sig;
t_sig	g_sig;

/*
** arrows.c
*/
void				ft_arrows(char line, t_cap caps, t_args *args);

/*
** display.c
*/
void				ft_set_win(struct winsize *w);
void				ft_init_display(t_cap caps);

/*
** ft_select.c
*/
void				ft_read(t_cap caps, t_args *args);

/*
** keys.c
*/
void				ft_keys(char *line, t_cap caps, t_args **args);
void				ft_exit(t_cap caps, t_args *args);

/*
** print.c
*/
void				ft_print_handler(t_cap caps, t_args *args);

/*
** signals.c
*/
void				ft_sigaction(void);

/*
** termcaps.c
*/
void				ft_free_capabilities(t_cap *caps);
void				ft_capabilities(t_cap *caps);
void				ft_termios();

/*
** utility.c
*/
void				ft_width(t_args *head, size_t *width);
void				ft_free_args(t_args **args);
void				ft_cursor(t_args **args);
void				ft_head(t_args **args);
#endif
