/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:29:49 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 16:14:34 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_tetris(t_tetris *block)
{
	int x;
	int y;

	x = -1;
	while (block->tetris[++x])
	{
		printf("\nblock->tetris[%d]:\n", x);
		y = -1;
		while (block->tetris[x][++y])
			printf("%c", block->tetris[x][y]);
	}
}

void	print_array(t_tetris *block)
{
	int	t;
	int	y;

	t = 0;
	while (block->array[t])
	{
		//printf("block->array[%d]:\n", t);
		y = 0;
		while (block->array[t][y])
		{
			printf("%s\n", block->array[t][y]);
			y++;
		}
		printf("\n");
		t++;
	}
}
