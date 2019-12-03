/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:55:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 18:10:57 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_tetrimino(t_tetris *block)
{
	char	letter;
	int		x;
	int		y;

	x = -1;
	y = -1;
	letter = 'A';
	while (block->tetris[++x])
	{
		y = -1;
		while (block->tetris[x][++y])
			if (block->tetris[x][y] == '#')
				block->tetris[x][y] = letter;
		letter++;
	}
}

int		split_input(t_tetris *block, char *input)
{
	int	x;
	int	y;
	int	i;
	int	length;

	block->tetris[0] = ft_strnew(21);
	x = 0;
	i = -1;
	y = -1;
	length = ft_strlen(input);
	while (length-- > -1)
	{
		block->tetris[x][++y] = input[++i];
		if (y == 20)
		{
			block->tetris[x][y] = '\0';
			x++;
			y = -1;
			if (!(block->tetris[x] = (char *)malloc(sizeof(char) * 21)))
				return (-1);
		}
	}
	block->tetris[x] = NULL;
	return (1);
}

int		get_input(const int fd, char **input)
{
	int		x;
	char	current[BUFF_SIZE + 1];

	x = 0;
	if (fd <= 0)
		return (-1);
	if ((x = read(fd, current, BUFF_SIZE)) > 0)
	{
		current[x] = '\0';
		*input = ft_strdup(current);
	}
	if (x < 20 || !(ft_strlen(*input) >= 20) || ((ft_strlen(*input) + 1) % 21 != 0))
		return (-1);
	else if (input == NULL)
		return (-1);
	return (1);
}

int		save_input(char *av, t_tetris *block)
{
	int		fd;
	char	*input;

	if (!(block->tetris = (char **)malloc(sizeof(char *) * 27)))
		return (-1);
	if ((fd = open(av, O_RDONLY)) < 0)
		return (-1);
	if (get_input(fd, &input) < 0)
		return (-1);
	if (split_input(block, input) < 0)
		return (-1);
	close(fd);
	if (validate_tetriminos(block) < 0)
		return (-1);
	stack_tetrimino(block);
	change_tetrimino(block);
	if (!(block->array = (char ***)malloc(sizeof(char **) * 27)))
		return (-1);
	if (fill_array(block) < 0)
		return (-1);
	return (1);
}
