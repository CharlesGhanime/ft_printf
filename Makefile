# **************************************************************************o* #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 18:38:35 by cghanime          #+#    #+#              #
#    Updated: 2019/08/10 16:23:57 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEADER := -I ./includes/ft_printf.h
NAME := libftprintf.a
EXEC := ft_printf
CC := gcc
AR = ar rcs
CFLAGS := -Wall -Wextra -Werror
SRCS :=		./srcs/ft_printf.c 				\
			./srcs/float_prec.c				\
			./srcs/funct_ptr.c				\
			./srcs/funct_ptr2.c				\
			./srcs/init.c					\
			./srcs/int_long_print.c			\
			./srcs/parse_type.c				\
			./srcs/parse_var.c				\
			./srcs/parser.c					\
			./srcs/print_info.c				\
			./srcs/return_letter.c			\
			./srcs/return_letter2.c			\
			./srcs/str_char_ptr_print.c		\
			./srcs/manage_opts.c			\
			./srcs/unsigned_octal_print.c	\
			./srcs/flags_functions.c		\
			./srcs/get_var_ouxx.c			\

OBJ := $(SRCS:.c=.o)

MAIN := ./main_printf/main_printf.c

LIB_PATH := ./libft
LIBFT := $(LIB_PATH)/libft.a

all : $(NAME) $(LIBFT)

$(NAME) : $(OBJ)
	@echo -e "\n\033[32m********\033[32m* MAKE *\033[32m********"
	$(MAKE) -C $(LIB_PATH)
	@libtool -static -o $@ $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME) $(LIBFT)

$(LIBFT) :
	$(MAKE) -C $(LIB_PATH)

	%.o : ./srcs/%.c

clean :
	@echo "\n"
	@echo "\033[31m************************************************************"
	@echo "\033[31m***************________________*****************************"
	@echo "\033[31m**************|                |****************************"
	@echo "\033[31m**************|   MAKE CLEAN   |****************************"
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


A_PATH = ./.annex

REAL = $(A_PATH)/printf
MINE = ft_printf

MAIN_FOLD = $(A_PATH)/mains_
MAIN_TEST = $(MAIN_FOLD)/main_test.c
MAIN_BUG = $(MAIN_FOLD)/main_bug.c
MAIN_PTR = $(MAIN_FOLD)/main_ptr.c

LOGS_FOLD = $(A_PATH)/logs
LOG_PTF = $(LOGS_FOLD)/logs_ptf
LOG_FTPTF = $(LOGS_FOLD)/logs_ftptf


trandom : 
	@sh .annex/modify/pct_conv.sh $(nb)
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(LIBFT) $(MAIN_TEST) -o $(REAL)
	@echo "$(GREEN)\tREAL PRINTF$(END)"
	@./$(REAL)

tdiff : trandom
	@sed -i '' 's/[^_]printf/ft_printf/g' $(MAIN_TEST)
	@$(CC) $(LIBFT) $(SRCS) $(MAIN_TEST) -o $(MINE)
	@echo "$(BBLUE)\t MY PRINTF$(END)"
	@./$(MINE)

catmain :
	@cat $(MAIN_TEST) | sed 's/\"_BBLUE\"//g' | sed 's/\"_RED\"//g' | sed 's/\"_END\"//g' | sed 's/\"_MAGENTA\"//g' | sed 's/\"_CYAN\"//g' | grep printf
catbug :
	@cat $(MAIN_BUG) | sed 's/\"_BBLUE\"//g' | sed 's/\"_RED\"//g' | sed 's/\"_END\"//g' | sed 's/\"_MAGENTA\"//g' | sed 's/\"_CYAN\"//g' | grep printf
catptr :	
	@cat $(MAIN_PTR) | sed 's/\"_BBLUE\"//g' | sed 's/\"_RED\"//g' | sed 's/\"_END\"//g' | sed 's/\"_MAGENTA\"//g' | sed 's/\"_CYAN\"//g' | grep printf

