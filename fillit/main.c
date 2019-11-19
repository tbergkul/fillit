/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:07:29 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/19 12:58:39 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	char	**tetris;
	char	**solution;
	char	*line;
	int		fd;
	char	*input;

	printf("\n\n-----------------INPUT------------------\n\n");
	if (ac != 2)
		return (-1);
	/*if (!av[1])//Fix so that empty file doesn't work!
		return (-1);*/
	if (!(tetris = (char **)malloc(sizeof(char*) * 26)))
		return (-1);
	tetris[0] = ft_strnew(21);
	input = ft_strnew(675);
	if ((fd = open(av[1], O_RDONLY)) > 0)
		if ((save_tetriminos(tetris, line, fd, &input) < 0))//tetris onodig???
			return (-1);
	split_tetriminos(tetris, input);
	/*printf("tetris[0]:\n%s\n", tetris[0]);
	printf("tetris[1]:\n%s\n", tetris[1]);
	printf("tetris[2]:\n%s\n", tetris[2]);*/
	close(fd);
	if (validate_tetriminos(tetris) < 0)
	{
		printf("Not proper tetriminos\n");
		return (-1);
	}
	else
		printf("Tetriminos validated!");
	change_tetrimino(tetris);
	print_tetris(tetris);
	printf("\n\n---------------Solution----------------\n");
	if (!(solution = (char **)malloc(sizeof(char*) * 5)))
		return (-1);
	int	size;
	int	grid;

	size = 3;
	grid = 0;
	if (ft_solution(&tetris, solution, size, grid) < 0)
		ft_solution(&tetris, solution, ++size, ++grid);
	print_tetris(solution);
	return (0);
}
