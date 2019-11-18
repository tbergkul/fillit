/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:40:50 by tbergkul          #+#    #+#             */
/*   Updated: 2019/11/18 14:17:46 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_neighbours(char **tetris, int x, int y, int letter)
{
	int	i;
	int	newline;

	newline = 0;
	i = 0;
	if (tetris[x][y + 1] == '\n')
		newline = 1;
	if (tetris[x][y + 1 + newline] == letter)
		i++;
	if (newline == 1)
		newline = 0;
	if (tetris[x][y - 1] == '\n')
		newline = 1;
	if (tetris[x][y - 1 - newline] == letter)
		i++;
	if (tetris[x][y - 5] == letter)
		i++;
	if (tetris[x][y + 5] == letter)
		i++;
	return (i);
}

int		validate_character(char **tetris, int x)
{
	int dot;
	int hash;
	int y;

	dot = 0;
	hash = 0;
	y = -1;
	while (tetris[x][++y])
	{
		if (tetris[x][y] == '.')
			dot++;
		if (tetris[x][y] == '#')
			hash++;
	}
	if ((dot != 12 || hash != 4) || ft_strlen(tetris[x]) != 20)
		return (-1);
	return (0);
}

void	change_tetrimino(char **tetris)
{
	char	letter;
	int		x;
	int		y;

	x = -1;
	y = -1;
	letter = 'A';
	while (tetris[++x])
	{
		y = -1;
		while (tetris[x][++y])
			if (tetris[x][y] == '#')
				tetris[x][y] = letter;
		letter++;
	}
}

int		validate_tetriminos(char **tetris)//godkanner empty input
{
	int		i;
	int		x;
	int		y;
	int		counter;
	int		letter;

	x = -1;
	while (tetris[++x])
	{
		if (validate_character(tetris, x) < 0)
			return (-1);
		y = -1;
		i = 0;
		counter = 0;
		letter = '#';
		while (tetris[x][++y])
		{
			if (tetris[x][y] == '.' || tetris[x][y] == letter)
				counter++;
			if (tetris[x][y] == letter)
				i = i + (check_neighbours(tetris, x, y, letter));
		}
		if ((i != 6 || i != 8) && counter != 16)
			return (-1);
	}
	return (0);
}

int		save_tetriminos(char **tetris, char *line, int fd, char **input)
{
	int	x;
	//int	y;

	x = 0;
	//y = 1;
	if (get_next_tetrimino(fd, &line) > 0)
	{
		//if (!tetris[x])
		//printf("line:\n%s", line);
		*input = ft_strdup(line);
		//printf("input:\n%s", *input);
		//printf("tetris[x]:\n%s", tetris[x]);
		/*else
		{
			tetris[x] = ft_strjoin(tetris[x], line);
			if (y % 5 == 0)
			{
				tetris[x++][21] = '\0';
				if (!(tetris[x] = (char *)malloc(sizeof(char) * 21)))
					return (-1);
			}
		}*/
		//tetris[x++][21] = '\0';
		//x++;
		//printf("tetris[0]:\n%s", tetris[0]);
		/*if (!(tetris[x] = (char *)malloc(sizeof(char) * 21)))
			return (-1);*/
		free(line);
		//y++;
	}
	//tetris[++x] = NULL;
	return (0);
}
