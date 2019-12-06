/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:44:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/06 13:59:27 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	leaks
**	push binary
**	check makefile rules
**	ac != 2
*/

int		main(int ac, char **av)
{
	t_tetris	*block;

	if (ac != 2)
	{
		ft_putendl("Usage: fillit input_file");
		return (-1);
	}
	if (!(block = (t_tetris *)malloc(sizeof(t_tetris))))
		return (ft_error());
	if (!(save_input(av[1], block)))
		return (ft_error());
	if (!(solver(block)))
		return (ft_error());
	int y = 1;
	while (y)
	{
		y = 1;
	}
	return (0);
}
