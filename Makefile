# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzawko <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 10:18:45 by bzawko            #+#    #+#              #
#    Updated: 2022/09/20 15:28:00 by bzawko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/libft_funcs.c srcs/main.c srcs/map_errors.c \
		srcs/map_to_array.c srcs/misc_funcs.c srcs/misc_funcs_2.c \
		srcs/misc_funcs_3.c srcs/check_paths.c srcs/move_funcs.c \
		srcs/misc_funcs_4.c srcs/misc_funcs_5.c srcs/move_funcs_2.c

OBJS 	= $(SRCS:.c=.o)

INCS	=	-Iincludes -Imlx

CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra $(INCS)

RM	=	rm -rf

NAME	=	so_long

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS)
		mv ./mlx/libmlx.dylib .

%.o: %.c mlx
		$(CC) -c $(CFLAGS) -Imlx $< -o $@

mlx:
		make -C ./mlx

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME) libmlx.dylib
		make clean -C ./mlx

re:		fclean $(NAME)

.PHONY:		all clean mlx fclean re
