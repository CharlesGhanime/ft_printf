# **************************************************************************o* #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 18:38:35 by cghanime          #+#    #+#              #
#    Updated: 2019/08/15 00:03:27 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPP_FLAGS = -Iinclude

SRC_PATH = ./srcs
LIB_PATH = ./lib
INC_PATH = ./includes
OBJ_PATH = ./objs
OBJLIB_PATH = ./objs

SRC_NAME =		ft_printf.c 			\
			float_prec.c			\
			funct_ptr.c			\
			funct_ptr2.c			\
			init.c				\
			int_long_print.c		\
			parse_type.c			\
			parse_var.c			\
			parser.c			\
			print_info.c			\
			return_letter.c			\
			return_letter2.c		\
			str_char_ptr_print.c		\
			manage_opts.c			\
			unsigned_octal_print.c		\
			flags_functions.c		\
			get_var_ouxx.c			

LIB_SRCS = ft_addonechar.c	\
	ft_itoa_base.c		\
	ft_padding.c		\
	ft_strjoinfrchoz.c	\
	ft_addonecharpos.c	\
	ft_lltoa.c         	\
	ft_putchar.c       	\
	ft_strlen.c		\
	ft_atoi.c          	\
	ft_ltoa.c        	\
	ft_putstr.c        	\
	ft_strncat.c		\
	ft_bzero.c         	\
	ft_memalloc.c      	\
	ft_strcat.c        	\
	ft_strncpy.c		\
	ft_counter.c       	\
	ft_memcpy.c   	     	\
	ft_strcpy.c        	\
	ft_strndup.c		\
	ft_ftoa.c          	\
	ft_memdel.c        	\
	ft_strdup.c        	\
	ft_strsub.c		\
	ft_ischar.c        	\
	ft_memmove.c       	\
	ft_strjoin.c		\
	ft_itoa.c		\
	ft_memset.c		\
	ft_strjoinfr.c		\
	ft_uintmaxtoa_base.c \

INC_NAME = ft_printf.h libft.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_SRCS:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_SRCS))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/, $(OBJLIB_NAME))


all : $(NAME) 

$(NAME) : $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB)
#	@ranlib $(NAME)
	@echo "\033[1;34mlibftprintf.a\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o:$(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean :
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mlibftprintf.a\t\033[1;33mDeletion\t\033[0;32m[OK]\033[0m"

fclean : clean
	@rm -rf $(NAME) ./objs

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
	@$(CC) $(MAIN_TEST) -o $(REAL)
	@echo "$(GREEN)\tREAL PRINTF$(END)"
	@./$(REAL)

tdiff : trandom
	@sed -i '' 's/[^_]printf/ft_printf/g' $(MAIN_TEST)
	@$(CC) $(SRC) $(LIB) $(MAIN_TEST) -o $(MINE)
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
	@$(CC) $(LIB) $(SRC) $(A_PATH)/$(MAIN_BUG) -o $(MINE)
	@./$(MINE)
tptr:
	@$(CC) $(LIB) $(SRC)$(MAIN_PTR) -o $(MINE)
	@./$(MINE)


run :
	@echo "$(RED)LOGS$(END)\n" > logs
	@$(CC) $(SRC) $(LIB) $(MAIN_TEST) -o $(NAME)
	@clear
	@echo "\t$(BBLUE)O$(END)U$(RED)T$(END)$(BBLUE)P$(END)U$(RED)T$(END)"
	@./$(NAME) 

diff : run toptf
	@$(CC) $(SRC) $(LIB) $(MAIN_TEST) -o $(NAME)
	@./$(NAME) > $(LOG_PTF)
	@sed -i '' 's/printf(/ft_printf(/g' 				$(MAIN_TEST)		
	@$(CC) $(SRC) $(LIB) $(MAIN_TEST) -o $(NAME)
	@./$(NAME) > $(LOG_FTPTF)
	@diff --text $(LOG_PTF) $(LOG_FTPTF)

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
