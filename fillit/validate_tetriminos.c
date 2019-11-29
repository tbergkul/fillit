/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:34:06 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 13:51:54 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_neighbours(char *tetris, int y, int letter)
{
	int	i;
	int	newline;

	newline = 0;
	i = 0;
	if (tetris[y + 1] == '\n')
		newline = 1;
	if (tetris[y + 1 + newline] == letter)
		i++;
	if (newline == 1)
		newline = 0;
	if (tetris[y - 1] == '\n')
		newline = 1;
	if (tetris[y - 1 - newline] == letter)
		i++;
	if (tetris[y - 5] == letter)
		i++;
	if (tetris[y + 5] == letter)
		i++;
	return (i);
}

int	validate_character(char *tetris)
{
	int dot;
	int hash;
	int y;

	dot = 0;
	hash = 0;
	y = -1;
	while (tetris[++y])
	{
		if (tetris[y] == '.')
			dot++;
		if (tetris[y] == '#')
			hash++;
	}
	if ((dot != 12 || hash != 4) || ft_strlen(tetris) != 20)
		return (-1);
	return (1);
}

int	validate_tetriminos(t_tetris *block)
{
	int		i;
	int		x;
	int		y;
	int		counter;
	int		letter;

	x = -1;
	while (block->tetris[++x])
	{
		if (validate_character(block->tetris[x]) < 0)
			return (-1);
		y = -1;
		i = 0;
		counter = 0;
		letter = '#';
		while (block->tetris[x][++y])
		{
			if (block->tetris[x][y] == '.' || block->tetris[x][y] == letter)
				counter++;
			if (block->tetris[x][y] == letter)
				i = i + (check_neighbours(block->tetris[x], y, letter));
		}
		if ((i != 6 || i != 8) && counter != 16)
			return (-1);
	}
	return (1);
}
