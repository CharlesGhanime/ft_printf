# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 18:38:35 by cghanime          #+#    #+#              #
#    Updated: 2019/03/20 19:32:57 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_printf
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRCS :=	srcs/ft_printf.c \
		srcs/main_printf.c \

OBJ := $(SRCS:.c=.o)
LIBFT := libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $^ $(LIB)

libft : 
	make -C ./libft/

%.o : ./srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	rm -f srcs/*.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : libft all clean fclean re
