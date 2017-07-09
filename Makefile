#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 11:53:50 by jpfeffer          #+#    #+#              #
#    Updated: 2017/06/14 17:58:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_select

C_FILES = ft_select.c arrows.c keys.c utility.c termcaps.c display.c print.c \
			signals.c colors.c bonus.c

LIBFT		=	./libft/libft.a
PRINTF		=	./libraries/ft_printf/libftprintf.a
PRINTE		=	./libraries/ft_printe/libftprinte.a
LIBLINK		=	-ltermcap -L ./libraries -lselect
LIBRARY		=	./libraries/libselect.a

SRCS = $(C_FILES)

C_FLAGS = -Wall -Werror -Wextra

.PHONY: all library libft printf printe test testre clean fclean re

all: library $(NAME)

library: libft printf printe $(LIBRARY)

$(LIBRARY):
	@libtool -static -o ./libraries/libselect.a $(LIBFT) $(PRINTF) \
	$(PRINTE)

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

printf: $(PRINTF)

$(PRINTF):
	@make -C ./libraries/ft_printf

printe: $(PRINTE)

$(PRINTE):
	@make -C ./libraries/ft_printe

$(NAME): $(C_FILES) ft_select.h
	@gcc $(C_FLAGS) $(LIBLINK) $(SRCS) -o ft_select

test: library
	@gcc $(SRCS) $(LIBLINK) -o ft_select

testre: fclean library
	@gcc $(SRCS) $(LIBLINK) -o ft_select

ftest: fclean library
	@gcc $(SRCS) $(LIBLINK) -fsanitize=address -o ft_select

clean:
	@make clean -C ./libft
	@make clean -C ./libraries/ft_printf
	@make clean -C ./libraries/ft_printe

fclean: clean
	@rm -f $(LIBRARY) a.out ft_select
	@make fclean -C ./libft
	@make fclean -C ./libraries/ft_printf
	@make fclean -C ./libraries/ft_printe

re: fclean all