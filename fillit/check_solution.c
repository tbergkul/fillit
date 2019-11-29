/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:42:16 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/29 17:05:49 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The place_block function places the block if path == 'p',
**	else if path == 'd' it will replace the last placed block
*/

void	place_block(t_map *map, t_tetris *block, int t, int path)
{
	if (path == 'p')
	{

	}
	else if (path == 'd')
	{

	}
}

/*
**	The function check_overlap checks if the next block to be placed will
**	overlap a previously placed block.
*/

int		check_overlap(t_map *map, t_tetris *block, int t)
{

	return (1);
}

/*
**
**
*/

int		inside_solution_y(t_map *map, t_tetris *block, int t, int size)
{
	return (1);
}

int		inside_solution_x(t_map *map, t_tetris *block, int t, int size)
{

	return (1);
}
