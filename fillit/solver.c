/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:22:42 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 17:12:21 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	solve_solution(t_map *map, t_tetris *block, int size)
{
	static int	t;
	system("clear");
	print_map(map, size);
	usleep(10000);

	block->x = 0;
	block->y = 0;
	t = 0;
	while (inside_solution_y(map, block, t, size))
	{
		while (inside_solution_x(map, block, t, size))
		{
			if (!check_overlap(map, block, t))
			{
				place_block(map, block, t, 'p');
				if (solve_solution(map, block, size))
					return (1);
				else
					place_block(map, block, t, 'd');
			}
			block->x++;
		}
		t++;
		block->x = 0;
		block->y++;
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

int	min_map(int	hashtags)
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

	size = min_map(amount_tetriminos(block) * 4);
	//printf("size done\n");
	map = create_map(size);
	printf("map created\n");
	while (solve_solution(map, block, size) < 0)
	{
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	//print_map(map, size);
	free_map(map, size);
	return (1);
}
