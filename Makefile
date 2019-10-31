# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/28 00:48:48 by tbareich          #+#    #+#              #
#    Updated: 2019/10/30 11:34:52 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FDF = main.c
LIBFT = libft/libft.a
FT_PRINTF = libft/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
GRAPHICFLAGC = -lmlx -framework OpenGL -framework AppKit
MINILIBX = minilibx
SRC = src/draw_line.o src/read_fdf_file.o src/helpers/ft_hextoi.o fdf.o

all : $(NAME)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(FDF) $(LIBFT) $(FT_PRINTF) $(SRC) \
	$(GRAPHICFLAGC) -L $(MINILIBX)

$(LIBFT): 
	make -C libft

clean: 
	rm -f $(SRC)
	make clean -C libft

fclean : clean
	rm -f fdf
	make fclean -C libft

re: fclean all