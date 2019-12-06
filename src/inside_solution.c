/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inside_solution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:57:12 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/05 11:17:11 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function size_left_in_y_two checks if
**	the size of the tetrimino in y-axis is bigger than the
**	size of the solution. Returns 1, if it fits, else returns 0.
*/

int	size_left_in_y(t_tetris *block, int t, t_map *map)
{
	int	x;
	int	y;
	int count;

	y = -1;
	count = 0;
	while (block->array[t][++y])
	{
		x = -1;
		while (block->array[t][y][++x])
			if (block->array[t][y][x] >= 'A' && block->array[t][y][x] <= 'Z')
			{
				count++;
				break ;
			}
	}
	if (count > map->size)
		return (0);
	return (1);
}

/*
**	The function inside_solution_y checks if the tetriminos
**	size in y is bigger than the solution size.
**	Returns 0 if the tetrimino size is bigger
**	than solution size, if it fits returns 1.
*/

int	inside_solution_y(t_map *map, t_tetris *block, int t)
{
	if (!(size_left_in_y(block, t, map)))
		return (0);
	return (1);
}

/*
**	The function size_left_in_x checks if there is size
**	left in the solution that would fit the next
**	tetrimino (in x-axis).
**	Returns 1 if there is size left in solution, else returns 0.
*/

int	size_left_in_x(t_map *map, int maxletters)
{
	int	x;
	int	y;
	int	count;

	y = -1;
	count = 0;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
		{
			if (map->solution[y][x] != '.')
				count = 0;
			if (map->solution[y][x] == '.')
				count++;
			if (count == maxletters)
				return (1);
		}
	}
	return (0);
}

/*
**	The function size_left_in_x_two checks if the tetrimino is
**	bigger in size (in x-axis) than the solution size.
**	Returns 0 if the tetrimino is bigger than
**	the solution size, else if tetrimino fits, returns 1.
*/

int	size_left_in_x_two(t_map *map)
{
	int	y;
	int	x;
	int count;

	y = -1;
	count = 0;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
		{
			if (map->solution[y][x] == '.')
			{
				if (x >= count)
				{
					count = x + 1;
				}
			}
		}
	}
	if (count > map->size)
		return (0);
	return (1);
}

/*
**	The function inside_solution_x counts the maxletters
**	per line in the tetrimino. Then checks if there is size
**	left in the solution that would fit the next
**	tetrimino (in x-axis). Also checks if the tetriminos
**	size (in x-axis) is bigger than the solution size.
**	Returns 0 if the tetrimino size is bigger than
**	solution size, if it fits returns 1.
*/

int	inside_solution_x(t_map *map, t_tetris *block, int t)
{
	int	x;
	int	y;
	int	letters;
	int	maxletters;

	y = -1;
	maxletters = 0;
	while (block->array[t][++y])
	{
		x = -1;
		letters = 0;
		while (block->array[t][y][++x])
			if (block->array[t][y][x] >= 'A' && block->array[t][y][x] <= 'Z')
				letters++;
		if (letters > maxletters)
			maxletters = letters;
	}
	if (!(size_left_in_x(map, maxletters)))
		return (0);
	if (!(size_left_in_x_two(map)))
		return (0);
	return (1);
}
