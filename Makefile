# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 12:49:31 by tbareich          #+#    #+#              #
#    Updated: 2019/11/09 12:49:32 by tbareich         ###   ########.fr        #
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
		helpers/move.o \
		helpers/mouse_move.o \
		helpers/mouse_release.o

MINI_LIB_FLAGS = -lm -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	$(CC) $(CFLAG) $(OBJ) libft/libft.a $(MINI_LIB_FLAGS) -o $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C libft/

fclean : clean
	make fclean -C libft/
	rm -f $(NAME)

re : fclean all
