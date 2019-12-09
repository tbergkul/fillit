/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:55:21 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/09 16:07:44 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	The function change_tetrimino changes the hashtags in the
**	tetriminos to letters starting from A.
*/

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

/*
**	The function split_input takes the amount of tetriminos given and splits
**	them into each their own string making an array of them.
**	Null-terminates each string and mallocs memory for them.
*/

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
	while (length-- > -1 && x < 26)
	{
		block->tetris[x][++y] = input[++i];
		if (y == 20)
		{
			block->tetris[x][y] = '\0';
			x++;
			y = -1;
			if (!(block->tetris[x] = (char *)malloc(sizeof(char) * 21)))
				return (0);
		}
	}
	free(block->tetris[x]);
	block->tetris[x] = NULL;
	return (1);
}

int		ft_amount(char **input)
{
	int	amount;

	amount = 0;
	amount = (ft_strlen(*input) + 1) / 21;
	amount = amount + 1;
	return (amount);
}

/*
**	The function get_input reads the inputfile and saves the line read into
**	the variable 'input'.
*/

int		get_input(const int fd, char **input)
{
	int		x;
	char	current[BUFF_SIZE + 1];

	x = 0;
	if (fd <= 0)
		return (0);
	if ((x = read(fd, current, BUFF_SIZE)) > 0)
	{
		if (x == 546)
			ft_error();
		current[x] = '\0';
		*input = ft_strdup(current);
	}
	if (x < 20 || !(ft_strlen(*input) >= 20)
	|| ((ft_strlen(*input) + 1) % 21 != 0))
	{
		if (input)
			ft_memdel((void *)(input));
		return (0);
	}
	else if (input == NULL)
		return (0);
	return (1);
}

/*
**	The function save_input reads the input, splits the input
**	into own tetriminos, validates the tetriminos, stacks the
**	tetriminos to the upper left corner, changes the
**	tetriminos hashtags into letters and fills them into a new array.
*/

int		save_input(char *av, t_tetris *block)
{
	int		fd;
	char	*input;
	int		amount;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	if (!(get_input(fd, &input)))
		return (0);
	amount = ft_amount(&input);
	if (!(block->tetris = (char **)malloc(sizeof(char *) * amount)))
		return (0);
	if (!(split_input(block, input)))
		return (0);
	ft_memdel((void *)(&input));
	close(fd);
	if (!(validate_tetriminos(block)))
		return (0);
	stack_tetrimino(block);
	change_tetrimino(block);
	if (!(block->array = (char ***)malloc(sizeof(char **) * amount)))
		return (0);
	if (!(fill_array(block)))
		return (0);
	return (1);
}
