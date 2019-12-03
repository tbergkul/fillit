/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:42:16 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 18:10:49 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function check_overlap checks if the next block to be placed will
**	overlap a previously placed block.
*/

int		tetrimino_fits(t_map *map, t_tetris *block, int t)
{
	int	a;
	int	b;
	int	i;
	int	j;
	int	first_x;

	a = -1;
	while (block->array[t][0][++a])
		if (block->array[t][0][a] >= 'A' && block->array[t][0][a] <= 'Z')
		{
			first_x = a;
			break ;
		}
	j = -1;
	while (block->array[t][++j])
	{
		i = a;
		while (block->array[t][j][++i])
		{
			if (block->array[t][j][i] >= 'A' && block->array[t][j][i] <= 'Z')
			{
				b = first_x - i;
				if ((block->x - b < 0) || block->y + j > map->size - 1 || map->solution[block->y + j][block->x - b] != '.')
					return (0);
			}
		}
		a = -1;
	}
	return (1);
}

int		check_overlap2(t_map *map, t_tetris *block, int t)
{
	if (!(inside_solution_x(map, block, t)))
		return (0);
	if (!(inside_solution_y(map, block, t)))
		return (0);
	if (!(tetrimino_fits(map, block, t)))
		return (0);
	return (1);
}

/*
**	The function check_overlap checks if the next block to be placed will
**	overlap a previously placed block.
*/

int		check_overlap(t_map *map, t_tetris *block, int t)
{
	int	x;
	int	y;

	y = -1;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
			if (map->solution[y][x] == '.')
			{
				block->x = x;
				block->y = y;
				if (tetrimino_fits(map, block, t))
					return (1);
			}
	}
	return (0);
}

/*
**
**
*/

/*int		size_left_in_y(t_map *map, int size)
{
	int	x;
	int	y;
	int count;

	y = -1;
	count = 0;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
			if (map->solution[y][x] == '.')//paska tills vidare
			{
				count++;
				break ;
			}
	}
	if (count > size)
		return (0);
	return (1);
}*/

/*
**	The function size_left_in_y_two checks if the size of the tetrimino in y-axis is bigger than the
**	size of the solution. Returns 1, if it fits, else returns 0.
*/

int		size_left_in_y_two(t_tetris *block, int t, t_map *map)
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
**	The function inside_solution_y checks if the tetriminos size in y is bigger than the solution size.
**	Returns 0 if the tetrimino size is bigger than solution size, if it fits returns 1.
*/

int		inside_solution_y(t_map *map, t_tetris *block, int t)
{
	//if (!(size_left_in_y(map, map->size)))
	//	return (0);
	if (!(size_left_in_y_two(block, t, map)))
		return (0);
	return (1);
}

/*
**	The function size_left_in_x checks if there is size left in the solution that would fit the next
**	tetrimino (in x-axis). Returns 1 if there is size left in solution, else returns 0.
*/

int		size_left_in_x(t_map *map, int maxletters)
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
**	Returns 0 if the tetrimino is bigger than the solution size, else if tetrimino fits, returns 1.
*/

int		size_left_in_x_two(t_map *map)
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
**	The function inside_solution_x counts the maxletters per line in the tetrimino.
**	Then checks if there is size left in the solution that would fit the next
**	tetrimino (in x-axis).
**	Also checks if the tetriminos size (in x-axis) is bigger than the solution size.
**	Returns 0 if the tetrimino size is bigger than solution size, if it fits returns 1.
*/

int		inside_solution_x(t_map *map, t_tetris *block, int t)
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