removecol :
	@sed -i '' 's/\"_BBLUE\"//g'					    $(MAIN_TEST)
	@sed -i '' 's/\"_RED\"//g'  					    $(MAIN_TEST)
	@sed -i '' 's/\"_END\"//g'  					    $(MAIN_TEST)
	@sed -i '' 's/\"_MAGENTA\"//g'  					$(MAIN_TEST)
	@sed -i '' 's/\"_CYAN\"//g' 					    $(MAIN_TEST)

greppct:																	# Greps %, symptoms and conv
	@grep -on -E "%.{1,6}"								$(MAIN_TEST)		# Useful for detailed view

toftptf:																	# printf becomes ft_printf
	@sed -i '' 's/printf(/ft_printf(/g' 				$(MAIN_TEST)		

toptf:																		# ft_printf becomes printf	
	@sed -i '' "s/ft_printf(/printf(/g" 				$(MAIN_TEST)

#ifeq (comline,$(firstword $(MAKECMDGOALS)))
#	COMLINE_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
#	$(eval $(COMLINE_ARGS):;@:)
#endif

coml:
	@sed -i '' '$(l)s/^/\/\//' $(MAIN_TEST)
dcoml:
	@sed -i '' '$(l)s/\/\///' $(MAIN_TEST)

tbug:
	@$(CC) $(LIBFT) $(SRCS) $(A_PATH)/$(MAIN_BUG) -o $(MINE)
	@./$(MINE)
tptr:
	@$(CC) $(LIBFT) $(SRCS) $(A_PATH)/$(MAIN_PTR) -o $(MINE)
	@./$(MINE)


run :
	@echo "$(RED)LOGS$(END)\n" > logs
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) $(SRCS) $(LIBFT) $(MAIN_TEST) -o $(NAME)
	@clear
	@echo "\t$(BBLUE)O$(END)U$(RED)T$(END)$(BBLUE)P$(END)U$(RED)T$(END)"
	@./$(NAME) 

diff : run toptf
	@$(CC) $(SRCS) $(LIBFT) $(MAIN_TEST) -o $(NAME)
	@./$(NAME) > $(LOG_PTF)
	@sed -i '' 's/printf(/ft_printf(/g' 				$(MAIN_TEST)		
	@$(CC) $(SRCS) $(LIBFT) $(MAIN_TEST) -o $(NAME)
	@./$(NAME) > $(LOG_FTPTF)
	@diff $(LOG_PTF) $(LOG_FTPTF)

modtest:
	@vim													$(MAIN_TEST)
modbug:
	@vim												 $(MAIN_BUG)
modptr:
	@vim												 $(MAIN_PTR)


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
	$(CC) -v $(NAME) $(MAIN) -o $(EXEC)

exef : $(NAME)
	@echo "\n"
	@echo "\033[32m************************************************************"
	@echo "\033[32m**********************MAKE EXECUTABLE WITH FLAGS************"
	@echo "\033[32m************************************************************"
	@echo "\n"
	$(CC) -v $(FLAGS) -o $(EXEC) $(NAME) $(MAIN)
	@echo        "______________________________         ________________________________          __________________________________"
	@echo       "/             /               /        /   _____    /  ___    /    /   \        /  /                /             /"
	@echo      "/    _________/_____    ______/        /   /___ /   /  /__/   /    /     \      /  /______    ______/    _________/"
	@echo     "/    /____          /   /              /   _________/  __   __/    /   /\  \    /  /     /   /      /    /____"
	@echo    "/    _____/         /   /              /   /        /  /  \  \/    /   /  \  \  /  /     /   /      /    _____/"
	@echo   "/    /              /   /______________/   /        /  /    \  \   /   /     \ \/  /     /   /      /    /"
	@echo  "/    /              /   /______________/   /        /  /      \  \ /   /       \   /     /   /      /    /"
	@echo "/____/              /___/______________/___/        /__/        \__\___/          \/     /___/      /____/"

.PHONY : all clean fclean re toptf toftptf#libft
