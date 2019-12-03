/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbergkul <tbergkul@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:44:44 by tbergkul          #+#    #+#             */
/*   Updated: 2019/12/03 18:10:57 by tbergkul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetris	block;

	if (ac != 2)
	{
		ft_putendl("Usage: fillit input_file");
		return (-1);
	}
	if (save_input(av[1], &block) < 0)
		return (ft_error());
	if (solver(&block) < 0)
		return (ft_error());
	return (0);
}
