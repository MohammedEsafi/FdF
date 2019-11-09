# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 23:44:50 by tbareich          #+#    #+#              #
#    Updated: 2019/11/05 22:13:29 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = bst_delete.o bst_deletenode.o bst_find.o bst_inorder.o bst_insert.o \
	   bst_max.o bst_min.o bst_modify_addr.o bst_newnode.o ft_atoi.o \
	   ft_bzero.o ft_delcontent.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
	   ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstaddat.o \
	   ft_lstdel.o ft_lstdelat.o ft_lstdelone.o ft_lstiter.o ft_lstlen.o \
	   ft_lstmap.o ft_lstnew.o ft_lstpop.o ft_lstpush.o ft_lstshift.o \
	   ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o \
	   ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
	   ft_putendl.o ft_putendl_fd.o ft_putlst.o ft_putnbr.o ft_putnbr_fd.o \
	   ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o \
	   ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strdup_free.o \
	   ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strjoin_free.o \
	   ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o \
	   ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o \
	   ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o \
	   ft_tolower.o ft_toupper.o get_next_line.o ft_realloc.o get_int_len.o
CFLAGS = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME) : $(SRCS) $(FT_PRINTF)
	ar rc $(NAME) $(SRCS)
	ranlib $(NAME)

clean:
	rm -rf $(SRCS)

fclean: clean
	rm -f $(NAME)

re: fclean all
