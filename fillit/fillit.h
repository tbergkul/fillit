/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:31:04 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 17:06:18 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>//remove this when done

typedef struct	s_map
{
	char		**solution;
	int			size;
}				t_map;

typedef struct	s_coord//remove this??
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetris
{
	char		**tetris;
	char		***array;
	int			x;
	int			y;
}				t_tetris;

void			place_block(t_map *map, t_tetris *block, int t, int path);//not done yet

int				check_overlap(t_map *map, t_tetris *block, int t);//not done yet

int				inside_solution_y(t_map *map, t_tetris *block, int t, int size);//not done yet

int				inside_solution_x(t_map *map, t_tetris *block, int t, int size);//not done yet

int				fill_array(t_tetris *block);

void			do_stack_left(char *tetrimino, int y, int *temp);

void			check_one(char *tetrimino, int y, int *temp);

void			check_two(char *tetrimino, int y, int *temp);

void			check_three(char *tetrimino, int y, int *temp);

void			stack_tetrimino(t_tetris *block);

void			free_map(t_map *map, int size);

void			print_map(t_map *map, int size);

t_map			*create_map(int size);

int				solver(t_tetris *block);

void			print_array(t_tetris *block);//remove this when done

void			print_tetris(t_tetris *block);//remove this when done

int				validate_tetriminos(t_tetris *block);

int				save_input(char *av, t_tetris *block);

int				ft_error(void);

#endif
