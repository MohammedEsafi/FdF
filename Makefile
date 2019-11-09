# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 13:57:00 by ael-makk          #+#    #+#              #
#    Updated: 2019/11/08 05:16:44 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ =	fdf.o \
		helpers/ft_check_file.o \
		helpers/lst_to_map.o \
		helpers/ft_hextoi.o \
		helpers/draw_line.o \
		helpers/draw_map.o \
		helpers/scale.o \
		helpers/projection.o \
		helpers/mouse_press.o \
		helpers/center.o \
		helpers/kit.o \
		helpers/rotation.o \
		helpers/key_press.o \
		helpers/z_altitude.o \
		helpers/usage.o \
		helpers/best_zoom.o \
		helpers/move.o

MLX_LIB = MiniLibX

MINI_LIB_FLAGS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAG) $(OBJ) libft/libft.a -L $(MLX_LIB) $(MINI_LIB_FLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all
