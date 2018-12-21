# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:51:31 by ayguillo          #+#    #+#              #
#    Updated: 2018/12/17 18:46:32 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = ./includes/

CC = @ gcc 

CFLAGS = -c -I $(INCLUDES) -Wall -Wextra -Werror

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_strcat.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnstr.c \
	  ft_strstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memalloc.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strclr.c \
	  ft_strdel.c \
	  ft_strnew.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_memset.c\
	  ft_putstr.c \
	  ft_striter.c  \
	  ft_striteri.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strsub.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_putchar.c \
	  ft_itoa.c \
	  ft_putendl.c \
	  ft_putnbr.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_putnstr.c \
	  ft_strclen.c \
	  ft_strndup.c \
	  ft_strcdup.c \
	  ft_sqrt.c \
	  ft_pwd.c \
	  ft_gnl.c \
	  ft_print_words_tables.c \
	  ft_lstdelcontent.c \
	  ft_lstclearifdata.c \
	  ft_putlst.c \
	  ft_lstlen.c \
	  ft_lstclear.c \
	  ft_str_joinfree.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) ./libft.h
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libft compiled ✔"

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

clean :
	@/bin/rm -f $(OBJ)
	@echo "objects deleted ✔"

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "deleted ✔"

re : fclean $(NAME)
