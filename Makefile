# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalazhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 12:45:50 by aalazhar          #+#    #+#              #
#    Updated: 2021/12/01 15:46:15 by aalazhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

CNVRT = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all : $(NAME)

$(NAME) : $(CNVRT) $(INCLUDE)
	@ar rcs $(NAME) $(CNVRT)

%.o : %.c $(INCLUDE)
	@$(CC) $(FLAGS) -c $<

clean :
	@rm -rf $(CNVRT)

fclean : 
	@rm -rf $(NAME)

re : fclean all
