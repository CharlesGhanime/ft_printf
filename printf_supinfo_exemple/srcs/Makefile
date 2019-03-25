#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 08:22:03 by cghanime          #+#    #+#              #
#    Updated: 2019/03/25 08:28:44 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
OPT := -o
NAME := cprintf
CFLAGS := -Wall -Wextra -Werror
SRCS := $(shell find ./ -type f -name "*.c")
OBJS := $(SRCS:.c=.o)
RM := rm -rf
BACKUP := *~

all: build

build: $(OBJS) $(CC) $(OPT) $(NAME) $(OBJS) $(CFLAGS)

clean: $(RM) $(OBJS) $(RM) $(BACKUP)

re: clear all
