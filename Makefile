# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 18:38:35 by cghanime          #+#    #+#              #
#    Updated: 2019/06/06 11:29:27 by aboitier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER := -I ./includes/ft_printf.h
NAME := libftprintf.a
EXEC := ft_printf
CC := gcc
AR = ar rcs
CFLAGS := -Wall -Wextra -Werror
SRCS :=		./srcs/ft_printf.c \
			./srcs/ft_p_functions.c \
			./srcs/ft_p_functions_2.c \
			./srcs/ft_printf_aff_reforged.c \
			./srcs/ft_printf_get.c \
			./srcs/ft_printf_get_2.c \
			./srcs/check.c  \
			./srcs/init.c  \
			./srcs/print_info.c \
			./srcs/get_type.c \
			./srcs/ft_flags_functions.c \

#aff et aff_2 remplacées par reforged pour debugger la partie des fonctions d'affichage (trop de code accumulé)

OBJ := $(SRCS:.c=.o)

MAIN := ./main_printf/main_printf.c

LIB_PATH := ./libft
LIBFT := $(LIB_PATH)/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\n"
	@echo "\033[32m********"
	@echo "\033[32m* MAKE *"
	@echo "\033[32m********"
	@echo "\n"
	$(MAKE) -C $(LIB_PATH)
#	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT)
	@libtool -static -o $@ $(OBJ) $(LIBFT)


#@libtool -static -o $@ $^
#-o <objects> libft.a

libft : 
	$(MAKE) -C $(LIB_PATH)

	%.o : ./srcs/%.c

clean :
	@echo "\n"
	@echo "\033[31m************************************************************"
	@echo "\033[31m***************________________*****************************"
	@echo "\033[31m**************|                |****************************"
	@echo "\033[31m**************|   MAKE CLEAN  |****************************"
	@echo "\033[31m**************|________________|****************************"
	@echo "\033[31m************************************************************"
	@echo "\n"
	rm -rf $(OBJ)
	rm -rf *.o

clean_libft :
	make clean -C $(LIB_PATH)

fclean : clean
	@echo "\n"
	@echo "\033[31m************************************************************"
	@echo "\033[31m***************________________*****************************"
	@echo "\033[31m**************|                |****************************"
	@echo "\033[31m**************|   MAKE FCLEAN  |****************************"
	@echo "\033[31m**************|________________|****************************"
	@echo "\033[31m************************************************************"
	@echo "\n"
	rm -rf $(NAME)

re : fclean all

#############
#           #
#   TEST    #
#           #
#############

REAL = printf
MINE = ft_printf

A_PATH = ./.annex
MAIN_TEST = $(A_PATH)/main_test.c

trandom :
	@sh .annex/modify/pct_conv.sh $(nb)
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(LIBFT) $(MAIN_TEST) -o $(REAL)
	@echo "$(GREEN)\tREAL PRINTF$(END)"
	@./$(REAL)

ifeq (ptest2,$(firstword $(MAKECMDGOALS)))
	PTEST_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
	$(eval $RGS):;@:)
endif

tdiff : trandom
	@sed -i '' 's/[^_]printf/ft_printf/g' $(MAIN_TEST)
	@$(CC) $(CFLAGS) $(LIBFT) $(SRCS) $(MAIN_TEST) -o $(MINE)
	@echo "$(BBLUE)\t MY PRINTF$(END)"
	@./$(MINE)

catmain :
	@cat $(MAIN_TEST) | sed 's/\"_BBLUE\"//g' | sed 's/\"_RED\"//g' | sed 's/\"_END\"//
	g' | sed 's/\"_MAGENTA\"//g' | sed 's/\"_CYAN\"//g' | grep printf

removecol :
	@sed -i '' 's/\"_BBLUE\"//g'    $(MAIN_TEST)
	@sed -i '' 's/\"_RED\"//g'      $(MAIN_TEST)
	@sed -i '' 's/\"_END\"//g'      $(MAIN_TEST)
	@sed -i '' 's/\"_MAGENTA\"//g'  $(MAIN_TEST)
	@sed -i '' 's/\"_CYAN\"//g'     $(MAIN_TEST)

greppct:
	@grep -o -E "%.{1,6}" $(MAIN_TEST)

toftptf:
	@sed -i '' 's/printf/ft_printf/g' $(MAIN_TEST)
toptf:
	@sed -i '' 's/ft_printf/printf/g' $(MAIN_TEST)

tbug:
	@$(CC) $(LIBFT) $(SRCS) $(A_PATH)/main_bug.c -o $(MINE)
	@./$(MINE)

run :
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(SRCS) $(LIBFT) $(MAIN_TEST) -o $(NAME)
	@clear
	@echo "\t$(BBLUE)O$(END)U$(RED)T$(END)$(BBLUE)P$(END)U$(RED)T$(END)"
	@./$(NAME)

#############
#           #
#  COLORS   #
#           #
#############

RED     = \x1b[31m
GREEN   = \x1b[32m
YELLOW  = \x1b[33m
BLUE    = \x1b[34m
BBLUE   = \x1b[1;34m
MAGENTA = \x1b[35m
CYAN    = \x1b[36m
END     = \x1b[0m

ascii :
	@echo        "______________________________         ________________________________         ___________________________________"
	@echo       "/             /               /        /   _____    /  ___    /    /    \       /   /                /             /"
	@echo      "/    _________/_____    ______/        /   /___ /   /  /__/   /    /      \     /   /______    ______/    _________/"
	@echo     "/    /____          /   /              /   _________/  __   __/    /   /\   \   /   /     /   /      /    /____"
	@echo    "/    _____/         /   /              /   /        /  /  \  \/    /   /  \   \ /   /     /   /      /    _____/"
	@echo   "/    /              /   /______________/   /        /  /    \  \   /   /    \   /   /     /   /      /    /"
	@echo  "/    /              /   /______________/   /        /  /      \  \ /   /      \     /     /   /      /    /"
	@echo "/____/              /___/______________/___/        /__/        \__\___/        \___/     /___/      /____/"

exe : $(NAME)
	@echo "\n"
	@echo "\033[32m************************************************************"
	@echo "\033[32m**********************MAKE EXECUTABLE***********************"
	@echo "\033[32m************************************************************"
	@echo "\n"
	$(CC) $(NAME) $(MAIN) -o $(EXEC)

exef : $(NAME)
	@echo "\n"
	@echo "\033[32m************************************************************"
	@echo "\033[32m**********************MAKE EXECUTABLE WITH FLAGS************"
	@echo "\033[32m************************************************************"
	@echo "\n"
	$(CC) $(FLAGS) -o $(EXEC) $(NAME) $(MAIN)
	@echo        "______________________________         ________________________________          __________________________________"
	@echo       "/             /               /        /   _____    /  ___    /    /   \        /  /                /             /"
	@echo      "/    _________/_____    ______/        /   /___ /   /  /__/   /    /     \      /  /______    ______/    _________/"
	@echo     "/    /____          /   /              /   _________/  __   __/    /   /\  \    /  /     /   /      /    /____"
	@echo    "/    _____/         /   /              /   /        /  /  \  \/    /   /  \  \  /  /     /   /      /    _____/"
	@echo   "/    /              /   /______________/   /        /  /    \  \   /   /     \ \/  /     /   /      /    /"
	@echo  "/    /              /   /______________/   /        /  /      \  \ /   /       \   /     /   /      /    /"
	@echo "/____/              /___/______________/___/        /__/        \__\___/          \/     /___/      /____/"

.PHONY : all clean fclean re #libft
