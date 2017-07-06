#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:33:14 by jpfeffer          #+#    #+#              #
#    Updated: 2016/09/21 09:33:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a
SRCS		=	$(shell ls | grep -E "ft_.+\.c")
OBJS		=	$(SRCS:.c=.o)
CC			=	@gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	make fclean

.PHONY: all clean fclean o make test
