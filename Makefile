# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 16:28:56 by ahel-mou          #+#    #+#              #
#    Updated: 2021/11/20 15:45:17 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_F = main.c get_next_line.c get_next_line_utils.c

main:
	gcc $(FLAGS) $(SRC_F) -o main
	clear
	./main
clean:
	rm -f main
.PHONY: clean, main