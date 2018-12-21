# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 16:47:38 by ayguillo          #+#    #+#              #
#    Updated: 2018/12/21 10:34:05 by ayguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TESTNAME = printtest

LIBFT = libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = capture_the_flag.c	\
	   get_precision.c		\
	   get_space_number.c	\
	   flag_plus_space.c 	\
	   flag_space.c			\
	   flag_0.c				\
	   flag_hash.c			\
	   flag_space_neg.c		\
	   flag_precision.c		\
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
	   ft_putnstr.c			\
	   dispatcher.c			\
	   ft_nblen.c			\
	   ft_nblen_double.c	\
	   increment.c			\
	   increment_error.c	\
	   check_error.c		\
	   check_flag_hl.c		\
	   ft_nblen_unsign.c	\
	   ft_putnbr_base_addr.c\
	   ft_putnbr_unsign.c	\

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
	@make -C $(LIBDIR)
	mv libft/libft.a ./
	@ar rc libft.a $(OBJECTS)
	@mv libft.a $(NAME)
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
	@$(CC) $(CFLAGS) -o $(TESTNAME) $(SRCSDIR)test.c -L./ -lftprintf
	@echo "Test ready ✔"

testclean :
	@rm -f $(TESTNAME)
	@echo "Test deleted ✕"

.PHONY : all clean fclean re test
