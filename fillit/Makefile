# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 16:11:53 by khakala           #+#    #+#              #
#    Updated: 2019/12/03 18:10:51 by tbergkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = ../libft/libft.a check_solution.c create_map.c fill_array.c ft_error.c main.c place_block.c save_input.c solver.c stack_tetrimino.c stacking_left.c validate_tetriminos.c

.PHONY = all $(NAME) clean fclean re

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRCS)

clean:
	/bin/rm -f a.out

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
