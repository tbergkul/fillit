/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:29:49 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/18 14:12:28 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_tetris(char **tetris)
{
	int x;
	int y;

	x = -1;
	while (tetris[++x])
	{
		printf("\nTetris %d:\n", x);
		y = -1;
		while (tetris[x][++y])
		{
			/*if (y % 4 == 0)
				printf("\n");*/
			printf("%c", tetris[x][y]);
		}
	}
}
