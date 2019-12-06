/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:42:16 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/05 17:55:44 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function tetrimino_fits_two checks if the tetriminos 2-4
**	hashtags will fit in the solution on the available dot.
**	Returns 1 if it fits, else returns 0.
*/

int		tetrimino_fits_two(t_map *map, t_tetris *block, int t, int first_x)
{
	int	a;
	int	i;
	int	j;
	int	diff_in_x;

	a = first_x;
	j = -1;
	while (block->array[t][++j])
	{
		i = a;
		while (block->array[t][j][++i])
		{
			if (block->array[t][j][i] >= 'A' && block->array[t][j][i] <= 'Z')
			{
				diff_in_x = first_x - i;
				if ((block->x - diff_in_x < 0)
				|| block->y + j > map->size - 1
				|| map->solution[block->y + j][block->x - diff_in_x] != '.')
					return (0);
			}
		}
		a = -1;
	}
	return (1);
}

/*
**	The function tetrimino_fits checks if the tetrimino will
**	fit in the solution on the available dot.
**	Returns 1 if it fits, else returns 0.
*/

int		tetrimino_fits(t_map *map, t_tetris *block, int t)
{
	int	a;
	int	first_x;

	a = -1;
	first_x = 0;
	while (block->array[t][0][++a])
		if (block->array[t][0][a] >= 'A' && block->array[t][0][a] <= 'Z')
		{
			first_x = a;
			break ;
		}
	if (!(tetrimino_fits_two(map, block, t, first_x)))
		return (0);
	return (1);
}

/*
**	The function check_if_fits checks if the next block to be placed will
**	fit into the solution on the available dot.
**	Returns 1 if it fits, else returns 0.
*/

int		check_if_fits(t_map *map, t_tetris *block, int t)
{
	if (!(inside_solution_x(map, block, t)))
		return (0);
	if (!(inside_solution_y(map, block, t)))
		return (0);
	if (!(tetrimino_fits(map, block, t)))
		return (0);
	return (1);
}
