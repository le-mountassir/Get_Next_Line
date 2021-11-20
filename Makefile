# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:28:56 by ahel-mou          #+#    #+#              #
#    Updated: 2021/11/20 13:18:53 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F = get_next_line.c get_next_line_utils.c

FLAGS = -Wall -Werror -Wextra

main:
	gcc $(FLAGS) main.c $(SRC_F) -o main
	clear
	./main

rm:
	rm -f main

.PHONY: crm, main