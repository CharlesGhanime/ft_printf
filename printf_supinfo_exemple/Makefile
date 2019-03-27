# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cghanime <cghanime@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 09:43:15 by cghanime          #+#    #+#              #
#    Updated: 2019/03/27 09:57:21 by cghanime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
OPT := -o
NAME := cprintf
CFLAGS := -w -Wall
SRCS := $(shell find srcs/ -type f -name "*.c")
OBJS := $(SRCS:.c=.o)
RM := rm -rf
BACKUP := *~
all: build
build: $(OBJS) $(CC) $(OPT) $(NAME) $(OBJS) $(CFLAGS)
clear: $(RM) $(OBJS) $(RM) $(BACKUP)
re: clear all
