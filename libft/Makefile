# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/29 23:44:50 by tbareich          #+#    #+#              #
#    Updated: 2019/10/29 20:44:48 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = bst_delete.c bst_deletenode.c bst_find.c bst_inorder.c bst_insert.c \
	   bst_max.c bst_min.c bst_modify_addr.c bst_newnode.c ft_atoi.c \
	   ft_bzero.c ft_delcontent.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	   ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstaddat.c \
	   ft_lstdel.c ft_lstdelat.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c \
	   ft_lstmap.c ft_lstnew.c ft_lstpop.c ft_lstpush.c ft_lstshift.c \
	   ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
	   ft_putendl.c ft_putendl_fd.c ft_putlst.c ft_putnbr.c ft_putnbr_fd.c \
	   ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	   ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strdup_free.c \
	   ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strjoin_free.c \
	   ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
	   ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
	   ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	   ft_tolower.c ft_toupper.c get_next_line.c ft_realloc.c
OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, ${SRCS:.c=.o})
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): $(OBJS_DIR)/%.o : %.c | $(OBJS_DIR)
	gcc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
