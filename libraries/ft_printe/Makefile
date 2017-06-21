#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:33:14 by jpfeffer          #+#    #+#              #
#    Updated: 2017/04/19 12:18:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprinte.a

C_FILES = ft_printe.c ft_putwidth_e.c ft_conversions_alpha_e.c \
        ft_conversions_numerical_e.c ft_handlers_e.c ft_flags_1_e.c \
        ft_flags_2_e.c ft_hexadecimal_e.c

LIBFT		=	../../libft/libft.a
LIBLINK		=	-L ../../libft -lft

CFLAGS = -Wall -Wextra

LIBFT_SRCS = $(addprefix libft/,$(LIBFT))

SRCS = $(C_FILES)

OBJ = $(C_FILES:.c=.o)

.PHONY: all libft test clean fclean o

all: libft $(NAME)

libft: $(LIBFT)

$(LIBFT):
	@make -C ../../libft

$(NAME):
	@gcc $(CFLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

test: fclean
	@gcc $(SRCS) main.c

clean:
	@rm -f $(OBJ) main.o
	@make clean -C ../../libft

fclean: clean
	@rm -f $(NAME) a.out
	@make fclean -C ../../libft

o: fclean all