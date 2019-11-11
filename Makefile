# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/09 12:49:31 by tbareich          #+#    #+#              #
#    Updated: 2019/11/11 16:51:16 by tbareich         ###   ########.fr        #
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
		helpers/mouse_release.o \
		helpers/animation.o \
		helpers/make_usage_background.o \
		helpers/make_image_background.o \
		helpers/ft_free_map.o \
		handlers/handler_2d.o \
		handlers/handler_camera.o \
		handlers/handler_animation.o \
		handlers/handler_scale.o \
		handlers/handler_theme.o \
		handlers/handler_x_angle.o \
		handlers/handler_animation_direction.o \
		handlers/handler_y_angle.o \
		handlers/handler_z_alt.o \
		handlers/handler_z_angle.o

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
