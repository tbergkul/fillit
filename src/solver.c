/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:22:42 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/09 16:09:04 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_solution(t_map *map, t_tetris *block, int t)
{
	int	x;
	int	y;

	if (!block->array[t])
		return (1);
	y = -1;
	while (map->solution[++y])
	{
		x = -1;
		while (map->solution[y][++x])
			if (map->solution[y][x] == '.')
			{
				block->x = x;
				block->y = y;
				if (check_if_fits(map, block, t))
				{
					place_block(map, block, t, 'p');
					if (solve_solution(map, block, ++t))
						return (1);
					else
						place_block(map, block, --t, 'd');
				}
			}
	}
	return (0);
}

int	amount_tetriminos(t_tetris *block)
{
	int	x;

	x = 0;
	while (block->array[x])
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
	int		t;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->size = min_map(amount_tetriminos(block) * 4);
	if (!(create_map(map, map->size)))
	{
		ft_memdel((void **)(&map));
		return (0);
	}
	t = 0;
	while (!solve_solution(map, block, t))
	{
		free_map(map, map->size);
		map->size++;
		create_map(map, map->size);
		t = 0;
	}
	print_map(map, map->size);
	free_map(map, map->size);
	free_stuff(map, block);
	return (1);
}
