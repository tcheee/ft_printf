# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 16:47:38 by ayguillo          #+#    #+#              #
#    Updated: 2018/12/14 18:47:30 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TESTNAME = printtest

LIBFT = libft

INCLUDES = ./includes

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = flag_plus_space.c 	\
	   flag_space.c			\
	   flag_space_neg.c		\
	   ft_printf.c			\
	   ft_print_char.c 		\
	   ft_print_float.c		\
	   ft_print_hex.c		\
	   ft_print_number.c	\
	   ft_print_hex.c		\
	   ft_print_number.c	\
	   ft_print_octal.c		\
	   ft_print_percent.c	\
	   ft_print_string.c	\
	   ft_print_uhex.c		\
	   ft_print_uhexmaj.c	\
	   ft_print_unsign.c	\
	   ft_putnbr_base.c		\
	   ft_putnbr_basemaj.c	\
	   ft_putnbr_double.c	\
	   dispatcher.c			\
	   ft_nblen.c			\
	   increment.c			\

INCS = ft_printf.h

SRCSDIR = ./srcs/
LIBDIR = ./libft/
INCDIR = ./includes/

SOURCES = $(addprefix $(SRCDIR), $SRCS)
INCLUDES = $(addprefix $(INCDIR, $INCS))
OBJECTS = $(addprefix objs/, $(notdir $(SRCS:.c=.o)))

LIBRARIES = -lft

all : $(NAME)

$(NAME) : $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@make -C $(LIBDIR)
	@echo "$(NAME) compiled ✔"

objs/%.o : srcs/%.c
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $< -I./includes -o $@

$(LIBDIR)libft.a :
	@make -c $(LIBDIR)

clean :
	@rm -rf $(OBJECTS) objs
	@make -C $(LIBDIR) clean
	@echo "Objects deleted ✕"

fclean : clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "$(NAME) deleted ✕"

re : fclean all

test : all
	@$(CC) $(CFLAGS) -o $(TESTNAME) $(SRCSDIR)test.c -L./libft -lft \
		-L./ -lftprintf
	@echo "Test ready ✔"

testclean :
	@rm -f $(TESTNAME)
	@echo "Test deleted ✕"

.PHONY : all clean fclean re test
