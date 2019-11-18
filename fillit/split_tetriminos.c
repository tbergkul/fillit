/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:20:16 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/18 12:53:53 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	split_tetriminos(char **tetris, char *input)
{
	int	x;
	int	y;
	int	i;
	int	length;

	x = 0;
	i = -1;
	y = -1;
	length = ft_strlen(input);
	while (length-- > 0)
	{
		tetris[x][++y] = input[++i];
		//printf("input[%d]: %c\n", i, input[i]);
		if (y == 19)
		{
			tetris[x][++y] = '\0';
			//printf("tetris[%d]:\n%s\n", x, tetris[x]);
			x++;
			i++;
			length--;
			y = -1;
			//if (input[i])
			if (!(tetris[x] = (char *)malloc(sizeof(char) * 21)))
				return ;
		}
	}
	tetris[x] = NULL;
}
