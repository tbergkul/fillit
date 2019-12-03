/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:48:18 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 18:10:46 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The place_block function places the block if path == 'p',
**	else if path == 'd' it will replace the last placed block
*/

void	place_block(t_map *map, t_tetris *block, int t, int path)
{
	int	x;
	int	y;
	int	i;
	int temp;
	int	first_x;

	if (path == 'p')
	{
		first_x = 0;
		x = -1;
		while (block->array[t][0][++x])
			if (block->array[t][0][x] >= 'A' && block->array[t][0][x] <= 'Z')
			{
				map->solution[block->y][block->x] = block->array[t][0][x];
				first_x = x;
				break ;
			}
		y = -1;
		temp = first_x;
		while (block->array[t][++y])
		{
			x = temp;
			while (block->array[t][y][++x] && map->size - 1 >= x)
			{
				if (block->array[t][y][x] >= 'A' && block->array[t][y][x] <= 'Z')
				{
					i = first_x - x;
					map->solution[block->y + y][block->x - i] = 65 + t;
				}
			}
			temp = -1;
		}
	}
	else if (path == 'd')
	{
		y = -1;
		while (map->solution[++y])
		{
			x = -1;
			while (map->solution[y][++x])
				if (map->solution[y][x] == 65 + t)
					map->solution[y][x] = '.';
		}
	}
}
