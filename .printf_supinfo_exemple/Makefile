# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 09:43:15 by cghanime          #+#    #+#              #
#    Updated: 2019/04/07 09:42:01 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_cprintf
CC := gcc
OPT := -o
FLAGS := -Wall -Wextra -Werror
SRCS :=		srcs/cprintf.c \
			srcs/cprintf_aff.c \
			srcs/ft_write_functions.c \
			srcs/main.c \

OBJ := $(SRCS:.c=.o)
RM := rm -rf
BACKUP := *~

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OPT) $(NAME) $(OBJ)

%.o : ./srcs./%.c
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(RM) $(BACKUP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
