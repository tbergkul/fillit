/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:56:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/05 20:58:08 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_tetris(t_tetris *block)
{
	int	x;

	x = 0;
	while (block->tetris[x])
	{
		ft_memdel((void **)(&block->tetris[x]));
		x++;
	}
	ft_memdel((void **)(&block->tetris[x]));
	ft_memdel((void **)(&block->tetris));
}

void	fill_array_two(t_tetris *block, int *t)
{
	int	i;

	i = 0;
	while (block->tetris[*t][i])
	{
		block->array[*t][block->y][++block->x] = block->tetris[*t][i++];
		if (block->x == 4)
		{
			block->array[*t][block->y][block->x] = '\0';
			block->y++;
			block->x = -1;
		}
	}
}

int		fill_array(t_tetris *block)
{
	int	t;

	t = -1;
	while (block->tetris[++t])
	{
		if (!(block->array[t] = (char **)malloc(sizeof(char *) * 5)))
			return (0);
		block->y = 0;
		while (block->y < 4)
			block->array[t][block->y++] = ft_strnew(4);
		block->y = 0;
		block->x = -1;
		fill_array_two(block, &t);
		block->array[t][block->y] = NULL;
	}
	block->array[t] = NULL;
	free_tetris(block);
	return (1);
}
