/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:32:58 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 16:36:08 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	amount_left(char *tetrimino, int y, int *temp)
{
	if (*temp == 3 || *temp == 2 || *temp == 1)
	{
		do_stack_left(tetrimino, y, temp);
		return ;
	}
	if (tetrimino[y - 3] == '.' && tetrimino[y - 2] != '\n'
		&& tetrimino[y - 1] != '\n' && (*temp == 3 || *temp == 0) && y >= 3)
		check_three(tetrimino, y, temp);
	if (tetrimino[y - 2] == '.' && tetrimino[y - 1] != '\n'
		&& (*temp == 2 || *temp == 0) && y >= 2)
		check_two(tetrimino, y, temp);
	if (tetrimino[y - 1] == '.' && (*temp == 1 || *temp == 0) && y >= 1)
		check_one(tetrimino, y, temp);
}

void	stack_left(t_tetris *block)
{
	int			x;
	int			y;
	int			temp;

	x = -1;
	while (block->tetris[++x])
	{
		y = -1;
		temp = 0;
		while (block->tetris[x][++y])
		{
			if (block->tetris[x][y] == '#')
				amount_left(block->tetris[x], y, &temp);
		}
	}
}

void	amount_up(char *tetrimino, int y, int *temp)
{
	if (tetrimino[y - 15] == '.' && (*temp == 15 || *temp == 0) && y >= 15)
	{
		tetrimino[y - 15] = '#';
		tetrimino[y] = '.';
		*temp = 15;
	}
	if (tetrimino[y - 10] == '.' && (*temp == 10 || *temp == 0) && y >= 10)
	{
		tetrimino[y - 10] = '#';
		tetrimino[y] = '.';
		*temp = 10;
	}
	if (tetrimino[y - 5] == '.' && (*temp == 5 || *temp == 0) && y >= 5)
	{
		tetrimino[y - 5] = '#';
		tetrimino[y] = '.';
		*temp = 5;
	}
}

void	stack_up(t_tetris *block)
{
	int			x;
	int			y;
	int			temp;

	x = -1;
	while (block->tetris[++x])
	{
		y = -1;
		temp = 0;
		while (block->tetris[x][++y])
		{
			if (block->tetris[x][y] == '#')
				amount_up(block->tetris[x], y, &temp);
		}
	}
}

void	stack_tetrimino(t_tetris *block)
{
	stack_up(block);
	stack_left(block);
}
