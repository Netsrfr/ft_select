cmake_minimum_required(VERSION 3.6)
project(ft_select)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES ft_select.c ft_select.h
        libft/
        libft/libft.h
        libraries/ft_printf/ft_conversions_alpha.c
        libraries/ft_printf/ft_conversions_numerical.c
        libraries/ft_printf/ft_flags_1.c
        libraries/ft_printf/ft_flags_2.c
        libraries/ft_printf/ft_handlers.c
        libraries/ft_printf/ft_hexadecimal.c
        libraries/ft_printf/ft_printf.c
        libraries/ft_printf/ft_printf.h
        libraries/ft_printf/ft_putwidth.c
        libraries/ft_printe/ft_conversions_alpha_e.c
        libraries/ft_printe/ft_conversions_numerical_e.c
        libraries/ft_printe/ft_flags_1_e.c
        libraries/ft_printe/ft_flags_2_e.c
        libraries/ft_printe/ft_handlers_e.c
        libraries/ft_printe/ft_hexadecimal_e.c
        libraries/ft_printe/ft_printe.c
        libraries/ft_printe/ft_printe.h
        libraries/ft_printe/ft_putwidth_e.c
        libraries/get_next_line/get_next_line.c
        libraries/get_next_line/get_next_line.h
        libft/ft_split_whitespaces.c ft_select.c ft_select.h arrows.c keys.c utility.c termcaps.c display.c print.c signals.c colors.c bonus.c)
add_executable(ft_select ${SOURCE_FILES})