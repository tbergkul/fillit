/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacking_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:32:30 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 13:51:57 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	do_stack_left(char *tetrimino, int y, int *temp)
{
	if (*temp == 3)
	{
		tetrimino[y - 3] = '#';
		tetrimino[y] = '.';
		return ;
	}
	if (*temp == 2)
	{
		tetrimino[y - 2] = '#';
		tetrimino[y] = '.';
		return ;
	}
	if (*temp == 1)
	{
		tetrimino[y - 1] = '#';
		tetrimino[y] = '.';
		return ;
	}
}

void	check_one(char *tetrimino, int y, int *temp)
{
	int	count;
	int	i;

	i = y;
	count = 0;
	while (tetrimino[++i])
	{
		if (tetrimino[i] == '#' && tetrimino[i - 1] == '\n')
			break ;
		if (tetrimino[i] == '#' && tetrimino[i - 1] != '\n')
			count++;
		if (tetrimino[i + 1] == '\0' && count >= 3)
		{
			tetrimino[y - 1] = '#';
			tetrimino[y] = '.';
			*temp = 1;
		}
	}
}

void	check_two(char *tetrimino, int y, int *temp)
{
	int	count;
	int	i;

	i = y;
	count = 1;
	while (tetrimino[++i])
	{
		if (tetrimino[i] == '#' && (tetrimino[i - 2] == '\n'
			|| tetrimino[i - 1] == '\n'))
			break ;
		if (tetrimino[i] == '#' && tetrimino[i - 2] == '.'
			&& tetrimino[i - 1] != '\n')
			count++;
		if (tetrimino[i + 1] == '\0' && count >= 3)
		{
			tetrimino[y - 2] = '#';
			tetrimino[y] = '.';
			*temp = 2;
		}
	}
}

void	check_three(char *tetrimino, int y, int *temp)
{
	int	count;
	int	i;

	i = y;
	count = 0;
	while (tetrimino[++i])
	{
		if (tetrimino[i] == '#' && (tetrimino[i - 3] == '\n'
			|| tetrimino[i - 2] == '\n' || tetrimino[i - 1] == '\n'))
			break ;
		if (tetrimino[i] == '#' && tetrimino[i - 3] == '.'
			&& tetrimino[i - 2] != '\n' && tetrimino[i - 1] != '\n')
			count++;
		if (tetrimino[i + 1] == '\0' && count >= 3)
		{
			tetrimino[y - 3] = '#';
			tetrimino[y] = '.';
			*temp = 3;
		}
	}
}
