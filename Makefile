# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 16:11:53 by khakala           #+#    #+#              #
#    Updated: 2019/12/05 13:55:31 by tbergkul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = libft/libft.a src/check_solution.c src/create_map.c src/fill_array.c src/ft_error.c src/main.c src/place_block.c src/save_input.c src/solver.c src/stack_tetrimino.c src/stacking_left.c src/inside_solution.c src/validate_tetriminos.c

OBJ = $(SRC:.c=.o)

CCFL = gcc -g -Wall -Wextra -Werror

LIBFT = libft/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CCFL) -o $(NAME) $(OBJ) $(SRCS)

clean:
	/bin/rm -f $(OBJ)
	make -C $(LIBFT) clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY = all $(NAME) clean fclean re
