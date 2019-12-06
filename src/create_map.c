/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:17:23 by khakala           #+#    #+#             */
/*   Updated: 2019/12/06 11:06:50 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *map, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		ft_putstr(map->solution[x]);
		ft_putchar('\n');
		x++;
	}
}

void	free_map(t_map *map, int size)
{
	int x;

	x = 0;
	while (x < size)
	{
		ft_memdel((void **)&(map->solution[x]));
		x++;
	}
	ft_memdel((void **)&(map->solution[x]));
	ft_memdel((void **)(&map->solution));
}

void	free_stuff(t_map *map, t_tetris *block)
{
	int	y;
	int	t;

	t = 0;
	while (block->array[t])
	{
		y = 0;
		while (block->array[t][y])
		{
			ft_memdel((void **)(&block->array[t][y]));
			y++;
		}
		ft_memdel((void *)(&block->array[t]));
		t++;
	}
	ft_memdel((void *)(&block->array[t]));
	ft_memdel((void **)(&block->array));
	ft_memdel((void **)(&map));
	ft_memdel((void **)(&block));
}

int		create_map(t_map *map, int size)
{
	int		y;

	if (!(map->solution = (char **)malloc(sizeof(char *) * size + 1)))
		return (0);
	y = 0;
	while (y < size)
	{
		map->solution[y] = ft_strnew(size);
		ft_memset(map->solution[y], '.', size);
		y++;
	}
	map->solution[y] = NULL;
	return (1);
}
