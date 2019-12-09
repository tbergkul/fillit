/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:48:18 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/09 10:56:18 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function delete_block deletes the last placed block
**	from the solution and replaces it with dots.
*/

void	delete_block(t_map *map, int t)
{
	int	x;
	int	y;

	y = -1;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
			if (map->solution[y][x] == 65 + t)
				map->solution[y][x] = '.';
	}
}

/*
**	The function place_block_two finds the first letter in the
**	array and places it in the solution.
*/

int		place_block_two(t_map *map, t_tetris *block, int t, int *first_x)
{
	int	x;

	x = -1;
	while (block->array[t][0][++x])
		if (block->array[t][0][x] >= 'A' && block->array[t][0][x] <= 'Z')
		{
			map->solution[block->y][block->x] = 65 + t;
			*first_x = x;
			break ;
		}
	return (*first_x);
}

/*
**	The place_block function places the block if path == 'p',
**	else if path == 'd' it will replace the last placed block
**	with dots.
*/

void	place_block(t_map *map, t_tetris *block, int t, int path)
{
	int	x;
	int	y;
	int	i;
	int	first_x;

	if (path == 'p')
	{
		first_x = 0;
		x = place_block_two(map, block, t, &first_x);
		y = -1;
		while (block->array[t][++y])
		{
			while (block->array[t][y][++x] && map->size - 1 >= x)
				if (block->array[t][y][x] >= 'A'
				&& block->array[t][y][x] <= 'Z')
				{
					i = first_x - x;
					map->solution[block->y + y][block->x - i] = 65 + t;
				}
			x = -1;
		}
	}
	else if (path == 'd')
		delete_block(map, t);
}
