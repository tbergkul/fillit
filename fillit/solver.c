/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:22:42 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 18:10:44 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_solution(t_map *map, t_tetris *block, int size, int t)
{
	/*system("clear");
	print_map(map, map->size);
	usleep(10000);
	system("clear");*/
	int	x;
	int	y;

	y = 0;
	if (!block->array[t])
		return (1);
	while (map->solution[y])
	{
		x = -1;
		while (map->solution[y][++x])
			if (map->solution[y][x] == '.')
			{
				block->x = x;
				block->y = y;
				if (check_overlap2(map, block, t))
				{
					place_block(map, block, t, 'p');
					if (solve_solution(map, block, size, ++t))
						return (1);
					else
						place_block(map, block, --t, 'd');
				}
			}
		y++;
	}
	return (0);
}

int	amount_tetriminos(t_tetris *block)
{
	int	x;

	x = 0;
	while (block->tetris[x])
		x++;
	return (x);
}

int	min_map(int hashtags)
{
	int	size;

	size = 2;
	while (size * size < hashtags)
		size++;
	return (size);
}

int	solver(t_tetris *block)
{
	t_map	*map;
	int		size;
	int		t;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (-1);
	size = min_map(amount_tetriminos(block) * 4);
	if (!(create_map(map, size)))
		return (-1);
	map->size = size;
	t = 0;
	while (!solve_solution(map, block, map->size, t))
	{
		free_map(map, map->size);
		map->size++;
		create_map(map, map->size);
		t = 0;
	}
	print_map(map, map->size);
	free_map(map, map->size);
	return (1);
}
