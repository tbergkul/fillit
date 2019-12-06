/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:34:06 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/05 11:17:11 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function check_neighbours checks the amount of neighbouring
**	letters. Returns the amount of neighbours.
*/

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

/*
**	The function validate_character validates that all characters in
**	the tetrimino is either a dot or a hashtag. Also checks the amount
**	of hashtags and dots, as well as the length of the tetrimino.
**	Returns 1, if it's valid, else 0 if not valid.
*/

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
		return (0);
	return (1);
}

/*
**	The function validate_neighbours counts the size of the
**	tetrimino based on dots and hashtags and calls function
**	check_neighbours to check that the form of tetrimino is correct.
*/

int	validate_neighbours(t_tetris *block, int x)
{
	int y;
	int i;
	int counter;
	int letter;

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
	if ((i != 6 && i != 8) || counter != 16)
		return (0);
	return (1);
}

/*
**	The function validate_tetriminos calls functions validate_character
**	and validate neighbours to validate the given tetrimino based on
**	amount of neighbours and characters in tetrimino.
*/

int	validate_tetriminos(t_tetris *block)
{
	int	x;

	x = -1;
	while (block->tetris[++x])
	{
		if (!(validate_character(block->tetris[x])))
			return (0);
		if (!(validate_neighbours(block, x)))
			return (0);
	}
	return (1);
}
