/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:56:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 16:02:47 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fill_array(t_tetris *block)
{
	int	t;
	int	x;
	int	y;
	int	i;

	t = -1;
	while (block->tetris[++t])
	{
		if (!(block->array[t] = (char **)malloc(sizeof(char *) * 5)))
			return (-1);
		y = 0;
		while (y < 4)
			block->array[t][y++] = ft_strnew(4);
		y = 0;
		i = 0;
		x = -1;
		while (block->tetris[t][i])
		{
			block->array[t][y][++x] = block->tetris[t][i++];
			if (x == 4)
			{
				block->array[t][y][x] = '\0';
				y++;
				x = -1;
			}
		}
		block->array[t][y] = NULL;
	}
	block->array[++t] = NULL;
	return (1);
}
