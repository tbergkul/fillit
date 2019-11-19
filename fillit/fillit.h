/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:31:04 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/19 12:58:41 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef T_COORDINATES
#  define T_COORDINATES

typedef	struct	s_coordinates
{
	int			a;
	int			b;
	int			c;
	int			d;
}				t_coordinates;

# endif

void			split_tetriminos(char **tetris, char *input);

void			*ft_memset_newline(void *b, int c, size_t len);

int				get_next_tetrimino(const int fd, char **line);

void			ft_coordinates(char *tetrimino, t_coordinates *coordinates);

int				ft_solution(char ***tetris, char **solution, int size, int grid);

void			print_tetris(char **tetris);

int				check_neighbours(char **tetris, int x, int y, int letter);

int				validate_character(char **tetris, int x);

int				validate_tetriminos(char **tetris);

int				save_tetriminos(char **tetris, char *line, int fd, char **input);

void			change_tetrimino(char **tetris);

#endif
