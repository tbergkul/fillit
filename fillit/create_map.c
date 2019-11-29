/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:17:23 by khakala           #+#    #+#             */
/*   Updated: 2019/11/29 16:19:30 by tbergkul         ###   ########.fr       */
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
	ft_memdel((void **)&(map->solution));
	ft_memdel((void **)&map);
}

t_map		*create_map(int size)
{
	t_map	*map;
	int		i;

	//printf("create_map\n");
	map = (t_map *)malloc(sizeof(t_map));
	map->solution = (char **)malloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->solution[i] = ft_strnew(size);
		ft_memset(map->solution[i], '.', size);
		i++;
	}
	//printf("create_map2\n");
	//print_map(map, size);
	return (map);
}
