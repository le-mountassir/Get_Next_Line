# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:28:56 by ahel-mou          #+#    #+#              #
#    Updated: 2021/11/17 16:54:14 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC_F = get_next_line_utils.c

FLAGS = -Wall -Werror -Wextra

OBJ_F = $(SRC_F:.c=.o)

all = $(NAME)

$(NAME): $(OBJ_F)
	ar rcs $(NAME) $(OBJ_F)

%.o:%.c
	cc $(FLAGS) -c $<
clean:
	find . -name "*.o" -delete
	rm -f $(NAME)

re:clean all
.PHONY: clean, all, re