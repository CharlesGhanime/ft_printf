# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 18:38:35 by cghanime          #+#    #+#              #
#    Updated: 2019/05/06 12:15:40 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER := -I ./includes/ft_printf.h
NAME := libftprintf.a
EXEC := ft_printf
CC := gcc
FLAGS := -Wall -Wextra -Werror
SRCS :=		./srcs/ft_printf.c \
			./srcs/ft_p_functions.c \
			./srcs/ft_p_functions_2.c \
			./srcs/ft_printf_aff.c \
			./srcs/ft_printf_aff_2.c \
			./srcs/ft_printf_get.c \
			./srcs/ft_printf_get_2.c \
			./srcs/ft_putchar.c \
			./srcs/ft_putstr.c \
			./srcs/ft_strlen.c \
			./srcs/ft_putnbr.c \
			./srcs/ft_putnbr_base.c \
			./srcs/ft_atoi.c \
			./srcs/ft_itoa_base.c \
			./srcs/check.c  \
			./srcs/init.c  \
			./srcs/print_info.c \

OBJ := $(SRCS:.c=.o)

MAIN := ./main_printf/main_printf.c

#LIBFT := libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\n"
	@echo "\033[32m************************************************************"
	@echo "\033[32m*****************MAKE***************************************"
	@echo "\033[32m************************************************************"
	@echo "\n"
	$(CC) $(FLAGS) $(HEADER) -c $(SRCS) #$(NAME) $(OBJ) $(LIB)
	ar -rcv $(NAME) $(OBJ)
	ranlib $(NAME)
#	make -C libft

#libft : 
#	make -C ./libft/


$(EXEC) : $(NAME)
	@echo "\n"
	@echo "\033[32m************************************************************"
	@echo "\033[32m**********************MAKE EXECUTABLE***********************"
	@echo "\033[32m************************************************************"
	@echo "\n"
	$(CC) $(FLAGS) -o $(EXEC) $(NAME) $(MAIN)
	@echo         "______________ ________________       __________"
	@echo       "/             / /               /      /   __    /"
	@echo      "/    _________/ /____     ______/      /   /_/   / "
	@echo     "/    /____            /   /            /   ______/  "
	@echo    "/    _____/           /   /            /   /"
	@echo   "/    /                /   /            /   /"
	@echo  "/    /                /   /            /   /"
	@echo "/____/                /___/____________/___/              "
%.o : ./srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	@echo "\n"
	@echo "\033[31m************************************************************"
	@echo "\033[31m*****************MAKE CLEAN*********************************"
	@echo "\033[31m************************************************************"
	@echo "\n"
	rm -rf $(OBJ)
	rm -rf *.o

fclean : clean
	@echo "\n"
	@echo "\033[31m************************************************************"
	@echo "\033[31m*****************MAKE FCLEAN********************************"
	@echo "\033[31m************************************************************"
	@echo "\n"
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re #libft
